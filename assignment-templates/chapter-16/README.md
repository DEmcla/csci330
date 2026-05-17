# Chapter 16: Streams - Practice Problems

## 📋 Before You Begin

**✅ Prerequisites Check:**
- [ ] **Completed textbook reading**: Chapter 16 "Streams"
- [ ] **Worked through lecture notes**: All core concepts and hands-on problems
- [ ] **Development environment ready**: VS Code + compiler setup verified

**🚫 Don't start these assignments until you've completed the textbook and lecture notes!**

## Instructions
- These problems apply concepts from both the textbook and lecture notes
- Each problem builds on previous concepts
- **Time expectation**: 2.25 hours total for all three problem sets
- Test all programs thoroughly before submission

---

## Problem Set 1: File I/O Basics (45 minutes)

### Problem 1.1: Text File Statistics (25 minutes)

**Objective**: Read a text file with stream I/O and report statistics about its contents.

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct TextStats {
    int line_count = 0;
    int word_count = 0;
    int char_count = 0;
    std::string longest_line;
};

class TextFileAnalyzer {
public:
    // Write the sample text to a file so the program is self-contained.
    void create_sample_file(const std::string& filename) {
        std::ofstream file(filename);
        // TODO: Check that the file opened; if not, print an error and return.

        // TODO: Write at least four lines of text to the file using <<.
        //       Vary the line lengths so "longest line" is meaningful.
    }

    // Read the file back and compute statistics.
    TextStats analyze(const std::string& filename) {
        TextStats stats;
        std::ifstream file(filename);
        // TODO: Check that the file opened; if not, print an error and
        //       return the empty stats.

        std::string line;
        while (std::getline(file, line)) {
            // TODO: Count this line.
            // TODO: Add the line's length to the character count.
            // TODO: Count the words on this line (use an istringstream
            //       and the >> operator).
            // TODO: Track the longest line seen so far.
        }
        return stats;
    }

    void print_report(const TextStats& stats) {
        std::cout << "Lines: " << stats.line_count << std::endl;
        std::cout << "Words: " << stats.word_count << std::endl;
        std::cout << "Characters: " << stats.char_count << std::endl;
        std::cout << "Longest line: \"" << stats.longest_line << "\"" << std::endl;
        if (stats.line_count > 0) {
            double avg = static_cast<double>(stats.word_count) / stats.line_count;
            std::cout << "Average words per line: " << avg << std::endl;
        }
    }
};

int main() {
    TextFileAnalyzer analyzer;
    const std::string filename = "sample.txt";

    analyzer.create_sample_file(filename);
    TextStats stats = analyzer.analyze(filename);
    analyzer.print_report(stats);

    return 0;
}
```

**Expected Output** (your numbers depend on the sample text you write; this is the four-line sample used in the reference solution):
```
Lines: 4
Words: 29
Characters: 152
Longest line: "The quick brown fox jumps over the lazy dog again."
Average words per line: 7.25
```

**Hints**:
- Use `std::getline(file, line)` as the loop condition - it is the idiomatic read loop.
- To count words on a line, feed the line into a `std::istringstream` and pull tokens with `>>`.
- `line.length()` gives the character count for that line (the newline is not included).

### Problem 1.2: CSV Data Processor (20 minutes)

**Objective**: Read a CSV record file, aggregate the data, and write a summary to a new file.

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

struct Employee {
    std::string name;
    std::string department;
    double salary = 0.0;
};

class CSVProcessor {
public:
    // Create an input CSV file with a header row and several records.
    void create_input_csv(const std::string& filename) {
        std::ofstream file(filename);
        // TODO: Check the file opened.
        // TODO: Write a header line: Name,Department,Salary
        // TODO: Write at least five employee records, one per line,
        //       spread across at least two departments.
    }

    // Read the CSV file into a vector of Employee records.
    std::vector<Employee> read_csv(const std::string& filename) {
        std::vector<Employee> employees;
        std::ifstream file(filename);
        // TODO: Check the file opened; return empty vector on failure.

        std::string line;
        // TODO: Read and discard the header line.

        while (std::getline(file, line)) {
            std::istringstream ss(line);
            Employee e;
            std::string salary_field;
            // TODO: Use std::getline(ss, field, ',') to split the line into
            //       name, department, and salary_field.
            // TODO: Convert salary_field to a double with std::stod and
            //       store it in e.salary.
            // TODO: Push the completed Employee onto the vector.
        }
        return employees;
    }

    // Compute average salary per department.
    std::map<std::string, double> average_salary_by_department(
            const std::vector<Employee>& employees) {
        std::map<std::string, double> averages;
        // TODO: Sum salaries and count employees per department, then
        //       divide to produce the average for each department.
        return averages;
    }

    // Write the department summary to an output file.
    void write_summary(const std::string& filename,
                       const std::map<std::string, double>& averages) {
        std::ofstream file(filename);
        // TODO: Check the file opened.
        // TODO: Write a header line, then one line per department with the
        //       department name and its average salary formatted to 2 decimals.
    }
};

int main() {
    CSVProcessor processor;
    const std::string input = "employees.csv";
    const std::string output = "department_summary.csv";

    processor.create_input_csv(input);
    std::vector<Employee> employees = processor.read_csv(input);
    std::cout << "Read " << employees.size() << " employee records" << std::endl;

    auto averages = processor.average_salary_by_department(employees);
    processor.write_summary(output, averages);

    std::cout << "Department averages:" << std::endl;
    for (const auto& pair : averages) {
        std::cout << "  " << pair.first << ": $"
                  << std::fixed << std::setprecision(2) << pair.second << std::endl;
    }
    std::cout << "Summary written to " << output << std::endl;

    return 0;
}
```

**Expected Output** (with the sample data shown in the solution):
```
Read 5 employee records
Department averages:
  Engineering: $82500.00
  Sales: $61000.00
Summary written to department_summary.csv
```

**Hints**:
- `std::getline(ss, field, ',')` splits on commas - call it once per field.
- Convert the salary text to a number with `std::stod`.
- For the per-department average, keep a running sum and count in two maps keyed by department name.

---

## Problem Set 2: Formatted Reports (45 minutes)

### Problem 2.1: Formatted Report Generator (45 minutes)

**Objective**: Generate a professional, column-aligned report using stream manipulators.

```cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct Product {
    std::string name;
    int units_sold = 0;
    double unit_price = 0.0;

    double revenue() const { return units_sold * unit_price; }
};

class ReportGenerator {
public:
    // Print a report header: a title, a separator line, and column headers.
    void print_header() {
        // TODO: Print a centered or left-aligned title line.
        // TODO: Print a separator line (e.g. std::string(54, '=')).
        // TODO: Print column headers ("Product", "Units", "Price", "Revenue")
        //       using std::setw and std::left so they align with the rows.
    }

    // Print one product as an aligned table row.
    void print_row(const Product& p) {
        // TODO: Print the product name left-aligned in a fixed-width column.
        // TODO: Print units right-aligned in a fixed-width column.
        // TODO: Print the unit price and revenue with a '$' prefix,
        //       fixed-point, 2 decimal places, right-aligned.
        // Remember: std::setw applies only to the next item - reissue it
        //           for every column.
    }

    // Print a footer with the grand total revenue.
    void print_footer(const std::vector<Product>& products) {
        // TODO: Print a separator line.
        // TODO: Sum the revenue of all products.
        // TODO: Print a "TOTAL" line with the grand total, formatted as currency.
    }

    void generate(const std::vector<Product>& products) {
        print_header();
        for (const auto& p : products) {
            print_row(p);
        }
        print_footer(products);
    }
};

int main() {
    std::vector<Product> products = {
        {"Wireless Mouse", 120, 29.99},
        {"Mechanical Keyboard", 45, 89.95},
        {"USB-C Hub", 80, 39.50},
        {"Laptop Stand", 30, 24.00}
    };

    ReportGenerator report;
    report.generate(products);

    return 0;
}
```

**Expected Output** (exact spacing depends on the column widths you choose; aim for clean alignment - this is the reference solution's layout):
```
SALES REPORT
======================================================
Product                  Units       Price     Revenue
------------------------------------------------------
Wireless Mouse             120      $29.99    $3598.80
Mechanical Keyboard         45      $89.95    $4047.75
USB-C Hub                   80      $39.50    $3160.00
Laptop Stand                30      $24.00     $720.00
======================================================
TOTAL                                        $11526.55
```

**Hints**:
- Use `std::left` for text columns and `std::right` for numeric columns.
- `std::setw(n)` must be reissued before *each* field - it is not sticky.
- Apply `std::fixed << std::setprecision(2)` once before printing money values.
- Build separator lines with `std::string(width, '=')`.

---

## Problem Set 3: Custom Stream Operators (45 minutes)

### Problem 3.1: Date Class with Stream Operators (45 minutes)

**Objective**: Implement `<<` and `>>` operators for a `Date` class so it works naturally with streams.

```cpp
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

class Date {
private:
    int month_;
    int day_;
    int year_;

public:
    Date() : month_(1), day_(1), year_(2000) {}
    Date(int m, int d, int y) : month_(m), day_(d), year_(y) {}

    int month() const { return month_; }
    int day() const { return day_; }
    int year() const { return year_; }

    void set(int m, int d, int y) { month_ = m; day_ = d; year_ = y; }

    // Return true if this Date represents a valid calendar date.
    bool is_valid() const {
        // TODO: Reject months outside 1..12 and years <= 0.
        // TODO: Reject days outside 1..(days in that month).
        //       Account for leap years in February.
        return false;  // replace with real logic
    }

    // Friend declarations so the operators can read/write private members.
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d);
};

// Output operator: print the date in MM/DD/YYYY format.
std::ostream& operator<<(std::ostream& os, const Date& d) {
    // TODO: Print month and day zero-padded to 2 digits, year to 4 digits,
    //       separated by '/'. Save and restore the stream fill character so
    //       you do not leave '0' as the fill for later output.
    return os;
}

// Input operator: read a date in MM/DD/YYYY format.
std::istream& operator>>(std::istream& is, Date& d) {
    // TODO: Read month, a '/', day, a '/', year.
    // TODO: If the separators are not '/' OR the resulting date is not
    //       valid, call is.setstate(std::ios::failbit).
    // TODO: On success, store the values into d.
    return is;
}

int main() {
    // Output test
    Date independence_day(7, 4, 1776);
    std::cout << "Formatted date: " << independence_day << std::endl;

    // Round-trip test: write to a string, read it back
    std::ostringstream oss;
    oss << independence_day;
    std::istringstream iss(oss.str());
    Date parsed;
    iss >> parsed;
    std::cout << "Round-trip date: " << parsed << std::endl;

    // Parsing valid and invalid input
    std::vector<std::string> inputs = {
        "12/25/2024",   // valid
        "02/29/2024",   // valid (2024 is a leap year)
        "13/01/2024",   // invalid month
        "02/30/2024"    // invalid day
    };

    for (const std::string& text : inputs) {
        std::istringstream stream(text);
        Date d;
        stream >> d;
        if (stream.fail()) {
            std::cout << "Rejected: " << text << std::endl;
        } else {
            std::cout << "Accepted: " << d << std::endl;
        }
    }

    return 0;
}
```

**Expected Output**:
```
Formatted date: 07/04/1776
Round-trip date: 07/04/1776
Accepted: 12/25/2024
Accepted: 02/29/2024
Rejected: 13/01/2024
Rejected: 02/30/2024
```

**Hints**:
- For `operator<<`, use `std::setfill('0')` and `std::setw(2)` for month and day - then restore the previous fill so later output is not corrupted.
- For `operator>>`, read into `int` and `char` variables; check each separator equals `'/'`.
- Set the fail bit with `is.setstate(std::ios::failbit)` when the date is malformed or invalid.
- A leap year is divisible by 4, except century years must also be divisible by 400.

---

## 🚀 Challenge Problems (Optional)

### Challenge 1: Quoted CSV Fields

Extend the CSV processor so it correctly handles fields wrapped in double
quotes that may themselves contain commas (e.g. `"Doe, Jr."`).

### Challenge 2: Configuration File Parser

Write a parser for a simple INI-style configuration file:
`key = value` lines, `# comment` lines, and `[section]` headers.

### Challenge 3: Multiple Date Formats

Extend the `Date` input operator so it also accepts `YYYY-MM-DD` and
`DD-MM-YYYY`, detecting the format from the separators and field order.

---

## 📝 Submission Guidelines

1. **Code Quality**:
   - Use meaningful variable names
   - Add comments for non-obvious logic
   - Handle edge cases (missing files, malformed input)
   - Follow const-correctness

2. **Testing**:
   - Test with the provided sample data
   - Verify files are actually created and contain the expected content
   - Check behavior when an input file does not exist

3. **Stream Best Practices**:
   - Always check `if (!file)` after opening
   - Let RAII close files - do not rely on manual `.close()`
   - Save and restore stream state when changing formatting

4. **Error Handling**:
   - Detect failed file opens and report them clearly
   - Use `setstate(failbit)` in custom `>>` operators on bad input
   - Guard `std::stod` / `std::stoi` against empty or malformed fields

---

## 💡 Hints and Tips

- **Read loops**: `while (std::getline(file, line))` and `while (file >> value)` are the idiomatic patterns - never test `eof()` before the read.
- **Splitting lines**: feed a line into a `std::istringstream`, then split with `std::getline(ss, field, ',')`.
- **Sticky formatting**: `std::fixed`, `std::setprecision`, and `std::setfill` persist; `std::setw` does not.
- **Currency**: `std::cout << std::fixed << std::setprecision(2)` once, then print all money values.
- **Custom operators**: always return the stream so calls can chain.

Remember: the CSV read/write pattern in these problems is exactly what the course capstone needs for parsing files and storing records to disk.

---

## Evaluation Criteria

**Total: 16 Points (4 points per outcome criteria)**

1. **Correctness** (4 points): Programs compile -- confirmed by a green CI build check -- and work as specified
2. **Code Quality** (4 points): Clean, readable, well-organized code
3. **Best Practices** (4 points): Following C++ idioms and conventions
4. **Documentation** (4 points): Appropriate comments and clear output
