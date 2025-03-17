# Air Quality Monitoring System Using ESP32
![Project Banner](https://i.pinimg.com/736x/7f/00/93/7f00933f50f2688601e449be64023943.jpg)

This repository contains the code and instructions for building an **air quality monitoring system** that uses the ESP32 microcontroller to integrate gas and particle sensors. The system measures air quality parameters and sends the data to a cloud dashboard for real-time monitoring <button class="citation-flag" data-index="1"><button class="citation-flag" data-index="5">.

---

## Table of Contents  
1. [Overview](#overview)  
2. [Components Used](#components-used)  
3. [System Dimensions](#system-dimensions)  
4. [Assembly Instructions](#assembly-instructions)  
5. [Arduino Code Explanation](#arduino-code-explanation)  
6. [Cloud Dashboard Setup](#cloud-dashboard-setup)  
7. [Contributing](#contributing)  
8. [License](#license)  

---

## Overview  
The system uses gas sensors (MQ-135, MQ-2) and a particle sensor (SEN0177) to measure air quality parameters like CO2, CO, NH3, and particulate matter (PM2.5/PM10). The ESP32 processes the data and sends it to a cloud dashboard via Wi-Fi for real-time monitoring <button class="citation-flag" data-index="1"><button class="citation-flag" data-index="5">. This project is ideal for monitoring indoor or outdoor air quality in homes, offices, or industrial areas <button class="citation-flag" data-index="4">.  

---

## Components Used  
- **ESP32 Development Board** <button class="citation-flag" data-index="2">  
- **Gas Sensors**:  
  - **MQ-135**: Detects CO2, ammonia, and other harmful gases <button class="citation-flag" data-index="5">.  
  - **MQ-2**: Measures combustible gases (e.g., LPG, methane) <button class="citation-flag" data-index="9">.  
- **Particle Sensor**:  
  - **SEN0177 (PM2.5/PM10 Sensor)**: Measures airborne particulate matter <button class="citation-flag" data-index="7">.  
- **Buzzer**: Alerts users when air quality exceeds safe thresholds <button class="citation-flag" data-index="5">.  
- **Power Supply**: 5V USB adapter or battery pack <button class="citation-flag" data-index="6">.  

---

## System Dimensions  
For an ideal air quality monitoring system:  
- **Height**: 10–15 cm (for the control box)  
- **Width**: 10–15 cm  
- **Length**: 10–15 cm  

These dimensions ensure the system is compact and portable.  

---

## Assembly Instructions  
1. **Connect the Gas Sensors**:  
   - **MQ-135**:  
     - **VCC** → 5V, **GND** → GND, **AOUT** → GPIO34 (Analog Input) <button class="citation-flag" data-index="5">.  
   - **MQ-2**:  
     - **VCC** → 5V, **GND** → GND, **DOUT** → GPIO35 (Digital Output for threshold alerts) <button class="citation-flag" data-index="9">.  
2. **Connect the Particle Sensor (SEN0177)**:  
   - **VCC** → 5V, **GND** → GND, **SDA** → GPIO21, **SCL** → GPIO22 (I2C communication) <button class="citation-flag" data-index="7">.  
3. **Connect the Buzzer**:  
   - **Positive Pin** → GPIO23, **Negative Pin** → GND <button class="citation-flag" data-index="5">.  
4. **Power Connections**:  
   - Use a 5V USB adapter or battery pack to power the ESP32 and sensors <button class="citation-flag" data-index="6">.  

---

## Arduino Code Explanation  
The code reads data from the gas and particle sensors, processes it, and sends it to a cloud dashboard via Wi-Fi. Below is a breakdown of the key sections:  

1. **Sensor Initialization**:  
   - Gas sensors (MQ-135 and MQ-2) are read using analog and digital pins.  
   - The particle sensor (SEN0177) communicates via I2C <button class="citation-flag" data-index="7">.  

2. **Wi-Fi Connection**:  
   - The ESP32 connects to Wi-Fi using the provided SSID and password.  

3. **Data Transmission**:  
   - Data is sent to a cloud platform (e.g., ThingSpeak) using HTTP POST requests <button class="citation-flag" data-index="2">.  

4. **Threshold Alerts**:  
   - A buzzer is activated if air quality parameters exceed predefined thresholds <button class="citation-flag" data-index="5">.  

---

## Cloud Dashboard Setup  
1. **ThingSpeak Setup**:  
   - Create a free account at [ThingSpeak](https://thingspeak.com/).  
   - Create a new channel and note the API key.  
   - Replace `YOUR_API_KEY` in the code with your ThingSpeak API key <button class="citation-flag" data-index="2">.  

2. **Real-Time Monitoring**:  
   - Access the dashboard to view real-time graphs of air quality parameters.  

---

## Contributing  
Feel free to fork this repository and contribute improvements or new features. If you have suggestions or find bugs, please open an issue.  

---

## License  
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.  

---

<button class="citation-flag" data-index="1"> Integration of gas and particle sensors with ESP32 for air quality monitoring <button class="citation-flag" data-index="1">.  
<button class="citation-flag" data-index="2"> Sending sensor data to ThingSpeak via Wi-Fi <button class="citation-flag" data-index="2">.  
<button class="citation-flag" data-index="5"> Calibration and use of MQ-135 and MQ-2 gas sensors <button class="citation-flag" data-index="5">.  
<button class="citation-flag" data-index="7"> SEN0177 particle sensor integration <button class="citation-flag" data-index="7">.  
