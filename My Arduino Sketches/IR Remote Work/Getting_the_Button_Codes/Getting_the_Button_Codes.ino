/* This sketch is used to find the HEX codes for a given button on any
 *  IR remote */



/* Useful IR receiver and decoding URL
 https://www.pjrc.com/teensy/td_libs_IRremote.html */


#include <IRremote.h> // includes remote library
int RECV_PIN= 11; //defines the IR input pin
IRrecv irrecv(RECV_PIN); //sets the IR receiver pin
decode_results results;

void setup() 
{
  Serial.begin(9600); /* sets the rate (in transmissions per 
                         second) for serial data transmission */
                        
  irrecv.enableIRIn(); // starts the IR receiver

}

void loop()
{
  if (irrecv.decode(&results)) /* Attempt to receive a IR code. Returns 
                                 true if a code was received, 
                                 or false if nothing received yet. When 
                                 a code is received, information is 
                                 stored into "results". */
                                 
  {Serial.println(results.value, HEX);/* This will print (in the serial
                                        monitor of the Arduino IDE) the 
                                        received IR signal, we have 
                                        defined the iutput type as HEX -
                                        which stands for hexadecimal */
  irrecv.resume(); // Receive the next value;
                   // needed to close the 'decode'
                   // loop.
  }

}
