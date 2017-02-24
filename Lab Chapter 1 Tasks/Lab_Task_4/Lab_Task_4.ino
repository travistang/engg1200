//Pin Mappings for PWM and direction pins for motors
const int motorId[6] = {5,3,9,6,11,10};
const int motorDir[6] = {A5,A4,A3,A2,A1,A0};

void setup() {
  // put your setup code here, to run once:
  motor_init();
}

void loop() {
  // put your main code here, to run repeatedly:

  //Making all motors spin for 2 seconds
  
  //Insert Your Code Here
  for(int i =0 ;i < 6; i++)
  {
    motor_control(i,100);
  }
  delay(2000);

  //Reversing direction for all motors for 2 seconds
  
  //Insert Your Code Here
  for(int i =0 ;i < 6; i++)
  {
    motor_control(i,-100);
  }
  delay(2000);

}


//Function to Initialize motor related pins
void motor_init(){
  for(int i=0; i<6; i++){
    pinMode(motorId[i],OUTPUT);
    pinMode(motorDir[i],OUTPUT);
  }
}

//Function for turning on motors
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

