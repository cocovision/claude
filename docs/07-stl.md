# Chapter 7: Standard Template Library (STL)

## Introduction to STL

The STL provides:
- **Containers**: Data structures (vector, list, map, etc.)
- **Algorithms**: Common operations (sort, find, etc.)
- **Iterators**: Access elements in containers
- **Function Objects**: Callable objects

## Containers

### Vector (Dynamic Array)

```cpp
#include <iostream>
#include <vector>

int main() {
    // Create vector
    std::vector<int> vec;

    // Add elements
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Initialize with values
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> vec3(5, 100);  // 5 elements, all 100

    // Access elements
    std::cout << "First: " << vec[0] << std::endl;
    std::cout << "Second: " << vec.at(1) << std::endl;  // Bounds checking
    std::cout << "Front: " << vec.front() << std::endl;
    std::cout << "Back: " << vec.back() << std::endl;

    // Size and capacity
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Empty: " << vec.empty() << std::endl;

    // Iterate
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Range-based for loop
    for (int val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Iterator
    for (auto it = vec2.begin(); it != vec2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Modify
    vec[0] = 100;
    vec.pop_back();  // Remove last

    // Insert
    vec.insert(vec.begin(), 5);  // Insert at beginning
    vec.insert(vec.begin() + 1, 15);  // Insert at position

    // Erase
    vec.erase(vec.begin());  // Remove first
    vec.erase(vec.begin(), vec.begin() + 2);  // Remove range

    // Clear
    vec.clear();

    return 0;
}
```

### List (Doubly Linked List)

```cpp
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};

    // Add elements
    lst.push_front(0);   // Add at beginning
    lst.push_back(6);    // Add at end

    // Remove elements
    lst.pop_front();
    lst.pop_back();

    // Insert
    auto it = lst.begin();
    ++it;
    lst.insert(it, 10);

    // Remove by value
    lst.remove(3);  // Removes all elements with value 3

    // Iterate
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Sort
    lst.sort();

    // Reverse
    lst.reverse();

    return 0;
}
```

### Deque (Double-Ended Queue)

```cpp
#include <deque>

int main() {
    std::deque<int> dq = {1, 2, 3};

    // Add elements
    dq.push_front(0);
    dq.push_back(4);

    // Access
    std::cout << dq[0] << std::endl;
    std::cout << dq.front() << std::endl;
    std::cout << dq.back() << std::endl;

    // Remove
    dq.pop_front();
    dq.pop_back();

    return 0;
}
```

### Stack

```cpp
#include <stack>

int main() {
    std::stack<int> stk;

    // Push elements
    stk.push(10);
    stk.push(20);
    stk.push(30);

    // Access top
    std::cout << "Top: " << stk.top() << std::endl;

    // Pop element
    stk.pop();

    // Size
    std::cout << "Size: " << stk.size() << std::endl;

    // Empty check
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << std::endl;

    return 0;
}
```

### Queue

```cpp
#include <queue>

int main() {
    std::queue<int> q;

    // Enqueue
    q.push(10);
    q.push(20);
    q.push(30);

    // Front and back
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    // Dequeue
    q.pop();

    // Process all
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    return 0;
}
```

### Priority Queue

```cpp
#include <queue>

int main() {
    // Max heap by default
    std::priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";  // 50, 30, 20, 10
        pq.pop();
    }
    std::cout << std::endl;

    // Min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(50);

    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";  // 10, 30, 50
        minHeap.pop();
    }
    std::cout << std::endl;

    return 0;
}
```

### Set (Ordered, Unique)

```cpp
#include <set>

int main() {
    std::set<int> s = {5, 2, 8, 2, 1, 8};  // Duplicates ignored

    // Insert
    s.insert(3);
    s.insert(2);  // Already exists, ignored

    // Print (sorted)
    for (int val : s) {
        std::cout << val << " ";  // 1, 2, 3, 5, 8
    }
    std::cout << std::endl;

    // Find
    if (s.find(5) != s.end()) {
        std::cout << "Found 5" << std::endl;
    }

    // Count (0 or 1 for set)
    std::cout << "Count of 2: " << s.count(2) << std::endl;

    // Erase
    s.erase(2);

    // Size
    std::cout << "Size: " << s.size() << std::endl;

    return 0;
}
```

### Multiset (Ordered, Allows Duplicates)

```cpp
#include <set>

int main() {
    std::multiset<int> ms = {5, 2, 8, 2, 1, 8};

    // Print
    for (int val : ms) {
        std::cout << val << " ";  // 1, 2, 2, 5, 8, 8
    }
    std::cout << std::endl;

    // Count
    std::cout << "Count of 2: " << ms.count(2) << std::endl;  // 2

    // Erase all occurrences
    ms.erase(2);

    return 0;
}
```

### Unordered Set (Hash Set)

```cpp
#include <unordered_set>

int main() {
    std::unordered_set<int> us = {5, 2, 8, 1};

    // Insert
    us.insert(3);

    // Find (O(1) average)
    if (us.find(5) != us.end()) {
        std::cout << "Found 5" << std::endl;
    }

    // Print (unordered)
    for (int val : us) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Map (Key-Value Pairs, Ordered)

```cpp
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages;

    // Insert
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 35;
    ages.insert({"David", 40});

    // Access
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;

    // Check if key exists
    if (ages.find("Bob") != ages.end()) {
        std::cout << "Bob exists" << std::endl;
    }

    // Iterate
    for (const auto& pair : ages) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Erase
    ages.erase("Bob");

    // Size
    std::cout << "Size: " << ages.size() << std::endl;

    return 0;
}
```

### Unordered Map (Hash Map)

```cpp
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> scores;

    scores["Alice"] = 95;
    scores["Bob"] = 87;
    scores["Charlie"] = 92;

    // Access (O(1) average)
    std::cout << "Bob's score: " << scores["Bob"] << std::endl;

    // Iterate (unordered)
    for (const auto& [name, score] : scores) {  // C++17 structured binding
        std::cout << name << ": " << score << std::endl;
    }

    return 0;
}
```

### Pair

```cpp
#include <utility>

int main() {
    // Create pair
    std::pair<int, std::string> p1(1, "One");
    std::pair<int, std::string> p2 = std::make_pair(2, "Two");
    auto p3 = std::make_pair(3, "Three");  // Type deduction

    // Access
    std::cout << p1.first << ": " << p1.second << std::endl;

    // Modify
    p1.first = 10;
    p1.second = "Ten";

    // Compare
    if (p1 < p2) {
        std::cout << "p1 is less than p2" << std::endl;
    }

    return 0;
}
```

## Algorithms

```cpp
#include <algorithm>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> vec = {5, 2, 8, 1, 9, 3};

    // Sort
    std::sort(vec.begin(), vec.end());

    // Reverse
    std::reverse(vec.begin(), vec.end());

    // Find
    auto it = std::find(vec.begin(), vec.end(), 8);
    if (it != vec.end()) {
        std::cout << "Found 8 at position: " << (it - vec.begin()) << std::endl;
    }

    // Count
    int count = std::count(vec.begin(), vec.end(), 2);
    std::cout << "Count of 2: " << count << std::endl;

    // Min/Max element
    auto minIt = std::min_element(vec.begin(), vec.end());
    auto maxIt = std::max_element(vec.begin(), vec.end());
    std::cout << "Min: " << *minIt << ", Max: " << *maxIt << std::endl;

    // Sum (requires <numeric>)
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum: " << sum << std::endl;

    // Binary search (requires sorted)
    std::sort(vec.begin(), vec.end());
    bool found = std::binary_search(vec.begin(), vec.end(), 8);
    std::cout << "Found 8: " << found << std::endl;

    // Transform
    std::vector<int> squared(vec.size());
    std::transform(vec.begin(), vec.end(), squared.begin(),
                   [](int x) { return x * x; });

    // For each
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;

    // Remove (doesn't actually remove, returns new end)
    vec = {1, 2, 3, 2, 4, 2, 5};
    auto newEnd = std::remove(vec.begin(), vec.end(), 2);
    vec.erase(newEnd, vec.end());  // Actually remove

    // Unique (remove consecutive duplicates)
    vec = {1, 1, 2, 2, 3, 3, 3, 4};
    auto uniqueEnd = std::unique(vec.begin(), vec.end());
    vec.erase(uniqueEnd, vec.end());

    return 0;
}
```

## Practice Exercises

1. **Word Frequency Counter**: Use a map to count word occurrences in text.

2. **Student Database**: Store student records using appropriate containers.

3. **Top K Elements**: Find K largest elements using priority queue.

4. **Set Operations**: Implement union, intersection, difference using sets.

5. **LRU Cache**: Implement a Least Recently Used cache using map and list.

## Next Steps

Continue to [Chapter 8: Modern C++](08-modern-cpp.md) to learn about C++11/14/17 features!
