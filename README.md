# ESP32-ThingSpeak-DHT11

# ESP32-ThingSpeak-DHT11

This project uses an ESP32 microcontroller to read temperature and humidity data from a DHT11 sensor and send the data to a ThingSpeak channel for logging and visualization.

## Hardware Requirements

*   ESP32 Development Board
*   DHT11 Temperature and Humidity Sensor
*   Jumper wires
*   Breadboard (recommended)

## Software Requirements

*   Arduino IDE
*   DHT Sensor Library (install via Arduino Library Manager)
*   ThingSpeak Library (install via Arduino Library Manager)

## Wiring

Connect the DHT11 sensor to the ESP32 as follows:

| DHT11 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| GND       | GND       |
| Data      | GPIO4     |

## Setup and Installation

1.  Clone this repository: `git clone https://github.com/[your-username]/ESP32-ThingSpeak-DHT11.git`
2.  Open the `ESP32-ThingSpeak-DHT11.ino` file in the Arduino IDE.
3.  Install the required libraries (DHT Sensor Library and ThingSpeak Library) via the Arduino Library Manager.
4.  **Important:** Replace the placeholder values for `ssid`, `password`, `myChannelNumber`, and `myWriteAPIKey` in the code with your actual credentials.
5.  Select the correct ESP32 board and port in the Arduino IDE.
6.  Upload the code to your ESP32.

## Usage

Once the code is running, the ESP32 will read data from the DHT11 sensor every minute and send it to your ThingSpeak channel.  You can view the data on your ThingSpeak channel's website.

## ThingSpeak Channel Setup

1.  Create a ThingSpeak account (if you don't have one).
2.  Create a new ThingSpeak channel.
3.  Add two fields to your channel: one for temperature and one for humidity.
4.  Get your Channel ID and Write API Key from your ThingSpeak channel settings.

## Troubleshooting

*   **WiFi Connection Issues:** Double-check your WiFi credentials (SSID and password). Ensure your ESP32 is within range of your WiFi network.
*   **ThingSpeak Data Not Updating:** Verify your Channel ID and Write API Key. Check the ThingSpeak API limits.

