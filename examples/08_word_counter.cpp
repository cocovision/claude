// Word frequency counter using map
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    std::string text = "The quick brown fox jumps over the lazy dog. "
                       "The dog was sleeping under the tree. "
                       "The fox was very quick and clever.";

    std::cout << "Text: " << text << "\n" << std::endl;

    // Count word frequencies
    std::map<std::string, int> wordCount;
    std::istringstream stream(text);
    std::string word;

    while (stream >> word) {
        // Remove punctuation
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // Convert to lowercase
        word = toLowerCase(word);

        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    // Display results
    std::cout << "=== Word Frequencies ===" << std::endl;
    for (const auto& [word, count] : wordCount) {
        std::cout << word << ": " << count << std::endl;
    }

    // Find most common word
    auto maxElement = std::max_element(
        wordCount.begin(), wordCount.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
    );

    std::cout << "\nMost common word: \"" << maxElement->first
              << "\" (appears " << maxElement->second << " times)" << std::endl;

    std::cout << "Total unique words: " << wordCount.size() << std::endl;

    return 0;
}

// Compile: g++ -std=c++17 08_word_counter.cpp -o wordcount
// Run: ./wordcount
