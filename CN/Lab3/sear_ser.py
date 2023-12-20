import pickle
import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 1234))
server_socket.listen(1)

print("server listening...")

while True:
    client_socket, client_address = server_socket.accept()
    print(f"connectioon from {client_address}")
    
    data = client_socket.recv(1024)
    arr_recv = pickle.loads(data)
    else_to_search = arr_recv[-1]
    curr_arr = arr_recv[:-1]
    
    ans = False
    if (else_to_search in curr_arr): ans = True
    ans_send = pickle.dumps(ans)
    client_socket.send(ans_send)
    
    print ("sending", ans)
    client_socket.close()