# Import LED functions from gpiozero library
from gpiozero import LED          
# Import Button functions from gpiozero library
from gpiozero import Button        

# Var for GPIO pin 4 for LED out
led = LED(4)
# Var for GPIO pin 17 for Button out
button = Button(17)

# Loop (infinite)
while True:
        # Wait for Button press
        button.wait_for_press()
        
        #Turn on the LED
        led.on()

        # Wait for Button release
        button.wait_for_release()

        # Turn off the LED
        led.off()
