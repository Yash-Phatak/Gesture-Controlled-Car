**Gesture Controlled Car**

A 4-wheel drive controlled by gestures using esp-8266 and MPU-6050 accelerometer.

**Overview**
This project demonstrates a gesture-controlled car where hand movements dictate the car's motion. The system uses two ESP-8266 modules for communication and an MPU-6050 accelerometer to capture gestures.

**Components**
1. Esp-8266 x 2
2. MPU-6050
3. Motors x 4
4. L298N Motor Drive
5. Jumper Wires
6. Chasis
7. Wheels x 4

**Working**
1. Two Esp modules are used to establish a communication and act as transmitter and receiver respectively.
2. Secondary ESP (on the hand) acts as a transmitter to send commands derived from the MPU-6050 readings to the Primary ESP.
3. Primary ESP(mounted on the car) acts as a receiver and processes the received commands for controlling the direction of the car.
4. The Receiver ESP uses HTTP GET requests to process commands. Each command corresponds to a specific route, which invokes functions for car motion.
     a. primaryEspIP/W -> Forward
     b. primaryEspIP/A -> Left
     c. primaryEspIP/S -> Backward
     d. primaryEspIP/D -> Right
     e. primaryEspIP/Q -> Stop
5. Based on the commands, the car executes functions controlling the motors via the L298N Motor Driver.

![image](https://github.com/user-attachments/assets/07102aa1-a14e-4863-9561-d151334468fd)


**Diagram**

Primary ESP Mount and Car Chasis Connections :
![WhatsApp Image 2024-11-20 at 20 49 13_efbe7e27](https://github.com/user-attachments/assets/214df27c-215e-431f-849b-3188e45c37cd)

Transmitter Mount and MPU-6050 Connections :
![WhatsApp Image 2024-11-20 at 20 49 14_db786e5c](https://github.com/user-attachments/assets/84d56b6d-363a-4c67-aac5-c3abd902997c)

**How to Run the Project**
1. Connect the hardware as per the circuit diagram provided.
2. Flash the appropriate code to both ESP-8266 modules:
     a. Connect the receiver ESP to get the IP of the same.
     b. Write the IP of the receiver ESP in the transmitter code.
     c. Transmitter ESP: Handles MPU-6050 data and sends commands.
     d. Receiver ESP: Controls the car's motion.
3. Power up the components.
4. Calibrate the MPU-6050 for accurate gesture mapping.
5. Use hand gestures to control the car's movement.

**Future Enhancements**
1. Implement obstacle detection using ultrasonic sensors.
2. Add functionality for voice commands.
3. Improve gesture accuracy using machine learning models.



