const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2; 
int redVal = 0;
int greenVal = 0;
int blueVal = 0;
int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;
void setup() {
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  redSensorVal = analogRead(redSensorPin);
  delay(5);
  greenSensorVal = analogRead(greenSensorPin);
  delay(5);
  blueSensorVal = analogRead(blueSensorPin); 

  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(redSensorVal);
  Serial.print("\t green: ");
  Serial.print(greenSensorVal);
  Serial.print("\t blue: ");
  Serial.print(blueSensorVal);

  redVal = redSensorVal/4;
  greenVal = greenSensorVal/4;
  blueVal = blueSensorVal/4;

  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(redVal);
  Serial.print("\t green: ");
  Serial.print(greenVal);
  Serial.print("\t blue: ");
  Serial.print(blueVal);

  analogWrite(redLEDPin, redVal);
  analogWrite(greenLEDPin, greenVal);
  analogWrite(blueLEDPin, blueVal);
}
