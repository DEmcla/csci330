// Chapter 02: Types - Assignment Template
// Domain: Weather Station Readings
// TODO: Complete the exercises as specified in this template's README.md

#include <iostream>
#include <cstring>
using namespace std;

// TODO: Add any other includes you need (climits, cfloat, cassert, ...)

const int MAX_SAMPLES = 10;
const int MAX_READINGS = 5;

// A single weather-station reading: a set of temperature samples
// captured at one timestamp.
struct Reading {
    char station[50];
    int timestamp;                  // Minutes since midnight
    double samples[MAX_SAMPLES];    // Temperature samples (degrees C)
    int sample_count;               // How many samples are stored
    double average;                 // Calculated average temperature
};

// TODO: calculate one reading's average temperature using pointer arithmetic
// double calculate_average(const double* samples, size_t count) { ... }

// TODO: print one reading
// void print_reading(const Reading* r) { ... }

int main() {
    cout << "Chapter 02: Types" << endl;
    cout << "========================" << endl;

    // TODO: Implement assignment problems
    // Core Assignment 1: type_explorer (fundamental types, conversions, scope)
    // Core Assignment 2: station_logger (Reading structs, arrays, pointers)
    // See this template's README.md for requirements

    Reading readings[MAX_READINGS];
    int reading_count = 0;
    (void)readings;        // TODO: remove once you use the array
    (void)reading_count;   // TODO: remove once you use the counter

    return 0;
}
