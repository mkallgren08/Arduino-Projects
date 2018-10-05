#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>




//------------Declare Constants-------//
// int RECV_PIN= 2; // set pin 2 as the IR receiver pin
// int LED1 = 8; // set pin 8 as red LED
// int LED2 = 9; // set pin 9 as green LED
// int LED3 = 10; // set pin 10 as blue LED

int FAN_HI = 4; // set pin 4 as the fan's hi setting
int FAN_LOW = 5; // set pin 4 as the fan's low setting

//------------Declare Objects--------//




void setup() 
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}


void loop() 
{
  digitalWrite(5, HIGH); // Turn the fan on the LOW setting
  delay(5000);           // Keep the fan on for 5 seconds
  digitalWrite(5, LOW);  // Turn the fan off
  delay(5000);           // Keep the fan off for 5 seconds
  digitalWrite(4, HIGH); // Turn the fan on the HI setting
  delay(5000);           // Keep the fan on for 5 seconds
  digitalWrite(4, LOW);  // Turn the fan off
  delay(5000);           // Keep the fan off for 5 seconds
} //--------(ends the main loop)---------//

