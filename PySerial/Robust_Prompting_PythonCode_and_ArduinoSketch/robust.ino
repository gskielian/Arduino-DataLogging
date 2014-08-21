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
          // if '1' is received, then send back analog read A0
          Serial.println(analogRead(A0)); 
          break;
        
        case '2': 
          // if '2' is received, turn on the led attached to 13
          digitalWrite(13,HIGH); 
          break;
        
        case '3':
          // if '3' is received then turn off the led attached 13
          digitalWrite(13,LOW); 
          break;
          
        default: 
          delay(10);
          break;
      }
  }

}
