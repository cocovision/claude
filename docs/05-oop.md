# Chapter 5: Object-Oriented Programming

## Introduction to OOP

Object-Oriented Programming organizes code around **objects** that combine data and behavior.

### Key Concepts:
- **Encapsulation**: Bundling data and methods together
- **Abstraction**: Hiding complex implementation details
- **Inheritance**: Creating new classes from existing ones
- **Polymorphism**: Objects of different types responding to the same interface

## Classes and Objects

### Basic Class

```cpp
#include <iostream>
#include <string>

class Person {
public:
    // Data members (attributes)
    std::string name;
    int age;

    // Member functions (methods)
    void introduce() {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
    }
};

int main() {
    // Create objects
    Person person1;
    person1.name = "Alice";
    person1.age = 25;
    person1.introduce();

    Person person2;
    person2.name = "Bob";
    person2.age = 30;
    person2.introduce();

    return 0;
}
```

## Constructors and Destructors

### Constructors

```cpp
class Rectangle {
private:
    double width;
    double height;

public:
    // Default constructor
    Rectangle() {
        width = 0;
        height = 0;
        std::cout << "Default constructor called" << std::endl;
    }

    // Parameterized constructor
    Rectangle(double w, double h) {
        width = w;
        height = h;
        std::cout << "Parameterized constructor called" << std::endl;
    }

    // Constructor with default parameters
    Rectangle(double side = 1.0) {
        width = side;
        height = side;
    }

    // Member initializer list (preferred)
    Rectangle(double w, double h, bool verbose) : width(w), height(h) {
        if (verbose) {
            std::cout << "Rectangle created: " << w << "x" << h << std::endl;
        }
    }

    double area() const {
        return width * height;
    }
};

int main() {
    Rectangle r1;              // Default constructor
    Rectangle r2(5.0, 3.0);    // Parameterized constructor
    Rectangle r3(4.0);         // Constructor with default param

    std::cout << "Area: " << r2.area() << std::endl;
    return 0;
}
```

### Destructor

```cpp
class MyClass {
private:
    int* data;

public:
    // Constructor
    MyClass(int size) {
        data = new int[size];
        std::cout << "Constructor: Allocated memory" << std::endl;
    }

    // Destructor
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor: Freed memory" << std::endl;
    }
};

int main() {
    MyClass obj(10);
    // Destructor automatically called when obj goes out of scope
    return 0;
}
```

## Access Specifiers

```cpp
class BankAccount {
private:
    // Only accessible within the class
    double balance;
    std::string accountNumber;

protected:
    // Accessible in this class and derived classes
    std::string accountType;

public:
    // Accessible from anywhere
    std::string ownerName;

    // Constructor
    BankAccount(std::string owner, double initialBalance) {
        ownerName = owner;
        balance = initialBalance;
        accountType = "Savings";
    }

    // Public methods to access private data
    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }
};

int main() {
    BankAccount account("Alice", 1000.0);
    account.deposit(500.0);
    account.withdraw(200.0);
    std::cout << "Balance: $" << account.getBalance() << std::endl;
    // account.balance = 5000;  // ERROR! Private member
    return 0;
}
```

## Getters and Setters

```cpp
class Student {
private:
    std::string name;
    int age;
    double gpa;

public:
    // Getters (accessors)
    std::string getName() const { return name; }
    int getAge() const { return age; }
    double getGPA() const { return gpa; }

    // Setters (mutators)
    void setName(const std::string& n) {
        name = n;
    }

    void setAge(int a) {
        if (a >= 0 && a <= 120) {
            age = a;
        } else {
            std::cout << "Invalid age!" << std::endl;
        }
    }

    void setGPA(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        } else {
            std::cout << "Invalid GPA!" << std::endl;
        }
    }
};
```

## Inheritance

### Basic Inheritance

```cpp
// Base class (parent)
class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(std::string n, int a) : name(n), age(a) {}

    void eat() {
        std::cout << name << " is eating." << std::endl;
    }

    void sleep() {
        std::cout << name << " is sleeping." << std::endl;
    }

    virtual void makeSound() {
        std::cout << "Some generic animal sound" << std::endl;
    }
};

// Derived class (child)
class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(std::string n, int a, std::string b) : Animal(n, a), breed(b) {}

    void makeSound() override {
        std::cout << name << " says: Woof! Woof!" << std::endl;
    }

    void wagTail() {
        std::cout << name << " is wagging tail!" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(std::string n, int a) : Animal(n, a) {}

    void makeSound() override {
        std::cout << name << " says: Meow!" << std::endl;
    }

    void scratch() {
        std::cout << name << " is scratching!" << std::endl;
    }
};

int main() {
    Dog dog("Buddy", 3, "Golden Retriever");
    Cat cat("Whiskers", 2);

    dog.eat();
    dog.makeSound();
    dog.wagTail();

    cat.sleep();
    cat.makeSound();
    cat.scratch();

    return 0;
}
```

### Types of Inheritance

```cpp
// Public inheritance
class Derived1 : public Base {
    // Public members remain public
    // Protected members remain protected
};

// Protected inheritance
class Derived2 : protected Base {
    // Public and protected members become protected
};

// Private inheritance
class Derived3 : private Base {
    // Public and protected members become private
};
```

### Multiple Inheritance

```cpp
class Flyer {
public:
    void fly() {
        std::cout << "Flying..." << std::endl;
    }
};

class Swimmer {
public:
    void swim() {
        std::cout << "Swimming..." << std::endl;
    }
};

class Duck : public Flyer, public Swimmer {
public:
    void quack() {
        std::cout << "Quack!" << std::endl;
    }
};

int main() {
    Duck duck;
    duck.fly();
    duck.swim();
    duck.quack();
    return 0;
}
```

## Polymorphism

### Virtual Functions

```cpp
class Shape {
protected:
    std::string color;

public:
    Shape(std::string c) : color(c) {}

    // Virtual function
    virtual double area() const {
        return 0.0;
    }

    virtual void display() const {
        std::cout << "Shape with color: " << color << std::endl;
    }

    // Virtual destructor (important!)
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(std::string c, double r) : Shape(c), radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        std::cout << "Circle - Color: " << color << ", Radius: " << radius << std::endl;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(std::string c, double s) : Shape(c), side(s) {}

    double area() const override {
        return side * side;
    }

    void display() const override {
        std::cout << "Square - Color: " << color << ", Side: " << side << std::endl;
    }
};

int main() {
    // Polymorphism through pointers
    Shape* shapes[2];
    shapes[0] = new Circle("Red", 5.0);
    shapes[1] = new Square("Blue", 4.0);

    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
        std::cout << "Area: " << shapes[i]->area() << std::endl;
    }

    // Clean up
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}
```

### Abstract Classes and Pure Virtual Functions

```cpp
class Vehicle {
public:
    // Pure virtual function (makes class abstract)
    virtual void start() = 0;
    virtual void stop() = 0;

    // Regular virtual function
    virtual void honk() {
        std::cout << "Beep beep!" << std::endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void start() override {
        std::cout << "Car engine started" << std::endl;
    }

    void stop() override {
        std::cout << "Car engine stopped" << std::endl;
    }
};

class Motorcycle : public Vehicle {
public:
    void start() override {
        std::cout << "Motorcycle engine started" << std::endl;
    }

    void stop() override {
        std::cout << "Motorcycle engine stopped" << std::endl;
    }
};

int main() {
    // Vehicle v;  // ERROR! Cannot instantiate abstract class

    Vehicle* v1 = new Car();
    Vehicle* v2 = new Motorcycle();

    v1->start();
    v1->honk();
    v1->stop();

    v2->start();
    v2->stop();

    delete v1;
    delete v2;

    return 0;
}
```

## Static Members

```cpp
class Counter {
private:
    static int count;  // Shared by all objects
    int id;

public:
    Counter() {
        count++;
        id = count;
    }

    static int getCount() {
        return count;
    }

    int getID() const {
        return id;
    }
};

// Initialize static member outside class
int Counter::count = 0;

int main() {
    std::cout << "Count: " << Counter::getCount() << std::endl;  // 0

    Counter c1, c2, c3;

    std::cout << "Count: " << Counter::getCount() << std::endl;  // 3
    std::cout << "c1 ID: " << c1.getID() << std::endl;  // 1
    std::cout << "c2 ID: " << c2.getID() << std::endl;  // 2

    return 0;
}
```

## Friend Functions and Classes

```cpp
class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    // Friend function
    friend void printWidth(const Box& b);

    // Friend class
    friend class BoxPrinter;
};

void printWidth(const Box& b) {
    // Can access private members
    std::cout << "Width: " << b.width << std::endl;
}

class BoxPrinter {
public:
    void print(const Box& b) {
        std::cout << "Box width: " << b.width << std::endl;
    }
};
```

## Operator Overloading

```cpp
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload << operator (friend function)
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    // Overload == operator
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3 = c1 + c2;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;

    return 0;
}
```

## Practice Exercises

1. **Library System**: Create classes for Book, Library, and Member with appropriate relationships.

2. **Shape Hierarchy**: Implement a complete shape system with Triangle, Rectangle, Circle inheriting from Shape.

3. **Employee Management**: Create Employee base class with derived classes Manager, Developer, and Designer.

4. **Bank Account System**: Implement SavingsAccount and CheckingAccount inheriting from BankAccount.

5. **Vector Class**: Create a mathematical vector class with operator overloading (+, -, *, etc.).

## Next Steps

Continue to [Chapter 6: Memory Management](06-memory.md) to learn about pointers and dynamic memory!
