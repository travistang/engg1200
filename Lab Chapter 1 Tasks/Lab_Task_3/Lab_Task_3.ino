void setup() {
  // put your setup code here, to run once:
  /*Setting required pins as output.
   * Pin 5 is the PWM pin,
   * Pin A5 is the direction pin.*/
  pinMode(5,OUTPUT);
  pinMode(A5,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Set Direction with Pin A5
  
  //Set PWM with Pin 5
  analogWrite(5,200);
  digitalWrite(A5,HIGH);
}
