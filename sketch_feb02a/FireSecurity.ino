int gas = A0;
int blower_p = 7;
int blower_n = 8;
int fan_p = 10;
int fan_n = 11;
int gas_servo =9 ;
int thresh = 200;
int fire;
int fire_servo = 4;
void setup()
{
  pinMode(gas, INPUT);
  pinMode(blower, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(gas_off, OUTPUT);
  Serial.begin(9600);
}



void loop()
{
  int reading = analogRead(gas);
  if(reading > thresh && reading < high )
  {
    on_blower();
    off_fan();
    off_gas();
    
  }
  else if(reading<low)
  {
    off_blower();
    on_gas();
  }

  else if(reading > low && reading < thresh && isfire = true)
  {
    off_blower();
    off_fan();
    off_gas();
    stove_off();
  }
}


void
