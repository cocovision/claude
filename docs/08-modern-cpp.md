# Chapter 8: Modern C++ (C++11/14/17/20)

## Auto Keyword

```cpp
#include <vector>
#include <map>

int main() {
    // Type deduction
    auto x = 42;              // int
    auto y = 3.14;            // double
    auto z = "hello";         // const char*
    auto str = std::string("world");  // std::string

    // With containers
    auto vec = std::vector<int>{1, 2, 3, 4, 5};

    // Iterators
    std::vector<int> numbers = {1, 2, 3};
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }

    // Complex types
    std::map<std::string, std::vector<int>> data;
    for (const auto& [key, value] : data) {  // C++17 structured binding
        // ...
    }

    return 0;
}
```

## Range-Based For Loops

```cpp
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Read-only
    for (auto value : vec) {
        std::cout << value << " ";
    }

    // By reference (to modify)
    for (auto& value : vec) {
        value *= 2;
    }

    // By const reference (efficient, no copy)
    for (const auto& value : vec) {
        std::cout << value << " ";
    }

    return 0;
}
```

## Nullptr

```cpp
// Old way
int* ptr1 = NULL;   // Actually just 0
int* ptr2 = 0;

// Modern way (C++11)
int* ptr3 = nullptr;

void func(int x) { std::cout << "int" << std::endl; }
void func(int* ptr) { std::cout << "pointer" << std::endl; }

int main() {
    func(0);        // Calls func(int) - ambiguous!
    func(nullptr);  // Calls func(int*) - clear!
    return 0;
}
```

## Strongly Typed Enums

```cpp
// Old style enums
enum Color { RED, GREEN, BLUE };  // Global scope, implicit int conversion

// Modern enum class (C++11)
enum class TrafficLight { Red, Yellow, Green };
enum class Status { Pending, Active, Completed };

int main() {
    // Old style
    Color c = RED;
    int x = RED;  // Implicit conversion

    // New style
    TrafficLight light = TrafficLight::Red;
    // int y = TrafficLight::Red;  // ERROR: No implicit conversion

    // Can have same names in different enums
    Status s = Status::Active;

    // Switch with enum class
    switch (light) {
        case TrafficLight::Red:
            std::cout << "Stop" << std::endl;
            break;
        case TrafficLight::Yellow:
            std::cout << "Caution" << std::endl;
            break;
        case TrafficLight::Green:
            std::cout << "Go" << std::endl;
            break;
    }

    return 0;
}
```

## Lambda Expressions

```cpp
#include <vector>
#include <algorithm>

int main() {
    // Basic lambda
    auto hello = []() {
        std::cout << "Hello!" << std::endl;
    };
    hello();

    // Lambda with parameters and return
    auto add = [](int a, int b) -> int {
        return a + b;
    };
    std::cout << add(3, 5) << std::endl;

    // Capture by value
    int x = 10;
    auto addX = [x](int y) {
        return x + y;  // x is copied
    };
    std::cout << addX(5) << std::endl;

    // Capture by reference
    int count = 0;
    auto increment = [&count]() {
        count++;
    };
    increment();
    increment();
    std::cout << count << std::endl;  // 2

    // Capture all by value
    int a = 1, b = 2;
    auto lambda1 = [=]() {
        return a + b;
    };

    // Capture all by reference
    auto lambda2 = [&]() {
        a++;
        b++;
    };

    // Mixed capture
    int c = 5, d = 10;
    auto lambda3 = [c, &d]() {
        // c is by value, d is by reference
        d++;
        return c + d;
    };

    // Using with STL algorithms
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};

    // Find if
    auto it = std::find_if(numbers.begin(), numbers.end(),
                           [](int n) { return n > 3; });

    // Count if
    int evenCount = std::count_if(numbers.begin(), numbers.end(),
                                   [](int n) { return n % 2 == 0; });

    // Sort with custom comparator
    std::sort(numbers.begin(), numbers.end(),
              [](int a, int b) { return a > b; });  // Descending

    return 0;
}
```

## Smart Pointers

### unique_ptr

```cpp
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired" << std::endl; }
    ~Resource() { std::cout << "Resource released" << std::endl; }
    void use() { std::cout << "Using resource" << std::endl; }
};

int main() {
    {
        // Unique ownership
        std::unique_ptr<Resource> ptr1 = std::make_unique<Resource>();
        ptr1->use();

        // Cannot copy
        // std::unique_ptr<Resource> ptr2 = ptr1;  // ERROR

        // Can move
        std::unique_ptr<Resource> ptr2 = std::move(ptr1);
        // ptr1 is now nullptr

        if (!ptr1) {
            std::cout << "ptr1 is null" << std::endl;
        }

    }  // Resource automatically deleted

    return 0;
}
```

### shared_ptr

```cpp
#include <memory>

int main() {
    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>();
    std::cout << "Count: " << ptr1.use_count() << std::endl;  // 1

    {
        std::shared_ptr<Resource> ptr2 = ptr1;
        std::cout << "Count: " << ptr1.use_count() << std::endl;  // 2
        ptr2->use();
    }

    std::cout << "Count: " << ptr1.use_count() << std::endl;  // 1
    // Resource still alive

    return 0;
}
```

## Move Semantics

```cpp
#include <vector>
#include <string>

class BigData {
private:
    std::vector<int> data;

public:
    BigData(size_t size) : data(size) {
        std::cout << "Constructor" << std::endl;
    }

    // Copy constructor (expensive)
    BigData(const BigData& other) : data(other.data) {
        std::cout << "Copy constructor" << std::endl;
    }

    // Move constructor (cheap)
    BigData(BigData&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Move constructor" << std::endl;
    }

    // Copy assignment
    BigData& operator=(const BigData& other) {
        std::cout << "Copy assignment" << std::endl;
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    // Move assignment
    BigData& operator=(BigData&& other) noexcept {
        std::cout << "Move assignment" << std::endl;
        if (this != &other) {
            data = std::move(other.data);
        }
        return *this;
    }
};

BigData createBigData() {
    return BigData(1000000);
}

int main() {
    BigData bd1(100);
    BigData bd2 = bd1;           // Copy
    BigData bd3 = std::move(bd1); // Move

    BigData bd4 = createBigData(); // Move (RVO may optimize this away)

    return 0;
}
```

## Uniform Initialization

```cpp
int main() {
    // Traditional initialization
    int a = 5;
    int b(10);

    // Uniform initialization (C++11)
    int c{15};
    int d = {20};

    // Prevents narrowing conversions
    // int e{3.14};  // ERROR: narrowing

    // With containers
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::map<std::string, int> map{{"Alice", 25}, {"Bob", 30}};

    // With classes
    struct Point {
        int x, y;
    };
    Point p{10, 20};

    return 0;
}
```

## Variadic Templates

```cpp
#include <iostream>

// Base case
void print() {
    std::cout << std::endl;
}

// Recursive variadic template
template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...);
}

// Sum with variadic templates
template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... args) {
    return first + sum(args...);
}

int main() {
    print(1, 2.5, "hello", 'c');
    std::cout << "Sum: " << sum(1, 2, 3, 4, 5) << std::endl;
    return 0;
}
```

## Constexpr

```cpp
// Compile-time computation
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

constexpr int square(int x) {
    return x * x;
}

int main() {
    // Computed at compile time
    constexpr int fact5 = factorial(5);
    constexpr int sq10 = square(10);

    // Can be used in compile-time contexts
    int arr[factorial(4)];  // Array size must be compile-time constant

    std::cout << "5! = " << fact5 << std::endl;
    std::cout << "10^2 = " << sq10 << std::endl;

    return 0;
}
```

## Structured Bindings (C++17)

```cpp
#include <tuple>
#include <map>

std::tuple<int, double, std::string> getData() {
    return {42, 3.14, "hello"};
}

int main() {
    // With tuple
    auto [num, pi, str] = getData();
    std::cout << num << ", " << pi << ", " << str << std::endl;

    // With pair
    std::pair<int, std::string> p = {1, "one"};
    auto [id, name] = p;

    // With map
    std::map<std::string, int> ages = {{"Alice", 25}, {"Bob", 30}};
    for (const auto& [name, age] : ages) {
        std::cout << name << ": " << age << std::endl;
    }

    // With arrays
    int arr[] = {1, 2, 3};
    auto [a, b, c] = arr;

    return 0;
}
```

## Optional (C++17)

```cpp
#include <optional>
#include <string>

std::optional<int> divide(int a, int b) {
    if (b == 0) {
        return std::nullopt;  // No value
    }
    return a / b;
}

std::optional<std::string> findUser(int id) {
    if (id == 1) {
        return "Alice";
    }
    return std::nullopt;
}

int main() {
    auto result = divide(10, 2);
    if (result.has_value()) {
        std::cout << "Result: " << result.value() << std::endl;
    }

    // Or
    if (result) {
        std::cout << "Result: " << *result << std::endl;
    }

    // With default value
    auto result2 = divide(10, 0);
    std::cout << result2.value_or(0) << std::endl;

    // With structured binding
    auto user = findUser(1);
    if (auto name = findUser(1); name) {
        std::cout << "User: " << *name << std::endl;
    }

    return 0;
}
```

## Filesystem (C++17)

```cpp
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    // Current path
    std::cout << "Current path: " << fs::current_path() << std::endl;

    // Check if file exists
    if (fs::exists("file.txt")) {
        std::cout << "File exists" << std::endl;
    }

    // Check if directory
    if (fs::is_directory("mydir")) {
        std::cout << "It's a directory" << std::endl;
    }

    // File size
    if (fs::exists("file.txt")) {
        auto size = fs::file_size("file.txt");
        std::cout << "Size: " << size << " bytes" << std::endl;
    }

    // Create directory
    fs::create_directory("newdir");

    // Iterate directory
    for (const auto& entry : fs::directory_iterator(".")) {
        std::cout << entry.path() << std::endl;
    }

    // Path manipulation
    fs::path p = "dir/file.txt";
    std::cout << "Filename: " << p.filename() << std::endl;
    std::cout << "Extension: " << p.extension() << std::endl;
    std::cout << "Parent: " << p.parent_path() << std::endl;

    return 0;
}
```

## String View (C++17)

```cpp
#include <string_view>
#include <string>

void printString(std::string_view sv) {
    std::cout << sv << std::endl;
}

int main() {
    // No copy, just a view
    std::string str = "Hello, World!";
    std::string_view sv = str;

    printString("Literal");     // No string creation
    printString(str);           // No copy
    printString(sv);            // Just a view

    // Substring without copy
    std::string_view sub = sv.substr(0, 5);
    std::cout << sub << std::endl;

    return 0;
}
```

## Best Practices

1. **Use auto**: When type is obvious or verbose
2. **Prefer smart pointers**: Over raw pointers for ownership
3. **Use nullptr**: Instead of NULL or 0
4. **Range-based for**: When iterating containers
5. **Uniform initialization**: Consistent and safer
6. **constexpr**: For compile-time computation
7. **enum class**: Instead of traditional enums
8. **Lambda expressions**: For short, local functions
9. **std::optional**: Instead of special values for "no result"
10. **Move semantics**: For efficient transfers of large objects

## Practice Exercises

1. **Lambda Calculator**: Implement calculator using lambdas for operations.

2. **Smart Pointer Container**: Create a container managing objects with shared_ptr.

3. **File System Explorer**: Use C++17 filesystem to explore and analyze directories.

4. **Optional Parser**: Build a parser that returns optional values for parsing results.

5. **Move-Optimized Container**: Implement a container that properly uses move semantics.

## Conclusion

Congratulations on completing this C++ learning guide! You've covered:
- Basics and syntax
- Control flow and functions
- Object-oriented programming
- Memory management
- STL containers and algorithms
- Modern C++ features

Keep practicing, build projects, and explore advanced topics like:
- Multithreading
- Templates and metaprogramming
- Design patterns
- Performance optimization
- C++20 features (concepts, ranges, coroutines)

Happy coding!
