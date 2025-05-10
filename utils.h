#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>

namespace Utils {
    void setColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    void drawLine(char symbol = '-', int length = 50) {
        std::cout << std::string(length, symbol) << std::endl;
    }

    void logError(const std::string& error) {
        std::ofstream logFile("calculator_errors.log", std::ios::app);
        logFile << "[" << __DATE__ << " " << __TIME__ << "] Error: " << error << std::endl;
        logFile.close();
    }
}
