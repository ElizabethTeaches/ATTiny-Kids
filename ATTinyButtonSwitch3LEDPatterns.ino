const int buttonPin = 4;          

//Variables
int buttonState = 0;
int flag=0;


void setup()
{
  //The 8-pin ATTinys (25/45/85) all have 5 usable digital output pins 0-4
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}
void loop()

{
  //Read button state (pressed or not pressed?)
  buttonState = digitalRead(buttonPin);

  //If button pressed...
  if (buttonState == HIGH && flag == 0) // All on then off one by one mode
  
  {

  digitalWrite(0, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  digitalWrite(1, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  digitalWrite(2, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  digitalWrite(3, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  delay(500);   // Wait for a half a second

  digitalWrite(0, LOW);   // Set the LED pins to LOW. This turns it off
  delay(200);    // Wait for a half second
  digitalWrite(1, LOW);   // Set the LED pins to LOW. This turns it off
  delay(200);    // Wait for a half second
  digitalWrite(2, LOW);   // Set the LED pins to LOW. This turns it off
  delay(200);    // Wait for a half second
  digitalWrite(3, LOW);   // Set the LED pins to LOW. This turns it off
  delay(200);    // Wait for a half second

   }

   else if (buttonState == HIGH && flag == 1)   //  Rapid blink mode
   {
  digitalWrite(0, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  digitalWrite(1, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  digitalWrite(2, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  digitalWrite(3, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  delay(200);   // Wait for a one fifth of a second

  digitalWrite(0, LOW);   // Set the LED pins to LOW. This turns it off
  digitalWrite(1, LOW);   // Set the LED pins to LOW. This turns it off
  digitalWrite(2, LOW);   // Set the LED pins to LOW. This turns it off
  digitalWrite(3, LOW);   // Set the LED pins to LOW. This turns it off
  delay(200);    // Wait for a one fifth of a second

    }
  
  else if (buttonState == HIGH && flag == 2)   //  Odds and Evens
   {
  digitalWrite(0, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  digitalWrite(1, LOW);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  digitalWrite(2, HIGH);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  digitalWrite(3, LOW);    //Set the LED pins to HIGH. This gives power to the LED and turns it on
  delay(400);   // Wait for a two fifths of a second

  digitalWrite(0, LOW);   // Set the LED pins to LOW. This turns it off
  digitalWrite(1, HIGH);   // Set the LED pins to LOW. This turns it off
  digitalWrite(2, LOW);   // Set the LED pins to LOW. This turns it off
  digitalWrite(3, HIGH);   // Set the LED pins to LOW. This turns it off
  delay(400);    // Wait for a two fifths of a second

    }

    else if (buttonState == LOW && flag == 0) {flag=1; delay(1000);} // detect button press and change flag
    else if (buttonState == LOW && flag == 1) {flag=2; delay(1000);} // detect button press and change flag
  else if (buttonState == LOW && flag == 2) {flag=0; delay(1000);} // detect button press and change flag
  }


