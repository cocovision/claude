# Chapter 1: Getting Started with C++

## What is C++?

C++ is a powerful, high-performance programming language that combines:
- **Low-level control** (like C) - Direct memory manipulation
- **High-level abstractions** - Object-oriented and generic programming
- **Performance** - Compiled to native machine code

## Setting Up Your Environment

### Option 1: Linux/macOS
```bash
# Install GCC compiler
# Ubuntu/Debian:
sudo apt-get install g++

# macOS:
xcode-select --install
```

### Option 2: Windows
- Install MinGW-w64 or Visual Studio
- Or use WSL (Windows Subsystem for Linux)

### Verify Installation
```bash
g++ --version
```

## Your First C++ Program

Create a file called `hello.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

### Understanding the Code

- `#include <iostream>` - Includes input/output library
- `int main()` - Entry point of every C++ program
- `std::cout` - Standard output stream
- `<<` - Stream insertion operator
- `std::endl` - End line (newline + flush)
- `return 0` - Indicates successful program completion

## Compiling and Running

```bash
# Compile
g++ hello.cpp -o hello

# Run
./hello
```

### Compilation Flags (Important)

```bash
# Use C++17 standard (recommended)
g++ -std=c++17 hello.cpp -o hello

# Enable warnings
g++ -std=c++17 -Wall -Wextra hello.cpp -o hello

# Debug build
g++ -std=c++17 -g hello.cpp -o hello

# Optimized release build
g++ -std=c++17 -O3 hello.cpp -o hello
```

## Program Structure

Every C++ program follows this basic structure:

```cpp
// 1. Preprocessor directives
#include <iostream>

// 2. Namespace (optional)
using namespace std;  // (use sparingly!)

// 3. Function declarations

// 4. Main function
int main() {
    // Your code here
    return 0;
}

// 5. Function definitions
```

## Comments

```cpp
// This is a single-line comment

/*
  This is a
  multi-line comment
*/

/**
 * This is a documentation comment
 * Often used for functions and classes
 */
```

## Common Mistakes

1. **Missing semicolons** - Every statement needs a `;`
2. **Case sensitivity** - `Main` ≠ `main`
3. **Missing return** - `main()` should return an integer
4. **Wrong file extension** - Use `.cpp` not `.c`

## Practice Exercise

Modify the hello world program to:
1. Print your name
2. Print your favorite number
3. Print multiple lines

## Next Steps

Move on to [Chapter 2: Basics](02-basics.md) to learn about variables, data types, and operators!
