char ch;

void setup () {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
} 


void loop() {

  if (Serial.available()) 
  {

     ch = Serial.read();

     if ( ch == '1' ) { 
       Serial.println(analogRead(A0)); // if '1' is received, then send back analog read A0
     } 
     else if (ch == '2') {    
       digitalWrite(13,HIGH); // if '2' is received, turn on the led attached to 13
     } 
     else if (ch == '3') {
       digitalWrite(13,LOW); // if '3' is received then turn off the led attached 13
     } else {
       delay(10);
     }

  }

}
