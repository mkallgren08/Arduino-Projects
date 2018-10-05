/* 
 Stepper Motor Control with Arduino Motor Control Shield V3.0.

 This program drives a bipolar stepper motor. The motor is controlled
 by Arduino pins 10, 11, 12, 13.

 The motor should do five revolutions into one and five into another direction.

 Using this sketch for longer is not recommended because it will keep the motor under current
 and can cause it to become quite hot.

 */

#include <Stepper.h> // loads stepper control library
#include <IRremote.h> // loads IRemote library
int RECV_PIN= 2; // sets pin 2 as the IR receiver
IRrecv irrecv(RECV_PIN); 
decode_results results;

byte byteread = 0; //Variable used to store the byte received on the Serial Port

int enA  = 3;  // Enable pin 1 on Motor Control Shield   
int enB  = 11;  // Enable pin 2 on Motor Control Shield   
int dirA = 12;  // Direction pin dirA on Motor Control Shield
int dirB = 13;  // Direction pin dirB on Motor Control Shield

const int BUTTONA = 4; // sets pin 4 as BUTTON input pin, green wire

const int BUTTONB = 7; // sets pin 7 as BUTTON input pin, yellow wire

int valA = 0; // value will be used to store state of the pin on Button A

int valB = 0; // value will be used to store state of the pin on Button B


const int stepsPerRevolution = 200;  // Change this to fit the number of steps per revolution
                                     // for your motor

// Initialize the stepper library on pins 12 and 13:
Stepper myStepper(stepsPerRevolution, dirA, dirB);            


void setup() {
  // set the speed at 40 rpm - 40 seems to be upper limit without 12V power supply, 230-235 with 12 V
  myStepper.setSpeed(200);

  // Enable power to the motor
  pinMode(enA, OUTPUT);
 

  pinMode(enB, OUTPUT);

  Serial.begin(9600);

  irrecv.enableIRIn(); //turns on the IR receiver
 
}

void loop() {
    
}
}
}
