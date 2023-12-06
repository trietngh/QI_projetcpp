import serial

class communicate:
	def __init__(self, linkToESP):
		self.linkToESP = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
		self.linkToESP.flush()
	
	def sentMsg(message):
		message = message + "\n"
		message = message.encode('utf_8')
		self.linkToESP.write(message)
	
	def readMsg():
		return self.linkToESP.readline().decode('utf_8').rstrip()
