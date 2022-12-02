#!/usr/bin/env python3
import RPi.GPIO as GPIO

tiltPin  = 11 #GPIO17
redPin   = 12 #GPIO18
greenPin = 13 #GPIO27

def setup():
	GPIO.setmode(GPIO.BOARD)       
	GPIO.setup(redPin, GPIO.OUT)     # Set Red Pin mode to output
	GPIO.setup(greenPin, GPIO.OUT)     # Set Green Pin mode to output
	GPIO.setup(tiltPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)    # Set Tilt Pin mode is input
	GPIO.add_event_detect(tiltPin, GPIO.BOTH, callback=detect, bouncetime=200)

def Led(x):
	if x == 0:
		GPIO.output(redPin, 1)
		GPIO.output(greenPin, 0)
	if x == 1:
		GPIO.output(redPin, 0)
		GPIO.output(greenPin, 1)

def detect(chn):
	Led(GPIO.input(tiltPin))

def loop():
	while True:
		pass

def destroy():
	GPIO.output(redPin, GPIO.HIGH
	GPIO.output(greenPin, GPIO.HIGH)
	GPIO.cleanup()

if __name__ == '__main__':
	setup()
	try:
		loop()
	except KeyboardInterrupt:
		destroy()
