# ESP32 Bluetooth LED Control System

## Overview

This repository contains the source code for an ESP32-based Bluetooth communication module developed by the **BHJ_WORK** YouTube channel. The project demonstrates remote peripheral control over Bluetooth, using an LED connected to GPIO pin 2 as a target interface.

---

## Technical Specifications & Wiring

### Hardware Requirements

* **Microcontroller:** ESP32 Development Board (e.g., ESP32 DevKit v1 / NodeMCU-32S)
* **Output Peripheral:** Standard LED
* **Current-Limiting Resistor:** 220 Ohm (recommended)

### Pinout Configuration

| ESP32 Pin | Target Connection | Notes |
| --- | --- | --- |
| `GPIO 2` | LED Anode (+ long leg) | Standard onboard LED pin on most ESP32 boards |
| `GND` | LED Cathode (- short leg) | Connect via 220 Ohm resistor |

---

## Getting Started

### 1. Prerequisites

1. Download and install [Arduino IDE](https://www.arduino.cc/en/software).
2. Open Arduino IDE, go to **File > Preferences**, and add the following URL to **Additional Boards Manager URLs**:
```text
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

```


3. Go to **Tools > Board > Boards Manager**, search for `esp32` by Espressif Systems, and click **Install**.

---

### 2. Opening and Flashing the Project

1. Download this repository as a ZIP archive (click the green **Code** button at the top of the GitHub page, then select **Download ZIP**).
2. Extract the downloaded ZIP file to any convenient folder on your computer.
3. Open Arduino IDE and go to **File > Open**, then select the `.ino` sketch file from the extracted folder.
4. Connect your ESP32 board to your computer using a USB cable.
5. In Arduino IDE, select your board model under **Tools > Board > ESP32 Arduino**.
6. Select the assigned serial port under **Tools > Port**.
7. Click the **Upload** button.
8. Open the Serial Monitor (**Tools > Serial Monitor**) and set the baud rate to `115200` to check the system status.

---

## Mobile Application & Full Guide

A comprehensive video guide covering the firmware architecture and the step-by-step development of a custom mobile application for remote Bluetooth control is available on YouTube.

* **Full Video Tutorial:** [Link will be attached here upon release]
* **Official Channel:** [BHJ_WORK YouTube Channel](https://www.google.com/search?q=https://www.youtube.com/%40BHJ_WORK)

---

## License and Attribution

All code, documentation, and hardware design configurations in this repository belong to **BHJ_WORK**.

This software is provided for educational and development purposes. Re-use or distribution in public projects requires proper attribution back to the original source channel.
