#include <ESP8266WiFi.h>
// Receiver Code -> processes these commands to control the car's motion.
// Wi-Fi credentials
const char* ssid = "***";     // Replace with your Wi-Fi SSID
const char* password = "****"; // Replace with your Wi-Fi password

// Define motor pins
#define IN1 D0
#define IN2 D1
#define IN3 D2
#define IN4 D3

WiFiServer server(80); // Create a web server on port 80

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  carStop(); // Initialize all motors to stop

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

  server.begin(); // Start the server
  Serial.println("Server started!");
}

void loop() {
  WiFiClient client = server.available(); // Check for incoming client
  if (client) {
    String request = client.readStringUntil('\r'); // Read the HTTP request
    client.flush();

    // Parse commands from the HTTP request
    if (request.indexOf("/W") != -1) {
      carForward();
      Serial.println("Moving Forward");
    } else if (request.indexOf("/S") != -1) {
      carBackward();
      Serial.println("Moving Backward");
    } else if (request.indexOf("/A") != -1) {
      carLeft();
      Serial.println("Turning Left");
    } else if (request.indexOf("/D") != -1) {
      carRight();
      Serial.println("Turning Right");
    } else if (request.indexOf("/Q") != -1) {
      carStop();
      Serial.println("Stopped");
    }

    // Send an HTTP response to the client
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<head><title>Car Controller</title></head>");
    client.println("<body style='text-align: center; font-family: Arial;'>");
    client.println("<h1>Wi-Fi Car Controller</h1>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
  }
}

// Motor control functions
void carForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
