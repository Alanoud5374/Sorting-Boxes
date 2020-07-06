#include <Stepper.h>

int stepsPerRevolution = 300;  
Stepper myStepper(stepsPerRevolution, 4, 6, 5, 7);
Stepper myStepper1(stepsPerRevolution, 8, 10, 9, 11);
unsigned long a;

void setup() {
  myStepper.setSpeed(200); 
  myStepper1.setSpeed(200);
  Serial.begin(9600);
}

void loop() {
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  digitalWrite(12,HIGH);                      
  delayMicroseconds(2);                                 
  digitalWrite(12,LOW);
  pinMode(12,INPUT);                   
  a=pulseIn(12,HIGH);                        

  if(a>=3990 || a<=4030)
  {myStepper.step(2*stepsPerRevolution);
  Serial.println("The volume of the cube is 30cm^3");}
  
  else if(a>=4550 || a<=4590)
  {myStepper1.step(2*stepsPerRevolution);
  Serial.println("The volume of the cube is 20cm^3");}
  
  else
  {Serial.println("The volume of the cube is 10cm^3");}
}
