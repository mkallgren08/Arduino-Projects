#include <IRremote.h>

//------------Declare Constants-------//
int RECV_PIN= 2 ; // set pin 2 as the IR receiver pin
int LED1 = 8 ; // set pin 8 as red LED
int LED2 = 9 ; // set pin 9 as green LED
int LED3 = 10 ; // set pin 10 as blue LED
int LED4 = 7 ; // set pin 7 as orange LED
const int Buzzerpin = 3 ; // set pin 6 as piezo buzzer
unsigned int frequency = 100 ; // sets buzzer to 440 Hz

//------------Declare Objects--------//

IRrecv irrecv(RECV_PIN); // creates instance of 'irrecv'
decode_results results;  // create instance of 'decode_results'




void setup() 
{
irrecv.enableIRIn(); // starts the IR receiver
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 pinMode(LED4, OUTPUT);
 pinMode(Buzzerpin, OUTPUT);
}

void loop() 
{
if (irrecv.decode(&results)) //have we received an IR signal?
  {
    translateIR(); // runs the 'translateIR' 
                   // function, defined below
    irrecv.resume(); // receives the next IR value
  }
} //--------(ends the main loop)---------//

void translateIR() // takes action based on IR received
{
  switch(results.value)
  {
    case 0x962814CA: // switch 1 input
      
     digitalWrite(LED1, HIGH);   // Turn on the red LED
     delay(1000);              // Wait for one second
     digitalWrite(LED1, LOW);    // Turn off the LED
     delay(1000);              // Wait for one second
     break;

    case 0xB2CC429A: //switch 2 input
      digitalWrite(LED2, HIGH);   // Turn on the green LED
      delay(1000);              // Wait for one second
      digitalWrite(LED2, LOW);    // Turn off the LED
      delay(1000);              // Wait for one second
      break;

    case 0x5990708A: //switch 3 input
      digitalWrite(LED3, HIGH);   // Turn on the blue LED
      delay(1000);              // Wait for one second
      digitalWrite(LED3, LOW);    // Turn off the LED
      delay(1000);              // Wait for one second
      break;

     default:
      digitalWrite(LED4, HIGH);
      delay (1000);
      digitalWrite(LED4, LOW);
      delay (1000);
      break;

 
  
  }
  delay(250);
}

