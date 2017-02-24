void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    String message = Serial.readStringUntil('&');
    
    String decoded;
    //Write code to decode the message and store it in the string 'decoded'
    Serial.println(decoded);
    
  }
}
