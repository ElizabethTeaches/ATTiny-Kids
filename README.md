# ATTiny-Kids
ATTiny Code written so middle school kids can edit it to customize their circuitry projects.

This code is meant to be loaded onto ATTiny85 chips using a USB Programmer (we use [SparkFun's Tiny AVR Programmer](https://www.sparkfun.com/products/11801) and the Arduino IDE. Getting the drivers to work has been somewhat challenging. What has worked for us with on Windows 10 with the Arduino IDE 1.8.5 is:
1. Install [these drivers](https://learn.adafruit.com/usbtinyisp/drivers) from Adafruit.
2. Then [get this add-on](https://cdn.sparkfun.com/assets/learn_tutorials/1/5/0/attiny-ide-1.6.x.zip) Unzip the add-on and find the attiny folder living within the attiny-ide-1.x.x.zip file you downloaded. Copy that folder and paste it into a folder called hardware within your Arduino Sketchbook directory. I have had to make that folder each time. By default, Arduino Sketchbook will be under Documents on Windows machines that I have worked on.
3. Set the board to ATTiny, the processor to ATTiny85 and the programmer to USBTinyISP.

One other issue you may have is with the SoftwareServo library. You can download it [here](https://playground.arduino.cc/uploads/ComponentLib/SoftwareServo.zip).  Then:
1. Within the Arduino app, go to Sketch -> include libraries -> add .ZIP library and add the library.
2. Open the SofwareServo.h file in an editor (Notepad works fine) and change <WProgram.h> to <Arduino.h>
I still get a bunch of warnings on compile, but it all seems to work fine.
