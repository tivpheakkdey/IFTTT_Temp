#include "Adafruit_DHT.h"

// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#define DHTPIN D2     // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11		// DHT 11 
#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
	delay(10000);

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a 
// Read temperature as Celsius

	float t = dht.getTempCelcius();
	
	if(t <= 25) Particle.publish("tempLevel", "Under25", PRIVATE);
	else Particle.publish("tempLevel", "Over25", PRIVATE);

	String temp = String::format ("%.1f C",t);

Particle.publish("temp", temp, PRIVATE);

}
