# SurvBot
Remote controlled robot that surveys the environment it is travelling in.

# Part One - Robot Control Unit (RCU)
## Project Overview
- Design and implement a PCB that has closed-loop control over 2 DC motors
- Monitors and saves data about itself and the environment it is in:
  - Current flowing though the motors
  - Ambient temperature
  - Ambient light hitting the robot
  - Humidity
  - Orientation (or just the tilt angle, TBD)
- Possess Bluetooth communication
- Entire system is powered by a 9V-12V battery

## Block Diagaram
![Block Diagaram](https://github.com/user-attachments/assets/89ef3221-fca1-412c-b29d-0304cf2fd357)

***Figure 1: SYSTEM BLOCK DIAGRAM (SIMPLE)***

## Schematic Diagrams
### Power
![Power 1](https://github.com/user-attachments/assets/ac84a856-f3f7-4ddb-8305-b34f4061553d)
***Figure 2: Power Schematic***
- Can be connected to a < 20V at the battery terminals, as well as 5V at either USB connector
- Schottky diodes allow for all three power sources to be connected at once
  - Battery terminal has the highest priority, followed by USB1, then USB2
  - They also provide reverse voltage protection
- Battery can power all of the modules, USB1 and USB2 power all modules except the motor control module
- U100 provides 6V with a maximum output of 3A
- U101 provides 3.3V with a maximum output of 2A
- U102 provides 3.3VA with a maximum output of 1.35A


### Microconroller
![Microcontroller 2](https://github.com/user-attachments/assets/95b3cc38-1538-41ee-b512-a862448206da)
***Figure 3: Microconroller Schematic***
- Powered by 3.3V
- Using STM32G0B1CBT6 microcontroller with a clock speed of 16MHz
- Using SWD Interface to program and debug
- Communicates to peripheral ICs using I2C, UART and SPI
- Can use PWM or PH/EN protocol to control motors
- Can connect to a host computer via the USB interface


### Motor Control
![Motor_Control 3](https://github.com/user-attachments/assets/f751400b-4e1b-4aec-9535-00bd29f93e72)
***Figure 4: Motor Control Schematic***
- Powered by 6V
- The DRV8876 driver, one for each motor, takes control input signals form microcontroller
- Each motor driver can draw up to 1.5A before shutting down
- Each driver outputs current proportional to the current passing through its associated motor, which is converted to a voltage and sent to a voltage buffer
- Each motor has quadrature encoders, whose signals are fed to the microcontroller



### Bluetooth
![Bluetooth 4](https://github.com/user-attachments/assets/2fa1292d-a9bd-44f6-bc49-8cb4086a68c3)
***Figure 5: Bluetooth Schematic***
- Powered by 3.3V
- Using ESP32-Mini as a UART-Bluetooth bridge to communicate with a remote controller
- Can be programmed using USB 2.0 via the USB-to-UART IC: CH340C
- By sliding a SPDT switch, can switch between programming mode and communication mode



### Sensors
![Sensors 5](https://github.com/user-attachments/assets/f80c8aa7-6785-46ac-9d46-46bed380aeb3)
***Figure 6: Sensors Schematic***
- Powered by 3.3V
- Communicate with microcontroller via I2C interface
- APDS-9306-065: Ambient light sensor, automatically rejects 60Hz flicker
- SHT3D-DIS: Temperature and humidity sensor
- LSM6D53: 6-axis accelerometer and gyroscope


### Current Feedback
![Current_FDB 6](https://github.com/user-attachments/assets/ba6c2342-09d3-432e-842c-14d64108d192)
***Figure 7: Current Feedback Schematic***
- Powered by 3.3VA
- Takes buffered current-sense output of left and right motor driver as input
  - Signals are filtered to attenuate switching noise before entering the buffer
- Using ADC121C02CIMK to convert analog signal to 12bit digital signal
- Communicates with microcontroller via I2C



### External Memory
![External_Memory 7](https://github.com/user-attachments/assets/ce59d9ab-3ccf-4c5b-8fd0-67382fc3f497)
***Figure 7: External Memory Schematic***
- Powered by 3.3V
- 32Mb NOR Flash memory
- Communicates with microcontroller via SPI




