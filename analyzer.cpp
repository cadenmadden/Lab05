#include <iostream>
#include <vector>
#include <string>
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
        long long b1 = systemTimeNanoseconds();
        int index = binary_search(data, test_string);
        long long b2 = systemTimeNanoseconds();
        std::cout << "Binary search took " << (b2 - b1) << " nanoseconds to find '" << test_string << "'.\n";
        std::cout << "Index: " << index << "\n";
        
        long long l1 = systemTimeNanoseconds();
        index = linear_search(data, test_string);
        long long l2 = systemTimeNanoseconds();
        std::cout << "Linear search took " << (l2 - l1) << " nanoseconds to find '" << test_string << "'.\n";
        std::cout << "Index: " << index << "\n";
    }

    return 0;
}
