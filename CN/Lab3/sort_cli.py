import pickle
import socket

unsortred_array = list(map(int, input().split()))

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost',1234))

data = pickle.dumps(unsortred_array)
client_socket.send(data)

sorted_data = client_socket.recv(1024)
sorted_array = pickle.loads(sorted_data)
print("Received sorted array from server:", sorted_array)

client_socket.close()