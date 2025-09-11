#Task 5: A brief about what previous task  

<details> from the task 4, if see the Verilog code used in it, it is having hardcoded instructions, which is not equivalent to the standard ISA encoding for RISCV. For example: for the add instruction `add r1, r2, r3 ` riscv encoding is 0x3100b3 where as in our simulation waveform we have got 0x 02208300 that make our design check failed for the System on Chip Design flow (not inside our course scope) </details>.  
# Smart Motion Detector with Servo Motor using Squadron Board Mini

This project demonstrates how to connect a PIR motion sensor and a servo motor to the **Squadron Board Mini** to create a motion-based automated mechanism.

## Components Used
- Squadron Board Mini
- PIR Motion Sensor
- Servo Motor
- Breadboard and Jumper Wires
- External Power Supply (optional for servo motor)

## Circuit Connections

| Component        | Pin/Connection on Squadron Mini | Connected To | Notes |
|-----------------|---------------------------------|--------------|------|
| PIR Sensor VCC   | 3.3V or 5V                      | VCC          | Power supply to PIR sensor |
| PIR Sensor GND   | GND                             | GND          | Ground connection |
| PIR Sensor OUT   | GPIO Pin (e.g., D3)             | Signal Input | Detects motion, digital output |
| Servo Motor VCC  | 5V                              | Power supply | Separate regulated power if needed |
| Servo Motor GND  | GND                             | Ground      | Common ground with board and sensor |
| Servo Motor PWM  | GPIO Pin (e.g., D2)             | Control Signal | PWM control for servo position |

## Notes
- Ensure that all grounds (GND) are connected together to avoid signal reference issues.
- If the servo motor requires more current than the board can supply, use an external power source and ensure common grounding.
- Verify the logic level compatibility of the PIR sensor output and the Squadron Mini’s GPIO input.
- Adjust GPIO pins (`D2`, `D3`) as per availability and application needs.

## How it Works
1. The PIR sensor detects motion and sends a HIGH signal through its output pin.
2. The Squadron Mini reads the signal and triggers the servo motor using PWM to perform a desired action, like opening a door or turning towards the motion.

## Future Improvements
- Add debounce logic to avoid false triggers.
- Implement wireless notifications or logging.
- Integrate with IoT platforms for remote monitoring.


