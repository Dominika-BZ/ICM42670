import csv
import socket

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
            return None
        data = self.data[self.pointer]
        self.pointer += 1
        return data
    
    def handle_request(self, request):
        if request['action'] == 'read':
            data = self.get_next_data()
            if data:
                return data
            else:
                return {"Error: End of data."}
            
class IMUServer:
    def __init__(self, host, port, imu_simulator):
        self.host = host
        self.port = port
        self.imu_simulator = imu_simulator


if __name__ == "main":
    imu_simulator = IMUSimulator('2023-01-16-15-33-09-imu.csv')