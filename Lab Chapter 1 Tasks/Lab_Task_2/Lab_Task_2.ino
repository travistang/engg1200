long count = 0;
int pin_no = 13;
void setup() {
  // put your setup code here, to run once:\

  //Set Pin 13 as Output Pin
  pinMode(pin_no,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //The code below loops while ON time is less than 4 seconds
  while(millis()  < 4000)
  {
    digitalWrite(pin_no,HIGH);
    delay(19);
    digitalWrite(pin_no,LOW);
    delay(1);
  }

  //The code below loops while ON time is less than 8 seconds
  while (millis() < 8000)
  {
    digitalWrite(pin_no,HIGH);
    delay(10);
    digitalWrite(pin_no,LOW);
    delay(10);
  }

  //The code below loops while ON time is less than 12 seconds
  while(millis()<12000){
    //Insert Code Here
    digitalWrite(pin_no,HIGH);
    delay(1);
    digitalWrite(pin_no,LOW);
    delay(19);
  }
}

