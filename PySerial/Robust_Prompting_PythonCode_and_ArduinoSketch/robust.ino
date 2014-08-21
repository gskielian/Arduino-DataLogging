char char_input;

void setup () {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
} 


void loop() {

  if (Serial.available() > 0) 
  {
      
      char_input = Serial.read();
      
      switch (char_input) {
      case '1':
        Serial.println(analogRead(A0)); // if '1' is received, then send back analog read A0
      break;
      case '2':
       digitalWrite(13,HIGH); // if '2' is received, turn on the led attached to 13
      break;
      case '3':
       digitalWrite(13,LOW); // if '3' is received then turn off the led attached 13
      break;
      default: 
        delay(10);
      break;
      }
  }

}
