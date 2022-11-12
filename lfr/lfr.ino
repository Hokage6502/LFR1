#include <QTRSensors.h>
#define Kp 0.1 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd 4// experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define MaxSpeed 250
#define BaseSpeed 150 
#define speedturn 90
#define NUM_SENSORS  6     
#define rightMotor1 8
#define rightMotor2 9
#define rightMotorPWM 10
#define leftMotor1 7
#define leftMotor2 6
#define leftMotorPWM 5
#define IR_RIGHT A1
#define IR_LEFT A0
#define IR_TOP 4
#define buzzer 2

QTRSensors qtr;

const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];

void setup()
{
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount);
  qtr.setEmitterPin(13);
  
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  
  delay(2000);
  
  int i;
  for (int i = 0; i < 400; i++) 
  {
    qtr.calibrate();
  }
//  wait();
//  delay(2000); // wait for 2s to position the bot before entering the main loop 
}  

int lastError = 0;
unsigned int sensors[8];
int position = qtr.readLineWhite(sensors);
int rightMotorSpeed = 0;
int leftMotorSpeed = 0;

void loop()
{ 
    /*position = qtr.readLineWhite(sensors); 
    
    int error = position - 2500;
    int motorSpeed = Kp * error + Kd * (error - lastError);
    lastError = error;
  
    rightMotorSpeed = BaseSpeed + motorSpeed;
    leftMotorSpeed = BaseSpeed - motorSpeed;
    
    if (rightMotorSpeed > MaxSpeed ) rightMotorSpeed = MaxSpeed; 
    if (leftMotorSpeed > MaxSpeed ) leftMotorSpeed = MaxSpeed;
    if (rightMotorSpeed < 0)rightMotorSpeed = 0;    
    if (leftMotorSpeed < 0)leftMotorSpeed = 0;
      
    forward(leftMotor1,leftMotor2,rightMotor1,rightMotor2, rightMotorSpeed, leftMotorSpeed);*/
    forward(leftMotor1,leftMotor2,rightMotor1,rightMotor2, 150, 150);
    
}
//
//void wait(){
//  digitalWrite(in_1,LOW);   
//  digitalWrite(in_2,LOW);
//  analogWrite(pwm1,0);
//
//  digitalWrite(in_3,LOW);
//  digitalWrite(in_4,LOW);
//  analogWrite(pwm2,0);
//}

void forward(int in_1,int in_2,int in_3,int in_4, int speedRight, int speedLeft){
  digitalWrite(in_1,LOW);   
  digitalWrite(in_2,HIGH);
  analogWrite(pwm1,speedLeft);

  digitalWrite(in_3,LOW);
  digitalWrite(in_4,HIGH);
  analogWrite(pwm2,speedRight);
}
