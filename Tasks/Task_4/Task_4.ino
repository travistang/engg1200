void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    //Uncomment and complete the line below by using the "Serial.readStringUntil" command
    String message = Serial.readStringUntil('&');

    //Uncomment the line below to print the message to the Serial Monitor
    String msg = "";
    for(int i = 0; i < message.length(); i+=5)
    {
      msg +=message[i];
    }
    Serial.println(msg);
  }
}
