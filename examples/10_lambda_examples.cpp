// Modern C++ - Lambda expressions
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::cout << "=== Lambda Expressions ===" << std::endl;

    // Basic lambda
    auto greet = []() {
        std::cout << "Hello from lambda!" << std::endl;
    };
    greet();

    // Lambda with parameters
    auto add = [](int a, int b) {
        return a + b;
    };
    std::cout << "5 + 3 = " << add(5, 3) << std::endl;

    // Lambda with capture by value
    int multiplier = 10;
    auto multiplyBy = [multiplier](int x) {
        return x * multiplier;
    };
    std::cout << "5 * " << multiplier << " = " << multiplyBy(5) << std::endl;

    // Lambda with capture by reference
    int counter = 0;
    auto increment = [&counter]() {
        counter++;
    };
    increment();
    increment();
    increment();
    std::cout << "Counter: " << counter << std::endl;

    // Using lambdas with STL algorithms
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "\n=== STL with Lambdas ===" << std::endl;

    // For each
    std::cout << "Numbers: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;

    // Count if - count even numbers
    int evenCount = std::count_if(numbers.begin(), numbers.end(),
                                   [](int n) { return n % 2 == 0; });
    std::cout << "Even numbers: " << evenCount << std::endl;

    // Find if - find first number > 5
    auto it = std::find_if(numbers.begin(), numbers.end(),
                           [](int n) { return n > 5; });
    if (it != numbers.end()) {
        std::cout << "First number > 5: " << *it << std::endl;
    }

    // Transform - square all numbers
    std::vector<int> squared(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squared.begin(),
                   [](int n) { return n * n; });

    std::cout << "Squared: ";
    for (int n : squared) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Sort with custom comparator (descending)
    std::vector<int> toSort = {5, 2, 8, 1, 9, 3};
    std::sort(toSort.begin(), toSort.end(),
              [](int a, int b) { return a > b; });

    std::cout << "Sorted descending: ";
    for (int n : toSort) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Lambda returning lambda (function factory)
    auto makeAdder = [](int x) {
        return [x](int y) {
            return x + y;
        };
    };

    auto add5 = makeAdder(5);
    auto add10 = makeAdder(10);

    std::cout << "\n=== Function Factory ===" << std::endl;
    std::cout << "add5(3) = " << add5(3) << std::endl;
    std::cout << "add10(3) = " << add10(3) << std::endl;

    // Storing lambdas in std::function
    std::vector<std::function<int(int)>> operations;
    operations.push_back([](int x) { return x * 2; });
    operations.push_back([](int x) { return x * x; });
    operations.push_back([](int x) { return x + 10; });

    std::cout << "\n=== Stored Lambdas ===" << std::endl;
    int value = 5;
    std::cout << "Input: " << value << std::endl;
    for (size_t i = 0; i < operations.size(); i++) {
        std::cout << "Operation " << i << ": " << operations[i](value) << std::endl;
    }

    return 0;
}

// Compile: g++ -std=c++17 10_lambda_examples.cpp -o lambda
// Run: ./lambda
