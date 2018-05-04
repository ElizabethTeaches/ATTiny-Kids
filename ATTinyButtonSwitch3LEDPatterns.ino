
//There are 5 pins on the ATTinys we are using that we can use for the button and LEDS numbered 0-4
//The button will be on pin four and we are naming that pin the buttonPin
const int buttonPin = 4;          

// Create a variable for the button press and for the current led pattern
int buttonState = 0;
int flag=0;


void setup()
{
  //We are using the remaining four pins 0-3 for the LEDs and are not renaming them
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}
void loop()

{
  //This bit of code reads whether the button is pressed or not
  buttonState = digitalRead(buttonPin);

  //If button is currently pressed, then ....
  if (buttonState == HIGH && flag == 0) // All LEDs on then off one by one - mode 0
  
  {

  digitalWrite(0, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(1, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(2, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(3, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  delay(500);   // Wait for a half a second

  digitalWrite(0, LOW);   // Set the LED pin to LOW. This turns it off
  delay(200);    // Wait for a half second
  digitalWrite(1, LOW);   // Set the LED pin to LOW. This turns it off
  delay(200);    // Wait for a half second
  digitalWrite(2, LOW);   // Set the LED pin to LOW. This turns it off
  delay(200);    // Wait for a half second
  digitalWrite(3, LOW);   // Set the LED pin to LOW. This turns it off
  delay(200);    // Wait for a half second

   }

   else if (buttonState == HIGH && flag == 1)   //  Rapid blink - mode 1
   {
  digitalWrite(0, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(1, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(2, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(3, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  delay(200);   // Wait for a one fifth of a second

  digitalWrite(0, LOW);   // Set the LED pin to LOW. This turns it off
  digitalWrite(1, LOW);   // Set the LED pin to LOW. This turns it off
  digitalWrite(2, LOW);   // Set the LED pin to LOW. This turns it off
  digitalWrite(3, LOW);   // Set the LED pin to LOW. This turns it off
  delay(200);    // Wait for a one fifth of a second

    }
  
  else if (buttonState == HIGH && flag == 2)   //  Odds and Evens - mode 2
   {
  digitalWrite(0, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(1, LOW);    //Set the LED pin to LOW. This turns it off
  digitalWrite(2, HIGH);    //Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(3, LOW);    //Set the LED pin to LOW. This turns it off
  delay(400);   // Wait for a two fifths of a second

  digitalWrite(0, LOW);   // Set the LED pin to LOW. This turns it off
  digitalWrite(1, HIGH);   // Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(2, LOW);   // Set the LED pin to HIGH. This gives power to the LED and turns it on
  digitalWrite(3, HIGH);   // Set the LED pin to LOW. This turns it off
  delay(400);    // Wait for a two fifths of a second

    }

    else if (buttonState == LOW && flag == 0) {flag=1; delay(1000);} // detect button press and change flag
    else if (buttonState == LOW && flag == 1) {flag=2; delay(1000);} // detect button press and change flag
    else if (buttonState == LOW && flag == 2) {flag=0; delay(1000);} // detect button press and change flag
  }


