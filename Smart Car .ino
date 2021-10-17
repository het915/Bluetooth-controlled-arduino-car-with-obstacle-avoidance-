
int motor_R_f=6;  
int motor_R_r=7;

int motor_L_f=4;
int motor_L_r=5;

int ledfar=A0;
int ledmid=A1;
int lednear=A2;

int trig_f=8;
int echo_f=9;

int trig_r=10;
int echo_r=11;

long duration;
float distance,FD,BD;

char data;
int flag;


void setup() 
{
Serial.begin(9600);

pinMode(motor_R_f,OUTPUT);
pinMode(motor_R_r,OUTPUT);
pinMode(motor_L_f,OUTPUT);
pinMode(motor_L_r,OUTPUT);

pinMode(trig_f,OUTPUT);
pinMode(echo_f,INPUT);

pinMode(trig_r,OUTPUT);
pinMode(echo_r,INPUT);

pinMode(ledfar,OUTPUT);
pinMode(ledmid,OUTPUT);
pinMode(lednear,OUTPUT);
}

void loop() 
{

  if(flag==0)
 {
  forward_distance();
 }
 else if(flag==1)
 {
  backward_distance();
 }
if (Serial.available())
{
  data=Serial.read();
  if (data == 'F' )
  {
    forward();
  }
  else if (data == 'B'  )
  {
    backward();
  }
  else if(data == 'L')
  {
    left();
  }
   else if(data == 'R')
  {
    right();
  }
  else if(data == 'S')
  {
    stopall();
  }
}
delay(1);


void forward()
{
  digitalWrite(motor_R_f,HIGH);
  digitalWrite(motor_R_r,LOW);
  digitalWrite(motor_L_f,HIGH);
  digitalWrite(motor_L_r,LOW);
  flag =0;
}
void backward()
{
  digitalWrite(motor_R_f,LOW);
  digitalWrite(motor_R_r,HIGH);
  digitalWrite(motor_L_f,LOW);
  digitalWrite(motor_L_r,HIGH);
  flag=1;
}
void left()
{
  digitalWrite(motor_R_f,HIGH);
  digitalWrite(motor_R_r,LOW);
  digitalWrite(motor_L_f,LOW);
  digitalWrite(motor_L_r,LOW);
}
void right()
{
  digitalWrite(motor_R_f,LOW);
  digitalWrite(motor_R_r,LOW);
  digitalWrite(motor_L_f,HIGH);
  digitalWrite(motor_L_r,LOW);
}
void stopall()
{
  digitalWrite(motor_R_f,LOW);
  digitalWrite(motor_R_r,LOW);
  digitalWrite(motor_L_f,LOW);
  digitalWrite(motor_L_r,LOW);
}





void forward_distance()
{
  digitalWrite(trig_f, LOW);
  delay(2);
  digitalWrite(trig_f, HIGH);
  delay(10);
  digitalWrite(trig_f, LOW);
  duration = pulseIn(echo_f, HIGH);
  distance = duration * 0.034 / 2; 
  
  if(distance<20)                     
  {
    stopall();
   }
  delay(1);
}



void backward_distance()
{
  digitalWrite(trig_r, LOW);
  delay(2);
  digitalWrite(trig_r, HIGH);
  delay(10);
  digitalWrite(trig_r, LOW);
  duration = pulseIn(echo_r, HIGH);
  distance = duration * 0.034 / 2; 


  if(distance<20)                     
  {
    stopall();
  }
  delay(1);  



  if (distance<30)
{
  digitalWrite(ledfar,HIGH);
}
else if(distance<25)
{
  digitalWrite(ledmid,HIGH);
  digitalWrite(ledfar,HIGH);
}
else if (distance<20)
{
  digitalWrite(ledmid,HIGH);
  digitalWrite(ledfar,HIGH);
  digitalWrite(lednear,HIGH);
}
else
{
  digitalWrite(ledmid,LOW);
  digitalWrite(ledfar,LOW);
  digitalWrite(lednear,LOW);
}

}




