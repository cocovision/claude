# C++ Quick Reference

## Compilation

```bash
# Basic compilation
g++ program.cpp -o program

# With C++17 standard
g++ -std=c++17 program.cpp -o program

# With warnings
g++ -std=c++17 -Wall -Wextra program.cpp -o program

# Debug mode
g++ -std=c++17 -g program.cpp -o program

# Optimized (release)
g++ -std=c++17 -O3 program.cpp -o program
```

## Basic Syntax

```cpp
#include <iostream>

int main() {
    // Your code here
    return 0;
}
```

## Data Types

| Type | Size | Range |
|------|------|-------|
| `int` | 4 bytes | -2B to 2B |
| `short` | 2 bytes | -32K to 32K |
| `long` | 4/8 bytes | Large |
| `float` | 4 bytes | ~7 digits |
| `double` | 8 bytes | ~15 digits |
| `char` | 1 byte | -128 to 127 |
| `bool` | 1 byte | true/false |

## Common Operations

### Input/Output
```cpp
std::cout << "Output" << std::endl;
std::cin >> variable;
std::getline(std::cin, stringVar);
```

### Strings
```cpp
std::string str = "Hello";
str.length()
str.substr(0, 5)
str.find("lo")
str1 + str2  // Concatenation
```

### Vectors
```cpp
std::vector<int> vec = {1, 2, 3};
vec.push_back(4);
vec.pop_back();
vec.size()
vec[0]
vec.at(1)
```

### Maps
```cpp
std::map<string, int> map;
map["key"] = value;
map.find("key")
map.count("key")
```

### Loops
```cpp
for (int i = 0; i < n; i++) { }
while (condition) { }
for (auto& item : container) { }
```

### Smart Pointers
```cpp
auto ptr = std::make_unique<Type>();
auto ptr = std::make_shared<Type>();
```

### Lambdas
```cpp
auto func = [](int x) { return x * 2; };
[&] // capture all by reference
[=] // capture all by value
```

## Useful Algorithms

```cpp
std::sort(vec.begin(), vec.end());
std::reverse(vec.begin(), vec.end());
std::find(vec.begin(), vec.end(), value);
std::count(vec.begin(), vec.end(), value);
std::max_element(vec.begin(), vec.end());
std::min_element(vec.begin(), vec.end());
std::accumulate(vec.begin(), vec.end(), 0);
```

## Common Patterns

### Range-based loop
```cpp
for (const auto& item : container) {
    // Use item
}
```

### Error checking
```cpp
if (ptr != nullptr) {
    // Use ptr
}

if (map.find(key) != map.end()) {
    // Key exists
}
```

### RAII Pattern
```cpp
{
    std::unique_ptr<Type> resource = std::make_unique<Type>();
    // Use resource
} // Automatically cleaned up
```
