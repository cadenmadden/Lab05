#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "StringData.h"

int linear_search(const std::vector<std::string>& container, const std::string& element) {
    for (int index = 0; index < container.size(); ++index) {
        if (container[index] == element) {
            return index;
        }
    }
    return -1;
}

int binary_search(const std::vector<std::string>& container, const std::string& element) {
    int left = 0;
    int right = container.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (container[middle] < element) {
            left = middle + 1;
        } else if (container[middle] > element) {
            right = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;
}

int main() {
    std::vector<std::string> data = getStringData();

    const std::string test_strings[] = {"not_here", "mzzzz", "aaaaa"};

    for (const std::string& test_string : test_strings) {
        auto b1 = std::chrono::system_clock::now();
        int index = binary_search(data, test_string);
        auto b2 = std::chrono::system_clock::now();
        std::chrono::duration<double> b_duration = b2 - b1;
        std::cout << "Binary search took " << b_duration.count() << " seconds to find '" << test_string << "'.\n";
        std::cout << "Index: " << index << "\n";

        auto l1 = std::chrono::system_clock::now();
        index = linear_search(data, test_string);
        auto l2 = std::chrono::system_clock::now();
        std::chrono::duration<double> l_duration = l2 - l1;
        std::cout << "Linear search took " << l_duration.count() << " seconds to find '" << test_string << "'.\n";
        std::cout << "Index: " << index << "\n";
    }

    return 0;
}
