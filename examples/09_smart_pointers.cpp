// Modern C++ - Smart pointers demonstration
#include <iostream>
#include <memory>
#include <vector>

class Resource {
private:
    std::string name;
    int* data;

public:
    Resource(std::string n) : name(n), data(new int[100]) {
        std::cout << "Resource '" << name << "' created" << std::endl;
    }

    ~Resource() {
        delete[] data;
        std::cout << "Resource '" << name << "' destroyed" << std::endl;
    }

    void use() {
        std::cout << "Using resource: " << name << std::endl;
    }

    std::string getName() const { return name; }
};

// unique_ptr example
void uniquePtrDemo() {
    std::cout << "\n=== unique_ptr Demo ===" << std::endl;

    {
        std::unique_ptr<Resource> res1 = std::make_unique<Resource>("Unique1");
        res1->use();

        // Transfer ownership
        std::unique_ptr<Resource> res2 = std::move(res1);

        if (!res1) {
            std::cout << "res1 is now null" << std::endl;
        }

        res2->use();
    }  // res2 automatically deleted here

    std::cout << "End of unique_ptr demo" << std::endl;
}

// shared_ptr example
void sharedPtrDemo() {
    std::cout << "\n=== shared_ptr Demo ===" << std::endl;

    std::shared_ptr<Resource> shared1 = std::make_shared<Resource>("Shared1");
    std::cout << "Reference count: " << shared1.use_count() << std::endl;

    {
        std::shared_ptr<Resource> shared2 = shared1;  // Shared ownership
        std::cout << "Reference count: " << shared1.use_count() << std::endl;

        shared2->use();
    }  // shared2 destroyed, but resource still alive

    std::cout << "Reference count: " << shared1.use_count() << std::endl;
    shared1->use();

    std::cout << "End of shared_ptr demo" << std::endl;
}  // shared1 destroyed, resource finally deleted

// Container with smart pointers
void containerDemo() {
    std::cout << "\n=== Container with Smart Pointers ===" << std::endl;

    std::vector<std::unique_ptr<Resource>> resources;

    // Add resources
    resources.push_back(std::make_unique<Resource>("Resource1"));
    resources.push_back(std::make_unique<Resource>("Resource2"));
    resources.push_back(std::make_unique<Resource>("Resource3"));

    // Use resources
    for (const auto& res : resources) {
        res->use();
    }

    std::cout << "End of container demo" << std::endl;
}  // All resources automatically deleted

int main() {
    uniquePtrDemo();
    sharedPtrDemo();
    containerDemo();

    std::cout << "\n=== End of Program ===" << std::endl;
    return 0;
}

// Compile: g++ -std=c++17 09_smart_pointers.cpp -o smartptr
// Run: ./smartptr
