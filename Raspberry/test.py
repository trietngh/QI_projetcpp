import communicate
import speaker
import time
import os
import pygame
from serial import SerialException


METTRE_MUSIQUE = "100"
ETEINT_MUSIQUE = "101"

if __name__ == '__main__':
	pygame.init()
	
	pygame.mixer.music.load("./sound/Chrono.mp3")
	pygame.mixer.music.play()
	while pygame.mixer.music.get_busy():
		continue
	pygame.mixer.music.stop()

