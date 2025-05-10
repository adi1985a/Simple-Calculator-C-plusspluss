# Simple Calculator

## Description
A C++ console application for performing basic mathematical operations: addition, subtraction, multiplication, and division. Features a colorful interface, input validation, and error logging. Created by Adrian Lesniak.

## Features
- Perform addition, subtraction, multiplication, and division
- Update input values
- Display current values in menu
- Log errors (via `utils.h`)
- Colorful console interface

## Requirements
- C++ compiler (e.g., g++)
- Header file: `utils.h` (not provided)
- Windows OS (uses `windows.h` and `conio.h`)

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Ensure `utils.h` is in the project directory.
3. Compile the program:
   ```bash
   g++ main.cpp -o simple_calculator
   ```

## Usage
1. Run the program:
   ```bash
   ./simple_calculator
   ```
2. Enter two numbers (initial values).
3. Choose options 1-6 from the menu:
   - 1: Add
   - 2: Subtract
   - 3: Multiply
   - 4: Divide
   - 5: Change values
   - 6: Exit
4. Results are displayed with division rounded to 2 decimal places.

## Notes
- Requires `utils.h` for functions like `setColor()`, `drawLine()`, and `logError()`.
- Division by zero and invalid inputs are handled with error messages.
- Uses Windows-specific console functions for color and keypress handling.

## Author
Adrian Lesniak

## License
MIT License