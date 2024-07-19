//Working code that connects a PM2.5 sensor and a 1306 OLED to an ESP8266
// Pins connected:
// OLED VIN - 3.3
//      GND - GND
//      SLA - SLA
//      SCK - SCK
//  SENSOR
//      VIN - 5V
//      GND - GND
//      TX  - D2
//      RX  - D4

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
#include "Adafruit_PM25AQI.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Define SoftwareSerial pins for the PM2.5 sensor
SoftwareSerial pmSerial(2, 3); // RX, TX (TX is not used)

// Initialize the AirGradient object
Adafruit_PM25AQI aqi = Adafruit_PM25AQI();

void setup() {
  // Initialize serial monitor
  Serial.begin(115200);
  while (!Serial) delay(10);

  Serial.println("Adafruit PMSA003I Air Quality Sensor");

  // Initialize the OLED display
  Serial.println("128x32 OLED FeatherWing test");
  
  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  Serial.println("OLED begun");

  display.display();
  delay(2000);
  // Clear the buffer
  display.clearDisplay();
  display.display();

  // Initialize SoftwareSerial for the PM2.5 sensor
  pmSerial.begin(9600);

  // Connect to the sensor using SoftwareSerial
  if (!aqi.begin_UART(&pmSerial)) {
    Serial.println("Could not find PM 2.5 sensor!");
    while (1) delay(10);
  }

  Serial.println("PM25 found!");

  display.setTextSize(1);
  display.setRotation(0);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  PM25_AQI_Data data;

  // Read data from the sensor
  if (!aqi.read(&data)) {
    Serial.println("Could not read from AQI");
    delay(500);  // try again in a bit!
    return;
  }
  Serial.println("AQI reading success");

  Serial.println();
  Serial.println(F("---------------------------------------"));
  Serial.println(F("Concentration Units (standard)"));
  Serial.println(F("---------------------------------------"));
  Serial.print(F("PM 1.0: ")); Serial.print(data.pm10_standard);
  Serial.print(F("\t\tPM 2.5: ")); Serial.print(data.pm25_standard);
  Serial.print(F("\t\tPM 10: ")); Serial.println(data.pm100_standard);
  Serial.println(F("Concentration Units (environmental)"));
  Serial.println(F("---------------------------------------"));
  Serial.print(F("PM 1.0: ")); Serial.print(data.pm10_env);
  Serial.print(F("\t\tPM 2.5: ")); Serial.print(data.pm25_env);
  Serial.print(F("\t\tPM 10: ")); Serial.println(data.pm100_env);
  Serial.println(F("---------------------------------------"));
  Serial.print(F("Particles > 0.3um / 0.1L air:")); Serial.println(data.particles_03um);
  Serial.print(F("Particles > 0.5um / 0.1L air:")); Serial.println(data.particles_05um);
  Serial.print(F("Particles > 1.0um / 0.1L air:")); Serial.println(data.particles_10um);
  Serial.print(F("Particles > 2.5um / 0.1L air:")); Serial.println(data.particles_25um);
  Serial.print(F("Particles > 5.0um / 0.1L air:")); Serial.println(data.particles_50um);
  Serial.print(F("Particles > 10 um / 0.1L air:")); Serial.println(data.particles_100um);
  Serial.println(F("---------------------------------------"));

  display.clearDisplay();
  display.setCursor(0,0);
  display.print("PM 1.0: "); display.println(data.pm10_env);
  display.print("PM 2.5: "); display.println(data.pm25_env);
  display.print("PM 10: "); display.println(data.pm100_env);
  
  display.print("Part's >0.3um: "); display.println(data.particles_03um);
  display.print("Part's >0.5um: "); display.println(data.particles_05um);
  display.print("Part's >1.0um: "); display.println(data.particles_10um);
  display.print("Part's >2.5um: "); display.println(data.particles_25um);
  display.print("Part's >5.0um: "); display.println(data.particles_50um);
  display.print("Part's >10um: "); display.println(data.particles_100um);
  display.display(); // actually display all of the above

  delay(1000);
}
