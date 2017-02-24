//Pin Mappings for PWM and direction pins for motors
const int motorId[6] = {5,3,9,6,11,10};
const int motorDir[6] = {A5,A4,A3,A2,A1,A0};


void setup() {
  // put your setup code here, to run once:
  motor_init();
  //Setup Serial Communication
  Serial.begin(9600);
}

//Store time of last check signal received
int last_received_time = 0;

void loop() {
  // put your main code here, to run repeatedly:

  //Read receieved data and print to serial monitor under different interpretations
  if(Serial.available()>0){
    int data = Serial.read();
     
    //Using Receieved Data to Contorl Motors
    if(data >= 1 && data <= 6)
    {
      motor_control(data,100);
      last_received_time = millis()/1000;
    }
    if(data == 0)
    {
      stop_all_motors();
    }
    //If data received is Check Signal
//    else if(data == 44){
//      last_received_time = millis()/1000;
//      stop_all_motors();
//    }
    
  }
  //Check how long between current time and time of last check signal
  //If longer than 8 seconds, turn off all motors
  if(millis()/1000 - last_received_time >= 8)
  {
    stop_all_motors();
  }
}

void stop_all_motors()
{
      for(int i = 1; i <=6; i++)
      {
        motor_control(i,0);
      }
}
/*----------------------Motor Control Function: DO NOT ALTER-------------------*/

//Function to Initialize motor related pins as Outputs
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

