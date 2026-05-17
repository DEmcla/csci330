# Chapter 12: Utilities - Programming Problems

## 📋 Before You Begin

**✅ Prerequisites Check:**
- [ ] **Completed textbook reading**: Chapter 12 "Utilities"
- [ ] **Worked through lecture notes**: All core concepts and hands-on problems
- [ ] **Development environment ready**: VS Code + compiler setup verified

**🚫 Don't start these assignments until you've completed the textbook and lecture notes!**

## Instructions
- These problems apply concepts from both the textbook and lecture notes
- Each problem builds on previous concepts  
- **Time expectation**: 2.25 hours total for all three problem sets
- Test all programs thoroughly before submission

---

## Problem Set 1: Foundation Problems (45 minutes)
*Focus: Basic usage of each utility type*

### Problem 1.1: Safe GPS Fix Operations (15 minutes)
**Learning Objective**: Practice `std::optional` for safe operations

**Problem**: Create a `SafeFixReader` class that handles potentially invalid GPS fix operations. A GPS receiver does not always produce a usable fix, so each lookup may legitimately have "no value".

```cpp
class SafeFixReader {
public:
    // Returns the satellite ID at index, or nullopt if index is invalid
    static std::optional<int> satellite_at(const std::vector<int>& satellites, size_t index);
    
    // Finds the first occurrence of a satellite ID, returns its index or nullopt
    static std::optional<size_t> find_satellite(const std::vector<int>& satellites, int sat_id);
    
    // Converts a raw coordinate string to a decimal-degree value,
    // returns nullopt if conversion fails
    static std::optional<double> to_coordinate(const std::string& raw);
};
```

**Test Cases**:
```cpp
std::vector<int> sats{12, 24, 5, 31};

// Should work
assert(SafeFixReader::satellite_at(sats, 1) == 24);
assert(SafeFixReader::find_satellite(sats, 5) == 2);
assert(SafeFixReader::to_coordinate("42.637") == 42.637);

// Should return nullopt
assert(!SafeFixReader::satellite_at(sats, 10).has_value());
assert(!SafeFixReader::find_satellite(sats, 99).has_value());
assert(!SafeFixReader::to_coordinate("no_fix").has_value());
```

**Python/Java Connection**: Similar to Python methods that return None or Java's Optional returns.

---

### Problem 1.2: Coordinate Format Handler (15 minutes)
**Learning Objective**: Practice `std::variant` for handling different data representations

**Problem**: A waypoint coordinate may be stored as a raw decimal-degree number, a degrees-minutes-seconds (DMS) string, or a named landmark. Create a handler that works with any of these representations.

```cpp
using Coordinate = std::variant<double, std::string, int>;
// double -> decimal degrees, std::string -> DMS text, int -> landmark code

class CoordinateHandler {
public:
    // Process a single coordinate and return a description string
    static std::string describe(const Coordinate& coord);
    
    // Calculate a numeric "key" for the coordinate
    // (double->rounded degrees, string->length, int->the code value)
    static int calculate_key(const Coordinate& coord);
};
```

**Expected Behavior**:
```cpp
Coordinate decimal_coord = 42.6;
Coordinate dms_coord = std::string("42 deg 36 min N");
Coordinate landmark_coord = 7;

assert(CoordinateHandler::describe(decimal_coord) == "Decimal: 42.6");
assert(CoordinateHandler::describe(dms_coord) == "DMS: 42 deg 36 min N");
assert(CoordinateHandler::describe(landmark_coord) == "Landmark: 7");

assert(CoordinateHandler::calculate_key(decimal_coord) == 43);  // rounded
assert(CoordinateHandler::calculate_key(dms_coord) == 15);      // length
assert(CoordinateHandler::calculate_key(landmark_coord) == 7);  // the code
```

---

### Problem 1.3: Waypoint Record System (15 minutes)
**Learning Objective**: Practice `std::tuple` for grouping related data

**Problem**: Create a waypoint record system that uses tuples to manage GPS waypoint information.

```cpp
using WaypointRecord = std::tuple<std::string, double, double>; // label, latitude, longitude

class WaypointManager {
public:
    // Create a waypoint record
    static WaypointRecord create_waypoint(const std::string& label, double lat, double lon);
    
    // Extract waypoint information
    static std::string get_label(const WaypointRecord& wp);
    static double get_latitude(const WaypointRecord& wp);
    static double get_longitude(const WaypointRecord& wp);
    
    // Format waypoint information as a string
    static std::string format_waypoint(const WaypointRecord& wp);
};
```

**Expected Output**:
```cpp
auto wp = WaypointManager::create_waypoint("Trailhead", 42.75, -73.10);
assert(WaypointManager::get_label(wp) == "Trailhead");
assert(WaypointManager::get_latitude(wp) == 42.75);
assert(WaypointManager::get_longitude(wp) == -73.10);
assert(WaypointManager::format_waypoint(wp) == "Trailhead (42.75, -73.10)");
```

---

## Problem Set 2: Intermediate Applications (50 minutes)
*Focus: Practical applications combining multiple utilities*

### Problem 2.1: Track Metadata Parser (25 minutes)
**Learning Objective**: Combine `std::optional` and `std::variant` for robust parsing

**Problem**: A recorded GPS track carries metadata (units, device name, sample interval, etc.) as raw text. Create a parser that can safely interpret these values as different types.

```cpp
using MetaValue = std::variant<int, double, std::string, bool>;

class TrackMetadataParser {
private:
    std::map<std::string, std::string> raw_data;
    
public:
    TrackMetadataParser(const std::map<std::string, std::string>& data) : raw_data(data) {}
    
    // Get a metadata value, attempting to parse it as the requested type
    template<typename T>
    std::optional<T> get_value(const std::string& key);
    
    // Get a value with a default fallback
    template<typename T>
    T get_value_or(const std::string& key, const T& default_value);
    
    // Get all metadata as a map of MetaValues
    std::map<std::string, MetaValue> get_all_parsed();
};
```

**Test Scenario**:
```cpp
std::map<std::string, std::string> meta_data = {
    {"sample_interval", "5"},
    {"device", "TrailMate-3"},
    {"min_elevation", "318.4"},
    {"smoothing", "true"},
    {"bad_field", "not_a_number"}
};

TrackMetadataParser parser(meta_data);

// Should successfully parse
assert(parser.get_value<int>("sample_interval") == 5);
assert(parser.get_value<std::string>("device") == "TrailMate-3");
assert(parser.get_value<double>("min_elevation") == 318.4);

// Should return nullopt for invalid parsing
assert(!parser.get_value<int>("bad_field").has_value());

// Should use defaults
assert(parser.get_value_or<int>("missing_key", 60) == 60);
```

---

### Problem 2.2: Leg Timing Recorder (25 minutes)
**Learning Objective**: Use `std::chrono` and `std::tuple` for elapsed-time measurement

**Problem**: A track is made of legs (the segment between two waypoints). Create a utility that measures how long a leg takes to process and returns detailed timing statistics.

```cpp
#include <chrono>
#include <functional>

using TimingResult = std::tuple<double, double, double>; // min_time, max_time, avg_time (in milliseconds)

class LegTimer {
public:
    // Run a leg-processing function multiple times and return timing statistics
    template<typename Func>
    static TimingResult time_leg(Func leg_function, int iterations = 1000);
    
    // Format timing results as a string
    static std::string format_results(const TimingResult& results);
    
    // Compare two timing results - returns optional<string> with comparison
    static std::optional<std::string> compare_results(
        const TimingResult& result1, 
        const TimingResult& result2,
        const std::string& name1 = "Leg 1",
        const std::string& name2 = "Leg 2"
    );
};
```

**Example Usage**:
```cpp
// Leg-processing functions of different cost
auto short_leg = []() {
    int sum = 0;
    for (int i = 0; i < 100; ++i) sum += i;
    return sum;
};

auto long_leg = []() {
    int sum = 0;
    for (int i = 0; i < 10000; ++i) sum += i;
    return sum;
};

auto short_results = LegTimer::time_leg(short_leg, 1000);
auto long_results = LegTimer::time_leg(long_leg, 100);

std::cout << "Short leg: " << LegTimer::format_results(short_results) << std::endl;
std::cout << "Long leg: " << LegTimer::format_results(long_results) << std::endl;

auto comparison = LegTimer::compare_results(short_results, long_results, "Short", "Long");
if (comparison) {
    std::cout << *comparison << std::endl;
}
```

---

## Problem Set 3: Integration Project (40 minutes)
*Focus: Building a complete application using all utilities*

### Problem 3.1: GPS Track Analysis Pipeline (40 minutes)
**Learning Objective**: Integrate all utilities in a realistic GPS-track processing scenario

**Problem**: Build a track analysis pipeline that processes elevation readings logged at GPS waypoints, handles failed fixes gracefully, and provides timing information.

```cpp
// Data structures
using ElevationSample = std::variant<int, double, std::string>;
// int / double -> elevation in metres; std::string -> a failed fix (raw text)
using ProcessingResult = std::tuple<size_t, size_t, double>; // processed_count, error_count, processing_time_ms
using TrackSummary = std::tuple<std::optional<double>, std::optional<double>, size_t>; // min, max, count

class TrackAnalyzer {
private:
    std::vector<ElevationSample> samples;
    
public:
    // Load samples from different sources
    void add_sample(const ElevationSample& sample);
    void load_from_strings(const std::vector<std::string>& raw_samples);
    
    // Process samples with error handling and timing
    ProcessingResult process_samples();
    
    // Calculate elevation statistics for numeric samples only
    TrackSummary calculate_elevation_summary();
    
    // Get samples of a specific type
    template<typename T>
    std::vector<T> get_samples_of_type();
    
    // Export results with timing information
    std::optional<std::string> export_summary();
};

// Helper class for timing operations
class TimedOperation {
private:
    std::chrono::steady_clock::time_point start_time;
    std::string operation_name;
    
public:
    TimedOperation(const std::string& name);
    ~TimedOperation(); // Print timing on destruction
    
    double elapsed_ms() const;
};
```

**Implementation Requirements**:

1. **Sample Loading**: Handle conversion from raw GPS-log strings to numeric elevations, storing unconvertible entries (failed fixes) as string samples
2. **Processing**: Time the processing operation and count successes/failures
3. **Analysis**: Calculate min/max elevation for numeric values only, handle an empty track gracefully
4. **Error Handling**: Use optional types for operations that might fail
5. **Timing**: Provide accurate timing for all major operations

**Test Scenario**:
```cpp
TrackAnalyzer analyzer;

// Load mixed elevation log data
std::vector<std::string> raw_samples = {
    "318",          // int elevation
    "402.7",        // double elevation
    "no_fix",       // failed fix
    "455",          // int elevation
    "289.3",        // double elevation
    "signal_lost",  // failed fix
    "dropout"       // failed fix
};

analyzer.load_from_strings(raw_samples);

// Process and analyze
auto [processed, errors, time_ms] = analyzer.process_samples();
auto [min_val, max_val, numeric_count] = analyzer.calculate_elevation_summary();

// Verify results
assert(processed == 7);  // All items processed
assert(errors == 0);     // No processing errors (failed fixes handled gracefully)
assert(time_ms > 0);     // Some time elapsed

assert(min_val.has_value() && *min_val == 289.3);  // Lowest elevation
assert(max_val.has_value() && *max_val == 455);    // Highest elevation
assert(numeric_count == 4);  // 318, 402.7, 455, 289.3

// Test type filtering
auto failed_fixes = analyzer.get_samples_of_type<std::string>();
assert(failed_fixes.size() == 3);  // "no_fix", "signal_lost", "dropout"

// Export summary
auto summary = analyzer.export_summary();
assert(summary.has_value());
```

**Expected Summary Output**:
```
GPS Track Analysis Summary
==========================
Total samples: 7
Numeric elevations: 4 (min: 289.3, max: 455)
Failed fixes: 3
Processing time: X.XX ms
```

---

## Time Verification

- **Problem Set 1**: 45 minutes (3 × 15 minutes)
- **Problem Set 2**: 50 minutes (25 + 25 minutes)  
- **Problem Set 3**: 40 minutes (1 × 40 minutes)
- **Total**: 135 minutes (2.25 hours) ✓


## Compilation Instructions

**Choose your workflow:**

**Docker/Command Line:**
```bash
g++ -std=c++17 -Wall -Wextra -g -o utilities_program program.cpp
```

**VS Code (any workflow):**
- Press `Ctrl+Shift+B` (or `Cmd+Shift+B` on macOS)
- Or use Terminal → Run Build Task

**VS Code Utility Types Debugging Tips:**
- Use Variables panel to see optional/variant internal state
- Watch tuple unpacking and structured bindings
- Debug std::chrono time calculations step-by-step
- Monitor variant type changes during execution

---

## Connections to Future Learning
These utilities prepare students for:
- Advanced template programming
- Modern C++ idioms and patterns
- Error handling strategies
- Performance measurement and optimization
- Data processing applications

---

## Evaluation Criteria

**Total: 16 Points (4 points per outcome criteria)**

1. **Correctness** (4 points): Programs compile -- confirmed by a green CI build check -- and work as specified
2. **Code Quality** (4 points): Clean, readable, well-organized code
3. **Best Practices** (4 points): Following C++ idioms and conventions
4. **Documentation** (4 points): Appropriate comments and clear output
