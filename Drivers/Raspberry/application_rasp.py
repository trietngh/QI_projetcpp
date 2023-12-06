import communicate
import time

if __name__ == '__main__':
	communicate.__init__()
	
	while True:
		communicate.sentMsg('A')
		time.sleep(1)
		communicate.sentMsg('ErrBlt')
		time.sleep(1)
		msgReceived = communicate.readMsg();
		print("receive: ", msgReceived)
		time.sleep(1)
		
