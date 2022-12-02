#!/usr/bin/env python3
import RPi.GPIO as GPIO
import time

vibrationPin = 11 # GPIO17
redPin       = 12 # GPIO18
greenPin     = 13 # GPIO27

def setup():
	GPIO.setmode(GPIO.BOARD)       
	GPIO.setup(redPin, GPIO.OUT)   # Set Red Pin mode to output
	GPIO.setup(greenPin, GPIO.OUT) # Set Green Pin mode to output
	GPIO.setup(vibrationPin, GPIO.IN, pull_up_down=GPIO.PUD_UP) # Set Vib Pin mode as input

def Led(x):
	if x == 0:
		GPIO.output(redPin, 1)
		GPIO.output(greenPin, 0)
	if x == 1:
		GPIO.output(redPin, 0)
		GPIO.output(greenPin, 1)
	
def loop():
	state = 0
	while True:
		if GPIO.input(vibrationPin) == 0:
			state = state + 1
			if state > 1:
				state = 0
			Led(state)
			time.sleep(1)

def destroy():
	GPIO.output(redPin, GPIO.HIGH) 
	GPIO.output(greenPin, GPIO.HIGH) 
	GPIO.cleanup()     

if __name__ == '__main__':    
	setup()
	try:
		loop()
	except KeyboardInterrupt:  
		destroy()
