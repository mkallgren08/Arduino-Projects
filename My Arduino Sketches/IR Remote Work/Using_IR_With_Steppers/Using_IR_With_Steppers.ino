#include <Stepper.h>
#include <IRremote.h>
int RECV_PIN= 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

byte byteread = 0; //Variable used to store the byte received on the Serial Port

int enA  = 3;  // Enable pin 1 on Motor Control Shield   
int enB  = 11;  // Enable pin 2 on Motor Control Shield   
int dirA = 12;  // Direction pin dirA on Motor Control Shield
int dirB = 13;  // Direction pin dirB on Motor Control Shield

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
    valA = digitalRead(BUTTONA); //sets reading the state of the BUTTON A as 
                             // first step of program

                             
    if (valA==LOW) { 
      // this checks if button A is pressed and causes
      // program to run
                                             
    // Step five revolutions into one direction after enabling power to motors
    digitalWrite (enA, HIGH);
    digitalWrite (enB, HIGH);  
    myStepper.step(stepsPerRevolution*5);
    digitalWrite (enA, LOW);
    digitalWrite (enB, LOW);
    delay(1);
    }

    else { valB = digitalRead(BUTTONB); 

      if (valB==LOW) {
        // Step five revolutions in the other direction:
      digitalWrite (enA, HIGH);
      digitalWrite (enB, HIGH);
      myStepper.step(-stepsPerRevolution*5);
      digitalWrite (enA, LOW);
      digitalWrite (enB, LOW);
      delay(1);
    }
    
    else { 
      if (irrecv.decode(&results)) {

     
      digitalWrite (enA, HIGH);
      digitalWrite (enB, HIGH);  
      myStepper.step(stepsPerRevolution*5);
      digitalWrite (enA, LOW);
      digitalWrite (enB, LOW);
      delay(1);
    }
    
    
    else { delay(1);
     //checks if button is not pushed, and if it is not
     //the motor will not turn
    }
}
}
}
