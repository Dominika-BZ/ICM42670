import csv
import socket
import struct

#To make python find the csv file:
import os    
os.chdir(os.path.dirname(os.path.abspath(__file__)))

class IMUSimulator:
    def __init__(self, csv_file):
        self.csv_file = csv_file
        self.data = self.load_data(csv_file)
        self.pointer = 0

    def load_data(self, csv_file):
        with open(csv_file, 'r') as file:
            reader = csv.reader(file)
            headers = next(reader)
            return [row for row in reader]
        
    def get_next_data(self):
        if self.pointer >= len(self.data):
            self.pointer = 0
        data = self.data[self.pointer]
        self.pointer += 1
        return data
    
    def data_to_raw(self, value, range_max):
            raw_value = int((value / range_max) * 32768)
            return raw_value
        
    def handle_request(self, client_socket):
        while True:

            request = client_socket.recv(1024).decode('utf-8')

            if not request:
                break

            if request == 'GET_ACCEL_DATA':
                acc_range_max = 2.0
                try:
                    row = self.get_next_data()
                    acc_x = float(row[0])
                    acc_y = float(row[1])
                    acc_z = float(row[2])

                    raw_acc_x = self.data_to_raw(acc_x, acc_range_max)
                    raw_acc_y = self.data_to_raw(acc_y, acc_range_max)
                    raw_acc_z = self.data_to_raw(acc_z, acc_range_max)

                    response = struct.pack('hhh', raw_acc_x, raw_acc_y, raw_acc_z)
                    client_socket.send(response)

                except StopIteration:
                    client_socket.send(b'EOF')

            elif request == 'GET_GYRO_DATA':
                gyro_range_max = 250.0
                try:
                    row = self.get_next_data()
                    gyro_x = float(row[3])
                    gyro_y = float(row[4])
                    gyro_z = float(row[5])

                    raw_gyro_x = self.data_to_raw(gyro_x, gyro_range_max)
                    raw_gyro_y = self.data_to_raw(gyro_y, gyro_range_max)
                    raw_gyro_z = self.data_to_raw(gyro_z, gyro_range_max)

                    response = struct.pack('hhh', raw_gyro_x, raw_gyro_y, raw_gyro_z)
                    client_socket.send(response)

                except StopIteration:
                    client_socket.send(b'EOF')

        client_socket.close()
            
class IMUServer:
    def __init__(self, host, port, imu_simulator):
        self.host = host
        self.port = port
        self.imu_simulator = imu_simulator

    def start(self):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
            server_socket.bind((self.host, self.port))
            server_socket.listen()
            print(f"Server started on {self.host}:{self.port}")

            while True:
                client_socket, _ = server_socket.accept()
                print(f"Connected with {client_socket}")
                self.imu_simulator.handle_request(client_socket)
                       
if __name__ == "__main__":
    imu_simulator = IMUSimulator('2023-01-16-15-33-09-imu.csv')
    server = IMUServer('127.0.0.1', 65432, imu_simulator)
    server.start()