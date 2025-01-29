# Horizontal Axis Wind Turbine with Datalogger

## Features
- Generates electricity using a horizontal-axis wind turbine
- Measures **voltage** using a voltage sensor
- Measures **current** using the **INA219 current sensor**
- Calculates **power output** in real-time
- Uses an **LED load** to simulate power consumption
- Transmits data via **Bluetooth** for remote monitoring

## Components Used
- **Wind Turbine** – Generates power
- **Voltage Sensor** – Measures voltage across the load
- **INA219 Current Sensor** – Measures current draw
- **LED Load** – Simulates power usage
- **Microcontroller (e.g., Arduino)** – Processes and logs data
- **Bluetooth Module (e.g., HC-05/HC-06)** – Sends data to external device

## Setup & Usage
1. **Connect Components**: Wire the wind turbine, sensors, LED load, and Bluetooth module to the microcontroller.
2. **Upload Code**: Flash the microcontroller with the provided firmware.
3. **Power Up**: Start the wind turbine and connect the system to power.
4. **Data Transmission**: The system calculates power output and sends data via Bluetooth.
5. **Monitor Data**: Use a Bluetooth-enabled device to receive and analyze the data.

## Data Format
The transmitted data is structured as follows:
```
Timestamp, Voltage (V), Current (A), Power (W)
2025-01-29 12:00:00, 12.5, 0.8, 10
2025-01-29 12:01:00, 13.0, 0.85, 11.05
```

## Dependencies
Ensure the following Arduino libraries are installed:
- `Wire.h` (for I2C communication with INA219)
- `Adafruit_INA219.h` (INA219 sensor library)
- `SoftwareSerial.h` (for Bluetooth communication)

## Future Improvements
- Implement data logging to an SD card
- Enhance Bluetooth connectivity with a mobile app
- Improve power efficiency and data accuracy

## License
This project is open-source and available under the MIT License.

## Author
[Your Name]

