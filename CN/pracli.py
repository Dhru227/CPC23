import socket
import threading
import pickle

ip,port= '127.0.0.1',4000
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect((ip,port))

def receive():
    while True:
        try:
            msg = s.recv(4096)
            decoded_msg = pickle.loads(msg)
            print(f"Received: {decoded_msg}")
        except:
            try:
                s.close()
            except:
                pass
  
def send():
    while True:
        inp = input("Enter data:")
        if(inp == '-1'):
            s.close()
            print("Disconnected")
        else:
            s.sendall(pickle.dump(inp))                
            
sender = threading.Thread(target=send)
receiver = threading.Thread(target=receive)

sender.start()
receiver.start()            