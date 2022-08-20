# Adafruit ESP32-S3 Feather Programs

A collection of programs for the [Adafruit ESP32-S3 Feather](https://learn.adafruit.com/adafruit-esp32-s3-feather) written in Arduino Programming Language

## wifi-ap-recon

Scans for wifi access points using the onboard wifi adapter and returns the results over serial

For each AP found it returns:
- SSID
- RSSI
- BSSID
- Encryption Type

The onboard LED is used to indicate the state of the program:
- Red: Initialising
- Yellow: Scanning
- Green: Scan complete