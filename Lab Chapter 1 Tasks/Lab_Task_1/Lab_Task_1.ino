void setup() {
  // put your setup code here, to run once:
  
  //Set Pin 13 as an Output Pin
  //Insert Code Here
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Turn ON LED for 1 second
  //Insert Code Here
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);     

  //Turn OFF LED for 1 second
  //Insert Code Here
  digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(100);     
}
