# Chapter 2: Assignment Helpers

## Purpose
This document provides scaffolding and hints for the main assignments. Use this if you're stuck or want to verify you're on the right track.

---

## Assignment 1: Type System Exploration - Scaffolding

### Part A: Type Discovery Helper

#### Structure Template
```cpp
#include <cstdio>
#include <climits>  // For INT_MAX, INT_MIN
#include <cfloat>   // For DBL_MAX, FLT_MAX

void print_type_analysis() {
    printf("=== C++ Type System Analysis ===\n");
    printf("Fundamental Types:\n");

    // Hint: Create variables for each type
    int my_int = 42;
    // TODO: Add double, char, bool, long, float

    // Hint: Use this pattern for each type
    printf("  int: %d (size: %zu bytes, range: %d to %d)\n",
           my_int, sizeof(int), INT_MIN, INT_MAX);
    // TODO: Similar printf for other types
}

void demonstrate_conversions() {
    printf("\nType Conversions:\n");

    int whole = 42;
    double decimal = 3.14159;

    // Implicit conversion (automatic)
    double whole_as_double = whole;  // TODO: Print this

    // Explicit conversion (you control it)
    int decimal_as_int = static_cast<int>(decimal);  // TODO: Print this

    // Show precision loss
    // TODO: Print both values to show what was lost
}

int main() {
    print_type_analysis();
    demonstrate_conversions();
    // TODO: Add your converter functions
    return 0;
}
```

#### Key Functions You'll Need

**Temperature Conversion Formulas:**
```cpp
double celsius_to_fahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;  // Note: 9.0 not 9 for double math
}

double fahrenheit_to_celsius(double f) {
    // TODO: Implement (F - 32) * 5/9
}
```

**Atmospheric Conversion Helpers:**
```cpp
const double HPA_TO_INHG = 0.02953;   // hectopascals to inches of mercury
const double MPS_TO_KMH  = 3.6;       // meters/second to kilometers/hour

double hpa_to_inches_mercury(double hpa) {
    // TODO: Implement using the constant
}
```

### Part C: Memory Behavior Helper

#### Initialization Demo Structure
```cpp
int global_var;  // Global: auto-initialized to 0

void show_initialization() {
    int local_uninit;       // Dangerous: random value
    int local_init = 0;     // Safe: explicitly initialized
    static int static_var;  // Static: auto-initialized to 0

    printf("Global (auto-init): %d\n", global_var);
    printf("Local uninitialized: %d (RANDOM!)\n", local_uninit);
    printf("Local initialized: %d\n", local_init);
    printf("Static: %d\n", static_var);
}

void show_scope() {
    int x = 10;
    printf("Outer x: %d\n", x);

    {  // New scope block
        int x = 20;  // Shadows outer x
        printf("Inner x: %d\n", x);
    }

    printf("Outer x again: %d\n", x);  // What prints?
}
```

---

## Assignment 2: Weather Station Reading Logger - Scaffolding

### Part A: Core Structure Template

#### Start With This Structure
```cpp
#include <cstdio>
#include <cstring>
#include <cassert>

const int MAX_SAMPLES = 10;
const int MAX_READINGS = 5;

struct Reading {
    char station[50];
    int timestamp;                  // Minutes since midnight
    double samples[MAX_SAMPLES];    // Temperature samples (degrees C)
    int sample_count;               // How many samples this reading has
    double average;                 // Calculated average temperature
};

// Function to calculate one reading's average temperature
void calculate_average(Reading* reading) {
    if (reading->sample_count == 0) {
        reading->average = 0.0;
        return;
    }

    double total = 0.0;
    for (int i = 0; i < reading->sample_count; i++) {
        total += reading->samples[i];
    }
    reading->average = total / reading->sample_count;
}

// Function to print one reading
void print_reading(const Reading* r) {
    printf("Reading: %s (timestamp: %04d)\n", r->station, r->timestamp);
    printf("  Samples: [");
    for (int i = 0; i < r->sample_count; i++) {
        printf("%.1f", r->samples[i]);
        if (i < r->sample_count - 1) printf(", ");
    }
    printf("]\n");
    printf("  Average: %.1f\n", r->average);
}

int main() {
    // Create array of readings
    Reading readings[MAX_READINGS];
    int reading_count = 0;  // Track how many we actually use

    // Initialize first reading (example)
    strcpy(readings[0].station, "North Ridge");
    readings[0].timestamp = 480;     // 08:00
    readings[0].samples[0] = 18.5;
    readings[0].samples[1] = 19.2;
    readings[0].samples[2] = 17.8;
    readings[0].samples[3] = 20.6;
    readings[0].samples[4] = 18.8;
    readings[0].sample_count = 5;
    calculate_average(&readings[0]);
    reading_count++;

    // TODO: Add at least 2 more readings

    // TODO: Print all readings

    // TODO: Find station statistics

    return 0;
}
```

### Part B: Pointer Operations Helper

#### Array Access Patterns
```cpp
// Two ways to process arrays - both are equivalent

// Method 1: Array indexing (familiar)
void process_with_index(double samples[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Sample %d: %.1f\n", i, samples[i]);
    }
}

// Method 2: Pointer arithmetic (new concept)
void process_with_pointers(double* samples, int count) {
    double* end = samples + count;  // Point to one past the last element
    int index = 0;

    for (double* ptr = samples; ptr < end; ptr++) {
        printf("Sample %d: %.1f\n", index++, *ptr);
    }
}

// Understanding the equivalence:
// samples[i] is the same as *(samples + i)
// &samples[i] is the same as (samples + i)
```

#### Memory Layout Visualization
```cpp
void show_memory_layout(Reading* r) {
    printf("Memory Layout of Reading struct:\n");
    printf("  Base address: %p\n", (void*)r);
    printf("  station field: %p (offset: %ld)\n",
           (void*)&r->station, (char*)&r->station - (char*)r);
    printf("  timestamp field: %p (offset: %ld)\n",
           (void*)&r->timestamp, (char*)&r->timestamp - (char*)r);
    printf("  samples field: %p (offset: %ld)\n",
           (void*)&r->samples, (char*)&r->samples - (char*)r);
    printf("  Total size: %zu bytes\n", sizeof(Reading));
}
```

#### Safe Array Access Pattern
```cpp
// Always validate array access
bool safe_get_sample(const Reading* r, int index, double* result) {
    if (index < 0 || index >= r->sample_count) {
        return false;  // Invalid index
    }
    *result = r->samples[index];
    return true;  // Success
}

// Usage:
double sample;
if (safe_get_sample(&readings[0], 2, &sample)) {
    printf("Sample at index 2: %.1f\n", sample);
} else {
    printf("Invalid index!\n");
}
```

---

## Common Pitfalls and Solutions

### Pitfall 1: String Assignment
```cpp
// WRONG:
char station[50];
station = "North Ridge";  // ERROR: Can't assign arrays

// CORRECT:
strcpy(station, "North Ridge");  // Use strcpy for C-strings
```

### Pitfall 2: Uninitialized Arrays
```cpp
// DANGEROUS:
double samples[10];
printf("%f", samples[0]);  // Random value!

// SAFE:
double samples[10] = {0};  // Initialize all to zero
```

### Pitfall 3: Array Bounds
```cpp
// UNSAFE:
for (int i = 0; i <= 10; i++) {  // <= is wrong for size 10!
    arr[i] = 0;  // arr[10] is out of bounds
}

// SAFE:
for (int i = 0; i < 10; i++) {  // < not <=
    arr[i] = 0;
}
```

### Pitfall 4: Integer Division
```cpp
// WRONG:
int total = 24;
int count = 5;
double average = total / count;  // Result: 4.0 (not 4.8!)

// CORRECT:
double average = (double)total / count;  // Result: 4.8
```

### Pitfall 5: Pointer vs Value
```cpp
// Understanding the symbols:
int x = 42;
int* ptr = &x;   // & means "address of"

printf("%d", ptr);   // WRONG: Prints address as number
printf("%d", *ptr);  // CORRECT: * means "value at"
printf("%p", ptr);   // CORRECT: %p for addresses
```

---

## Debugging Strategies

### 1. Add Print Statements
```cpp
printf("DEBUG: Before calculation, total=%.1f, count=%d\n", total, count);
// Your calculation here
printf("DEBUG: After calculation, average=%.2f\n", average);
```

### 2. Use Assertions
```cpp
#include <cassert>

void process_array(double arr[], int size) {
    assert(size > 0);  // Program stops if false
    assert(arr != nullptr);
    // Safe to process now
}
```

### 3. Check Your Loops
```cpp
// Always verify loop bounds
for (int i = 0; i < size; i++) {
    printf("Processing index %d of %d\n", i, size-1);
    // Your code
}
```

### 4. Initialize Everything
```cpp
// Defensive initialization
Reading r = {};  // Zero-initializes entire struct
double arr[10] = {};  // Zero-initializes entire array
```

---

## Progress Checkpoints

### Before Submitting Assignment 1
- [ ] All types print with correct format specifiers
- [ ] Size information displays correctly
- [ ] Type conversions show precision loss where expected
- [ ] Temperature converter handles negative values
- [ ] Atmospheric converter maintains precision
- [ ] No compiler warnings with -Wall flag

### Before Submitting Assignment 2
- [ ] Readings stored in array successfully
- [ ] Averages calculate correctly (watch integer division!)
- [ ] Sorting works (if implemented)
- [ ] Memory safety demonstrated
- [ ] Pointer arithmetic section works
- [ ] No array bounds violations

---

## When to Ask for Help

Get help immediately if:
1. Segmentation fault you can't trace
2. Compiler errors you don't understand
3. Stuck on same problem for 30+ minutes
4. Output doesn't match expected after debugging
5. Unsure about memory safety

Remember: The goal is learning, not struggling alone!
