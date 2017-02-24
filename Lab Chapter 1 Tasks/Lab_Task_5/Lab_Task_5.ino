//Pin Mappings for PWM and direction pins for motors
const int motorId[6] = {5,3,9,6,11,10};
const int motorDir[6] = {A5,A4,A3,A2,A1,A0};

void setup() {
  // put your setup code here, to run once:
  motor_init();

  //Initialize Serial Communication
  //INSERT YOUR CODE HERE
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Check if data has arrived in serial port
  //Execute motor_contorl function according to data received
  if(Serial.available() > 0)
  {
      char c = Serial.read();
      Serial.println(c);
      switch(c)
      {
        case 'a':
        {
          motor_control(1,100);
          break;
        }
        case 'b':
        {
          motor_control(2,100);
          break;
        }
        case 'c':
        {
          motor_control(3,100);
          break;
        }
        case 'd':
        {
          motor_control(4,100);
          break;
        }

        case '1':
        {
          motor_control(1,-100);
          break;
        }
        
        case '2':
        {
          motor_control(2,-100);
          break;
        }
        
        case '3':
        {
          motor_control(3,-100);
          break;
        }
        
        case '4':
        {
          motor_control(4,-100);
          break;
        }

        case '0':
        {
          for(int i =1 ;i <= 6; i++)
          {
            motor_control(i,0);
          }
          break;
        }
        default:
          break;
      }
      
  }

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

