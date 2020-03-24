#include <ESP8266WiFi.h>
#include <SPI.h>
#include "LedMatrix.h"
#include <time.h>
#include "DHT.h"

#define NUMBER_OF_DEVICES 5 // 5 dispositivos MAX7219
#define CS_PIN 15 // Pin 15 de MAX7219
#define DHTTYPE DHT11 // Tipo de sensor

LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CS_PIN);
int x = 0;
char time_value[20];

uint8_t DHTPin = D1;

DHT dht(DHTPin, DHTTYPE);
  
void setup() {
  pinMode(DHTPin, INPUT);
  dht.begin(); 
  
  WiFi.begin("LoDeMarta","noteladoy2018");
  //CHANGE THE POOL WITH YOUR CITY. SEARCH AT https://www.ntppool.org/zone/@
  configTime(0 * 3600, 0, "0.ar.pool.ntp.org", "time.nist.gov");
  //AR setenv("TZ", "<-03>3",1);
  setenv("TZ", "GMT0",1); // GMT-0
  ledMatrix.init();
  ledMatrix.setIntensity(4);
  while ( WiFi.status() != WL_CONNECTED ) {
    ledMatrix.setText("OK");
    delay(50);
  }
}

void loop() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  time_t now = time(nullptr);
  String time = String(ctime(&now));
  time.trim();
  time=time.substring(11,16);
  
  ledMatrix.clear();
  ledMatrix.scrollTextLeft();
  ledMatrix.drawText();
  ledMatrix.commit();
  delay(100);
  ledMatrix.setNextText(time+" - T:"+temperature+"  - H:"+humidity+"%"); 
}
