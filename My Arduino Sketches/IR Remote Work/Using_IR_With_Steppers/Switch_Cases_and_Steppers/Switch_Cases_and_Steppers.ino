//----------Initialize Libraries-------//
#include <IRremote.h>
#include <Stepper.h>

//------------Declare Constants-------//
int RECV_PIN= 2 ; // set pin 2 as the IR receiver pin
int LED1 = 8 ; // set pin 8 as red LED
int LED2 = 9 ; // set pin 9 as green LED
int LED3 = 10 ; // set pin 10 as blue LED
int LED4 = 7 ; // set pin 7 as orange LED
int enA  = 3;  // Enable pin 1 on Motor Control Shield   
int enB  = 11;  // Enable pin 2 on Motor Control Shield   
int dirA = 12;  // Direction pin dirA on Motor Control Shield
int dirB = 13;  // Direction pin dirB on Motor Control Shield
const int stepsPerRevolution = 200;  // Change this to fit the 
                                     // number of steps per 
                                     // revolution for your
             // motor (https://www.sparkfun.com/products/9238)

//------------Declare Objects--------//

IRrecv irrecv(RECV_PIN); // creates instance of 'irrecv'
decode_results results;  // create instance of 'decode_results'
Stepper myStepper(stepsPerRevolution, dirA, dirB); 
                        //creates instance of Stepper Motor




void setup() 
{
irrecv.enableIRIn(); // starts the IR receiver
myStepper.setSpeed(200); // set the speed at 
        // 40 rpm - 40 seems to be upper limit without 
        // 12V power supply, 230-235 with 12 V
pinMode(enA, OUTPUT); //sets up output for Stepper coil A 
pinMode(enB, OUTPUT); //sets up output for Stepper coil A 
Serial.begin(9600); // not sure what this is here for, but it 
                    // lets you hold a button down for repeat 
                    // usage without trigger default case.
irrecv.enableIRIn(); //turns on the IR receiver
pinMode(LED1, OUTPUT); // enables red LED Pin
pinMode(LED2, OUTPUT); // enables green LED Pin
pinMode(LED3, OUTPUT); // enables blue LED Pin
pinMode(LED4, OUTPUT); // enables orange LED Pin
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
     delay(1);              // Wait for one millisecond
     break;

    case 0xB2CC429A: //switch 2 input
      digitalWrite(LED2, HIGH);   // Turn on the green LED
      delay(1000);              // Wait for one second
      digitalWrite(LED2, LOW);    // Turn off the LED
      delay(1);              // Wait for one millisecond
      break;

    case 0x5990708A: //switch 3 input
      digitalWrite(LED3, HIGH);   // Turn on the blue LED
      delay(1000);              // Wait for one second
      digitalWrite(LED3, LOW);    // Turn off the LED
      delay(1);              // Wait for one millisecond
      break;

    case 0x8D2A4BAF: //switch 5 output
      digitalWrite (enA, HIGH); // sends power to motor
      digitalWrite (enB, HIGH); // ^ 
      myStepper.step(stepsPerRevolution*5); 
                          //turns motor 5 revs clockwise
      digitalWrite (enA, LOW); // turns motor off
      digitalWrite (enB, LOW); // turns motor off
      delay(1);
      break;

    case 0x1C22DE05: //switch 6 ouput
      digitalWrite (enA, HIGH); // sends power to motor
      digitalWrite (enB, HIGH); // ^ 
      myStepper.step(-stepsPerRevolution*5); 
                          // turns motor 5 revs 
                          // counter-clockwise
      digitalWrite (enA, LOW); // turns motor off
      digitalWrite (enB, LOW); // turns motor off
      delay(1);
      break;
   

     default:
      digitalWrite(LED4, HIGH); // Turn on LED
      delay (1000);  // wait one second
      digitalWrite(LED4, LOW); // Turn off the LED
      delay (1);     // Wait for one millisecond
      break;

 
  
  }
  delay(1);
}

