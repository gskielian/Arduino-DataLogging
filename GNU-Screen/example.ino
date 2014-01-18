//some Arduino code to test out the GNU-Screen method
void setup() {
  Serial.begin(9600);
}


void loop() {
  Serial.println(analogRead(A0)); //it's okay to leave AO floating in this example, as it is just there to provide live data)
  delay(100);
}

