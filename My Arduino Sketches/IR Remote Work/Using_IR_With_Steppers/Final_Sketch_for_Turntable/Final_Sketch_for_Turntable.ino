//----------Initialize Libraries-------//
#include <IRremote.h>
#include <Stepper.h>

//------------Declare Constants-------//
int RECV_PIN= 2 ; // set pin 2 as the IR receiver pin
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
myStepper.setSpeed(300); // set the speed at 
        // 40 rpm - 40 seems to be upper limit without 
        // 12V power supply, 230-235 with 12 V
pinMode(enA, OUTPUT); //sets up output for Stepper coil A 
pinMode(enB, OUTPUT); //sets up output for Stepper coil A 
Serial.begin(9600); // not sure what this is here for, but it 
                    // lets you hold a button down for repeat 
                    // usage without trigger default case.
irrecv.enableIRIn(); //turns on the IR receiver
}

void loop() 
{
if (irrecv.decode(&results)) //have we received an IR signal?
  {
    translateIR(); // runs the 'translateIR' 
                   // function, which turns the signal
                   // into a HEX string
    irrecv.resume(); // receives the next IR value
  }
} //--------(ends the main loop)---------//

void translateIR() // takes action based on IR received
{
  switch(results.value)
  {

    case 0x8D2A4BAF: //switch 5 output
      digitalWrite (enA, HIGH); // sends power to motor
      digitalWrite (enB, HIGH); // ^ 
      myStepper.step(stepsPerRevolution*15); 
                          //turns motor 5 revs clockwise
      digitalWrite (enA, LOW); // turns motor off
      digitalWrite (enB, LOW); // turns motor off
      delay(1);
      break;

    case 0x1C22DE05: //switch 6 ouput
      digitalWrite (enA, HIGH); // sends power to motor
      digitalWrite (enB, HIGH); // ^ 
      myStepper.step(-stepsPerRevolution*15); 
                          // turns motor 5 revs 
                          // counter-clockwise
      digitalWrite (enA, LOW); // turns motor off
      digitalWrite (enB, LOW); // turns motor off
      delay(1);
      break;

    case 0x11B08F7: // '+' button on XB1Rem (XBox One Remote)
      digitalWrite (enA, HIGH); // sends power to motor
      digitalWrite (enB, HIGH); // ^ 
      myStepper.step(stepsPerRevolution*15); 
                          //turns motor 5 revs clockwise
      digitalWrite (enA, LOW); // turns motor off
      digitalWrite (enB, LOW); // turns motor off
      delay(1);
      break;

    case 0x11B8877: // '-' button on XB1Rem
      digitalWrite (enA, HIGH); // sends power to motor
      digitalWrite (enB, HIGH); // ^ 
      myStepper.step(-stepsPerRevolution*15); 
                          //turns motor 5 revs clockwise
      digitalWrite (enA, LOW); // turns motor off
      digitalWrite (enB, LOW); // turns motor off
      delay(1);
      break;

     default:
 
      break;

 
  
  }
  delay(1);
}
