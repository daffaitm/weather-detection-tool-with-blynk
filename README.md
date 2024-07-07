# weather-detection-tool-with-blynk

This project is a weather monitoring device equipped with a rain alert system, utilizing the Blynk IoT platform for real-time monitoring and control via a smartphone application. The project aims to provide a cost-effective alternative to commercial weather stations with similar functionalities.

## Abstract
With the rainy season upon us, frequent and unpredictable rain can cause inconvenience in daily activities. Our device, "Weather Monitoring with Rain Alert using Blynk," offers a solution by providing weather monitoring and rain alert features. The data collected by our device can be monitored and controlled using the Blynk smartphone application, making it practical for everyday use.

## Keywords
- Blynk
- Rain sensor
- Light detection sensor
- DHT11

## Features
- **Weather Monitoring:** Measures temperature, humidity, and light levels.
- **Rain Alert:** Provides an alert when rain is detected.
- **IoT Integration:** Monitors and controls the device via the Blynk smartphone application.

## Components
- **ESP32:** Microcontroller with integrated Wi-Fi and Bluetooth, used for controlling sensors, buzzer, and Blynk connection.
- **Rain Sensor:** Detects rain and converts it into digital and analog signals.
- **DHT11:** Measures temperature and humidity.
- **Light Detection Sensor (LDR):** Detects light levels.
- **LCD 16x2 with I2C:** Displays visual or textual information.
- **Buzzer:** Provides audio alerts.
- **Switch:** Manually controls the buzzer.

## System Integration
- **ESP32 and Blynk Integration:** The ESP32 microcontroller is programmed to collect data from the sensors and send it to the Blynk application for monitoring and control.
- **System Design and Wiring:** Complete wiring and system design have been implemented to ensure seamless operation of all components.

## Video Demonstration
Watch the video demonstration of our project [here](https://youtu.be/XOnppKJMeDY).


## Schematic

![Schematic](images/schematic.jpg)

## System Flowchart

![System Flowchart](images/flowchart.png)


## Bill of Materials
| Component           | Quantity | Unit Price (IDR) | Total Price (IDR) | Purchase Link |
|---------------------|----------|------------------|-------------------|---------------|
| ESP32               | 1        | 70,000           | 70,000            | [Link](https://www.tokopedia.com/hwthinker/esp32-esp-32-wifi-bluetooth-dual-core-development-board-usb-type-c-esp32?extParam=ivf%3Dfalse&src=topads) |
| Rain Sensor         | 1        | 9,000            | 9,000             | [Link](https://www.tokopedia.com/aisyahsa/md0127-sensor-cuaca-air-hujan-rain-arduino-raspberry-pi-md-0127-module?extParam=ivf%3Dfalse&src=search) |
| LDR Sensor          | 1        | 6,600            | 6,600             | [Link](https://www.tokopedia.com/cncstorebandung/cnc-photosenstive-light-ldr-resistance-sensor-cahaya-module?extParam=ivf%3Dfalse&src=search) |
| DHT11               | 1        | 15,000           | 15,000            | [Link](https://www.tokopedia.com/mechatron/dht11-dht-11-dht-11-sensor-suhu-lembab-temperature-humidity-arduino?extParam=ivf%3Dfalse&src=topads) |
| LCD 16x2 with I2C   | 1        | 32,000           | 32,000            | [Link](https://www.tokopedia.com/cncstorebandung/cnc-lcd-1602-char-blue-backlight-with-i2c-serial-interface-module?extParam=ivf%3Dfalse&src=search&refined=true) |
| Buzzer              | 1        | 2,000            | 2,000             | [Link](https://www.tokopedia.com/anugrah-solo/active-buzzer-5v-buser-aktif-5v?extParam=ivf%3Dfalse&src=search) |
| Switch              | 1        | 1,500            | 1,500             | [Link](https://www.tokopedia.com/nivico-online/mini-rocket-switch-kcd5-101-high-quality?extParam=ivf%3Dfalse&src=search) |

## Validation and Characterization
- **Input, Output, and PWM:** The rain sensor provides rain detection input, DHT11 provides temperature and humidity data, and the LDR sensor detects light levels. When it rains, the rain sensor activates the buzzer via PWM. The switch can manually turn off the buzzer.
- **Blynk Integration:** All sensor data can be monitored using the Blynk app on a smartphone. The device must be connected to the same internet network as the Blynk app for monitoring.

