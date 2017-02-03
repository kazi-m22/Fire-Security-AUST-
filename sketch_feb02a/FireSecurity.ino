#include <Servo.h>
int adjuster_p = 12;
int adjuster_n = 13;
int gas = A0;
int blower_p = 7;
int blower_n = 8;
int fan_p = 10;
int fan_n = 11;
int fire;
Servo fire_servo;
int low=200;
int thresh = 300;
int high = 450;
int buzzer_p = 13;
int buzzer_n = 14;





void setup()
{
  pinMode(gas, INPUT);
  pinMode(blower_p, OUTPUT);
  pinMode(blower_n, OUTPUT);
  pinMode(adjuster_p, OUTPUT);
  pinMode(adjuster_n, OUTPUT);
  pinMode(fan_p, OUTPUT);
  pinMode(fan_n, OUTPUT);
  

  fire_servo.attach(9);
  
  Serial.begin(9600);
  
}



void loop()
{
  
  int reading = analogRead(gas);
  Serial.println(reading);

  digitalWrite(fan_p, HIGH);
  digitalWrite(fan_n, LOW);

  
  if(reading>=low && reading <thresh)
  {
    digitalWrite(adjuster_p, HIGH);
    digitalWrite(adjuster_n, LOW);
    
  }

  else if((reading>thresh && reading<=high) || (reading >=high) && analogRead(A0) < fire)
  {
    digitalWrite(adjuster_p,HIGH);
    digitalWrite(adjuster_n,LOW);
    
    digitalWrite(blower_p, HIGH);
    digitalWrite(blower_n, LOW);

    buzzer();

    digitalWrite(fan_p, LOW);
    digitalWrite(fan_n, LOW);
   
  }

  else if((reading>thresh && reading<=high) || (reading >=high) && analogRead(A0) > fire)
  {
    digitalWrite(adjuster_p,HIGH);
    digitalWrite(adjuster_n,LOW);
    
    digitalWrite(blower_p, LOW);
    digitalWrite(blower_n, LOW);

    buzzer();

    digitalWrite(fan_p, LOW);
    digitalWrite(fan_n, LOW);
  }
}


void buzzer()
{
  digitalWrite(buzzer_p, HIGH);
  digitalWrite(buzzer_n, LOW);
  delay(200);
  digitalWrite(buzzer_p, LOW);
  digitalWrite(buzzer_n, LOW);
  delay(200);
}

