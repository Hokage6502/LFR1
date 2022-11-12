const int pwm1 = 5;
const int in_1 = 6;
const int in_2 = 7;
const int pwm2 = 10;
const int in_3 = 8;
const int in_4 = 9;

void forward(int in_1,int in_2,int in_3,int in_4){
  digitalWrite(in_1,LOW);   
  digitalWrite(in_2,HIGH);
  analogWrite(pwm1,150);

  digitalWrite(in_3,LOW);
  digitalWrite(in_4,HIGH);
  analogWrite(pwm2,150);
}

void backward(int in_1,int in_2,int in_3,int in_4){
  digitalWrite(in_1,HIGH);   
  digitalWrite(in_2,LOW);
  analogWrite(pwm1,150);

  digitalWrite(in_3,HIGH);
  digitalWrite(in_4,LOW);
  analogWrite(pwm2,150);
}

void wait(int in_1,int in_2,int in_3,int in_4){
  digitalWrite(in_1,LOW);   
  digitalWrite(in_2,LOW);
  analogWrite(pwm1,0);

  digitalWrite(in_3,LOW);
  digitalWrite(in_4,LOW);
  analogWrite(pwm2,0);
}

void setup() {
  // put your setup code here, to run once:

  pinMode(pwm1,OUTPUT);
 
  pinMode(in_1,OUTPUT);

  pinMode(in_2,OUTPUT);
  pinMode(pwm2,OUTPUT);
 
  pinMode(in_3,OUTPUT);

  pinMode(in_4,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  forward(in_1,in_2,in_3,in_4);

}
