#include <Servo.h>
Servo servo; 
int const potPin = A0;
int potVal;
int angle; 

void setup() {
  servo.attach(9); //Servo is on Pin 9 
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin); //Read the potentiometer value
  Serial.print("potVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179); //The potentiometer values range from 0 to 1023 while the servo can only turn 0-180 degrees
  Serial.print(", angle: ");
  Serial.println(angle);
  servo.write(angle); //Write the new angle value to the servo
  delay(15); //Add delay so the servo has time to turn
}
