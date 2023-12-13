import communicate
import speaker
import pygame
from serial import SerialException

# Code send by ESP through serial link
METTRE_MUSIQUE = "100"
ETEINT_MUSIQUE = "101"
CHRONO_MUSIQUE = "105"

if __name__ == '__main__':
	pygame.init()
	esp_connected = False
	while True:
		try:
			# Check if esp (via serial usb) is connected, if not, do nothing
			if not esp_connected :
				ser = communicate.serial_init()
				esp_connected = True
			else :	
				# Read data from serial link
				if communicate.checkBufferEmpty(ser):
					msgReceived = communicate.readMsg(ser)
					print(msgReceived)
					# Decode message and play music
					# Send a ack to confirm with ESP
					if msgReceived == METTRE_MUSIQUE :
						communicate.sentMsg(ser, 'ack')
						speaker.playMusic()
					elif msgReceived == ETEINT_MUSIQUE:
						communicate.sentMsg(ser, 'ack')
						speaker.stopMusic()
					elif msgReceived == CHRONO_MUSIQUE:
						communicate.sentMsg(ser, 'ack')
						speaker.playChronoSound()
					else:
						speaker.playSound(msgReceived)
						communicate.sentMsg(ser, 'ack')
					#Flush the serial buffer
					communicate.flushBuffer(ser)

		except SerialException:
			pass
		except UnicodeDecodeError:
			pass
		except pygame.error:
			pass
