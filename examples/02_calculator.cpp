// Simple calculator with functions
#include <iostream>

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
    return a / b;
}

int main() {
    double num1, num2;
    char operation;

    std::cout << "=== Simple Calculator ===" << std::endl;
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result;
    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            std::cout << "Invalid operation!" << std::endl;
            return 1;
    }

    std::cout << "Result: " << result << std::endl;
    return 0;
}

// Compile: g++ -std=c++17 02_calculator.cpp -o calculator
// Run: ./calculator
