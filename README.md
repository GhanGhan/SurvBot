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
![Power](https://github.com/user-attachments/assets/15e312aa-5f7f-4c6a-aa32-5c9672b27439)
***Figure 2: Power Schematic***

### Microconroller
![Microcontroller](https://github.com/user-attachments/assets/09a7ce51-f9dc-4b2b-89cb-1e5c9eb2239a)
***Figure 3: Microconroller Schematic***

### Motor Control
![Motor Control](https://github.com/user-attachments/assets/7bbb7a27-39bd-4f7b-8f13-dcb1d081e6b7)
***Figure 4: Motor Control Schematic***

### Bluetooth
![Bluetooth](https://github.com/user-attachments/assets/55732fd5-0aa0-45e2-ab0e-66e6c3c63ade)
***Figure 5: Bluetooth Schematic***

### Sensors
![Sensors](https://github.com/user-attachments/assets/5e321a49-7e56-41b1-914b-e2740f7c2ed6)
***Figure 6: Sensors Schematic***

### ADC
![ADCs](https://github.com/user-attachments/assets/beede93a-a0f6-4cf3-9625-52e2d84cf019)
***Figure 7: ADC Schematic***



