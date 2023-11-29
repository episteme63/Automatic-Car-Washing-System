// define pins
int switchPin = 3;
int onOffLED = 2;
int wash_choice = A5;
int redPin= 13;
int bluePin = 12;
int greenPin = 11;
int waterBoothLED = 6;
int soapBoothLED = 5;
int dryingBoothLED = 4;
int switch_state = LOW;
int cm = 0;
int del = 10000; // delay in milliseconds
  
// initialization
void setup()
{
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(onOffLED, OUTPUT);
  pinMode(wash_choice, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(waterBoothLED, OUTPUT);
  pinMode(soapBoothLED, OUTPUT);
  pinMode(dryingBoothLED, OUTPUT);
}

// check if the sliding switch is ON or OFF
bool check_on_off()
{
  switch_state = digitalRead(switchPin);
  if(!switch_state)
  {
    Serial.println("CarWash System is OFF");
    setColor(waterBoothLED, soapBoothLED, dryingBoothLED, 0,0,0);
	setColor(redPin, greenPin, bluePin,0,0,0);
    digitalWrite(onOffLED, LOW);
  }
  return switch_state;
}

// set color of RGB LED
void setColor(int rPin, int gPin, int bPin, int redValue, int greenValue, int blueValue) {
  analogWrite(rPin, redValue);
  analogWrite(gPin, greenValue);
  analogWrite(bPin, blueValue);
}

// calculate the distance of car from the sensor
long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);  // Clear the trigger
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // Sets the pin on HIGH state for 10 micro seconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  // Reads the pin, and returns the sound wave travel time in microseconds
  return pulseIn(pin, HIGH);
}

// get the type of carwash choice of user
int get_choice()
{
  delay(del);
  int choice_value = analogRead(wash_choice);
  return choice_value;
}

// car reaches the water station
int waterBooth()
{
  if(!(check_on_off()))
  {
    return 0;
  }
  
  delay(del);
  
  cm = 0.01723 * readUltrasonicDistance(10);
  if(cm <= 200)
  {
    Serial.println("Water Booth reached");
    setColor(waterBoothLED, soapBoothLED, dryingBoothLED, 255,0,0);
    
    // provides a delay of 'del' milliseconds
    // during that, if sliding switch is turned off, we return 0 to disable the system
    for (int i=0; i<del; i++)
    {
      if(!(check_on_off()))
      {
        return 0;
      }
      delay(1);
    }
  }
  
  cm = 0.01723 * readUltrasonicDistance(10);
  if(cm > 200)
  {
    Serial.println("Water Booth exited");
    setColor(waterBoothLED, soapBoothLED, dryingBoothLED, 0,0,0);
    for (int i=0; i<del; i++)
    {
      if(!(check_on_off()))
      {
        return 0;
      }
      delay(1);
    }
  }
  
  return 1;
}

// car reaches the soap station
int soapBooth()
{
  if(!(check_on_off()))
  {
    return 0;
  }
  
  delay(del);
  
  cm = 0.01723 * readUltrasonicDistance(9);
  if(cm <= 200)
  {
    Serial.println("Soap Booth reached");
    setColor(waterBoothLED, soapBoothLED, dryingBoothLED, 0,255,0);
    for (int i=0; i<del; i++)
    {
      if(!(check_on_off()))
      {
        return 0;
      }
      delay(1);
    }
  }
  
  cm = 0.01723 * readUltrasonicDistance(9);
  if(cm > 200)
  {
    Serial.println("Soap Booth exited");
    setColor(waterBoothLED, soapBoothLED, dryingBoothLED, 0,0,0);
    for (int i=0; i<del; i++)
    {
      if(!(check_on_off()))
      {
        return 0;
      }
      delay(1);
    }
  }
  
  return 1;
}

// car reaches the soap+wax station
int soapWaxBooth()
{
  if(!(check_on_off()))
  {
    return 0;
  }
  
  delay(del);
  
  cm = 0.01723 * readUltrasonicDistance(8);
  if(cm <= 200)
  {
    Serial.println("Soap+Wax Booth reached");
    setColor(waterBoothLED, soapBoothLED, dryingBoothLED, 0,255,0);
    for (int i=0; i<del; i++)
    {
      if(!(check_on_off()))
      {
        return 0;
      }
      delay(1);
    }
  }
  
  cm = 0.01723 * readUltrasonicDistance(8);
  if(cm > 200)
  {
    Serial.println("Soap+Wax Booth exited");
    setColor(waterBoothLED, soapBoothLED, dryingBoothLED, 0,0,0);
    for (int i=0; i<del; i++)
    {
      if(!(check_on_off()))
      {
        return 0;
      }
      delay(1);
    }
  }
  
  return 1;  
}

// car reaches the drying station
int dryingBooth()
{
  if(!(check_on_off()))
  {
    return 0;
  }
  
  delay(del);
  
  cm = 0.01723 * readUltrasonicDistance(7);
  if(cm <= 200)
  {
    Serial.println("Drying Booth reached");
    setColor(waterBoothLED, soapBoothLED, dryingBoothLED, 0,0,255);
  	for (int i=0; i<del; i++)
    {
      if(!(check_on_off()))
      {
        return 0;
      }
      delay(1);
    }  
  }
  
  cm = 0.01723 * readUltrasonicDistance(7);
  if(cm > 200)
  {
    Serial.println("Drying Booth exited");
    setColor(waterBoothLED, soapBoothLED, dryingBoothLED, 0,0,0);
    for (int i=0; i<del; i++)
    {
      if(!(check_on_off()))
      {
        return 0;
      }
      delay(1);
    }
  }
 return 1;
}

// only water wash (RED LED)
int water_wash()
{
  if(!(check_on_off()))
  {
    return 0;
  }
  
  setColor(redPin, greenPin, bluePin,255,0,0);
  
  int success = 0;
  success = waterBooth();
  if(!success)
  {return 0;}
  success = dryingBooth();
  if(!success)
  {return 0;}
  
  return 1;
}

// water+soap wash (BLUE LED)
int water_soap_wash()
{
  if(!(check_on_off()))
  {
    return 0;
  }
  
  setColor(redPin, greenPin, bluePin,0,0,255);
  
  int success = 0;
  success = waterBooth();
  if(!success)
  {return 0;}
  success = soapBooth();
  if(!success)
  {return 0;}
  success = dryingBooth();
  if(!success)
  {return 0;}
  
  return 1;
}

// water+soap+wax wash (GREEN LED)
int water_soap_wax_wash()
{
  if(!(check_on_off()))
  {
    return 0;
  }
  
  setColor(redPin, greenPin, bluePin,0,255,0);
  
  int success = 0;
  success = waterBooth();
  if(!success)
  {return 0;}
  success = soapWaxBooth();
  if(!success)
  {return 0;}
  success = dryingBooth();
  if(!success)
  {return 0;}
  
  return 1;
}

void loop()
{
  if(!check_on_off())
  {
    return;
  }
  
  Serial.println("CarWash System is ON");
  digitalWrite(onOffLED, HIGH);
  for (int i=0; i<del; i++)
  {
    if(!(check_on_off()))
    {
      return;
    }
    delay(1);
  }  
  
  // success variable determines whether the wash was successfully completed
  int success = 0;
  
  // get the choice of the user
  // water or water+soap or water+soap+wax
  int choice = get_choice();
  Serial.print("Choice:");
  
  
  // call appropriate functionality based on user choice
  if(choice < 341)
  {
    Serial.println("Water");
    
    // call the water_wash function
    success = water_wash();
    //Serial.println(success);
  }
  else if(choice >= 341 && choice < 682)
  {
    Serial.println("Water+soap");
    
    // call the water_soap_wash function
    success = water_soap_wash();
    //Serial.println(success);
  }
  else
  {
    Serial.println("Water+soap+wax");
    
    // call the water_soap_wax_wash function
    success = water_soap_wax_wash();
    //Serial.println(success);
  }
  
  if(success)
  {
    Serial.println("Car washed successfully!");
  }
  else
  {
    Serial.println("Car could not be washed.");
  }
  
}