dability.

---

## Arduino Digital Dice Roller

A hardware-based random number generator that uses an Arduino Uno, a 7-segment display, and tactile feedback to simulate a physical dice roll.

---

## What the Project Does

This project provides a digital alternative to traditional dice. When the user presses a button, the system triggers a rolling animation on a 7-segment display and then outputs a random integer between 1 and 6. It includes status LEDs to indicate whether the system is "Idle" or "Processing" a roll.

The software utilizes a 2D matrix mapping technique to control the 7-segment display, making it easy to adapt the hardware for displaying letters or custom symbols.

---

## Why the Project is Useful

* Hardware Interfacing: Demonstrates how to control multiple GPIO pins to drive complex components like 7-segment displays.
* Non-Blocking Logic: Uses state-based logic to handle button presses and LED transitions.
* Memory Efficiency: Uses a matrix-based approach to store digit patterns, reducing code complexity and improving readability.
* Visual Animation: Includes a specific routine to simulate the physical "spinning" of a die before the final result is revealed.

---

## How Users Can Get Started

### Hardware Requirements

* Arduino Uno (or compatible board)
* 1x Common Cathode 7-Segment Display
* 1x Momentary Pushbutton
* 1x Green LED, 1x Red LED
* 10x Resistors (for display segments and LEDs)
* Jumper wires and Breadboard

### Installation

1. Clone this repository to your local machine.
2. Open the dice_roller.ino file in the Arduino IDE.
3. Connect your Arduino Uno via USB.
4. Select Tools > Board > Arduino Uno.
5. Select the correct Port for your device.
6. Click Upload.

### Circuit Configuration

| Component | Arduino Pin |
| --- | --- |
| Pushbutton | Pin 2 (Internal Pullup) |
| Red LED | Pin 8 |
| Green LED | Pin 9 |
| 7-Segment Display (a-g, DP) | Pins 13, 12, 11, 10, 7, 6, 5, 4 |

---

## Code Example: Matrix Mapping

The display logic is handled by a 2D array where each row represents a number and each column represents the state of a specific segment.

```cpp
const int numArr[7][8] = {
  { 1, 0, 0, 0, 0, 0, 1, 0 }, // Number 1
  { 1, 1, 0, 1, 1, 1, 0, 0 }, // Number 2
  // ... segments continue
};

```

---

## Where Users Can Get Help

* Documentation: For hardware datasheets, refer to the docs/ folder.
* Issues: If you encounter bugs or hardware mapping errors, please open an issue in the GitHub repository.
* Arduino Reference: For general programming questions, visit the [Official Arduino Reference](https://www.arduino.cc/reference/en/).

---

## Who Maintains and Contributes

* Lead Maintainer: Anirudh Kamalakannan

---

