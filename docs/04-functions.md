# Chapter 4: Functions

## What are Functions?

Functions are reusable blocks of code that perform specific tasks. They help:
- **Organize code** into logical units
- **Avoid repetition** (DRY - Don't Repeat Yourself)
- **Improve readability** and maintainability
- **Enable testing** of individual components

## Function Basics

### Function Declaration and Definition

```cpp
#include <iostream>

// Function declaration (prototype)
void greet();
int add(int a, int b);

int main() {
    greet();
    int result = add(5, 3);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

// Function definitions
void greet() {
    std::cout << "Hello, World!" << std::endl;
}

int add(int a, int b) {
    return a + b;
}
```

### Function Components

```cpp
// return_type function_name(parameter_list) {
//     function_body
//     return value;
// }

int multiply(int x, int y) {
    int result = x * y;
    return result;
}
```

## Return Types

### Void Functions (No Return)

```cpp
void printMessage(std::string message) {
    std::cout << message << std::endl;
    // No return statement needed
}

void printLine() {
    std::cout << "--------------------" << std::endl;
    return;  // Optional for void functions
}
```

### Functions Returning Values

```cpp
int square(int num) {
    return num * num;
}

double divide(double a, double b) {
    if (b == 0) {
        return 0.0;  // Handle division by zero
    }
    return a / b;
}

bool isEven(int num) {
    return num % 2 == 0;
}

char getGrade(int score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}
```

## Parameters

### Pass by Value

```cpp
// Creates a copy of the argument
void increment(int x) {
    x++;  // Only modifies the copy
    std::cout << "Inside: " << x << std::endl;
}

int main() {
    int num = 5;
    increment(num);
    std::cout << "Outside: " << num << std::endl;  // Still 5
    return 0;
}
```

### Pass by Reference

```cpp
// Modifies the original variable
void increment(int& x) {
    x++;  // Modifies the original
    std::cout << "Inside: " << x << std::endl;
}

int main() {
    int num = 5;
    increment(num);
    std::cout << "Outside: " << num << std::endl;  // Now 6
    return 0;
}
```

### Pass by Const Reference

```cpp
// Efficient for large objects, prevents modification
void printVector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // vec.push_back(10);  // ERROR! Cannot modify const
}
```

### Default Parameters

```cpp
// Default values must be in declaration
void greet(std::string name = "Guest", int times = 1) {
    for (int i = 0; i < times; i++) {
        std::cout << "Hello, " << name << "!" << std::endl;
    }
}

int main() {
    greet();                    // Hello, Guest!
    greet("Alice");             // Hello, Alice!
    greet("Bob", 3);            // Hello, Bob! (3 times)
    return 0;
}
```

## Function Overloading

```cpp
// Same name, different parameters
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    std::cout << add(5, 3) << std::endl;        // Calls int version
    std::cout << add(5.5, 3.2) << std::endl;    // Calls double version
    std::cout << add(1, 2, 3) << std::endl;     // Calls 3-parameter version
    return 0;
}
```

## Inline Functions

```cpp
// Hint to compiler to expand function at call site
inline int square(int x) {
    return x * x;
}

// Modern C++: use constexpr for compile-time evaluation
constexpr int cube(int x) {
    return x * x * x;
}
```

## Function Templates (Generic Functions)

```cpp
// Works with any type
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << maximum(5, 3) << std::endl;           // int
    std::cout << maximum(5.5, 3.2) << std::endl;       // double
    std::cout << maximum('a', 'z') << std::endl;       // char
    return 0;
}
```

## Recursion

```cpp
// Function calling itself
int factorial(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Sum of digits
int sumDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return (num % 10) + sumDigits(num / 10);
}
```

## Lambda Functions (C++11)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Basic lambda
    auto greet = []() {
        std::cout << "Hello from lambda!" << std::endl;
    };
    greet();

    // Lambda with parameters
    auto add = [](int a, int b) {
        return a + b;
    };
    std::cout << add(5, 3) << std::endl;

    // Lambda with capture
    int x = 10;
    auto addX = [x](int y) {
        return x + y;
    };
    std::cout << addX(5) << std::endl;  // 15

    // Capture by reference
    int count = 0;
    auto increment = [&count]() {
        count++;
    };
    increment();
    increment();
    std::cout << count << std::endl;  // 2

    // Using lambdas with STL algorithms
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // For each
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n * 2 << " ";
    });
    std::cout << std::endl;

    return 0;
}
```

## Practical Examples

### Calculator Functions

```cpp
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
    double x = 10, y = 5;
    std::cout << "Add: " << add(x, y) << std::endl;
    std::cout << "Subtract: " << subtract(x, y) << std::endl;
    std::cout << "Multiply: " << multiply(x, y) << std::endl;
    std::cout << "Divide: " << divide(x, y) << std::endl;
    return 0;
}
```

### Array Processing

```cpp
#include <iostream>

// Print array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Find maximum
int findMax(const int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Sum array
int sumArray(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int numbers[] = {5, 2, 8, 1, 9};
    int size = 5;

    printArray(numbers, size);
    std::cout << "Max: " << findMax(numbers, size) << std::endl;
    std::cout << "Sum: " << sumArray(numbers, size) << std::endl;

    return 0;
}
```

## Best Practices

1. **One Task Per Function**: Each function should do one thing well
2. **Meaningful Names**: Use descriptive names (`calculateTotal` not `calc`)
3. **Keep Functions Short**: Ideally under 20-30 lines
4. **Use const**: Mark parameters that shouldn't be modified as `const`
5. **Pass Large Objects by Reference**: Avoid copying large data structures
6. **Document Complex Functions**: Add comments explaining what they do

## Practice Exercises

1. **Temperature Converter**: Create functions to convert between Celsius, Fahrenheit, and Kelvin.

2. **Prime Number Functions**: `isPrime()`, `nextPrime()`, `printPrimes()`

3. **String Utilities**: `reverseString()`, `isPalindrome()`, `countVowels()`

4. **Array Utilities**: `reverseArray()`, `sortArray()`, `searchArray()`

5. **Math Functions**: `power()`, `gcd()`, `lcm()`, `isPerfectSquare()`

## Next Steps

Continue to [Chapter 5: Object-Oriented Programming](05-oop.md) to learn about classes and objects!
