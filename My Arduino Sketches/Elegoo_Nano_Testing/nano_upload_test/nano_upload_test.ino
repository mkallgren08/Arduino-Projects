#include <IRremote.h>

//------------Declare Constants-------//
int RECV_PIN= 2; // set pin 2 as the IR receiver pin
int LED1 = 8; // set pin 8 as red LED
int LED2 = 9; // set pin 9 as green LED
int LED3 = 10; // set pin 10 as blue LED

//------------Declare Objects--------//




void setup() 
{
irrecv.enableIRIn(); // starts the IR receiver
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
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
    case 0x962814CA:
      
     digitalWrite(8, HIGH);   // Turn on the LED
     delay(1000);              // Wait for one second
     digitalWrite(8, LOW);    // Turn off the LED
     delay(1000);              // Wait for one second
     break;

    case 0xB2CC429A:
      digitalWrite(9, HIGH);   // Turn on the LED
      delay(1000);              // Wait for one second
      digitalWrite(9, LOW);    // Turn off the LED
      delay(1000);              // Wait for one second
      break;

    case 0x5990708A:
      digitalWrite(10, HIGH);   // Turn on the LED
      delay(1000);              // Wait for one second
      digitalWrite(10, LOW);    // Turn off the LED
      delay(1000);              // Wait for one second
      break;
  
  }
  delay(250);
}

