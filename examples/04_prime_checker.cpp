// Prime number checker with functions
#include <iostream>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void printPrimes(int limit) {
    std::cout << "Prime numbers up to " << limit << ":" << std::endl;
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int number;

    std::cout << "Enter a number to check if it's prime: ";
    std::cin >> number;

    if (isPrime(number)) {
        std::cout << number << " is prime!" << std::endl;
    } else {
        std::cout << number << " is not prime." << std::endl;
    }

    std::cout << "\nGenerating primes up to 100:" << std::endl;
    printPrimes(100);

    return 0;
}

// Compile: g++ -std=c++17 04_prime_checker.cpp -o prime
// Run: ./prime
