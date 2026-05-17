// Chapter 14: Iterators - Assignment Template
// Domain: sensor log (a sequence of timestamped sensor readings)
// TODO: Complete the exercises as specified in this template's README.md

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

// ============================================================================
// Problem Set 3: Advanced Iterator Patterns
// ============================================================================

// Problem 3.1: Custom Iterator Functions
// Implement each of these using iterators.

template<typename Container, typename T>
bool contains(const Container& container, const T& value) {
    // TODO: return true if the sensor log contains value
    (void)container; (void)value;
    return false;
}

template<typename Container, typename T>
size_t count_occurrences(const Container& container, const T& value) {
    // TODO: count how many times the reading value appears in the log
    (void)container; (void)value;
    return 0;
}

template<typename Container>
void print_reverse(const Container& container) {
    // TODO: print the sensor log in reverse (most recent reading first)
    //       use reverse iterators (rbegin / rend)
    (void)container;
}

// Problem 3.3: Multi-Container Iterator Project
struct Sensor {
    std::string name;
    std::vector<double> readings;

    double calculate_average() const {
        // TODO: use iterators to sum the readings and return the average
        return 0.0;
    }
};

int main() {
    cout << "Chapter 14: Iterators (Sensor Log)" << endl;
    cout << "==================================" << endl;

    // TODO: Implement assignment problems
    // See this template's README.md for requirements

    return 0;
}
