#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include "utils.h"

using namespace std;

class Calculator {
private:
    float a = 0, b = 0;  // Initialize with default values
    char choice;
    
    void displayHeader() {
        Utils::setColor(11); // Bright Cyan
        Utils::drawLine('*');
        cout << "\tSimple Calculator v2.0" << endl;
        cout << "\tCreated by Adrian Lesniak" << endl;
        Utils::drawLine('*');
        Utils::setColor(7); // White

        cout << "\nThis program allows you to perform basic mathematical operations:" << endl;
        cout << "Addition, Subtraction, Multiplication, and Division" << endl;
        cout << "Results are displayed immediately and can be repeated." << endl;
        Utils::drawLine();
    }

public:
    void inputValues() {
        try {
            Utils::setColor(14); // Yellow
            cout << "Enter the first value: ";
            Utils::setColor(7);
            if(!(cin >> a)) throw "Invalid input";
            
            Utils::setColor(14);
            cout << "Enter the second value: ";
            Utils::setColor(7);
            if(!(cin >> b)) throw "Invalid input";
        }
        catch(...) {
            cin.clear();
            cin.ignore(10000, '\n');
            Utils::setColor(12);
            cout << "Error: Please enter valid numbers!" << endl;
            Utils::setColor(7);
            Utils::logError("Invalid number input");
            throw;
        }
        system("cls");
    }

    void displayMenu() {
        displayHeader();
        
        // Add current values display at the top
        Utils::setColor(14); // Yellow
        Utils::drawLine('=', 30);
        cout << "Current values:" << endl;
        cout << "A = " << a << endl;
        cout << "B = " << b << endl;
        Utils::drawLine('=', 30);

        Utils::setColor(10); // Bright Green
        cout << "\nMAIN MENU:" << endl;
        Utils::drawLine('-', 30);
        cout << "1. Add\t\t(" << a << " + " << b << ")" << endl;
        cout << "2. Subtract\t(" << a << " - " << b << ")" << endl;
        cout << "3. Multiply\t(" << a << " * " << b << ")" << endl;
        cout << "4. Divide\t(" << a << " / " << b << ")" << endl;
        cout << "5. Change values" << endl;
        cout << "6. Exit" << endl;
        Utils::drawLine('-', 30);

        Utils::setColor(11);
        cout << "\nSelect operation (1-6): ";
        Utils::setColor(7);
        choice = _getch();
        system("cls");
    }

    void processChoice() {
        Utils::setColor(10);
        try {
            switch (choice) {
                case '1':
                    cout << "Addition: " << a << " + " << b << " = " << a + b << endl;
                    break;
                case '2':
                    cout << "Subtraction: " << a << " - " << b << " = " << a - b << endl;
                    break;
                case '3':
                    cout << "Multiplication: " << a << " * " << b << " = " << a * b << endl;
                    break;
                case '4':
                    if(b == 0) throw "Division by zero";
                    cout << "Division: " << a << " / " << b << " = " << fixed << setprecision(2) << a / b << endl;
                    break;
                case '5':
                    inputValues();
                    return;
                case '6':
                    Utils::setColor(14);
                    cout << "Thank you for using the calculator!" << endl;
                    exit(0);
                default:
                    throw "Invalid option";
            }
        }
        catch(const char* error) {
            Utils::setColor(12);
            cout << "Error: " << error << endl;
            Utils::logError(error);
        }
        
        Utils::setColor(7);
        cout << "\nPress any key to continue...";
        _getch();
        system("cls");
    }
};

int main() {
    Calculator calc;
    calc.inputValues(); // Ask for initial values once
    
    while(true) {
        try {
            calc.displayMenu();
            calc.processChoice();
        }
        catch(...) {
            continue;
        }
    }
    return 0;
}
