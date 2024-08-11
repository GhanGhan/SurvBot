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
![Power](https://github.com/user-attachments/assets/6de69447-7d2e-4e1a-8f29-dfeed855208b)

***Figure 2: Power Schematic***

### Microconroller
![Microcontroller](https://github.com/user-attachments/assets/b4e06eb7-2d89-4f07-b04d-a1b81fa692a9)

***Figure 3: Microconroller Schematic***

### Motor Control
![Motor Control](https://github.com/user-attachments/assets/47f0094b-3e79-49df-8891-e05d03818068)

***Figure 4: Motor Control Schematic***

### Bluetooth
![Bluetooth](https://github.com/user-attachments/assets/734077de-602a-4b5b-a0ef-c4449dd21269)

***Figure 5: Bluetooth Schematic***

### Sensors
![Sensors](https://github.com/user-attachments/assets/108134c9-4b39-4255-b702-e9150e9a9ca8)

***Figure 6: Sensors Schematic***

### Current Feedback
![Current_FDB 6](https://github.com/user-attachments/assets/bce510aa-703a-4d61-b3f4-fdee5434417d)

***Figure 7: Current Feedback Schematic***

### External Memory
![External_Memory](https://github.com/user-attachments/assets/db5fc1cf-efd5-4480-a7cf-50e9d49632f4)

***Figure 7: Current Feedback Schematic***



