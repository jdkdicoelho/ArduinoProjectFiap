//INCLUSÃO DAS BIBLIOTECAS
#include <dht.h>
#include <ArduinoJson.h>

//DEFINIÇÃO DE PINOS
#define pinoDHT11 7

dht sensorDHT11;

void setup() {
  Serial.begin(9600);
  delay(5000);

}

void loop() {
  sensorDHT11.read11(pinoDHT11);

  DynamicJsonBuffer jBufferT;
  JsonObject& root1 = jBufferT.createObject();

  root1["variable"] = "Temperatura";
  root1["unit"] = "C";
  root1["value"] = sensorDHT11.temperature;



  DynamicJsonBuffer jBufferU;
  JsonObject& root2 = jBufferU.createObject();

  root2["variable"] = "Umidade";
  root2["unit"] = "%";
  root2["value"] = sensorDHT11.humidity;

  root1.prettyPrintTo(Serial);
  root2.prettyPrintTo(Serial);
  
  
  delay(5000);
}
