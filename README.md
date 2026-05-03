How to use waveform samples application : 
# PowerMonitorAnalyser Project

A C program that reads power waveform data from a CSV file and analyses it. It calculates things like RMS voltage, peak-to-peak voltage, DC offset, and checks for clipping in a three-phase electrical signal.

\---

## What the program does

* Reads a CSV file with three-phase voltage data
* Calculates RMS voltage for each phase (A, B, C)
* Calculates peak-to-peak voltage for each phase
* Calculates DC offset for each phase
* Detects how many samples are clipped (voltage too high)
* Checks if each phase is within ±10% of 230V tolerance
* Writes all results to a text file

\---

## Project Structure

```
PowerMonitorAnalyser/
├── main.c          # entry point, controls the flow
├── io.c            # file reading and writing functions
├── io.h
├── waveform.c      # all the calculation functions (RMS, VPP, etc.)
├── waveform.h
└── CMakeLists.txt
```

\---

## How to run (CLion)

1. Open the project folder in CLion
2. CLion should detect the `CMakeLists.txt` automatically
3. Go to **Run > Edit Configurations**
4. In the **Program arguments** field, type the path to your CSV file
5. Click **Run**

The program takes the CSV filename as a command line argument. Without it, it will crash.

\---

## CSV File Format

The file should have a header row, then one row per sample with 8 comma-separated values:

```
time\_stamp, phase\_A\_voltage, phase\_B\_voltage, phase\_C\_voltage, line\_current, frequency, power\_factor, thd\_percent
```

\---

## Dependencies

* Standard C library (`stdio.h`, `stdlib.h`)
* Math library (`math.h`) — make sure `-lm` is in your CMakeLists.txt

\---

## Notes

* The program uses `malloc` to allocate memory based on how many rows are in the file, so it works with any size CSV
* Memory is freed at the end with `free()`
* If the file does not exist, the program will handle it
* Clipping threshold is set to 324.9V (based on 230V RMS peak)

\---

## Built with

* C (C99)
* CLion IDE
* CMake

## Developed history managed by Github : 
https://github.com/abdullahhj/ProgrammingProject