#include <SFE_BMP180.h>
#include <Wire.h>


SFE_BMP180 pressure;
void setup() {
  
    Serial.begin(9600);
    const int switchPin = 10;
    const int lightPin = 11;
    pinMode (switchPin, INPUT);
    pinMode (lightPin, OUTPUT);
    
 

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
        else if(P-p0>=(0.1)*p0){
           digitalWrite (lightPin, HIGH); 
        }
        else{
          digitalWrite (lightPin, LOW); 
        }
       
  delay(5000);  
}
