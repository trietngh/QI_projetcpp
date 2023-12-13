import serial

# Initialize the serial link through USB port
# Return ser : serial link	
def serial_init():
	ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
	ser.flush()
	return ser

# Sent a message through serial
# Parameter : 
# 	ser : serial link
# 	message : string of message to send	
def sentMsg(ser, message):
	message = message + "\n"
	message = message.encode('utf_8')
	ser.write(message)

# Read a message from serial link
# Parameter : 
# 	ser : serial link
# Return : string
def readMsg(ser):
	return ser.readline().decode('utf-8').rstrip()

# Check if serial buffer is empty
# Parameter : 
# 	ser : serial link
# Return : bool
def checkBufferEmpty(ser):
	result = False
	if ser.in_waiting != 0 :
		result = True
	return result

# Flush serial buffer
# Parameter : 
# 	ser : serial link 
def flushBuffer(ser):
	ser.flush()
