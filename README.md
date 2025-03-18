# SurvBot
Remote controlled robot that surveys the environment it is travelling in.  Designed in KiCad and Altium Designer.

# Part One - Robot Control Unit (RCU)
***Figure 1: Altium Designer 3D View***
![3d View](https://github.com/user-attachments/assets/8fb0b665-a536-49a9-b675-c503737b6a33)


***Figure 2: KiCad 3D View***
![Full3D](https://github.com/user-attachments/assets/90f6d3ef-7f1c-4ac4-8838-4249ae4c55d5)


## Block Diagaram
***Figure 3: SYSTEM BLOCK DIAGRAM (SIMPLE)***

![Block_Diagram2](https://github.com/user-attachments/assets/daec5c4c-c453-48a4-85f0-1a4a5af760ed)




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

***Figure 4: SYSTEM OVERVIEW***
![Overview](https://github.com/user-attachments/assets/f1233051-815b-4ca2-b81c-a65678752b47)



## Schematic Diagrams
### Power
***Figure 5: Power Schematic***
![Power 1](https://github.com/user-attachments/assets/ac84a856-f3f7-4ddb-8305-b34f4061553d)
- Can be connected to a < 20V at the battery terminals, as well as 5V at either USB connector
- Schottky diodes allow for all three power sources to be connected at once
  - Battery terminal has the highest priority, followed by USB1, then USB2
  - They also provide reverse voltage protection
- Battery can power all of the modules, USB1 and USB2 power all modules except the motor control module
- U100 provides 6V with a maximum output of 3A
- U101 provides 3.3V with a maximum output of 2A
- U102 provides 3.3VA with a maximum output of 1.35A


### Microconroller
***Figure 6: Microconroller Schematic***
![Microcontroller 2](https://github.com/user-attachments/assets/95b3cc38-1538-41ee-b512-a862448206da)
- Powered by 3.3V
- Using STM32G0B1CBT6 microcontroller with a clock speed of 16MHz
- Using SWD Interface to program and debug
- Communicates to peripheral ICs using I2C, UART and SPI
- Can use PWM or PH/EN protocol to control motors
- Can connect to a host computer via the USB interface


### Motor Control
***Figure 7: Motor Control Schematic***
![Motor_Control 3](https://github.com/user-attachments/assets/f751400b-4e1b-4aec-9535-00bd29f93e72)
- Powered by 6V
- The DRV8876 driver, one for each motor, takes control input signals form microcontroller
- Each motor driver can draw up to 1.5A before shutting down
- Each driver outputs current proportional to the current passing through its associated motor, which is converted to a voltage and sent to a voltage buffer
- Each motor has quadrature encoders, whose signals are fed to the microcontroller



### Bluetooth
***Figure 8: Bluetooth Schematic***
![Bluetooth 4](https://github.com/user-attachments/assets/2fa1292d-a9bd-44f6-bc49-8cb4086a68c3)
- Powered by 3.3V
- Using ESP32-Mini as a UART-Bluetooth bridge to communicate with a remote controller
- Can be programmed using USB 2.0 via the USB-to-UART IC: CH340C
- By sliding a SPDT switch, can switch between programming mode and communication mode



### Sensors
***Figure 9: Sensors Schematic***
![Sensors 5](https://github.com/user-attachments/assets/f80c8aa7-6785-46ac-9d46-46bed380aeb3)
- Powered by 3.3V
- Communicate with microcontroller via I2C interface
- APDS-9306-065: Ambient light sensor, automatically rejects 60Hz flicker
- SHT3D-DIS: Temperature and humidity sensor
- LSM6D53: 6-axis accelerometer and gyroscope


### Current Feedback
***Figure 10: Current Feedback Schematic***
![Current_FDB 6](https://github.com/user-attachments/assets/ba6c2342-09d3-432e-842c-14d64108d192)
- Powered by 3.3VA
- Takes buffered current-sense output of left and right motor driver as input
  - Signals are filtered to attenuate switching noise before entering the buffer
- Using ADC121C02CIMK to convert analog signal to 12bit digital signal
- Communicates with microcontroller via I2C



### External Memory
***Figure 11: External Memory Schematic***
![External_Memory 7](https://github.com/user-attachments/assets/ce59d9ab-3ccf-4c5b-8fd0-67382fc3f497)
- Powered by 3.3V
- 32Mb NOR Flash memory
- Communicates with microcontroller via SPI

# Part Two - Remote Controller
***Figure 12: 3D View***
![3D View Front](https://github.com/user-attachments/assets/3c9de429-c06d-4cf7-b5a8-fc2a2e617862)

Battery powered hand-held device that controls and monitors the state of the SurvBot. Commands are sent and data is received over Bluetooth. The design includes joysticks to control the robot’s velocity, buttons to change the mode it is in and a screen to display the sensor data. Can be used outdoors or indoors.

## Project Overview
***Figure 13: Remote controller Bloack Diagram***
![Block Diagram](https://github.com/user-attachments/assets/d62cd169-dad3-4300-8110-bfc14246c96f)
The user interface will contain joysticks and buttons to control the robot’s velocity and the state it is in.   Such states will determine whether the robot responds to velocity inputs, recording sensor data, is in low power mode etc.  Velocity commands and state changes are sent from the controller to the robot via Bluetooth.  The controller will receive sensor data; encoders, temperature, humidity and motor current from the robot in and display it on the onboard screen in real time.
The system will:
- be powered by a 9V battery
- use 2 thumb joysticks, one to control the robot’s linear velocity and another to control it’s angular velocity
- provide a USB interface to to program the microcontroller
- communicate with the SurvBot over Bluetooth
- provide a screen to view the data from the SurvBot’s motion and environment sensors, and Bluetooth connection status


## Schematic Diagrams
### Power
***Figure 14: Power Schematic***
![Power](https://github.com/user-attachments/assets/72ecf214-fc5a-486a-a89e-54a019f90e5d)
- Primary power source is a rechargeable 9V battery
- Secondary power source is a USB vable
- Power multiplexing circuitry used to decide the power source
- Power Rails 3.3V and 3V (for the LCD screen)


### Microcontroller
***Figure 7: Microconroller Schematic***
![uC and BT](https://github.com/user-attachments/assets/459cad85-2a47-4353-a654-0e8753169450)
- Programmed via a USB cable whose signals are converted to UART
- Peripherals: ADC, SPI and GPIO
- Has integrated Bluetooth antenna


### User Interface
***Figure 7: User Interface: Screen, Buttons, and Joysticks***
![User Interface](https://github.com/user-attachments/assets/6d6959cb-9086-4036-bf81-b993c2741b3c)
- LCD screen displays information such as state of Bluetooth connection, current speed, temperature, recorded data etc.
- Features 8 buttons to control the state of the robot
- Left joysticks controls rotational speed, right joystick controls linear speed

