# Chapter 2: C++ Basics

## Variables and Data Types

### Fundamental Data Types

```cpp
#include <iostream>

int main() {
    // Integer types
    int age = 25;                    // 4 bytes, range: ~-2B to 2B
    short smallNum = 100;            // 2 bytes
    long largeNum = 1000000L;        // 4 or 8 bytes
    long long veryLarge = 1000000LL; // 8 bytes

    // Unsigned versions (only positive)
    unsigned int count = 100;

    // Floating-point types
    float pi = 3.14f;                // 4 bytes, ~7 digits precision
    double precise = 3.14159265359;  // 8 bytes, ~15 digits precision
    long double veryPrecise = 3.14159265359L; // 10-16 bytes

    // Character type
    char letter = 'A';               // 1 byte, single character

    // Boolean type
    bool isTrue = true;              // true or false
    bool isFalse = false;

    // Print them
    std::cout << "Age: " << age << std::endl;
    std::cout << "Pi: " << pi << std::endl;
    std::cout << "Letter: " << letter << std::endl;
    std::cout << "Is true: " << isTrue << std::endl;

    return 0;
}
```

### Variable Declaration and Initialization

```cpp
// Declaration only
int x;

// Declaration and initialization
int y = 10;

// C++11 uniform initialization (preferred)
int z{15};
int a = {20};

// Multiple declarations
int i, j, k;
int m = 1, n = 2, o = 3;

// Auto type deduction (C++11)
auto number = 42;        // int
auto decimal = 3.14;     // double
auto letter = 'x';       // char
```

### Constants

```cpp
// const keyword
const int MAX_SIZE = 100;
const double PI = 3.14159;

// constexpr (compile-time constant)
constexpr int ARRAY_SIZE = 50;

// Cannot modify constants
// MAX_SIZE = 200;  // ERROR!
```

## Operators

### Arithmetic Operators

```cpp
int a = 10, b = 3;

int sum = a + b;         // Addition: 13
int diff = a - b;        // Subtraction: 7
int product = a * b;     // Multiplication: 30
int quotient = a / b;    // Integer division: 3
int remainder = a % b;   // Modulo: 1

// Compound assignment
a += 5;  // a = a + 5
a -= 3;  // a = a - 3
a *= 2;  // a = a * 2
a /= 4;  // a = a / 4
a %= 3;  // a = a % 3

// Increment/Decrement
int x = 5;
x++;     // Post-increment: use then add
++x;     // Pre-increment: add then use
x--;     // Post-decrement
--x;     // Pre-decrement
```

### Comparison Operators

```cpp
int x = 5, y = 10;

bool equal = (x == y);        // false
bool notEqual = (x != y);     // true
bool greater = (x > y);       // false
bool less = (x < y);          // true
bool greaterEq = (x >= y);    // false
bool lessEq = (x <= y);       // true
```

### Logical Operators

```cpp
bool a = true, b = false;

bool andResult = a && b;      // AND: false
bool orResult = a || b;       // OR: true
bool notResult = !a;          // NOT: false

// Short-circuit evaluation
if (a && b) {  // b is only evaluated if a is true
    // ...
}
```

### Bitwise Operators

```cpp
int x = 5;   // Binary: 0101
int y = 3;   // Binary: 0011

int andBit = x & y;   // AND: 0001 (1)
int orBit = x | y;    // OR: 0111 (7)
int xorBit = x ^ y;   // XOR: 0110 (6)
int notBit = ~x;      // NOT: 1010 (inverts all bits)

int leftShift = x << 1;   // Shift left: 1010 (10)
int rightShift = x >> 1;  // Shift right: 0010 (2)
```

## Input and Output

### Output with cout

```cpp
#include <iostream>

int main() {
    int age = 25;
    double height = 5.9;

    // Basic output
    std::cout << "Hello!" << std::endl;

    // Multiple values
    std::cout << "Age: " << age << ", Height: " << height << std::endl;

    // No newline
    std::cout << "This is ";
    std::cout << "one line" << std::endl;

    return 0;
}
```

### Input with cin

```cpp
#include <iostream>

int main() {
    int age;
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;  // Reads until whitespace

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;

    return 0;
}
```

### Reading a Full Line

```cpp
#include <iostream>
#include <string>

int main() {
    std::string fullName;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Hello, " << fullName << "!" << std::endl;

    return 0;
}
```

## Type Casting

```cpp
// Implicit casting (automatic)
int x = 10;
double y = x;  // int to double

// Explicit casting (C-style)
double pi = 3.14;
int intPi = (int)pi;  // 3

// C++ style casts (preferred)
double a = 3.14;
int b = static_cast<int>(a);  // 3

// Other C++ casts
// dynamic_cast - for polymorphic types
// const_cast - to add/remove const
// reinterpret_cast - low-level reinterpretation
```

## Strings

```cpp
#include <iostream>
#include <string>

int main() {
    // C++ strings (prefer these)
    std::string greeting = "Hello";
    std::string name = "Alice";

    // Concatenation
    std::string message = greeting + ", " + name + "!";

    // String methods
    int length = message.length();
    std::string upper = message;
    // (would need algorithm header for transform)

    // Accessing characters
    char firstChar = message[0];  // 'H'
    char lastChar = message[message.length() - 1];  // '!'

    // Substring
    std::string sub = message.substr(0, 5);  // "Hello"

    // Find
    size_t pos = message.find("Alice");

    std::cout << message << std::endl;
    std::cout << "Length: " << length << std::endl;

    return 0;
}
```

## Scope and Lifetime

```cpp
#include <iostream>

int globalVar = 100;  // Global scope

int main() {
    int localVar = 50;  // Local to main()

    {
        int blockVar = 25;  // Local to this block
        std::cout << blockVar << std::endl;  // OK
    }

    // std::cout << blockVar << std::endl;  // ERROR! Out of scope
    std::cout << localVar << std::endl;     // OK
    std::cout << globalVar << std::endl;    // OK

    return 0;
}
```

## Practice Exercises

1. **Calculator**: Write a program that takes two numbers and an operator (+, -, *, /) and performs the calculation.

2. **Temperature Converter**: Convert Celsius to Fahrenheit and vice versa.

3. **Circle Calculator**: Ask for radius, calculate area and circumference.

4. **Variable Swap**: Swap two variables without using a third variable.

5. **Type Sizes**: Print the size of all basic data types using `sizeof()`.

## Next Steps

Continue to [Chapter 3: Control Flow](03-control-flow.md) to learn about conditionals and loops!
