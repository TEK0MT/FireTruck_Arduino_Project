# Fire Truck Project
Description
This project involves the development of an autonomous fire truck capable of detecting and responding to fire hazards. The fire truck is equipped with flame sensors, a gas sensor, an ultrasonic sensor, and a servo-controlled water pump. The system detects fire using the flame sensors and gas sensor (MQ2) and navigates towards the fire source using ultrasonic distance measurements. Once a fire is detected, the truck activates its water pump to extinguish the flames.

## Authors
Ola Mohamed
Mariam Adhma
Mohamed Tarek
Last Updated
1 August 2024

## Scenario
The fire truck operates autonomously in an environment where it constantly scans for fire hazards. The flame sensors positioned on the left, center, and right sides of the truck detect the presence of flames. The gas sensor detects the presence of flammable gases, and the ultrasonic sensor helps the truck navigate by measuring the distance to obstacles. The truck moves forward, stops, turns left, or turns right based on sensor readings to approach the fire.

Upon detecting a fire, indicated by high readings from the flame sensors or gas sensor, the truck stops, assesses the surrounding area, and maneuvers towards the fire. The water pump is then activated to extinguish the fire. The truck continues to operate in this manner, responding to fire hazards in real-time.

## Hardware Components
Arduino (or compatible microcontroller)
Flame sensors (3 units: left, center, right)
MQ2 gas sensor
Ultrasonic sensor (for distance measurement)
Servo motor (for water pump direction control)
Water pump
DC motors for movement (4 motors)
Miscellaneous components (wires, resistors, etc.)
Software Components
The system's functionality is implemented using the Arduino programming language. The code handles sensor input, motor control, and servo operation. It follows a loop that continuously checks sensor readings and makes decisions based on the detected environmental conditions.

## Key Functions
move_forward(): Moves the truck forward.
move_Right(): Turns the truck right.
move_Left(): Turns the truck left.
move_Stop(): Stops the truck.
fire_off(): Activates the water pump to extinguish the fire.
fire_off_stop(): Stops the water pump.
measure_distance(): Measures the distance to obstacles using the ultrasonic sensor.
Setup
Connect all sensors and actuators to the Arduino according to the pin definitions in the code.
Attach the servo motor to the water pump mechanism.
Load the provided code onto the Arduino.
Power on the system and observe the truck's autonomous operation.
Usage
The fire truck operates autonomously once powered on. It will navigate the environment, detect fire hazards, and take appropriate action to extinguish fires. The system is designed for educational and experimental purposes and should be used in controlled environments.

## Contact
For questions or further information, please contact the authors.
