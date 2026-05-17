# Chapter 13: STL Containers - Problem Sets

## 📋 Before You Begin

**✅ Prerequisites Check:**
- [ ] **Completed textbook reading**: Chapter 13 "STL Containers"
- [ ] **Worked through lecture notes**: All core concepts and hands-on problems
- [ ] **Development environment ready**: VS Code + compiler setup verified

**🚫 Don't start these assignments until you've completed the textbook and lecture notes!**

## Instructions
- These problems apply concepts from both the textbook and lecture notes
- Each problem builds on previous concepts  
- **Time expectation**: 2.25 hours total for all three problem sets
- Test all programs thoroughly before submission

---

## Problem Set 1: Container Basics and Sequence Containers (45 minutes)

### Problem 1.1: Vector Fundamentals (15 minutes)
**Scenario**: You're modeling a transit route as an ordered sequence of ride times between consecutive stations, similar to a Python list of numbers.

Create a program that:
1. Declares a `std::vector<double>` to store leg ride times (minutes between consecutive stations)
2. Adds at least 5 leg times using `push_back()`
3. Calculates and displays the average leg time
4. Finds and displays the longest leg
5. Uses both `[]` operator and `at()` method to access elements

**Python Equivalent**:
```python
leg_times = []
leg_times.append(4.5)
# ... add more leg times
average = sum(leg_times) / len(leg_times)
longest = max(leg_times)
```

**Learning Focus**: Basic vector operations, element access methods, iteration

### Problem 1.2: Dynamic Array Operations (15 minutes)
**Scenario**: You need to manage the ordered list of station names along a transit line that can grow and shrink as the line is extended or rerouted.

Requirements:
1. Create a `std::vector<std::string>` for station names along a line
2. Implement functions to:
   - Add a station name to the end of the line
   - Insert a station name at a specific position (a new stop mid-line)
   - Remove a station by name (use `std::find` and `erase`)
   - Display all stations with their positions

**Starter Code**:
```cpp
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class TransitLine {
private:
    std::vector<std::string> stations;
public:
    void addStation(const std::string& name);
    void insertStation(const std::string& name, size_t position);
    void removeStation(const std::string& name);
    void displayStations() const;
};
```

**Learning Focus**: Vector modification operations, iterator usage, searching

### Problem 1.3: Performance Comparison (15 minutes)
**Scenario**: Compare vector and list performance for different operations.

Create a program that:
1. Creates both a `std::vector<int>` and `std::list<int>` with 10,000 station IDs
2. Measures time for:
   - Adding station IDs to the front (hint: use `insert()` for vector)
   - Adding station IDs to the back
   - Accessing the middle station ID (only possible with vector)
3. Reports which container is faster for each operation

**Timing Helper**:
```cpp
#include <chrono>

auto start = std::chrono::high_resolution_clock::now();
// ... operation to time
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
```

**Learning Focus**: Performance characteristics, when to choose vector vs list

---

## Problem Set 2: Associative Containers (50 minutes)

### Problem 2.1: Line Usage Counter (20 minutes)
**Scenario**: Build a line-usage analyzer that counts how often each transit line is ridden, like Python's `collections.Counter`.

Requirements:
1. Read line names from user input (or a string) until "quit"
2. Use `std::map<std::string, int>` to count line-usage frequencies
3. Display all lines and their counts in alphabetical order
4. Find and display the busiest line

**Python Equivalent**:
```python
from collections import Counter
rides = ["Red", "Blue", "Red", "Green", "Blue", "Red"]
counter = Counter(rides)
busiest = counter.most_common(1)
```

**Sample Input/Output**:
```
Enter line names (type 'quit' to finish):
Red Blue Red Green Blue Red quit

Line usage:
Blue: 2
Green: 1
Red: 3

Busiest line: Red (3 rides)
```

**Learning Focus**: Map operations, key-value pairs, iteration over maps

### Problem 2.2: Set Operations (15 minutes)
**Scenario**: Implement basic set operations on the sets of stations served by two transit lines.

Create a program that:
1. Creates two `std::set<int>` objects holding the station IDs on two different lines
2. Implements functions to find:
   - Union of two lines' stations (stations on either line)
   - Intersection (transfer stations - stations on both lines)
   - Difference (stations only on the first line)
3. Uses `std::set_union`, `std::set_intersection`, and `std::set_difference`

**Starter Code**:
```cpp
#include <set>
#include <algorithm>
#include <iterator>

std::set<int> setUnion(const std::set<int>& line1, const std::set<int>& line2);
std::set<int> setIntersection(const std::set<int>& line1, const std::set<int>& line2);
std::set<int> setDifference(const std::set<int>& line1, const std::set<int>& line2);
```

**Learning Focus**: Set operations, STL algorithms, set theory concepts

### Problem 2.3: Station Directory (15 minutes)
**Scenario**: Create a station information system using multiple associative containers.

Requirements:
1. Use `std::map<int, std::string>` for station ID to station name mapping
2. Use `std::map<std::string, int>` for station name to daily ridership mapping
3. Use `std::set<std::string>` for major hub stations (ridership >= 10000)
4. Implement functions to:
   - Add a station with ID, name, and daily ridership
   - Find a station's ridership by ID
   - List all major hub stations
   - Display all stations with their information

**Learning Focus**: Multiple container coordination, real-world data modeling

---

## Problem Set 3: Unordered Containers and Integration Project (50 minutes)

### Problem 3.1: Hash Performance Comparison (15 minutes)
**Scenario**: Compare performance of ordered vs unordered containers for large datasets.

Create a program that:
1. Generates 100,000 random station IDs
2. Inserts them into both `std::map<int, int>` and `std::unordered_map<int, int>`
3. Measures insertion time for both
4. Measures lookup time for 10,000 random station lookups in both
5. Reports performance differences

**Learning Focus**: Hash table performance, when to use unordered containers

### Problem 3.2: Custom Hash Function (20 minutes)
**Scenario**: Create a hash table for custom objects (similar to Python's custom `__hash__`).

Requirements:
1. Define a `Station` struct with name, ID, and zone
2. Create a custom hash function for `Station`
3. Use `std::unordered_set<Station>` to store unique stations
4. Implement equality operator for duplicate detection
5. Test with stations having same names but different IDs

**Starter Code**:
```cpp
struct Station {
    std::string name;
    int id;
    std::string zone;
    
    bool operator==(const Station& other) const;
};

struct StationHash {
    std::size_t operator()(const Station& s) const;
};

// Usage: std::unordered_set<Station, StationHash> stations;
```

**Learning Focus**: Custom hash functions, equality operators, advanced unordered container usage

### Problem 3.3: Container Integration Project - Transit Network System (15 minutes)
**Scenario**: Build a simplified transit network system that demonstrates multiple container usage.

Requirements:
1. **Stations**: Use `std::map<std::string, Station>` (station code -> Station details)
2. **Operators**: Use `std::unordered_set<std::string>` for unique transit operator names  
3. **Zones**: Use `std::set<std::string>` for fare zones (auto-sorted)
4. **Out Of Service**: Use `std::unordered_map<std::string, std::string>` (station code -> reason)

Implement functions:
- `addStation(code, name, operator, zone)`
- `closeStation(code, reason)`
- `reopenStation(code)`
- `findStationsByOperator(operator)` -> returns vector of stations
- `listZones()` -> shows all fare zones in alphabetical order
- `showClosedStations()` -> shows all currently out-of-service stations

**Station Structure**:
```cpp
struct Station {
    std::string name;
    std::string lineOperator;
    std::string zone;
    bool inService = true;
};
```

**Learning Focus**: Container selection for real scenarios, integration of multiple containers, practical system design

---

## Debugging Challenges (Extra Credit - 15 minutes)

### Challenge 1: Iterator Invalidation Bug
Find and fix the bug in this code:
```cpp
std::vector<int> stationIds = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
for (auto it = stationIds.begin(); it != stationIds.end(); ++it) {
    if (*it % 2 == 0) {
        stationIds.erase(it);  // Bug: What's wrong here?
    }
}
```

### Challenge 2: Map Access Bug  
Find and fix the bug in this code:
```cpp
std::map<std::string, int> ridership;
// ... add some ridership counts
std::string station = "Central";
if (ridership[station] > 0) {  // Bug: What's the issue?
    std::cout << station << " has riders\n";
}
```

---


## Compilation Instructions

**Choose your workflow:**

**Docker/Command Line:**
```bash
g++ -std=c++17 -Wall -Wextra -g -o containers_program program.cpp
```

**VS Code (any workflow):**
- Press `Ctrl+Shift+B` (or `Cmd+Shift+B` on macOS)
- Or use Terminal → Run Build Task

**VS Code Container Debugging Tips:**
- Use Variables panel to see container contents and sizes
- Watch container growth during insertions
- Debug performance comparisons with timing measurements
- Monitor memory usage patterns with different containers

---

## Time Management Tips
- **Problem Set 1**: Focus on getting basic operations working first, then optimize
- **Problem Set 2**: Start with simple test cases, then expand functionality  
- **Problem Set 3**: Plan your data structures before coding, think about which container fits each need
- **If stuck**: Review the Python/Java equivalents to understand the concept, then translate to C++

---

## Evaluation Criteria

**Total: 16 Points (4 points per outcome criteria)**

1. **Correctness** (4 points): Programs compile -- confirmed by a green CI build check -- and work as specified
2. **Code Quality** (4 points): Clean, readable, well-organized code
3. **Best Practices** (4 points): Following C++ idioms and conventions
4. **Documentation** (4 points): Appropriate comments and clear output
