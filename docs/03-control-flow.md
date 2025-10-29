# Chapter 3: Control Flow

## Conditional Statements

### if Statement

```cpp
#include <iostream>

int main() {
    int age = 18;

    if (age >= 18) {
        std::cout << "You are an adult." << std::endl;
    }

    return 0;
}
```

### if-else Statement

```cpp
int score = 75;

if (score >= 60) {
    std::cout << "You passed!" << std::endl;
} else {
    std::cout << "You failed." << std::endl;
}
```

### if-else if-else Chain

```cpp
int score = 85;

if (score >= 90) {
    std::cout << "Grade: A" << std::endl;
} else if (score >= 80) {
    std::cout << "Grade: B" << std::endl;
} else if (score >= 70) {
    std::cout << "Grade: C" << std::endl;
} else if (score >= 60) {
    std::cout << "Grade: D" << std::endl;
} else {
    std::cout << "Grade: F" << std::endl;
}
```

### Nested if Statements

```cpp
int age = 20;
bool hasLicense = true;

if (age >= 18) {
    if (hasLicense) {
        std::cout << "You can drive!" << std::endl;
    } else {
        std::cout << "You need a license." << std::endl;
    }
} else {
    std::cout << "You're too young to drive." << std::endl;
}
```

### Ternary Operator

```cpp
int age = 20;

// condition ? value_if_true : value_if_false
std::string status = (age >= 18) ? "adult" : "minor";

// More complex
int a = 10, b = 20;
int max = (a > b) ? a : b;

std::cout << "You are an " << status << std::endl;
std::cout << "Max: " << max << std::endl;
```

## Switch Statement

```cpp
#include <iostream>

int main() {
    int day = 3;

    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
        case 7:
            std::cout << "Weekend!" << std::endl;
            break;
        default:
            std::cout << "Invalid day" << std::endl;
            break;
    }

    return 0;
}
```

### Switch with Characters

```cpp
char grade = 'B';

switch (grade) {
    case 'A':
        std::cout << "Excellent!" << std::endl;
        break;
    case 'B':
        std::cout << "Good job!" << std::endl;
        break;
    case 'C':
        std::cout << "Satisfactory" << std::endl;
        break;
    case 'D':
        std::cout << "Needs improvement" << std::endl;
        break;
    case 'F':
        std::cout << "Failed" << std::endl;
        break;
    default:
        std::cout << "Invalid grade" << std::endl;
        break;
}
```

## Loops

### while Loop

```cpp
// Print numbers 1 to 5
int i = 1;
while (i <= 5) {
    std::cout << i << " ";
    i++;
}
std::cout << std::endl;

// User input validation
int number;
std::cout << "Enter a positive number: ";
std::cin >> number;

while (number <= 0) {
    std::cout << "Invalid! Enter a positive number: ";
    std::cin >> number;
}
```

### do-while Loop

```cpp
// Executes at least once
int num;
do {
    std::cout << "Enter a number (0 to quit): ";
    std::cin >> num;
    std::cout << "You entered: " << num << std::endl;
} while (num != 0);
```

### for Loop

```cpp
// Basic for loop
for (int i = 0; i < 5; i++) {
    std::cout << i << " ";
}
std::cout << std::endl;

// Count backwards
for (int i = 10; i >= 1; i--) {
    std::cout << i << " ";
}
std::cout << std::endl;

// Step by 2
for (int i = 0; i <= 10; i += 2) {
    std::cout << i << " ";
}
std::cout << std::endl;

// Multiple variables
for (int i = 0, j = 10; i < 5; i++, j--) {
    std::cout << "i: " << i << ", j: " << j << std::endl;
}
```

### Range-based for Loop (C++11)

```cpp
#include <vector>

// With arrays
int numbers[] = {1, 2, 3, 4, 5};
for (int num : numbers) {
    std::cout << num << " ";
}
std::cout << std::endl;

// With vectors
std::vector<int> vec = {10, 20, 30, 40};
for (int value : vec) {
    std::cout << value << " ";
}
std::cout << std::endl;

// By reference (to modify)
for (int& value : vec) {
    value *= 2;  // Double each value
}

// By const reference (efficient, no copy)
for (const int& value : vec) {
    std::cout << value << " ";
}
std::cout << std::endl;
```

## Loop Control Statements

### break Statement

```cpp
// Exit loop early
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break;  // Exit when i is 5
    }
    std::cout << i << " ";
}
std::cout << std::endl;

// Find first even number
int numbers[] = {1, 3, 7, 8, 9, 10};
for (int num : numbers) {
    if (num % 2 == 0) {
        std::cout << "First even: " << num << std::endl;
        break;
    }
}
```

### continue Statement

```cpp
// Skip even numbers
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
        continue;  // Skip rest of loop body
    }
    std::cout << i << " ";
}
std::cout << std::endl;

// Process only positive numbers
int values[] = {5, -2, 3, -8, 10, -1, 7};
for (int val : values) {
    if (val < 0) {
        continue;
    }
    std::cout << val << " ";
}
std::cout << std::endl;
```

### Nested Loops

```cpp
// Multiplication table
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
        std::cout << i * j << "\t";
    }
    std::cout << std::endl;
}

// Pattern printing
for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
        std::cout << "* ";
    }
    std::cout << std::endl;
}

// Break outer loop from inner loop
bool found = false;
for (int i = 0; i < 5 && !found; i++) {
    for (int j = 0; j < 5; j++) {
        if (i * j == 6) {
            std::cout << "Found: " << i << " * " << j << std::endl;
            found = true;
            break;
        }
    }
}
```

## Common Patterns

### Sum of Numbers

```cpp
int n = 100;
int sum = 0;

for (int i = 1; i <= n; i++) {
    sum += i;
}

std::cout << "Sum of 1 to " << n << " is: " << sum << std::endl;
```

### Factorial

```cpp
int n = 5;
int factorial = 1;

for (int i = 1; i <= n; i++) {
    factorial *= i;
}

std::cout << n << "! = " << factorial << std::endl;
```

### Menu-driven Program

```cpp
#include <iostream>

int main() {
    int choice;

    do {
        std::cout << "\n=== Menu ===" << std::endl;
        std::cout << "1. Option 1" << std::endl;
        std::cout << "2. Option 2" << std::endl;
        std::cout << "3. Option 3" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "You selected option 1" << std::endl;
                break;
            case 2:
                std::cout << "You selected option 2" << std::endl;
                break;
            case 3:
                std::cout << "You selected option 3" << std::endl;
                break;
            case 0:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
```

## Practice Exercises

1. **FizzBuzz**: Print numbers 1-100, but for multiples of 3 print "Fizz", for multiples of 5 print "Buzz", and for multiples of both print "FizzBuzz".

2. **Prime Number Checker**: Determine if a number is prime.

3. **Fibonacci Sequence**: Generate the first n Fibonacci numbers.

4. **Number Guessing Game**: Computer picks a random number, user guesses.

5. **Pattern Printing**: Create various patterns using nested loops.

6. **Palindrome Checker**: Check if a number/string is a palindrome.

## Next Steps

Move on to [Chapter 4: Functions](04-functions.md) to learn about code organization and reusability!
