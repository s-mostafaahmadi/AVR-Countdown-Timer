# AVR Digital Countdown Timer with Keypad Input and 7-Segment Display

This project implements a simple **digital countdown timer** using the **ATmega32 microcontroller**, a **4x4 matrix keypad**, **7-segment display**, and an **LCD module**. The timer takes a time input from the keypad, displays it on an LCD, and then counts down visually using a 4-digit 7-segment display.

---

## 🧠 Features

- 4-digit countdown timer (HH:MM style).
- Matrix keypad input interface.
- Real-time visual display on 7-segment.
- LCD messages for user interaction and feedback.
- Input validation (e.g. prevents minute values over 59).
- Optional clearing and reset with 'C' key.

---

## 🔧 Hardware Requirements

- ATmega32 microcontroller  
- 4x4 Matrix Keypad  
- 4-digit 7-segment display (common cathode)  
- LCD 16x2 display  
- External 5V power supply  
- Pull-up resistors for keypad (internal or external as needed)  

### 🔌 Pin Configuration

| Peripheral     | Pins Used  | Description                |
|----------------|------------|----------------------------|
| Keypad Rows    | PORTB.0-3  | Output (scan lines)        |
| Keypad Columns | PORTB.4-7  | Input (with pull-ups)      |
| 7-Segment      | PORTC      | Segment data (a-g)         |
| Digit Select   | PORTD.1-4  | Controls 4 digits          |
| LCD            | Default (via `alcd.h`) | LCD control lines |

---

## 📦 How to Use

1. Power on the device.
2. Enter 4 digits using the keypad (e.g. "0123" → 1 minute 23 seconds).
3. Press `=` to start the countdown.
4. LCD displays "Running..." while the countdown is active.
5. The 7-segment display shows the live countdown.
6. Press `C` to clear and restart input.


## 🔤 Keypad Mapping
[7] [8] [9] [ / ]
[4] [5] [6] [ * ]
[1] [2] [3] [ - ]
[C] [0] [=] [ + ]



---

## 💡 Notes

- Invalid inputs (like minute values > 59) are handled and auto-corrected.
- The countdown decrements every ~1 second (based on 48 steps).
- Timer logic runs in a blocking infinite loop until it finishes or reset.

---

## 📁 Project Structure

- `main.c` – Source code with logic for keypad scanning, LCD, 7-segment display, and timer logic.
- `alcd.h` – LCD driver header (not included here, use appropriate driver).
- `delay.h` – Delay utility (likely from CodeVisionAVR or similar).
- `LICENSE` – MIT License (recommended).

---

## 📜 License

This project is licensed under the **MIT License**.  
© 2025 Mostafa Ahmadi

