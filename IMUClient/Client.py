import socket
import struct

class IMUClient:
    def __init__(self, host, port):
        self.host = host
        self.port = port

    def connect(self):
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect((self.host, self.port))
        print(f"Connected to {self.host}:{self.port}")

    def request_accel_data(self):
        self.client_socket.sendall(b'GET_ACCEL_DATA')

        data = self.client_socket.recv(1024)

        if data == b'EOF':
            print("No more data available.")
            return None
        
        acc_x, acc_y, acc_z = struct.unpack('hhh', data)

        print(f"Received accelerometer data: X = {acc_x}, Y = {acc_y}, Z = {acc_z}")
        return acc_x, acc_y, acc_z
    
    def request_gyro_data(self):
        self.client_socket.sendall(b'GET_GYRO_DATA')

        data = self.client_socket.recv(1024)

        if data == b'EOF':
           print("No more data available.")
           return None
        
        gyro_x, gyro_y, gyro_z = struct.unpack('hhh', data)

        print(f"Received gyroscope data: X = {gyro_x}, Y = {gyro_y}, Z = {gyro_z}")
        return gyro_x, gyro_y, gyro_z
    
    #Example how to get the IMU register format:
    def format(self):
        value = -13332
        LSB = value & 0xFF
        MSB = value >> 8
        print(f"LSB: {LSB:08b}")
        print(f"MSB: {MSB & 0xFF:08b}")

if __name__ == "__main__":
    imu_client = IMUClient('127.0.0.1', 65432)
    imu_client.connect()

    for _ in range(10):
        imu_client.request_accel_data()
        imu_client.request_gyro_data()