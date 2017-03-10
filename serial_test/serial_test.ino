const int motorId[6] = {5,3,9,6,11,10};
const int motorDir[6] = {A5,A4,A3,A2,A1,A0};

void motor_init(){
  for(int i=0; i<6; i++){
    pinMode(motorId[i],OUTPUT);
    pinMode(motorDir[i],OUTPUT);
  }
}
void motor_control(int motorindex, int motorspeed){
  if (motorindex > 0 && motorindex <= 6 && motorspeed >= 0 && motorspeed <= 255){
    analogWrite(motorId[motorindex-1], motorspeed);
    digitalWrite (motorDir[motorindex-1], 0);
  }
  else if (motorindex > 0 && motorindex <= 6 && motorspeed < 0 && motorspeed >= -255){
    analogWrite (motorId[motorindex-1], abs(motorspeed));
    digitalWrite (motorDir[motorindex-1], 1);
  }
}
void setup() {
  // put your setup code here, to run once:
  motor_init();
  // for display purpose
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    /***
     *  Command format:
     *    p1:r1:p2:r2:p3:r3&
     */
    String cmd = Serial.readStringUntil('&');
    
    int end = 0;
    int power = 0;
    for(int count = 0; count < 6; count++)
    {
      end = cmd.indexOf(':');
      String val = cmd.substring(0,end);
      cmd = cmd.substring(end + 1,cmd.length());
      Serial.println(val);
      
      if(count % 2 == 0)
      {
          power = val.toFloat();
      }else
      {
          power *= (val.equals("true")?1:-1);
          // motor index can be inferred from "count"
          motor_control(count/2 + 1,power);
          power = 0;
      }
    }
//    while((end = cmd.indexOf(':')) != -1)
//    {
//      String val = cmd.substring(0,end);
//      cmd = cmd.substring(end + 1,cmd.length());
//      Serial.println(cmd);
//      // numbers in odd indices contain motor power
//      if(count % 2 == 0)
//      {
//          power = val.toFloat();
//      }else
//      {
//          power *= (val.equals("true")?1:-1);
//          // motor index can be inferred from "count"
//          motor_control(count/2 + 1,power);
//          power = 0;
//      }
//      count++; 
//    }
  }
}
