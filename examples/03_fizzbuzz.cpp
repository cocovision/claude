// FizzBuzz - Classic programming challenge
#include <iostream>

int main() {
    std::cout << "=== FizzBuzz ===" << std::endl;

    for (int i = 1; i <= 100; i++) {
        if (i % 15 == 0) {
            std::cout << "FizzBuzz";
        } else if (i % 3 == 0) {
            std::cout << "Fizz";
        } else if (i % 5 == 0) {
            std::cout << "Buzz";
        } else {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    return 0;
}

// Compile: g++ -std=c++17 03_fizzbuzz.cpp -o fizzbuzz
// Run: ./fizzbuzz
