# AVR Digital Countdown Timer

![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)
![MCU](https://img.shields.io/badge/ATmega32-AVR-red)
![Simulation](https://img.shields.io/badge/simulation-Proteus%20%C2%B7%20CodeVisionAVR-blue)
![License](https://img.shields.io/badge/license-MIT-green)

A digital countdown timer on an **ATmega32**: a 4×4 keypad sets the time, a 16×2 LCD gives feedback and a 4-digit 7-segment display counts down live.

![Schematic](images/AVR%20Countdown%20Timer%20Schema.png)

## Features

- 4-digit countdown (MM:SS style)
- Matrix keypad input interface
- Live output on the 4-digit 7-segment display
- LCD messages and validation (e.g. minutes above 59 are rejected)
- `C` clears and restarts the input

## Pin configuration

| Peripheral | Pins | Notes |
| --- | --- | --- |
| Keypad rows | `PORTB.0-3` | scan outputs |
| Keypad columns | `PORTB.4-7` | inputs with pull-ups |
| 7-segment | `PORTC` | segment data a–g |
| Digit select | `PORTD.1-4` | 4 digits |
| LCD | via `alcd.h` | default CodeVision mapping |

## Keypad map

```
[7] [8] [9] [ / ]
[4] [5] [6] [ * ]
[1] [2] [3] [ - ]
[C] [0] [=] [ + ]
```

## Usage

1. Power on the board.
2. Type four digits (e.g. `0123` → 1 minute 23 seconds).
3. Press `=` to start; the LCD shows `Running...` and the 7-segment counts down.
4. Press `C` to clear and enter a new time.

## Build and simulate

1. Open `KB.cproj` in **CodeVisionAVR**, target **ATmega32**, and compile — the `.hex` appears in `Debug/`.
2. In **Proteus**, place an ATmega32, attach the `.hex` as *Program File*, then wire the keypad, LCD and 7-segment display (`P2.pdsprj` contains the reference schematic).
3. Run the simulation.

## Files

```
KB.c / KB.cproj / KB.atsln   # CodeVisionAVR project
P2.pdsprj                    # Proteus schematic
images/                      # wiring diagram
LICENSE.txt                  # MIT
```

## License

MIT — see [LICENSE.txt](LICENSE.txt). © 2025 Mostafa Ahmadi
