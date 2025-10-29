// STL Vector operations and algorithms
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void printVector(const std::vector<int>& vec, const std::string& label) {
    std::cout << label << ": ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Create and initialize vector
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    printVector(numbers, "Original");

    // Sort
    std::sort(numbers.begin(), numbers.end());
    printVector(numbers, "Sorted");

    // Reverse
    std::reverse(numbers.begin(), numbers.end());
    printVector(numbers, "Reversed");

    // Find maximum and minimum
    auto maxIt = std::max_element(numbers.begin(), numbers.end());
    auto minIt = std::min_element(numbers.begin(), numbers.end());
    std::cout << "Max: " << *maxIt << ", Min: " << *minIt << std::endl;

    // Sum
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum: " << sum << std::endl;

    // Average
    double average = static_cast<double>(sum) / numbers.size();
    std::cout << "Average: " << average << std::endl;

    // Find element
    int searchValue = 7;
    auto it = std::find(numbers.begin(), numbers.end(), searchValue);
    if (it != numbers.end()) {
        std::cout << "Found " << searchValue << " at position: "
                  << (it - numbers.begin()) << std::endl;
    }

    // Count even numbers
    int evenCount = std::count_if(numbers.begin(), numbers.end(),
                                   [](int n) { return n % 2 == 0; });
    std::cout << "Even numbers count: " << evenCount << std::endl;

    // Transform - square all numbers
    std::vector<int> squared(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squared.begin(),
                   [](int n) { return n * n; });
    printVector(squared, "Squared");

    // Filter - get only even numbers
    std::vector<int> evens;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evens),
                 [](int n) { return n % 2 == 0; });
    printVector(evens, "Even numbers");

    // Remove duplicates
    std::vector<int> withDuplicates = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    printVector(withDuplicates, "With duplicates");
    std::sort(withDuplicates.begin(), withDuplicates.end());
    auto last = std::unique(withDuplicates.begin(), withDuplicates.end());
    withDuplicates.erase(last, withDuplicates.end());
    printVector(withDuplicates, "Unique values");

    return 0;
}

// Compile: g++ -std=c++17 07_vector_operations.cpp -o vector
// Run: ./vector
