#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup(void) 
{
  Serial.begin(9600);
  while (!Serial) {
      // Will pause Zero, Leonardo, etc., until serial console opens
      delay(1);
  }
  pinMode(A3, INPUT);

  Serial.println("Hello!");

  // Initialize the INA219
  if (!ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
  

  Serial.println("Measuring voltage and current with INA219 ...");
  delay(2000);
  Serial.print(",  "); Serial.println("Load Voltage (V),   Load Current (mA),    Power Output (mW) "); 
}



void loop(void) {
  float current_mA, load_voltage, power_output_mW;
  unsigned long start;

  // Read current from INA219 and initial load voltage
  current_mA = ina219.getCurrent_mA();
  load_voltage = (4.30 / 198) * analogRead(A3);

  // Record the start time
  start = millis();

  // Calculate average values over 2 seconds
  while (millis() - start < 2000) {
    float new_current = ina219.getCurrent_mA();
    float new_voltage = (4.30 / 198) * analogRead(A3);

    current_mA = sqrt((current_mA * current_mA + new_current * new_current) / 2);
    load_voltage = sqrt((load_voltage * load_voltage + new_voltage * new_voltage) / 2);
  }

  // Calculate power output
  power_output_mW = load_voltage * current_mA;


  Serial.print(",  "); Serial.print(load_voltage, 2);Serial.print(",  "); Serial.print(current_mA, 2); Serial.print(",  "); Serial.println(power_output_mW, 2); 
}

