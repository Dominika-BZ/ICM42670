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

if __name__ == "__main__":
    imu_client = IMUClient('127.0.0.1', 65432)
    imu_client.connect()

    for _ in range(10):
        imu_client.request_accel_data()