# ➕➖✖️➗ ConsoleCalc Pro: Your Essential Arithmetic Tool 🔢
_A straightforward C++ console calculator for quick and reliable basic mathematical operations, featuring a colorful UI and error handling._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📝 Project Description

**ConsoleCalc Pro** is a user-friendly C++ console application designed to perform fundamental arithmetic operations: addition, subtraction, multiplication, and division. It provides a clear, interactive experience with a colorful interface that displays current input values and results. The calculator includes robust input validation to handle incorrect entries and safeguards against common errors like division by zero. Any operational errors are logged for review. This tool is perfect for quick calculations without needing a complex GUI application.

## ✨ Key Features

*   ➕ **Addition**: Calculate the sum of two numbers.
*   ➖ **Subtraction**: Find the difference between two numbers.
*   ✖️ **Multiplication**: Compute the product of two numbers.
*   ➗ **Division**: Perform division, with results typically rounded to a set number of decimal places (e.g., 2).
*   🔄 **Update Input Values**: Easily change the two numbers used for calculations at any time.
*   📊 **Live Value Display**: The current input numbers are always visible in the main menu.
*   📄 **Error Logging**: Utilizes functions (presumably from `utils.h`) to log any errors encountered during operation (e.g., invalid input, division by zero).
*   🌈 **Colorful Console Interface**: Enhanced user experience with colored text for menus, prompts, and results (Windows-specific).
*   ✔️ **Input Validation**: Checks for valid numerical input and handles potential issues like division by zero.

## 🖼️ Screenshots

**Coming soon!**

_This section will be updated with screenshots showcasing the calculator's main menu, input prompts, calculation results, and error messages._

## ⚙️ System Requirements

*   **Operating System**: Windows (due to the use of `windows.h` for console color manipulation and `conio.h` for functions like `_getch()`).
*   **C++ Compiler**: Any modern C++ compiler that supports C++11 or newer (e.g., g++, MinGW, Clang, MSVC).
*   📄 **`utils.h` Header File (User-Provided)**: This project **requires** a header file named `utils.h`. **This file is not included in the repository and must be created by the user.** It should define essential utility functions used by the main calculator logic. See the "Installation and Running" section for more details.

## 🛠️ Installation and Running

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    ```
    (Replace `<repository-url>` with the actual URL of your repository)

2.  **Navigate to the Project Directory**:
    ```bash
    cd <repository-directory>
    ```
    (Replace `<repository-directory>` with the name of the cloned folder)

3.  **Create `utils.h`**:
    Before compiling, you **must** create a file named `utils.h` in the project's root directory. This file should define necessary utility functions. Here's an example of what it might contain:
    ```cpp
    #ifndef UTILS_H
    #define UTILS_H

    #include <string>
    #include <windows.h> // For SetConsoleTextAttribute
    #include <conio.h>   // For _getch() (if used for waitForKeyPress)
    #include <fstream>   // For logging
    #include <ctime>     // For timestamps in logs
    #include <iostream>  // For basic I/O if wrapper functions are here

    // Example: Console Color Codes
    const int CLR_DEFAULT = 7;
    const int CLR_MENU_HEADER = 11; // Light Cyan
    const int CLR_INPUT_PROMPT = 10;  // Light Green
    const int CLR_RESULT = 14;        // Yellow
    const int CLR_ERROR = 12;         // Light Red

    void setColor(int color);
    void drawLine(char c = '=', int length = 40); // Example for visual separation
    void logError(const std::string& message, const std::string& logFilePath = "calculator_errors.log");
    // Potentially a function like:
    // double getValidNumberInput(const std::string& prompt);
    // void clearScreen();
    // void waitForKeyPress(const std::string& message = "Press any key to continue...");

    #endif // UTILS_H
    ```
    *Adjust the constants (especially file paths and color codes) and function declarations to match what `main.cpp` expects from `utils.h`. You'll need to implement these functions, likely in a `utils.cpp` file.*

4.  **Compile the Program**:
    Open a terminal (like Command Prompt or PowerShell) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ main.cpp utils.cpp -o simple_calculator.exe -static-libgcc -static-libstdc++
    ```
    *(This assumes you have `utils.cpp` for the implementations of functions declared in `utils.h`. If all utility logic is inline in `utils.h`, then `g++ main.cpp -o simple_calculator.exe ...` might suffice, but this is less common).*

5.  **Run the Application**:
    After successful compilation, execute the generated program:
    ```bash
    ./simple_calculator.exe
    ```
    or simply in CMD:
    ```bash
    simple_calculator.exe
    ```

## ▶️ How to Use

1.  **Launch the Application**: Run the compiled executable.
2.  **Initial Input**: The program will first prompt you to enter two initial numbers that will be used for calculations.
3.  **Main Menu**: After setting the initial values, you'll see a menu with the following options. The current numbers will be displayed as part of the menu.
    *   **1: Add**: Adds the two current numbers and displays the sum.
    *   **2: Subtract**: Subtracts the second number from the first and displays the difference.
    *   **3: Multiply**: Multiplies the two current numbers and displays the product.
    *   **4: Divide**: Divides the first number by the second. Displays the result (often rounded to 2 decimal places). Handles division by zero errors.
    *   **5: Change values**: Allows you to enter new values for the two numbers.
    *   **6: Exit**: Terminates the application.
4.  **View Results**: After selecting an operation, the result will be displayed.
5.  **Continue or Exit**: You can perform more calculations, change values, or exit the program.

## 💡 Technical Details & Program Logic

*   **Input Handling**: The program takes two numbers as primary operands. These can be updated via a menu option.
*   **Arithmetic Operations**: Implements functions for addition, subtraction, multiplication, and division.
*   **Division by Zero**: Includes a check to prevent division by zero, displaying an error message and logging the event if attempted.
*   **Input Validation**: Ensures that the user inputs are valid numbers. Non-numeric input should be handled gracefully.
*   **`utils.h`**: This crucial user-provided header contains utility functions for console manipulation (e.g., `setColor()` for text colors, `drawLine()` for UI structure) and `logError()` for writing error details to a log file.
*   **Error Logging**: When errors occur (e.g., invalid input, division by zero), details are written to a log file specified (likely via `utils.h`).
*   **Console I/O**: Uses `iostream` for user interaction and `conio.h` (e.g., `_getch()`) for features like "press any key to continue". Windows-specific functions from `windows.h` are used for colored text.

## 🤝 Contributing

Contributions to **ConsoleCalc Pro** are welcome! If you have ideas for additional operations (e.g., exponents, square roots), UI improvements, or enhanced error handling:

1.  Fork the repository.
2.  Create a new branch for your feature: `git checkout -b feature/your-calculator-enhancement`
3.  Implement your changes and commit them: `git commit -m "Feature: Add your calculator enhancement"`
4.  Push your changes to your branch: `git push origin feature/your-calculator-enhancement`
5.  Open a Pull Request.

Please ensure your code is well-commented and aligns with the project's existing style.

## ✍️ Author

**Adrian Lesniak**
_C++ Developer & Console Application Enthusiast_

## 📃 License

This project is licensed under the **MIT License**.
The full text of the license is available at: [https://opensource.org/licenses/MIT](https://opensource.org/licenses/MIT)

---
🧮 _Making math simple, one calculation at a time!_
