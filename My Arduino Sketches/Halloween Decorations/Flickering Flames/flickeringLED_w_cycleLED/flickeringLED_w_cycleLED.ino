class CycleRGB
{
	// Class Member Variables
	// These are initialized at startup
	int rPin;      // the number of the red LED pin
  int gPin;      // the number of the green LED pin
  int bPin;      // the number of the blue LED pin
  long intervalTime; // the delay between updates (controls the speed of the cycle)

	// These maintain the current state
	int r; // r used to set the redLED value
  int g; // g used to set the greenLED value
  int b; // b used to set the blueLED value
  unsigned long previousMillis;    // will store last time LED was updated

  String rDir; // sets the direction of the Red LED
  String gDir; // sets the direction of the Green LED
  String bDir; // sets the direction of the Blue LED
  String overallDir; // sets the overall direction of the cycle
  

  // Constructor - creates a CycleRGB 
  // and initializes the member variables and state
  public:
  CycleRGB(int pin1, int pin2, int pin3, long interval)
  {
	rPin = pin1; 
	gPin = pin2; 
	bPin = pin3;
	pinMode(rPin, OUTPUT); 
	pinMode(gPin, OUTPUT); 
	pinMode(bPin, OUTPUT);      

  intervalTime = interval;
  
  r = 127;
  g = 255;
  b = 0;

  rDir = "increase";
  gDir = "hold";
  bDir = "hold";
  overallDir = "forward";
  previousMillis = 0;
  
  }

  void Update(unsigned long currentMillis)
  {
    if (currentMillis - previousMillis >= intervalTime){
      if (r ==  180 && g ==  255 && b== 0 && overallDir ==  "forward"){
        rDir = "decrease"; gDir = "hold"; bDir = "hold";
        } else if (r== 0 && g ==  255 && b ==  0  && overallDir ==  "forward"){
          rDir = "hold"; gDir = "hold"; bDir = "increase";
        } else if (r== 0 && g ==  255 && b ==  255  && overallDir ==  "forward"){
          rDir = "hold"; gDir = "decrease"; bDir = "hold";
        } else if (r== 0 && g== 0 && b== 255  && overallDir ==  "forward"){
          rDir = "increase"; gDir = "hold"; bDir = "hold";
        } else if (r ==  220 && g ==  0 && b== 255  && overallDir ==  "forward"){
          rDir = "decrease"; gDir = "hold"; bDir = "hold"; overallDir = "back";
        } else if (r ==  0 && g ==  0 && b ==  255 && overallDir == "back"){
          rDir = "hold"; gDir = "increase"; bDir = "hold";
        } else if (r ==  0 && g ==  255 && b ==  255 && overallDir == "back"){
          rDir = "hold"; gDir = "hold"; bDir = "decrease";
        } else if (r ==  0 && g ==  255 && b ==  0 && overallDir == "back"){
          rDir = "increase"; gDir = "hold"; bDir = "hold";
        } else if (r == 179 && g == 255 && b == 0 && overallDir == "back"){
          overallDir = "forward";
      }
  
      if (rDir == "increase"){r += 1;} else if (rDir != "hold"){r -= 1;};
      if (gDir == "increase"){g += 1;} else if (gDir != "hold"){g -= 1;};
      if (bDir == "increase"){b += 1;} else if (bDir != "hold"){b -= 1;};
  
      analogWrite(rPin, r);
      analogWrite(gPin, g);
      analogWrite(bPin, b);       
     }
   }
 };

int ledPin1 = 10;
int ledPin2 = 9;
int ledPin3 = 11;
CycleRGB spookyLED(3,4,5,1000);
int counter = 0;

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
  counter += 1;
  
  if(counter%20 == 0){
    spookyLED.Update(currentTime);
  }
}

void loop()
{
  analogWrite(ledPin1, random(120) + 135);
  analogWrite(ledPin2, random(120) + 135);
  analogWrite(ledPin3, random(120) + 135);
  delay(random(100));
}
