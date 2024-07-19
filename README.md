# AirSensor_PM2.5
Code to utilize a PM2.5 sensor, OLED, and ESP8266

# Air Quality Monitor with OLED Display

This project is an air quality monitor that uses a PM2.5 sensor and an SSD1306 OLED display to show real-time air quality data. The project is built using an ESP8266 microcontroller, Adafruit PM2.5 sensor, and a 128x32 OLED display.

## Features

- Measures and displays PM1.0, PM2.5, and PM10 concentration levels.
- Displays particle counts for particles larger than 0.3µm, 0.5µm, 1.0µm, 2.5µm, 5.0µm, and 10µm.
- Uses SoftwareSerial to interface with the PM2.5 sensor.
- Displays data on a 128x32 OLED display.

## Components

- ESP8266 microcontroller
- Adafruit PM2.5 sensor
- 128x32 SSD1306 OLED display
- Connecting wires

## Wiring

- **PM2.5 Sensor**:
  - RX: D2 (GPIO4)
  - TX: D4 (GPIO2)
- **OLED Display**:
  - VCC: 3.3V
  - GND: GND
  - SDA: D1 (GPIO5)
  - SCL: D3 (GPIO0)

## Software

The software is written in C++ and uses the Arduino framework. The following libraries are required:

- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit PM2.5 AQI Sensor Library](https://github.com/adafruit/Adafruit_PM25AQI)
- [SoftwareSerial Library](https://github.com/plerup/espsoftwareserial)

## Installation

1. Install the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/Main/Software).
2. Install the ESP8266 board package by following [these instructions](https://arduino-esp8266.readthedocs.io/en/latest/installing.html).
3. Install the required libraries using the Library Manager in the Arduino IDE.
4. Clone this repository or download the ZIP file and extract it.
5. Open the `air_sensor_oled.ino` file in the Arduino IDE.
6. Connect your ESP8266 board to your computer.
7. Select the appropriate board and port in the Arduino IDE.
8. Upload the code to your ESP8266 board.

## Usage

Once the code is uploaded, the OLED display will show the air quality data in real-time. The data includes PM1.0, PM2.5, and PM10 concentration levels, as well as particle counts for various particle sizes.

## License

This project is licensed under the [GNU General Public License v3.0](LICENSE).

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests with your improvements.

## Acknowledgements

- [Adafruit Industries](https://www.adafruit.com/) for their excellent libraries and hardware.

