# MorsaLisa
An offline wireless communications protocol using light.
## Purpose
To create a (semi-) encrypted wireless communication protocol between two devices that is not reliant upon WiFi, Bluetooth or cellular.

## Hardware Requirements
1. 2 Arduino boards **
2. Analog photoresistor sensor
3. Laser emit sensor
4. 5 Male-to-Female jumper wires
5. 4 Male-to-male jumper wires ***
6. Breadboard ***

** Most Arduino boards will do, I use a MKR1010 and a UNO WiFi
*** These are not circuit requirements, instead they are just to secure  

## Functionality
One board is connected to the laser emit, this will be referred to as the painter. The other is connected to the photoresistor, this will be referred to as the canvas.

The painter waits for inspiration to come, in the form of Serial.readString(). When the painter finds inspiration, it waits 6 seconds to allow the user to switch to monitoring the canvas. After the 6 seconds, the painter starts firing light signals measured in Morse units. The length of one Morse unit in this case is 50ms. The explanation of Morse units is found below, in the gallery.

A photoresistor has a resistance which depends on the light exposed to the surface. So the resistance of the photoresistor is high when the laser is reflecting on the surface, and low otherwise. The analogRead() function measures the voltage entering an analog pin. By ohm's law, when the resistance is high, our voltage will be low, and vice versa. We check for a low voltage (reading < 75) for a 1 (laser is on), and a 0 otherwise.

The canvas waits for light signals on intervals of one Morse unit, once it receives it's first '1', it creates a binary string representing the light patterns, of the form '1010101000100010111010100010111010100011101110111000000000'. This is converted to Morse using the unit conversions seen below, (ex. 000 translates to the end of a letter, 00000000 translates to the end of a word). Continuing with our example of our above binary string, this is then converting from binary to Morse, and looks like the following '.... . .-.. .-.. ---'. This string is then passed into another function, converting from Morse to alphabet, and finally, it will be returned as the final product, "HELLO".

## Gallery
![alt text](https://raw.githubusercontent.com/RohitKochhar/MorsaLisa/master/Public/Images/BreadboardLayout.jpg)
Connections and breaboard layout
![alt text](https://raw.githubusercontent.com/RohitKochhar/MorsaLisa/master/Public/Images/MorseLegend.jpg)
Morse code legend, explaining unit system (Retrieved from Wikipedia)
![alt text](https://raw.githubusercontent.com/RohitKochhar/MorsaLisa/master/Public/Videos/demo.mp4)
A demo video, spelling out "THE QUICK BROWN FOX JUMPS OVER THE LAZY BROWN DOG"

More information to come soon! (Posted 26/12/2018)
