#include <SoftwareServo.h> //This brings in a library that allows us to control our servo

//Now we can create something called an "object" to control our servo and name it according to the pin it will use
SoftwareServo myServo0;


//Next we will rename some pins for a button and some leds
//There are 5 pins on the ATTinys we are using that we can use for the button, servos, and LEDs
//The button will be on digital pin four and we are naming that pin the buttonPin 
//The LED(s) will be on digital pins one, two, and three and we are naming those pins so they are easy to track 

//const means that these won't change (they are not variables)
//int means that they have integer values
const int buttonPin = 4; //Our PCBs have a space drilled to fit a button on pin 4
const int ledPin1 = 1;
const int ledPin2 = 2;
const int ledPin3 = 3;          

// Now let's create a variable for the button press and a variable for the current movement and light pattern
int buttonState = 0;
int flag = 0; 

// I also need a variable for the position of the servo since the pulses to the servos are too short for abrupt changes.
int pos0;

void setup() //This is the one time set up code for the ATTiny (The code above was housekeeping for the setup and loop code)
{
  //attach the servo object to digital pins 0 and 1
  myServo0.attach(0);


  //setup the led pins as output and the buttonPin as an input
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() // This is the code that will run in a continuous loop on the ATTiny
{
  //This bit of code reads whether the button is pressed or not
  buttonState = digitalRead(buttonPin);

  //If button is currently pressed, then ....
  if (buttonState == HIGH && flag == 0) //This does fast servo, ledss go on after servo sweeps up and off after servo sweeps down
  {
    for(pos0 = 0; pos0 < 180; pos0 += 15) // Start the servo at position 0, and until it gets to 180, go up by 15 each time through
    {
      myServo0.write(pos0);              // this sets Servo0 to pos0
      delay(15);                         // this waits 15ms for the servo to reach the pos0
      SoftwareServo::refresh();          // this refreshes the servos location
    }
    digitalWrite(ledPin1, HIGH);           // This turns the first led on
    digitalWrite(ledPin2, HIGH);           // This turns the second led on
    digitalWrite(ledPin3, HIGH);           // This turns the third led on
    for(pos0 = 180; pos0 >= 0; pos0 -= 15) // start at position 180, and until it gets to position 0, go down by 15 each time through
    {
      myServo0.write(0);              
      delay(15);                       
      SoftwareServo::refresh();
    }
    digitalWrite(ledPin1, LOW);          // This turns the first led off
    digitalWrite(ledPin2, LOW);          // This turns the second led off
    digitalWrite(ledPin3, LOW);          // This turns the third led off
  }
    else if (buttonState == HIGH && flag == 1) //This does slow servo with leds 1 and 3 alternating with led 2 on servo sweeps
  {
    for(pos0 = 0; pos0 < 180; pos0 += 2)  // This starts a counter for pos0 at zero and increases to 180 in one degree steps 
    {                                     // this will sweep the first servo out from 0 to 180
      myServo0.write(pos0);               // this sets Servo0 to pos0
      delay(15);                          // this waits 15ms for the servo to reach the pos0
      SoftwareServo::refresh();           // this refreshes the servos location
    } 
    digitalWrite(ledPin1, HIGH);          // This turns the first led on
    digitalWrite(ledPin2, LOW);           // This turns the second led off
    digitalWrite(ledPin3, HIGH);          // This turns the third led on
    for(pos0 = 180; pos0 >= 0; pos0 -= 2) // this runs a counter back to zero to sweep the servo back
    {                                
      myServo0.write(pos0);              
      delay(15);                       
      SoftwareServo::refresh();
    }
     digitalWrite(ledPin1, LOW);         // This turns the first led off
     digitalWrite(ledPin2, HIGH);        // This turns the second led on
     digitalWrite(ledPin3, LOW);         // This turns the second led off
  }
      else if (buttonState == HIGH && flag == 2) //This sweeps out fast and back slow with led flashes.
  {
    for(pos0 = 0; pos0 < 180; pos0 += 20)  // This starts a counter for pos0 at zero and increases to 180 in one degree steps 
    {                                     // this will sweep the first servo out from 0 to 180
      myServo0.write(pos0);               // this sets Servo0 to pos0
      delay(15);                          // this waits 15ms for the servo to reach the pos0
      SoftwareServo::refresh();           // this refreshes the servos location
    } 
    digitalWrite(ledPin1, LOW);           // This turns the first led off
    digitalWrite(ledPin2, HIGH);          // This turns the second led on
    digitalWrite(ledPin3, LOW);           // This turns the third led off
    delay(100);
    digitalWrite(ledPin1, HIGH);          // This turns the first led on
    digitalWrite(ledPin2, LOW);           // This turns the second led off
    digitalWrite(ledPin3, HIGH);          // This turns the third led on
    for(pos0 = 180; pos0 >= 0; pos0 -= 2) // this runs a counter back to zero to sweep the servo back
    {                                
      myServo0.write(pos0);              
      delay(15);                       
      SoftwareServo::refresh();
    }
    digitalWrite(ledPin1, LOW);           // This turns the first led off
    digitalWrite(ledPin2, HIGH);          // This turns the second led on
    digitalWrite(ledPin3, LOW);           // This turns the third led off
    delay(100);
    digitalWrite(ledPin1, HIGH);          // This turns the first led on
    digitalWrite(ledPin2, LOW);           // This turns the second led off
    digitalWrite(ledPin3, HIGH);          // This turns the third led on
  }

      else if (buttonState == LOW && flag == 0) {flag=1; delay(1000);} // detect button press and change flag
      else if (buttonState == LOW && flag == 1) {flag=2; delay(1000);} // detect button press and change flag
      else if (buttonState == LOW && flag == 2) {flag=0; delay(1000);} // detect button press and change flag
}
