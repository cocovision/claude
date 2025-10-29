// OOP with inheritance - Student Management System
#include <iostream>
#include <string>
#include <vector>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    std::string studentId;
    double gpa;
    std::vector<std::string> courses;

public:
    Student(std::string n, int a, std::string id, double g)
        : Person(n, a), studentId(id), gpa(g) {}

    void addCourse(const std::string& course) {
        courses.push_back(course);
    }

    void display() const override {
        std::cout << "\n=== Student Information ===" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Student ID: " << studentId << std::endl;
        std::cout << "GPA: " << gpa << std::endl;
        std::cout << "Courses: ";
        for (const auto& course : courses) {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }

    double getGPA() const { return gpa; }
};

class Teacher : public Person {
private:
    std::string subject;
    int yearsExperience;

public:
    Teacher(std::string n, int a, std::string subj, int exp)
        : Person(n, a), subject(subj), yearsExperience(exp) {}

    void display() const override {
        std::cout << "\n=== Teacher Information ===" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Subject: " << subject << std::endl;
        std::cout << "Years of Experience: " << yearsExperience << std::endl;
    }
};

int main() {
    // Create students
    Student student1("Alice Smith", 20, "S001", 3.8);
    student1.addCourse("Math");
    student1.addCourse("Physics");
    student1.addCourse("Computer Science");

    Student student2("Bob Johnson", 21, "S002", 3.5);
    student2.addCourse("Biology");
    student2.addCourse("Chemistry");

    // Create teacher
    Teacher teacher1("Dr. Jane Doe", 45, "Mathematics", 20);

    // Display information
    student1.display();
    student2.display();
    teacher1.display();

    // Polymorphism
    std::cout << "\n=== Polymorphism Demo ===" << std::endl;
    Person* people[] = {&student1, &student2, &teacher1};
    for (int i = 0; i < 3; i++) {
        people[i]->display();
    }

    return 0;
}

// Compile: g++ -std=c++17 06_student_system.cpp -o student
// Run: ./student
