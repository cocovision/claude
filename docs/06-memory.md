# Chapter 6: Memory Management

## Understanding Memory

### Memory Segments

1. **Stack**: Local variables, function parameters (automatic, fast)
2. **Heap**: Dynamically allocated memory (manual, flexible)
3. **Static/Global**: Global and static variables
4. **Code**: Program instructions

## Pointers

### Pointer Basics

```cpp
#include <iostream>

int main() {
    int num = 42;
    int* ptr;  // Pointer to int

    ptr = &num;  // & = address-of operator

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Value of ptr: " << ptr << std::endl;
    std::cout << "Value pointed to: " << *ptr << std::endl;  // * = dereference

    // Modify through pointer
    *ptr = 100;
    std::cout << "New value of num: " << num << std::endl;

    return 0;
}
```

### Pointer Operations

```cpp
int main() {
    int x = 10;
    int* p = &x;

    // Dereferencing
    std::cout << *p << std::endl;  // 10

    // Modifying value
    *p = 20;
    std::cout << x << std::endl;  // 20

    // Pointer arithmetic (with arrays)
    int arr[] = {1, 2, 3, 4, 5};
    int* ptr = arr;  // Array name = pointer to first element

    std::cout << *ptr << std::endl;      // 1
    std::cout << *(ptr + 1) << std::endl;  // 2
    std::cout << *(ptr + 2) << std::endl;  // 3

    // Incrementing pointer
    ptr++;
    std::cout << *ptr << std::endl;  // 2

    return 0;
}
```

### Null Pointers

```cpp
int* ptr = nullptr;  // C++11 (preferred)
int* ptr2 = NULL;    // Old style
int* ptr3 = 0;       // Also works

// Always check before dereferencing
if (ptr != nullptr) {
    std::cout << *ptr << std::endl;
} else {
    std::cout << "Pointer is null" << std::endl;
}
```

### Void Pointers

```cpp
void* ptr;  // Generic pointer

int x = 10;
double y = 3.14;

ptr = &x;
std::cout << *(static_cast<int*>(ptr)) << std::endl;

ptr = &y;
std::cout << *(static_cast<double*>(ptr)) << std::endl;
```

## References

### Reference Basics

```cpp
int main() {
    int num = 42;
    int& ref = num;  // Reference (alias) to num

    std::cout << "num: " << num << std::endl;
    std::cout << "ref: " << ref << std::endl;

    // Modifying through reference
    ref = 100;
    std::cout << "num: " << num << std::endl;  // 100

    // References must be initialized
    // int& ref2;  // ERROR!

    // References cannot be reassigned
    int other = 50;
    ref = other;  // This copies value, doesn't change reference!

    return 0;
}
```

### Pointers vs References

```cpp
// Pointers
int* ptr = nullptr;  // Can be null
ptr = &x;            // Can be reassigned
*ptr = 10;           // Dereference needed

// References
int& ref = x;        // Must be initialized
// ref = y;          // Cannot be reassigned (copies value)
ref = 10;            // No dereference needed
```

## Dynamic Memory Allocation

### new and delete

```cpp
int main() {
    // Allocate single variable
    int* ptr = new int;
    *ptr = 42;
    std::cout << *ptr << std::endl;
    delete ptr;  // Free memory

    // Allocate with initialization
    int* ptr2 = new int(100);
    std::cout << *ptr2 << std::endl;
    delete ptr2;

    // Allocate array
    int size = 5;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;  // Use delete[] for arrays!

    return 0;
}
```

### Memory Leaks

```cpp
// BAD: Memory leak
void memoryLeak() {
    int* ptr = new int(42);
    // Forgot to delete!
    // Memory is never freed
}

// GOOD: Proper cleanup
void noLeak() {
    int* ptr = new int(42);
    delete ptr;
}

// BETTER: Use smart pointers (see below)
```

### Dangling Pointers

```cpp
int* createDanglingPointer() {
    int x = 10;
    return &x;  // BAD! x is destroyed when function returns
}

int* allocateMemory() {
    int* ptr = new int(42);
    return ptr;  // OK, but caller must delete
}

int main() {
    int* ptr1 = createDanglingPointer();  // DANGER!
    // *ptr1;  // Undefined behavior

    int* ptr2 = allocateMemory();  // OK
    std::cout << *ptr2 << std::endl;
    delete ptr2;  // Don't forget!

    return 0;
}
```

## Smart Pointers (C++11)

### unique_ptr

```cpp
#include <memory>

int main() {
    // Exclusive ownership
    std::unique_ptr<int> ptr1(new int(42));
    // Or better:
    std::unique_ptr<int> ptr2 = std::make_unique<int>(100);

    std::cout << *ptr2 << std::endl;

    // Cannot copy
    // std::unique_ptr<int> ptr3 = ptr2;  // ERROR!

    // Can move
    std::unique_ptr<int> ptr3 = std::move(ptr2);
    // Now ptr2 is null, ptr3 owns the memory

    if (ptr2 == nullptr) {
        std::cout << "ptr2 is null" << std::endl;
    }

    // Automatically deleted when out of scope
    return 0;
}
```

### shared_ptr

```cpp
#include <memory>

int main() {
    // Shared ownership
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);

    {
        std::shared_ptr<int> ptr2 = ptr1;  // Copy OK
        std::cout << "Use count: " << ptr1.use_count() << std::endl;  // 2
        std::cout << *ptr2 << std::endl;
    }  // ptr2 destroyed, but memory still valid

    std::cout << "Use count: " << ptr1.use_count() << std::endl;  // 1
    std::cout << *ptr1 << std::endl;  // Still valid

    // Memory freed when last shared_ptr is destroyed
    return 0;
}
```

### weak_ptr

```cpp
#include <memory>

int main() {
    std::shared_ptr<int> sptr = std::make_shared<int>(42);
    std::weak_ptr<int> wptr = sptr;  // Weak reference

    std::cout << "Use count: " << sptr.use_count() << std::endl;  // 1

    // Access through weak_ptr
    if (auto temp = wptr.lock()) {  // Creates temporary shared_ptr
        std::cout << *temp << std::endl;
    }

    // Reset shared_ptr
    sptr.reset();

    // weak_ptr now expired
    if (wptr.expired()) {
        std::cout << "weak_ptr is expired" << std::endl;
    }

    return 0;
}
```

### Smart Pointer with Classes

```cpp
#include <memory>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {
        std::cout << "Person created: " << name << std::endl;
    }

    ~Person() {
        std::cout << "Person destroyed: " << name << std::endl;
    }

    void introduce() {
        std::cout << "I'm " << name << ", age " << age << std::endl;
    }
};

int main() {
    {
        std::unique_ptr<Person> person1 = std::make_unique<Person>("Alice", 25);
        person1->introduce();

        std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob", 30);
        person2->introduce();
    }  // Destructors automatically called

    std::cout << "End of main" << std::endl;
    return 0;
}
```

## Dynamic Arrays

### Traditional Dynamic Arrays

```cpp
int main() {
    int size;
    std::cout << "Enter size: ";
    std::cin >> size;

    // Allocate
    int* arr = new int[size];

    // Initialize
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }

    // Use
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Free
    delete[] arr;

    return 0;
}
```

### 2D Dynamic Arrays

```cpp
int main() {
    int rows = 3, cols = 4;

    // Allocate
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Initialize
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }

    // Print
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
```

## The Rule of Three/Five

### Rule of Three (C++03)

```cpp
class MyString {
private:
    char* data;
    size_t length;

public:
    // Constructor
    MyString(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // 1. Destructor
    ~MyString() {
        delete[] data;
    }

    // 2. Copy constructor
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // 3. Copy assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {  // Self-assignment check
            delete[] data;  // Free old memory

            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    void print() const {
        std::cout << data << std::endl;
    }
};
```

### Rule of Five (C++11)

```cpp
class MyString {
private:
    char* data;
    size_t length;

public:
    // Constructor, Destructor, Copy constructor, Copy assignment (as above)
    // ...

    // 4. Move constructor
    MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    // 5. Move assignment operator
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data = other.data;
            length = other.length;

            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
};
```

## Memory Best Practices

1. **Always delete what you new**: Match every `new` with `delete`, every `new[]` with `delete[]`
2. **Use smart pointers**: Prefer `unique_ptr` and `shared_ptr` over raw pointers
3. **Initialize pointers**: Set to `nullptr` when not pointing to anything
4. **Avoid dangling pointers**: Don't return addresses of local variables
5. **Check for null**: Always validate pointers before dereferencing
6. **RAII**: Resource Acquisition Is Initialization - use constructors/destructors

## Practice Exercises

1. **Dynamic Array Class**: Implement a dynamic array with automatic resizing.

2. **Linked List**: Create a singly linked list using pointers.

3. **Memory Pool**: Implement a simple memory pool allocator.

4. **Reference Counter**: Build a reference-counted smart pointer.

5. **Matrix Class**: Create a matrix class with proper memory management.

## Next Steps

Continue to [Chapter 7: Standard Template Library](07-stl.md) to learn about containers and algorithms!
