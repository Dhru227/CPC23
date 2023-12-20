import pickle
import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost',1234))
server_socket.listen()

print ("Server listeing")

while True:
    client_socket, client_address = server_socket.accept()
    print(f"connection from {client_address}")
    
    data = client_socket.recv(1024)
    unsorted_array = pickle.loads(data)
    print ("Received undorted arrat:", unsorted_array)
    
    sorted_array = list(sorted(unsorted_array))
    sorted_array = pickle.dumps(sorted_array)
    client_socket.send(sorted_array)
    
    print("sorted array sent back to client:", sorted_array)
    
    client_socket.close()