#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  float suhu = dht.readTemperature();

  if (isnan(suhu)) {
    Serial.println("error");
  } else {
    Serial.println(suhu);
  }

  delay(2000);
}
