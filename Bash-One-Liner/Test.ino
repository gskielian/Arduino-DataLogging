int x=0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
    Serial.println(x++);
    delay(10);
}

//we can recover the date later with `date -r unixtime` e.g. `date -r 1390045244`
