#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_ADXL345_U.h>
#include <DallasTemperature.h>
#include <OneWire.h>

#define TEMP_PIN 4 // Pino do sensor DS18B20
OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

const char* ssid = "SEU_SSID";
const char* password = "SUA_SENHA";
const char* mqtt_server = "BROKER_IP";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado!");

  client.setServer(mqtt_server, 1883);

  sensors.begin();
  if (!accel.begin()) {
    Serial.println("Sensor ADXL345 não detectado!");
    while (1);
  }
}

void loop() {
  if (!client.connected()) {
    while (!client.connect("ESP32Client")) {
      delay(500);
    }
  }
  client.loop();

  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  sensors_event_t event;
  accel.getEvent(&event);

  String payload = "{\"temperature\": " + String(temp) +
                   ", \"vibration_x\": " + String(event.acceleration.x) +
                   ", \"vibration_y\": " + String(event.acceleration.y) +
                   ", \"vibration_z\": " + String(event.acceleration.z) + "}";
  client.publish("machine/data", payload.c_str());

  delay(1000);
}
