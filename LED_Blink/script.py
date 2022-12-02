#!/usr/bin/env python3
import RPi.GPIO as GPIO
import time

redLedPin = 11    # GPIO17

def setup():
	GPIO.setmode(GPIO.BOARD)        # Number GPIO by physical location
	GPIO.setup(redLedPin, GPIO.OUT) # Set redLedPin's mode as output
	GPIO.output(redLedPin, GPIO.HIGH)

def loop():
	while True:
		GPIO.output(redLedPin, GPIO.LOW)  # turn LED on
		time.sleep(0.5)
		GPIO.output(redLedPin, GPIO.HIGH) # turn LED off
		time.sleep(0.5)

def destroy():
	GPIO.output(redLedPin, GPIO.HIGH)     # led off
	GPIO.cleanup()

if __name__ == '__main__':
	setup()
	try:
		loop()
	except KeyboardInterrupt:  # 'Ctrl+C' to destroy
		destroy()
