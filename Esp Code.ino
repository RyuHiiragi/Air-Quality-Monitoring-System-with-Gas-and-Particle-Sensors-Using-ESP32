#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>

// Wi-Fi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ThingSpeak API endpoint and key
const char* serverUrl = "https://api.thingspeak.com/update";
const String apiKey = "YOUR_API_KEY";

// Sensor pins
#define MQ135_PIN 34
#define MQ2_PIN 35
#define PM_SENSOR_SDA 21
#define PM_SENSOR_SCL 22
#define BUZZER_PIN 23

float co2Level, pm25Level;

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize I2C for PM sensor
  Wire.begin(PM_SENSOR_SDA, PM_SENSOR_SCL);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Wi-Fi connected");
}

void loop() {
  // Read gas sensor values
  int mq135Value = analogRead(MQ135_PIN);
  int mq2Value = digitalRead(MQ2_PIN);

  // Convert MQ-135 analog reading to CO2 ppm (calibrate with known values) <button class="citation-flag" data-index="5">
  co2Level = map(mq135Value, 0, 4095, 0, 5000);

  // Read PM2.5/PM10 data via I2C <button class="citation-flag" data-index="7">
  pm25Level = readPM25();

  // Check thresholds and activate buzzer if exceeded
  if (co2Level > 1000 || pm25Level > 50) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Send data to ThingSpeak
  sendDataToCloud(co2Level, pm25Level);

  delay(10000); // Send data every 10 seconds
}

float readPM25() {
  // Example function to read PM2.5 data from SEN0177 via I2C
  Wire.requestFrom(0x12, 2); // Replace 0x12 with actual I2C address
  byte msb = Wire.read();
  byte lsb = Wire.read();
  return (msb << 8 | lsb) / 10.0; // Example conversion <button class="citation-flag" data-index="7">
}

void sendDataToCloud(float co2, float pm25) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = serverUrl + "?api_key=" + apiKey + "&field1=" + String(co2) + "&field2=" + String(pm25);
    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode == 200) {
      Serial.println("Data sent to ThingSpeak");
    } else {
      Serial.println("Error sending data to ThingSpeak");
    }
    http.end();
  }
}
