
# SafeCross: Pedestrian Assistance System for the Visually Impaired

## Overview

SafeCross is an assistive pedestrian crossing prototype designed to improve accessibility and crossing safety for visually impaired individuals. It combines an Arduino-based control system, ultrasonic sensing, audible alerts, and a tactile feedback mechanism to communicate crossing time and traffic movement.

## Key Features

### 1. Timed Pedestrian Crossing Assistance
- A push button placed near the traffic signal allows a pedestrian to initiate the crossing sequence.
- Pressing the button starts a 20-second crossing timer.
- Continuous audible beeps indicate that the crossing interval is active.
- During the final five seconds, the beep rate increases to warn that the available crossing time is nearly over.

### 2. Sensor-Based Crossing Time Extension
- An ultrasonic sensor monitors the pedestrian's presence in the crossing area.
- If a pedestrian is still detected when the timer expires, the system extends the crossing interval.
- This feature is designed to provide additional time for pedestrians who need longer to complete the crossing.

### 3. Tactile Traffic-Status Feedback
- A tactile feedback wheel provides a physical indication of traffic movement.
- When traffic is moving, the wheel rotates slowly.
- When traffic is stopped, the wheel stops rotating.
- This mechanism is designed to help visually impaired pedestrians perceive traffic status through touch rather than relying solely on visual signals.

## Hardware Components

- Arduino UNO R4 WiFi
- Ultrasonic sensor
- Push button
- Buzzer for audible alerts
- Traffic signal LED indicators
- Motorized tactile feedback wheel and associated components

## Technologies

- C/C++ (Arduino)
- Arduino IDE
- Embedded systems
- Sensor integration
- Hardware prototyping

## System Workflow

1. The pedestrian presses the push button near the traffic signal.
2. The controller initiates the 20-second crossing timer and activates audible alerts.
3. The beep rate increases during the final five seconds.
4. The ultrasonic sensor checks for a pedestrian remaining in the crossing area.
5. If the pedestrian is still detected at the end of the interval, the controller extends the time according to the implemented logic.
6. The tactile wheel communicates traffic movement through rotation or a stationary state. 


## Prototype

The following photographs show the physical SafeCross prototype, including the modeled pedestrian crossing, embedded controller, sensor setup, traffic signal indicators, and tactile feedback mechanism.

| Prototype View | Demonstration |
|---|---|
| ![SafeCross prototype view 1](Prototype%20Image%201.jpeg) | ![SafeCross prototype view 2](Prototype%20Image%202.jpeg) |


## Future Enhancements

- **Voice-Based Instructions:** Introduce spoken guidance to supplement audible beep alerts.
- **Real-Time Monitoring Dashboard (Ongoing):** Develop a dashboard to monitor system status, component health, crossing timer, and traffic signal state.
- **Enhanced Tactile Feedback:** Refine the tactile mechanism, drawing inspiration from tactile traffic feedback approaches used in Japan for visually impaired pedestrians.

## Project Outcome

SafeCross explores the application of embedded systems and accessible feedback mechanisms to pedestrian safety. The project received **Second Place at the IoT & Project Expo**.

## Project Status

Hardware prototype developed. Real-time monitoring dashboard is an ongoing enhancement.

## Disclaimer

SafeCross is an academic prototype and has not been established as a certified road-safety system. Further testing and validation would be required before real-world deployment.

## Acknowledgements

Developed as an academic project at the National Institute of Engineering, Mysuru.
