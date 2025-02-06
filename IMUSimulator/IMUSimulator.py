import csv
import socket
import json

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
            reader = csv.DictReader(file)
            return [row for row in reader]
        
    def get_next_data(self):
        if self.pointer >= len(self.data):
            self.pointer = 0
        data = self.data[self.pointer]
        self.pointer += 1
        return data
    
    def handle_request(self, request):
        if request['action'] == 'read':
            data = self.get_next_data()
            if data:
                return json.dumps(data)
            else:
                return json.dumps({"error": "End of data"})
            
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
                with client_socket:
                    data = client_socket.recv(1024)
                    while True:
                        try:
                            request = json.loads(data.decode())
                            response = self.imu_simulator.handle_request(request)
                            client_socket.sendall(response.encode())
                        except:
                            client_socket.sendall(json.dumps({"Error: Invalid json"}).encode())


if __name__ == "__main__":
    imu_simulator = IMUSimulator('2023-01-16-15-33-09-imu.csv')
    server = IMUServer('127.0.0.1', 65432, imu_simulator)
    server.start()