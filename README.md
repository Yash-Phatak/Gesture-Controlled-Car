Gesture Controlled Car

A 4-wheel drive controlled by gestures using esp-8266 and MPU-6050 accelerometer.

Components :
1. Esp-8266 x 2
2. MPU-6050
3. Motors x 4
4. L298N Motor Drive
5. Jumper Wires
6. Chasis
7. Wheels x 4

Working :

1. Two Esps are used to establish a communication and act as transmitter and receiver.
2. Primary ESP(mounted on the car) uses the get request to receive commands controlling the direction of the car.
3. Secondary ESP (on the hand) uses the calibrations of the accelerometer to send appropriate commands to the Primary ESP.
4. Routes are created based on commands received and then call subsequent functions controlling the motion of the car.
     a. primaryEspIP/W -> forward
     b. primaryEspIP/A -> left
     c. primaryEspIP/S -> backward
     d. primaryEspIP/D -> right
     e. primaryEspIP/Q -> stop
5. Based on the signals of the MPU-6050 subsequent routes are called and functions of motion are executed.

![image](https://github.com/user-attachments/assets/07102aa1-a14e-4863-9561-d151334468fd)


Diagram :

Primary ESP Mount and Car Chasis Connections :
![WhatsApp Image 2024-11-20 at 20 49 13_efbe7e27](https://github.com/user-attachments/assets/214df27c-215e-431f-849b-3188e45c37cd)

Transmitter Mount and MPU-6050 Connections :
![WhatsApp Image 2024-11-20 at 20 49 14_db786e5c](https://github.com/user-attachments/assets/84d56b6d-363a-4c67-aac5-c3abd902997c)





