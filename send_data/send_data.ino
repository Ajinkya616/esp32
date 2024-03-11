#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Galaxy_A34_5G_5B58";
const char* password = "12345678";
const char* serverAddress = "192.168.9.21"; // Change this to your server's IP address
const int serverPort = 3000;

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://" + String(serverAddress) + ":" + String(serverPort) + "/data");
    http.addHeader("Content-Type", "text/plain");

    String data = "123"; // Static data

    int httpResponseCode = http.POST(data);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error on sending POST request: ");
      Serial.println(httpResponseCode);
    }
    http.end();

    delay(5000); // Wait for 5 seconds before sending the next request
  }
}
