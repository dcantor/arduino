
#include <DHT.h>
#define Type DHT11
int sensePin=2;   //have to use Pin 2 with this lib
DHT HT(sensePin,Type);
float humidity;
float tempC;
float tempF;
int setTime=500;
int dt=1000;  //delay time between temp readings

void setup() {
  Serial.begin(9600);
  HT.begin();
  delay(setTime);


}

void loop() {
  humidity=HT.readHumidity();
  tempC=HT.readTemperature();
  tempF=HT.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" Temperature C ");
  Serial.print(tempC);
  Serial.print(" C ");
  Serial.print(tempF);
  Serial.println(" F ");
  delay(dt);
  
}
