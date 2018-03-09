// This program is designed to test if a remote is working
const int ledPin = 7;
const int irrecPin = 8; // IR Receiver Pin

void setup()
{
  pinMode(ledPin, OUTPUT); 
  pinMode(irrecPin, INPUT); 
}


void loop()
{

  int irstate;

  irstate = digitalRead(irrecPin);
  
  if( irstate == LOW)
  {
  digitalWrite(7, HIGH);   // Turn on the LED
  }

  else 
  {
  digitalWrite(7, LOW);    // Turn off the LED
  }
  
  delay(1);              // Wait for one second


}

