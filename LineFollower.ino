
#include "config.h"

void setup(void)
{
  Serial.begin(9600);
/*  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);*/
  pinMode(M1_OUT1,OUTPUT);
  pinMode(M1_OUT2,OUTPUT);
  pinMode(M2_OUT1,OUTPUT);
  pinMode(M2_OUT2,OUTPUT);
  pinMode(EN1_CTL,OUTPUT);
  pinMode(EN2_CTL,OUTPUT);
  Serial.println("Started");
  motorStop();
}


int readIR(int ch)
{
  long val = 0;
  for(int i = 0;i < SAMPLING_RATE;i++)
  {
    val = val + analogRead(ch);
  }
  return (int)(val / SAMPLING_RATE);
}

void motorStop(void)
{
  digitalWrite(EN1_CTL,LOW);
  digitalWrite(EN2_CTL,LOW);
  digitalWrite(M1_OUT1,LOW);
  digitalWrite(M1_OUT2,LOW);
  digitalWrite(M2_OUT1,LOW);
  digitalWrite(M2_OUT2,LOW);
  Serial.println("Motor Stop");
}

void motorFw(void)
{
  analogWrite(EN1_CTL,SPEED_VAL1);
  analogWrite(EN2_CTL,SPEED_VAL2);
  digitalWrite(M1_OUT1,HIGH);
  digitalWrite(M1_OUT2,LOW);
  digitalWrite(M2_OUT1,HIGH);
  digitalWrite(M2_OUT2,LOW);
  Serial.println("Motor Forward");
}

void motorBw(void)
{
  analogWrite(EN1_CTL,SPEED_VAL1);
  analogWrite(EN2_CTL,SPEED_VAL2);
  digitalWrite(M1_OUT1,LOW);
  digitalWrite(M1_OUT2,HIGH);
  digitalWrite(M2_OUT1,LOW);
  digitalWrite(M2_OUT2,HIGH);
  Serial.println("Motor Backward");
}


void motorRight(void)
{
  analogWrite(EN1_CTL,SPEED_VAL1);
  analogWrite(EN2_CTL,SPEED_VAL2);
  digitalWrite(M1_OUT1,LOW);
  digitalWrite(M1_OUT2,LOW);
  digitalWrite(M2_OUT1,HIGH);
  digitalWrite(M2_OUT2,LOW);
  Serial.println("Motor Right");
}

void motorLeft(void)
{
  analogWrite(EN1_CTL,SPEED_VAL1);
  analogWrite(EN2_CTL,SPEED_VAL2);
  digitalWrite(M1_OUT1,HIGH);
  digitalWrite(M1_OUT2,LOW);
  digitalWrite(M2_OUT1,LOW);
  digitalWrite(M2_OUT2,LOW);
  Serial.println("Motor Left");
}

// Test function to print IR Sensor values
void printValues()
{
  Serial.print(readIR(IR1));
  Serial.write(9);
  Serial.print(readIR(IR2));
/*  Serial.write(9);
  Serial.print(readIR(IR3));
  Serial.write(9);
  Serial.println(readIR(IR4));*/
  Serial.println();
}

// Test function for motor
void test(void)
{
  char c;
  if(Serial.available())
  {
    c = Serial.read();
    switch(c)
    {
      case 'f': motorFw();
                break;
      case 'b': motorBw();
                break;          
      case 's': motorStop();
                break;
      case 'r': motorRight();
                break;
      case 'l': motorLeft();
                break;
      default: motorStop();
                break;
    }
  }  
}


// main loop
void loop(void)
{
  unsigned int ir1,ir2;
  ir1 = readIR(IR1);
  ir2 = readIR(IR2);
  
  // If robot in white region ( Both threhold are crossed)
  if(ir1 > IR1_THRESHOLD && ir2 > IR2_THRESHOLD)
  {
    motorStop();
  }
  
  // If IR1 sensor is in white region
  else if(ir1 > IR1_THRESHOLD)
  {
    motorLeft();
  }
  
  // If IR2 sensor is in white region
  else if(ir2 > IR2_THRESHOLD)
  {
    motorRight();
  }

  // If both are in black region
  else
  {
    motorFw();
  }

  // Print values for debugging
  Serial.print(ir1);
  Serial.write(9);
  Serial.print(ir2);
  Serial.println();
  
  // Delay
  delay(loop_delay);
//  printValues();
}
