// This is some boilerplate code to tell the chip how are are going to program it
// and that we are using a Temp and Humidity Sensor
#include <Arduino.h>
#include "DHTesp.h"


// These lines say what pin on the chip the sensor is connected to
// and what type of sensor it is
const int DHTPin = 13;
#define DHTTYPE DHTesp::DHT22

// this gives the snesor a name, so we can talk to it.
DHTesp dht;

void setup() {
  // this tells the chip we are connected to a computer, so we can send messages to the computer
  Serial.begin(9600);
  
  // This sets up the sensor
  dht.setup(DHTPin, DHTTYPE);
}

void loop() {
  
  // Make a place to store the current temp and humidity
  TempAndHumidity TH;

  // Get the latest values from the sensor and store it in the place we just created
  TH = dht.getTempAndHumidity();

  // Turn the numbers into something we can send the computer
  String datapoint = String(TH.temperature) + "," + String(TH.humidity);

  // Send the data to the computer
  Serial.println(datapoint);

  // wait 10 seconds, then do it all again
  delay(10000);
}