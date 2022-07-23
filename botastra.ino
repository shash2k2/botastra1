#include <SFE_BMP180.h>
#include <Wire.h>


SFE_BMP180 pressure;
void setup() {
  
    Serial.begin(9600);
    Serial.println("REBOOT");
    const int switchPin = 10;
    const int lightPin = 11;
    pinMode (switchPin, INPUT);
    pinMode (A3, INPUT);
    pinMode (lightPin, OUTPUT);
    
 
  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    
  }
    
    Serial.println("BMP180 init fail\n\n");
    while(1); // Pause forever.
  }
}

void loop() {
  
char status;
  double T,P,p0,a;

 
  buttonState = digitalRead(switchPin);
  

      status = pressure.startPressure(3);
      if (status != 0)
      {
 
        delay(status);

      
        status = pressure.getPressure(P,T);
        if (buttonState== HIGH){
          p0 = pressure.getPressure(P,T);
        }        
        if (status != 0)
        {
          
          if (P-p0<=(0.1)*p0){
           digitalWrite (lightPin, HIGH); 
          }
        }
       
  delay(5000);  
}
