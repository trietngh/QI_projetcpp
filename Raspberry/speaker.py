import pygame

MESSAGE_FELICITATION = "102"
DOMMAGE = "103"
MERCI = "104"

# Play question and sound effet (Unable to interrupt, play until end)

def playSound(sound):
	if sound == DOMMAGE :
		pygame.mixer.music.load("/home/triet/Desktop/projets/QI_projetcpp/Drivers/Raspberry/sound/Dommage.mp3")
		pygame.mixer.music.play()
		while pygame.mixer.music.get_busy():
			continue
		pygame.mixer.music.stop()
	elif sound == MESSAGE_FELICITATION :
		pygame.mixer.music.load("/home/triet/Desktop/projets/QI_projetcpp/Drivers/Raspberry/sound/Felicitation.mp3")
		pygame.mixer.music.play()
		while pygame.mixer.music.get_busy():
			continue
		pygame.mixer.music.stop()
	elif sound == MERCI :
		pygame.mixer.music.load("/home/triet/Desktop/projets/QI_projetcpp/Drivers/Raspberry/sound/Merci.mp3")
		pygame.mixer.music.play()
		while pygame.mixer.music.get_busy():
			continue
		pygame.mixer.music.stop()
	elif sound >= "1" or sound <= "21":
		pygame.mixer.music.load("/home/triet/Desktop/projets/QI_projetcpp/Drivers/Raspberry/sound/q" + str(sound) + ".mp3")
		pygame.mixer.music.play()
		while pygame.mixer.music.get_busy():
			continue
		pygame.mixer.music.stop()

# Play background music (Interrupt possible)
def playMusic():
	pygame.mixer.music.load("/home/triet/Desktop/projets/QI_projetcpp/Drivers/Raspberry/sound/Music.mp3")
	pygame.mixer.music.play()
# Stop background music
def stopMusic():
	pygame.mixer.music.stop()
# Play chronometer sound (Interrupt possible)
def playChronoSound():
	pygame.mixer.music.load("/home/triet/Desktop/projets/QI_projetcpp/Drivers/Raspberry/sound/Chrono.mp3")
	pygame.mixer.music.play()

