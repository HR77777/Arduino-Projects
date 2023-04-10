int switchState = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2); //We want to read the input from the switch 
  //Pin 3 is the green LED, Pins 4 and 5 are red LEDs
  if (switchState == HIGH) { //If the switch is pressed, flicker the red LEDs
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(500); 
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(500);
  } 
  else { //Green LED on, Red LEDs off 
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
}
