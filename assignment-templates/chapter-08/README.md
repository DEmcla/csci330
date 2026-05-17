# Chapter 8: Statements - Problem Sets

## 📋 Before You Begin

**✅ Prerequisites Check:**
- [ ] **Completed textbook reading**: Chapter 8 "Statements"
- [ ] **Worked through lecture notes**: All core concepts and hands-on problems
- [ ] **Development environment ready**: VS Code + compiler setup verified

**🚫 Don't start these assignments until you've completed the textbook and lecture notes!**

## Instructions
- These problems apply concepts from both the textbook and lecture notes
- Each problem builds on previous concepts  
- **Time expectation**: 2.25 hours total for all three problem sets
- Test all programs thoroughly before submission

**Target Audience**: Students with Python/Java background  
**Total Time**: 2.25 hours (135 minutes)  
**Prerequisites**: Chapters 1-7 completed + Chapter 8 lesson  

## Problem Set Structure

- **Problem Set 1**: Control Flow Fundamentals (45 minutes)
- **Problem Set 2**: Exception Handling & RAII (50 minutes) 
- **Problem Set 3**: Advanced Integration Project (40 minutes)

> **Theme for this chapter**: a self-service **vending machine / checkout kiosk**.
> Every problem builds a piece of the kiosk, so you exercise statements and
> exceptions in a single coherent scenario.

---

## Problem Set 1: Control Flow Fundamentals (45 minutes)

### Problem 1.1: Vending Slot Selector with Switch (15 minutes)

**Background**: Coming from Python dictionaries or Java if-else chains, learn C++ switch statements.

**Task**: Create a program that maps a kiosk slot code to a product name and price using a switch statement.

**Requirements**:
1. Read a slot code (1-99) from user input
2. Map slot codes to products using this scale (group ranges with fall-through):
   - 1-9: Snacks (e.g., "Chips") - $1.50
   - 10-19: Candy (e.g., "Chocolate Bar") - $1.25
   - 20-29: Cold Drinks (e.g., "Bottled Water") - $2.00
   - 30-39: Hot Drinks (e.g., "Coffee") - $2.50
   - 40-99: Premium items (e.g., "Trail Mix") - $3.75
3. Use a switch statement (not if-else)
4. Handle invalid input (negative numbers, slot code 0, > 99)

**Starter Code**:
```cpp
#include <iostream>

int main() {
    std::cout << "Enter slot code (1-99): ";
    int slot;
    std::cin >> slot;
    
    // TODO: Validate input
    // TODO: Map slot code to product/price using switch
    // TODO: Print result
    
    return 0;
}
```

**Expected Output**:
```
Enter slot code (1-99): 24
Slot 24: Cold Drinks - $2.00

Enter slot code (1-99): 105
Error: Slot code must be between 1 and 99

Enter slot code (1-99): -5
Error: Slot code must be between 1 and 99
```

**Learning Goals**:
- Switch statement syntax and break usage
- Input validation
- Range-based case grouping

---

### Problem 1.2: Stock Shelf Display Generator (15 minutes)

**Background**: Practice nested loops and loop control (break/continue).

**Task**: Generate a stock-shelf diagram using nested for loops.

**Requirements**:
1. Ask user for shelf count (1-10)
2. Generate this diagram for shelf count = 5 (shelf N holds N items, drawn as `#`):
```
#
##
###
####
#####
```
3. Use nested for loops
4. Validate input range
5. Use continue to skip even-numbered shelves if user chooses "odd shelves only" mode (those shelves are out of service)

**Starter Code**:
```cpp
#include <iostream>

int main() {
    int shelves;
    char mode;
    
    std::cout << "Enter shelf count (1-10): ";
    std::cin >> shelves;
    
    std::cout << "Show all shelves (a) or in-service odd shelves only (o)? ";
    std::cin >> mode;
    
    // TODO: Validate inputs
    // TODO: Generate diagram with nested loops
    // TODO: Use continue for odd-only mode
    
    return 0;
}
```

**Learning Goals**:
- Nested loop control
- Break and continue statements
- Input validation patterns

---

### Problem 1.3: Range-Based For Loop with Containers (15 minutes)  

**Background**: Transition from Python's for-in loops to C++ range-based for loops.

**Task**: Create a program that processes the prices of items currently loaded in the kiosk.

**Requirements**:
1. Start with a vector of item prices: `{1.50, 2.25, 0.99, 3.75, 1.25, 2.00, 1.75}`
2. Display all prices using range-based for loop
3. Find and display the average price
4. Count items priced above average
5. Apply a $0.25 price increase to all items (using range-based for with references)

**Starter Code**:
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<double> prices = {1.50, 2.25, 0.99, 3.75, 1.25, 2.00, 1.75};
    
    // TODO: Display all prices
    // TODO: Calculate average
    // TODO: Count above average
    // TODO: Add 0.25 to all prices
    // TODO: Display modified prices
    
    return 0;
}
```

**Learning Goals**:
- Range-based for loops
- const auto& vs auto&
- Vector operations
- Accumulation patterns

---

## Problem Set 2: Exception Handling & RAII (50 minutes)

### Problem 2.1: Safe Payment Handler (20 minutes)

**Background**: Learn proper exception handling patterns, transitioning from Python's try/except or Java's try/catch.

**Task**: Create a payment handler for the kiosk that safely rejects invalid purchases.

**Requirements**:
1. Create a `process_purchase` function that throws appropriate exceptions
2. Handle different types of exceptions with specific catch blocks
3. Use standard exception types (`std::invalid_argument`, `std::runtime_error`)
4. Implement a menu-driven purchase loop with exception handling

The handler should reject a purchase when:
- The slot code is unknown (`std::invalid_argument`)
- The selected slot is out of stock (`std::runtime_error`)
- The amount inserted is less than the item price (`std::runtime_error`)

**Starter Code**:
```cpp
#include <iostream>
#include <stdexcept>

// Returns the change due (amount_inserted - price)
double process_purchase(int slot_code, double amount_inserted) {
    // TODO: Implement with proper exception throwing
}

int main() {
    int slot;
    double amount;
    
    while (true) {
        std::cout << "Enter slot code and amount inserted (or 'q' to quit): ";
        
        if (!(std::cin >> slot >> amount)) {
            if (std::cin.eof()) break;
            // TODO: Handle invalid input
        }
        
        try {
            // TODO: Implement purchase handling with exception handling
        } catch (/* TODO: Add appropriate catch blocks */) {
            // TODO: Handle specific exceptions
        }
    }
    
    return 0;
}
```

**Expected Behavior**:
```
Enter slot code and amount inserted (or 'q' to quit): 24 5.00
Dispensing Cold Drinks. Change due: $3.00

Enter slot code and amount inserted (or 'q' to quit): 24 1.00
Error: Insufficient funds for Cold Drinks ($2.00)

Enter slot code and amount inserted (or 'q' to quit): 77 5.00
Error: Slot 77 is out of stock
```

**Learning Goals**:
- Exception throwing and catching
- Standard exception hierarchy
- Input validation with exceptions
- Multiple catch blocks

---

### Problem 2.2: Transaction Log with RAII (30 minutes)

**Background**: Learn RAII (Resource Acquisition Is Initialization) - a key C++ concept not present in Python/Java garbage collection.

**Task**: Create a transaction-log class that demonstrates RAII principles.

**Requirements**:
1. Create a `TransactionLog` class that opens a log file in its constructor
2. Implement RAII: the file should auto-close (with a closing summary line) in the destructor
3. Add methods to record sales and to report counts (entries logged, total revenue)
4. Handle file-related exceptions properly
5. Demonstrate that the log file closes even when exceptions occur

**Starter Code**:
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class TransactionLog {
private:
    std::ofstream file;
    std::string filename;

public:
    // TODO: Constructor - acquire resource (open log file)
    TransactionLog(const std::string& filename) {
        // TODO: Open file and handle errors
    }
    
    // TODO: Destructor - release resource (write summary, close file)
    ~TransactionLog() {
        // TODO: Ensure file is closed
    }
    
    // TODO: Delete copy constructor and assignment (RAII best practice)
    
    void record_sale(const std::string& product, double price) {
        // TODO: Write a log entry, update counters
    }
    
    int entries_logged() const {
        // TODO: Return number of recorded sales
    }
    
    double total_revenue() const {
        // TODO: Return accumulated revenue
    }
};

// Test function that demonstrates RAII even with exceptions
void run_shift(const std::string& filename) {
    try {
        TransactionLog log(filename);
        
        log.record_sale("Chips", 1.50);
        log.record_sale("Coffee", 2.50);
        
        std::cout << "Entries: " << log.entries_logged() << std::endl;
        std::cout << "Revenue: $" << log.total_revenue() << std::endl;
        
        // Simulate an exception
        if (log.total_revenue() > 1000.0) {
            throw std::runtime_error("Cash box full - service required!");
        }
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        // Log file should still be properly closed due to RAII
    }
}

int main() {
    // TODO: Run a shift and test with valid and invalid log filenames
    // TODO: Demonstrate RAII behavior
    
    return 0;
}
```

**Learning Goals**:
- RAII implementation
- Constructor/destructor patterns
- File stream handling
- Exception safety
- Resource management

---

## Problem Set 3: Advanced Integration Project (40 minutes)

### Problem 3.1: Vending Machine Controller (40 minutes)

**Background**: Integrate all Chapter 8 concepts into a comprehensive program that demonstrates control flow, exception handling, and RAII.

**Task**: Create a vending machine controller with robust error handling.

**Requirements**:

**Core Features**:
1. Store product records (slot code, name, price, quantity in stock)
2. Menu-driven interface with switch statement
3. Add products, restock, search, and display inventory
4. Process a purchase with exception handling
5. Save/load inventory data from file using RAII

**Control Flow Requirements**:
- Use switch statement for the menu system
- Use range-based for loops for processing collections
- Use traditional for loops where appropriate
- Implement input validation loops

**Exception Handling Requirements**:
- Custom exception classes for domain-specific errors
- File operation exceptions
- Input validation exceptions
- Graceful error recovery

**RAII Requirements**:
- Automatic file handling
- Proper resource cleanup
- Exception-safe operations

**Starter Code**:
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>

// Custom exception classes
class SlotNotFoundException : public std::runtime_error {
public:
    SlotNotFoundException(const std::string& message)
        : std::runtime_error(message) {}
};

class OutOfStockException : public std::runtime_error {
public:
    OutOfStockException(const std::string& message)
        : std::runtime_error(message) {}
};

class InsufficientFundsException : public std::runtime_error {
public:
    InsufficientFundsException(const std::string& message)
        : std::runtime_error(message) {}
};

// Product class
class Product {
private:
    int slot_code;
    std::string name;
    double price;
    int quantity;

public:
    // TODO: Implement constructors
    Product(int slot_code, const std::string& name, double price, int quantity)
        : slot_code(slot_code), name(name), price(price), quantity(quantity) {}
    
    // TODO: Implement getters
    int get_slot_code() const { return slot_code; }
    const std::string& get_name() const { return name; }
    double get_price() const { return price; }
    int get_quantity() const { return quantity; }
    
    // TODO: Implement stock management with validation
    void restock(int amount) {
        // TODO: Validate amount (must be positive)
        // TODO: Throw std::invalid_argument if invalid
    }
    
    void dispense() {
        // TODO: Decrement quantity
        // TODO: Throw OutOfStockException if quantity is 0
    }
    
    // TODO: Implement display method
    void display() const;
};

// RAII File Manager
class InventoryFileManager {
private:
    std::string filename;

public:
    InventoryFileManager(const std::string& filename) : filename(filename) {}
    
    // TODO: Implement save_products with RAII file handling
    void save_products(const std::vector<Product>& products) {
        // TODO: Use RAII for file operations
        // TODO: Handle file exceptions
    }
    
    // TODO: Implement load_products with RAII file handling
    std::vector<Product> load_products() {
        // TODO: Use RAII for file operations
        // TODO: Handle file exceptions
        // TODO: Return loaded products
    }
};

// Main application class
class VendingMachine {
private:
    std::vector<Product> products;
    InventoryFileManager file_manager;

public:
    VendingMachine(const std::string& data_file)
        : file_manager(data_file) {
        try {
            products = file_manager.load_products();
        } catch (const std::exception& e) {
            std::cout << "Warning: Could not load existing data: " 
                      << e.what() << std::endl;
        }
    }
    
    ~VendingMachine() {
        try {
            file_manager.save_products(products);
        } catch (const std::exception& e) {
            std::cout << "Warning: Could not save data: " 
                      << e.what() << std::endl;
        }
    }
    
    void run() {
        int choice;
        
        do {
            display_menu();
            std::cout << "Enter choice: ";
            
            if (!(std::cin >> choice)) {
                // TODO: Handle invalid input
                continue;
            }
            
            try {
                switch (choice) {
                    case 1:
                        add_product();
                        break;
                    case 2:
                        restock_product();
                        break;
                    case 3:
                        search_product();
                        break;
                    case 4:
                        display_all_products();
                        break;
                    case 5:
                        buy_product();
                        break;
                    case 0:
                        std::cout << "Goodbye!" << std::endl;
                        break;
                    default:
                        std::cout << "Invalid choice!" << std::endl;
                }
            } catch (const SlotNotFoundException& e) {
                std::cout << "Slot Error: " << e.what() << std::endl;
            } catch (const OutOfStockException& e) {
                std::cout << "Stock Error: " << e.what() << std::endl;
            } catch (const InsufficientFundsException& e) {
                std::cout << "Payment Error: " << e.what() << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            
        } while (choice != 0);
    }

private:
    void display_menu() {
        std::cout << "\n=== Vending Machine Controller ===" << std::endl;
        std::cout << "1. Add Product" << std::endl;
        std::cout << "2. Restock Product" << std::endl;
        std::cout << "3. Search Product" << std::endl;
        std::cout << "4. Display Inventory" << std::endl;
        std::cout << "5. Buy Product" << std::endl;
        std::cout << "0. Exit" << std::endl;
    }
    
    // TODO: Implement menu functions
    void add_product();
    void restock_product();
    void search_product();
    void display_all_products();
    void buy_product();
    
    // TODO: Helper function to find a product by slot code
    Product* find_product_by_slot(int slot_code);
};

int main() {
    try {
        VendingMachine machine("inventory.txt");
        machine.run();
    } catch (const std::exception& e) {
        std::cout << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
```

**Expected Features**:
1. **Menu System**: Clean switch-based menu
2. **Data Validation**: All inputs validated with appropriate exceptions
3. **File Operations**: Automatic save/load with RAII
4. **Search Functionality**: Find products by slot code with proper error handling
5. **Purchase Processing**: Buy items with stock and payment validation
6. **Error Recovery**: System continues running after non-fatal errors

**Learning Goals**:
- Integration of all Chapter 8 concepts
- Custom exception hierarchies
- RAII in complex applications
- Menu-driven program architecture
- File I/O with exception safety
- Real-world error handling patterns

---

## Submission Guidelines

### What to Submit

1. **Source code files** for all problems
2. **Test output** showing your programs working
3. **Brief reflection** (2-3 paragraphs) comparing C++ control flow to Python/Java

### Evaluation Criteria

**Total: 16 Points (4 points per outcome criteria)**

1. **Correctness** (4 points): Programs compile -- confirmed by a green CI build check -- and work as specified
2. **Exception Safety** (4 points): Proper exception handling and RAII
3. **Code Quality** (4 points): Clean, readable, well-organized code
4. **Best Practices** (4 points): Following C++ idioms and conventions

### Time Management Tips

- **Problem Set 1**: Focus on getting syntax right, don't over-engineer
- **Problem Set 2**: Take time to understand RAII - it's crucial for C++
- **Problem Set 3**: Start with basic functionality, add features incrementally

### Common Pitfalls to Avoid

1. **Forgetting `break`** in switch statements
2. **Not using RAII** for resource management
3. **Overusing exceptions** for normal control flow
4. **Forgetting `const auto&`** in range-based for loops
5. **Not handling all exception types**

### Getting Help

- Refer to the chapter's quick help guide on Canvas for syntax reminders
- Re-read the chapter's lecture notes on Canvas if you're completely stuck
- Focus on understanding concepts, not just completing problems

---

## Extension Challenges (Optional)

For students who finish early:

1. **Smart Pointers**: Modify Problem 2.2 to use `std::unique_ptr` or `std::shared_ptr`
2. **Exception Specifications**: Add `noexcept` specifications where appropriate
3. **Performance**: Profile your loops and optimize hot paths
4. **Modern C++**: Use C++17 features like structured bindings or `if constexpr`

These extensions are not required but provide additional learning opportunities for advanced students.
