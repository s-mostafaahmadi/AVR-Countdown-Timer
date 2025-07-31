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

## 🚀 How to Run in Simulator Using CodeVisionAVR and Proteus

### Step 1: Compile the Project in CodeVisionAVR
1. Open the project in CodeVisionAVR (`KB.cproj`).
2. Ensure the microcontroller is set to **ATmega32** in the project settings.
3. Edit the code if needed.
4. Click **Compile** to build the project.
5. After a successful compilation, the output `.hex` file will be generated in the `Debug` folder.

### Step 2: Run Simulation in Proteus
1. Open Proteus software.
2. Load your project schematic or create a new one.
3. Place the **ATmega32** microcontroller component in the schematic.
4. Attach the compiled `.hex` file to the microcontroller:
   - Double-click on the ATmega32 component.
   - In the **Program File** field, browse and select the `.hex` file generated in CodeVisionAVR.
5. Connect the input devices like keypad and output devices such as 7-segment displays and LCD as per your circuit design.
6. Start the simulation and test the timer functionality.

---

**Note:** You can use Proteus’ built-in libraries for keypad and displays or design the schematic according to your hardware connections.

---

If you encounter any issues or have questions, feel free to ask!

---

## 📜 License

This project is licensed under the **MIT License**.  
© 2025 Mostafa Ahmadi

