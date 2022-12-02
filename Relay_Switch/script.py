#!/usr/bin/env python
import RPi.GPIO as GPIO
import time

relayPin = 11    # GPIO17

def setup():
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(relayPin, GPIO.OUT)
	GPIO.output(relayPin, GPIO.HIGH)

def loop():
	while True:
		GPIO.output(relayPin, GPIO.LOW)
		time.sleep(0.5)
		GPIO.output(relayPin, GPIO.HIGH)
		time.sleep(0.5)

def destroy():
	GPIO.output(relayPin, GPIO.HIGH)
	GPIO.cleanup()

if __name__ == '__main__': 
	setup()
	try:
		loop()
	except KeyboardInterrupt: 
		destroy()
