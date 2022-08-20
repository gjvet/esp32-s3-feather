#include "WiFi.h"
#include <Adafruit_NeoPixel.h>

// Create a pixel strand with 1 pixel on PIN_NEOPIXEL (the RGB led on the board)
Adafruit_NeoPixel pixels(1, PIN_NEOPIXEL);


void setup() {
  Serial.begin(115200);
  pixels.begin(); // Initialise the pixel
  setPixelColour(255, 0, 0); // Set the led colour to red 
  while (!Serial) {} // Wait for the serial connection to initiaite
  WiFi.mode(WIFI_STA); // Set WiFi to station mode
  delay(100);
}

void setPixelColour(int r, int g, int b) {
  pixels.setPixelColor(0, pixels.Color(r,g,b)); // Set the first pixel to red
  pixels.show(); // Write the data
}

// Convert the encryption type from the WiFi Library to a string representation 
char* decodeEncryptionType(int type) {
  switch (type) {
    case WIFI_AUTH_WEP:
      return "WEP";
     case WIFI_AUTH_WPA_PSK:
      return "WPA / PSK";
     case WIFI_AUTH_WPA2_PSK:
      return "WPA2 / PSK";
     case WIFI_AUTH_OPEN:
      return "open network";
     case WIFI_AUTH_WPA_WPA2_PSK:
      return "WPA / WPA2 / PSK";
     case WIFI_AUTH_WPA2_ENTERPRISE:
      return "WPA2 Enterprise";
     default:
      return "Unknown";
  }
}

void loop() {
  
  Serial.println("Scanning for WiFi Networks");
  setPixelColour(247,247,0); // Set led to yellow
  int count = WiFi.scanNetworks(); // Start scanning for wifi networks
  Serial.println("Scan Complete");
  if (count == 0) {
    Serial.println("No networks found");
  } else {
    Serial.printf("%d networks found\n", count);
    for (int i = 0; i < count; ++i) { // For each network found
      // Print the SSID, RSSI, BSSID and encryption type to serial
      Serial.printf("%d: %s (%d) %s %s\n", i+1, WiFi.SSID(i).c_str(), WiFi.RSSI(i), WiFi.BSSIDstr(i).c_str(), decodeEncryptionType(WiFi.encryptionType(i))); 
    }
  }
  Serial.println();
  Serial.println("Send newline to scan again\n");
  setPixelColour(0,255,0); // Set led to green
  // Wait for a new line
  bool wait = true;
  while(wait) {
    if (Serial.readString() == "\n") {
      wait = false;
    }
  }
}
