/*************************************************************
Motor Shield Stepper Demo
by Randy Sarafan

For more information see:
http://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/

*************************************************************/
/******
 Based on "Stepper__turn_in_one_direction"
 */

int delaylegnth = 30; //sets speed of rotation

const int BUTTON = 4; // sets pin 4 as BUTTON input pin

int val = 0; // value will be used to store state of the pin

void setup() {
  
  //establish motor direction toggle pins
  pinMode(12, OUTPUT); //CH A -- HIGH = forwards and LOW = backwards???
  pinMode(13, OUTPUT); //CH B -- HIGH = forwards and LOW = backwards???
  
  //establish motor brake pins
  pinMode(9, OUTPUT); //brake (disable) CH A
  pinMode(8, OUTPUT); //brake (disable) CH B

  // establish BUTTON as an input
  pinMode(BUTTON, INPUT);

}

void loop(){
  val = digitalRead(BUTTON); //sets reading the state of the BUTTON as 
                             // first step of program
  if (val==LOW) { // this checks if button is pressed and causes
                  // clockwise turn
 digitalWrite(9, HIGH);  //ENABLE CH A
  digitalWrite(8, LOW); //DISABLE CH B

  digitalWrite(12, HIGH);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A, full PWM (255 is max value)
  
  delay(delaylegnth);
  
  digitalWrite(9, LOW);  //DISABLE CH A
  digitalWrite(8, HIGH); //ENABLE CH B

  digitalWrite(13, LOW);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B
  
  delay(delaylegnth);
  
  digitalWrite(9, HIGH);  //ENABLE CH A
  digitalWrite(8, LOW); //DISABLE CH B

  digitalWrite(12, LOW);   //Sets direction of CH A
  analogWrite(3, 255);   //Moves CH A
  
  delay(delaylegnth);
    
  digitalWrite(9, LOW);  //DISABLE CH A
  digitalWrite(8, HIGH); //ENABLE CH B

  digitalWrite(13, HIGH);   //Sets direction of CH B
  analogWrite(11, 255);   //Moves CH B
  
  delay(delaylegnth); 
  } else { //checks if button is not pushed, and if it is not
           //switch to counterclockwise motion
 
 delay(500);}

}
