int gas;
int blower;
int fan;
int gas_servo;
int thresh;
int high;
int low;
int fire;
int fire_servo;
void setup()
{
  pinMode(gas, INPUT);
  pinMode(blower, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(gas_off, OUTPUT);
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

