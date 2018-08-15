#include <SoftwareServo.h> //This brings in a library that allows us to control our servos

//Now we can create something called "objects" to control our servos and name them according to the pins they will use
SoftwareServo myServo0;
SoftwareServo myServo1;

//Next we will rename some pins for a button and some leds
//There are 5 pins on the ATTinys we are using that we can use for the button, servos, and LEDs
//The button will be on digital pin four and we are naming that pin the buttonPin 
//The LED(s) will be on digital pins two and three and we are naming those pins so they are easy to track 

//const means that these won't change (they are not variables)
//int means that they have integer values
const int buttonPin = 4; //Our PCBs have a space drilled to fit a button on pin 4
const int ledPin2 = 2;
const int ledPin3 = 3;          

// Now let's create a variable for the button press and a variable for the current movement pattern
int buttonState = 0;
int flag = 0; 

// I also need a variable for the position of each servo since the pulses to the servos are too short for abrupt changes.
int pos0;
int pos1;

void setup() //This is the one time set up code for the ATTiny (The code above was housekeeping for the setup and loop code)
{
  //attach the servo objects to digital pins 0 and 1
  myServo0.attach(0);
  myServo1.attach(1);

  //setup the led pins as output and the buttonPin as an input
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() // This is the code that will run in a continuous loop on the ATTiny
{
  //This bit of code reads whether the button is pressed or not
  buttonState = digitalRead(buttonPin);

  //If button is currently pressed, then ....
  if (buttonState == HIGH && flag == 0) //This does fast servos
  {
    for(pos0 = 0; pos0 < 180; pos0 += 15)
    {
      myServo0.write(pos0);              // this sets Servo0 to pos0
      delay(15);                         // this waits 15ms for the servo to reach the pos0
      SoftwareServo::refresh();          // this refreshes the servos location
    }
    digitalWrite(ledPin2, HIGH);           // This turns the first led on
    for(pos1 = 0; pos1 < 180; pos1 += 15)  // This sets up the same sweep for Servo1 after the first servo finishes
    {                                  
      myServo1.write(pos1);              
      delay(15);                       
      SoftwareServo::refresh();  
    }
    digitalWrite(ledPin3, HIGH);           // This turns the second led on
    for(pos0 = 180; pos0 >= 1; pos0 -= 15)
    {
      myServo0.write(0);              
      delay(15);                       
      SoftwareServo::refresh();
    }
    digitalWrite(ledPin2, LOW);            // This turns the first led off
    for(pos1 = 180; pos1 >= 1; pos1 -= 15) // this runs a counter back to zero to sweep the second servo back
    {                                
      myServo1.write(pos1);              
      delay(15);                       
      SoftwareServo::refresh();
    }
     digitalWrite(ledPin3, LOW);          // This turns the second led off
  }
    else if (buttonState == HIGH && flag == 1) //This does Servo0 fast and Servo1 slow
  {
    for(pos0 = 0; pos0 < 180; pos0 += 20)  // This starts a counter for pos0 at zero and increases to 180 in one degree steps 
    {                                     // this will sweep the first servo out from 0 to 180
      myServo0.write(pos0);               // this sets Servo0 to pos0
      delay(15);                          // this waits 15ms for the servo to reach the pos0
      SoftwareServo::refresh();           // this refreshes the servos location
    } 
    digitalWrite(ledPin2, HIGH);          // This turns the first led on
    for(pos1 = 0; pos1 < 180; pos1 += 2)  // This sets up the same sweep for Servo1 after the first servo finishes
    {                                  
      myServo1.write(pos1);              
      delay(15);                       
      SoftwareServo::refresh();  
    }
    digitalWrite(ledPin3, HIGH);          // This turns the second led on
    for(pos0 = 180; pos0 >= 1; pos0 -= 20) // this runs a counter back to zero to sweep the first servo back
    {                                
      myServo0.write(pos0);              
      delay(15);                       
      SoftwareServo::refresh();
    }
     digitalWrite(ledPin2, LOW);          // This turns the first led off
    for(pos1 = 180; pos1 >= 1; pos1 -= 2) // this runs a counter back to zero to sweep the second servo back
    {                                
      myServo1.write(pos1);              
      delay(15);                       
      SoftwareServo::refresh();
    }
     digitalWrite(ledPin3, LOW);         // This turns the second led off
  }
      else if (buttonState == HIGH && flag == 2) //This does Servo0 slow and Servo1 fast
  {
    for(pos0 = 0; pos0 < 180; pos0 += 2)  // This starts a counter for pos0 at zero and increases to 180 in one degree steps 
    {                                     // this will sweep the first servo out from 0 to 180
      myServo0.write(pos0);               // this sets Servo0 to pos0
      delay(15);                          // this waits 15ms for the servo to reach the pos0
      SoftwareServo::refresh();           // this refreshes the servos location
    } 
    digitalWrite(ledPin2, HIGH);          // This turns the first led on
    for(pos1 = 0; pos1 < 180; pos1 += 20)  // This sets up the same sweep for Servo1 after the first servo finishes
    {                                  
      myServo1.write(pos1);              
      delay(15);                       
      SoftwareServo::refresh();  
    }
    digitalWrite(ledPin3, HIGH);          // This turns the second led on
    for(pos0 = 180; pos0 >= 1; pos0 -= 2) // this runs a counter back to zero to sweep the first servo back
    {                                
      myServo0.write(pos0);              
      delay(15);                       
      SoftwareServo::refresh();
    }
     digitalWrite(ledPin2, LOW);          // This turns the first led off
    for(pos1 = 180; pos1 >= 1; pos1 -= 20)// this runs a counter back to zero to sweep the second servo back
    {                                
      myServo1.write(pos1);              
      delay(15);                       
      SoftwareServo::refresh();
    }
     digitalWrite(ledPin3, LOW);         // This turns the second led off
  }

      else if (buttonState == LOW && flag == 0) {flag=1; delay(1000);} // detect button press and change flag
      else if (buttonState == LOW && flag == 1) {flag=2; delay(1000);} // detect button press and change flag
      else if (buttonState == LOW && flag == 2) {flag=0; delay(1000);} // detect button press and change flag
}

