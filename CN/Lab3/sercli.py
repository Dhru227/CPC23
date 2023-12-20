import pickle
import socket
unsorted_array = list(map(int, input().split()))
x = int(input())

arr_to_send = unsorted_array + [x]

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost',1234))

data = pickle.dumps(arr_to_send)
client_socket.send(data)

recv_data = client_socket.recv(1024)
ans = pickle.loads(recv_data)
print("is element there?",ans)

client_socket.close()