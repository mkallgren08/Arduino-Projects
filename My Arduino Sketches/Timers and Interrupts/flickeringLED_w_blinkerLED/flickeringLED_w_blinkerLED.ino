class Blinker
{
	// Class Member Variables
	// These are initialized at startup
	int ledPin;      // the number of the LED pin
	long OnTime;     // milliseconds of on-time
	long OffTime;    // milliseconds of off-time

	// These maintain the current state
	int ledState;             		// ledState used to set the LED
	unsigned long previousMillis;  	// will store last time LED was updated

  // Constructor - creates a Blinker 
  // and initializes the member variables and state
  public:
  Blinker(int pin, long on, long off)
  {
	ledPin = pin;
	pinMode(ledPin, OUTPUT);     
	
  //NOTE: this is NOT a type. In the original sketch I found on learn.adafruit
  // the code was:
  // OnTime = on;
	// OffTime = off;
  // But that flipped the observed effects, i.e. if on =500 and off = 1000
  // the LED would turn off for 500ms and stary on for 1000ms. So I flipped
  // how the parameters updated the variables in the code below so you don't 
  // have to flip the times around in your head as you're programming new 
  // Blinkers.
  
	OnTime = off;
	OffTime = on;
	
	ledState = LOW; 
	previousMillis = 0;
  }

  void Update(unsigned long currentMillis)
  {
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
    	ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);	  // Update the actual LED
    }
  }
};

int ledPin1 = 10;
int ledPin2 = 9;
int ledPin3 = 11;
Blinker blinkLED(2,2000, 1000);

void setup()
{
  // Timer0 is already used for millis() - we'll just interrupt somewhere
  // in the middle and call the "Compare A" function below
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

// Interrupt is called once a millisecond, looks for any new GPS data, and stores it
SIGNAL(TIMER0_COMPA_vect)
{
  unsigned long currentTime = millis(); // grabs the current time from the system
                                        // clock(in milliseconds)
  blinkLED.Update(currentTime);
}

void loop()
{
  analogWrite(ledPin1, random(120) + 135);
  analogWrite(ledPin2, random(120) + 135);
  analogWrite(ledPin3, random(120) + 135);
  delay(random(100));
}
