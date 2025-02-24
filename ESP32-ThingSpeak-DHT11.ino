#include <WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

// --- Configuration ---
#define DHTPIN 4     // DHT11 data pin (connected to GPIO4)
#define DHTTYPE DHT11   // DHT11 sensor type

const char* ssid = "Your_WiFi_SSID";      // **REPLACE WITH YOUR WIFI SSID**
const char* password = "Your_WiFi_Password"; // **REPLACE WITH YOUR WIFI PASSWORD**

unsigned long myChannelNumber = YOUR CHANNEL NUMBER; // **YOUR CHANNEL NUMBER**
const char * myWriteAPIKey = "YOUR WRITE API KEY"; // **YOUR WRITE API KEY**

// --- Global Variables ---
DHT dht(DHTPIN, DHTTYPE); // Create DHT sensor object

WiFiClient client; // Create WiFi client object

float temperature, humidity; // Variables to store temperature and humidity readings

unsigned long previousMillis = 0; // Variable to store the time of the last reading
const long interval = 60000; // Time interval between readings (1 minute in milliseconds)

// --- Setup Function ---
void setup() {
  Serial.begin(115200); // Initialize serial communication for debugging
  dht.begin(); // Initialize DHT sensor

  WiFi.begin(ssid, password); // Connect to WiFi network
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) { // Wait until connected to WiFi
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!"); // Print connected message

  ThingSpeak.begin(client); // Initialize ThingSpeak client
}

// --- Loop Function ---
void loop() {
  readAndSendData(); // Call function to read sensor data and send to ThingSpeak
}

// --- Function to Read DHT11 and Send Data to ThingSpeak ---
void readAndSendData() {
  unsigned long currentMillis = millis(); // Get current time
  if (currentMillis - previousMillis >= interval) { // Check if it's time to read sensor data
    previousMillis = currentMillis; // Update the time of the last reading

    temperature = dht.readTemperature(); // Read temperature from DHT11 sensor
    humidity = dht.readHumidity(); // Read humidity from DHT11 sensor

    if (isnan(temperature) || isnan(humidity)) { // Check for reading errors
      Serial.println("Failed to read from DHT sensor!");
      return; // Don't send data if there's an error
    }

    Serial.print("Temperature: "); // Print temperature reading to serial monitor
    Serial.print(temperature);
    Serial.print(" *C, Humidity: "); // Print humidity reading to serial monitor
    Serial.print(humidity);
    Serial.println(" %");

    // Send data to ThingSpeak
    ThingSpeak.setField(1, temperature); // Set temperature value for Field 1
    ThingSpeak.setField(2, humidity); // Set humidity value for Field 2

    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); // Send data to ThingSpeak
    if (x == 0) { // Check if data was sent successfully
      Serial.println("Channel write failed. Check API Key and Channel ID.");
    } else {
      Serial.println("Channel write successful.");
    }
  }
}
