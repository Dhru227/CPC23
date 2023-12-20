import socket
import pickle
import threading

ip,port = '127.0.0.1',4000

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((ip,port))
s.listen()
print(f"listening on port {port}")


def handle_client(conn,addr):
    while True:
        try:
            msg = conn.recv(4096)
            decoded_msg = pickle.loads(msg)
            print(f"received {decoded_msg}")
            conn.sendall(pickle.dumps("Received message"))
        except:
            print("ending connection")
            conn.close()
            break

while True:
    conn,addr = s.accept()
    # conn.sendall()
    print(f"Connection opened by {addr}")
    th = threading.Thread(target=handle_client,args=(conn,addr,))
    th.start()

s.close()
print("closed successfully")

