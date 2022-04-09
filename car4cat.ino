
#include <SoftwareSerial.h> 
// Pin10鎺C05鐨凾XD
// Pin1鎺C05鐨凴XD
SoftwareSerial BT(10, 11); 
char val;
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  Serial.begin(38400); 
  Serial.println("bluetooth is ready!");
  BT.begin(38400);
}
 
void loop() {
  if (Serial.available()) {
    val = Serial.read();
    BT.print(val);}

 if(val == 'f')
    {//forward 向前转
      go();}
    if(val == 'b')
    { //stop 停止
      back();} 
    if(val == 'l')
    { //forward 向左转
      go_left();}
    if(val == 'r')
    { //back 向右转
      go_right();}
    if(val == 's')
    { //stop
      car_stop();} 
    val=0;
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);


    
  }
}


void car_stop()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
//  delay(1000);  //寤舵椂1绉�

}

void go()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  delay(1000);   //寤舵椂1绉�
  Serial.print("Forward!!");
}

void back()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(1000);   //寤舵椂1绉�
  Serial.print("Forward!!");
}

void go_left()
{
  digitalWrite(in1,HIGH);
  analogWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(1000);   //寤舵椂1绉�
  Serial.print("Left");
}

void go_right()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  analogWrite(in4,LOW);
  delay(1000);   //寤舵椂1绉� 
  Serial.print("Right"); 

}


