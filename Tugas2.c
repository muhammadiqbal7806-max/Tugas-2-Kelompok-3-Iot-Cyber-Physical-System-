#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LED 4

LiquidCrystal_I2C lcd(0x27, 16, 2);

// WIFI
const char* ssid = "Le Minerale";
const char* password = "gosong12";

// THINGSBOARD
const char* mqtt_server = "mqtt.thingsboard.cloud";
const char* TOKEN = "B3vCpTQb3MSzyJPCmqOC";

// MQTT
WiFiClient espClient;
PubSubClient client(espClient);

// UART dari Arduino
HardwareSerial mySerial(2);

void callback(char* topic, byte* payload, unsigned int length) {

  String message = "";

  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (message.indexOf("true") != -1) {
    digitalWrite(LED, HIGH);
  }

  if (message.indexOf("false") != -1) {
    digitalWrite(LED, LOW);
  }
}

void connectWiFi() {

  Serial.print("Connecting WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");
}

void reconnect() {

  while (!client.connected()) {

    Serial.println("Connecting MQTT...");

    if (client.connect("ESP32", TOKEN, NULL)) {

      Serial.println("MQTT Connected");

      client.subscribe("v1/devices/me/rpc/request/+");

    }

    else {

      Serial.print("Failed MQTT rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(LED, OUTPUT);

  // UART Arduino
  mySerial.begin(9600, SERIAL_8N1, 16, 17);

  // LCD
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Factory");

  connectWiFi();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  if (mySerial.available()) {

    String temp = mySerial.readStringUntil('\n');

    Serial.println(temp);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(temp);
    lcd.print("C");

    String payload = "{\"temperature\":";
    payload += temp;
    payload += "}";

    client.publish("v1/devices/me/telemetry", payload.c_str());
  }
}
