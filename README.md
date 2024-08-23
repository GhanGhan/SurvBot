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

### Microconroller
![Microcontroller 2](https://github.com/user-attachments/assets/95b3cc38-1538-41ee-b512-a862448206da)


***Figure 3: Microconroller Schematic***

### Motor Control
![Motor_Control 3](https://github.com/user-attachments/assets/f751400b-4e1b-4aec-9535-00bd29f93e72)


***Figure 4: Motor Control Schematic***

### Bluetooth
![Bluetooth 4](https://github.com/user-attachments/assets/2fa1292d-a9bd-44f6-bc49-8cb4086a68c3)


***Figure 5: Bluetooth Schematic***

### Sensors
![Sensors 5](https://github.com/user-attachments/assets/f80c8aa7-6785-46ac-9d46-46bed380aeb3)


***Figure 6: Sensors Schematic***

### Current Feedback
![Current_FDB 6](https://github.com/user-attachments/assets/ba6c2342-09d3-432e-842c-14d64108d192)


***Figure 7: Current Feedback Schematic***

### External Memory
![External_Memory 7](https://github.com/user-attachments/assets/ce59d9ab-3ccf-4c5b-8fd0-67382fc3f497)


***Figure 7: External Memory Schematic***



