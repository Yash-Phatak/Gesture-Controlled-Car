#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

const char* ssid = "****";     // Replace with your Wi-Fi SSID
const char* password = "*****"; // Replace with your Wi-Fi password

const char* serverIP = "192.168.137.179"; // Replace with the IP of the primary ESP

Adafruit_MPU6050 mpu;
WiFiClient client;

void setup() {
  Serial.begin(9600);

  // Initialize gyroscope
  if (!mpu.begin()) {
    Serial.println("MPU6050 connection failed! Check wiring or I2C address.");
    while (1); // Halt on failure
  }
  Serial.println("MPU6050 initialized!");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}


void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp); // Fetch accelerometer and gyroscope data

  // Detect gestures based on accelerometer readings
  if(a.acceleration.x>8 && a.acceleration.x<12 && a.acceleration.y>-2 && a.acceleration.y<2){
    Serial.println("Stop Car");
    sendCommand("Q"); 
  }
  else if(a.acceleration.y>2){
    Serial.println("Front Car");
    sendCommand("W");
  }
  else if(a.acceleration.y<-2){
    Serial.println("Back Car");
    sendCommand("S");
  }
  else if(a.acceleration.x<8 && a.acceleration.z>0){
    Serial.println("Left Car");
    sendCommand("A");
  }
  else if(a.acceleration.x<8 && a.acceleration.z<0){
    Serial.println("Right Car");
    sendCommand("D");
  }

  delay(200); // Adjust delay as needed
}


// Function to send HTTP commands to the primary ESP
void sendCommand(const char* command) {
  if (client.connect(serverIP, 80)) {
    client.print(String("GET /") + command + " HTTP/1.1\r\n" +
                 "Host: " + serverIP + "\r\n" +
                 "Connection: close\r\n\r\n");
    client.flush(); // Ensure all data is sent
    client.stop();
    Serial.println(String("Sent command: ") + command);
  } else {
    Serial.println("Connection to server failed!");
  }
}
