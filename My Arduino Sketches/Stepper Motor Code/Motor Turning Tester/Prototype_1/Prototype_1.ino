/* 
 Stepper Motor Control with Arduino Motor Control Shield V3.0.

 This program drives a bipolar stepper motor. The motor is controlled
 by Arduino pins 10, 11, 12, 13.

 The motor should do five revolutions into one and five into another direction.

 Using this sketch for longer is not recommended because it will keep the motor under current
 and can cause it to become quite hot.

 */

#include <Stepper.h>

int enA  = 3;  // Enable pin 1 on Motor Control Shield   
int enB  = 11;  // Enable pin 2 on Motor Control Shield   
int dirA = 12;  // Direction pin dirA on Motor Control Shield
int dirB = 13;  // Direction pin dirB on Motor Control Shield

const int BUTTON = 7; // sets pin 7 as BUTTON input pin, green wire

int val = 0; // value will be used to store state of the pin on Button B


const int stepsPerRevolution = 200;  // Change this to fit the number of steps per revolution
                                     // for your motor

// Initialize the stepper library on pins 12 and 13:
Stepper myStepper(stepsPerRevolution, dirA, dirB);            


void setup() {
  // set the speed at 40 rpm - 40 seems to be upper limit without 12V power supply, 230-235 with 12 V
  myStepper.setSpeed(80);

  // Enable power to the motor
  pinMode(enA, OUTPUT);
 

  pinMode(enB, OUTPUT);
 
}

void loop() {
    val = digitalRead(BUTTON); //sets reading the state of the BUTTON A as 
                             // first step of program

                             
    if (val==LOW) { 
      // this checks if button A is pressed and causes
      // program to run
                                             
    // Step five revolutions into one direction after enabling power to motors
    digitalWrite (enA, HIGH);
    digitalWrite (enB, HIGH);  
    myStepper.step(stepsPerRevolution*5);
    digitalWrite (enA, LOW);
    digitalWrite (enB, LOW);
    delay(5);
    }

    
    else { delay(5);
     //checks if button is not pushed, and if it is not
     //the motor will not turn
    }
}
