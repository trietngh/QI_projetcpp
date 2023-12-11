import serial

	
def serial_init():
	ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
	ser.flush()
	return ser
	
def sentMsg(ser, message):
	message = message + "\n"
	message = message.encode('utf_8')
	ser.write(message)
	
def readMsg(ser):
	return ser.readline().decode('utf-8').rstrip()

def checkBufferEmpty(ser):
	result = False
	if ser.in_waiting != 0 :
		result = True
	return result
	
def flushBuffer(ser):
	ser.flush()
