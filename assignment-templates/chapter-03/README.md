# Chapter 3: Reference Types - Programming Problems

> **Stuck or want to check your approach?** See [`HELPERS.md`](HELPERS.md) in this folder for scaffolding and hints paired with these assignments.

## 📋 Before You Begin

**✅ Prerequisites Check:**
- [ ] **Completed textbook reading**: Chapter 3 "References and Aliases"
- [ ] **Worked through lecture notes**: All core concepts and hands-on problems
- [ ] **Development environment ready**: VS Code + compiler setup verified

**🚫 Don't start these assignments until you've completed the textbook and lecture notes!**

**Domain:** Every problem in this chapter works with **game player state** - the data a video game keeps for each player. You will use references to read and mutate that state without making expensive copies.

**Total Time Budget: 2.25 hours across all problem sets**

## Problem Set 1: Basic References (45 minutes)

### Problem 1.1: Reference Fundamentals (15 minutes)
**Objective**: Understand reference creation and basic usage

Create a program that demonstrates basic reference usage:

```cpp
// Template provided:
#include <cstdio>

int main() {
    // TODO: Create an integer variable 'health' with value 85
    // TODO: Create a reference 'health_ref' that refers to 'health'
    // TODO: Print both health and health_ref
    // TODO: Modify health through health_ref to 92
    // TODO: Print both values again to show they're the same
    
    return 0;
}
```

**Expected Output:**
```
Original health: 85, Reference: 85
Modified health: 92, Reference: 92
```

### Problem 1.2: References vs Copies (15 minutes)
**Objective**: Understand that references are aliases, not copies

Write a program that shows the difference between references and copies:

```cpp
// Template provided:
#include <cstdio>

int main() {
    int score = 100;
    
    // TODO: Create a copy of score called 'copy_score'
    // TODO: Create a reference to score called 'score_ref'
    
    // TODO: Modify score to 200
    
    // TODO: Print all three values to show the difference
    
    return 0;
}
```

**Expected Output:**
```
Score: 200, Copy: 100, Reference: 200
```

### Problem 1.3: Multiple References (15 minutes)
**Objective**: Multiple references can refer to the same object

Create a program where multiple references point to the same variable:

```cpp
// Template provided:
#include <cstdio>

int main() {
    int shared_score = 50;
    
    // TODO: Create two different references to shared_score
    // TODO: Modify shared_score through the first reference
    // TODO: Print the value using the second reference
    // TODO: Show that all three (original + 2 references) have the same value
    
    return 0;
}
```

---

## Problem Set 2: Const References and Functions (45 minutes)

### Problem 2.1: Const Reference Parameters (20 minutes)
**Objective**: Use const references for read-only function parameters

Create a program with functions that use const references:

```cpp
// Template provided:
#include <cstdio>

struct Player {
    char name[50];
    int level;
    double score;
};

// TODO: Write a function 'display_player' that takes a const Player reference
// and prints the player's information

// TODO: Write a function 'is_top_player' that takes a const Player reference
// and returns true if score >= 3.5

int main() {
    Player alice = {"Alice the Brave", 20, 3.8};
    
    // TODO: Call both functions with alice
    
    return 0;
}
```

**Expected Output:**
```
Player: Alice the Brave, Level: 20, Score: 3.80
Alice the Brave is a top player: Yes
```

### Problem 2.2: Modifying Through Non-Const References (25 minutes)
**Objective**: Use non-const references to modify objects in functions

Extend the previous program:

```cpp
// Template provided (build on Problem 2.1):
#include <cstdio>
#include <cstring>

struct Player {
    char name[50];
    int level;
    double score;
};

// TODO: Keep your display_player and is_top_player functions from 2.1

// TODO: Write a function 'update_score' that takes a Player reference (non-const)
// and a new score value, then updates the player's score

// TODO: Write a function 'level_up' that takes a Player reference
// and increments their level by 1

int main() {
    Player bob = {"Bob the Bold", 19, 3.2};
    
    // TODO: Display Bob's initial info
    // TODO: Update Bob's score to 3.6
    // TODO: Level Bob up
    // TODO: Display Bob's updated info
    // TODO: Check if Bob is now a top player
    
    return 0;
}
```

**Expected Output:**
```
Initial - Player: Bob the Bold, Level: 19, Score: 3.20
Bob the Bold is a top player: No
Updated - Player: Bob the Bold, Level: 20, Score: 3.60
Bob the Bold is a top player: Yes
```

---

## Problem Set 3: Advanced References and Object Lifecycle (55 minutes)

### Problem 3.1: Reference Return Types (25 minutes)
**Objective**: Understand functions that return references

Create a program that demonstrates reference return types:

```cpp
// Template provided:
#include <cstdio>

struct Player {
    double health;
    int player_id;
};

// TODO: Write a function 'get_health' that takes a const Player reference
// and returns a const reference to the health

// TODO: Write a function 'get_player_for_update' that takes a roster of Player
// and a player id, then returns a reference to the matching player
// (For simplicity, assume the player exists and is at index = player_id - 1)

int main() {
    Player roster[3] = {
        {1000.50, 1},
        {2500.75, 2}, 
        {750.25, 3}
    };
    
    // TODO: Use get_health to display player 2's health
    // TODO: Use get_player_for_update to modify player 1's health to 1200.00
    // TODO: Display all player health values
    
    return 0;
}
```

**Expected Output:**
```
Player 2 health: 2500.75
Updated health values:
Player 1: 1200.00
Player 2: 2500.75
Player 3: 750.25
```

### Problem 3.2: Object Lifecycle with References (30 minutes)
**Objective**: Understand object creation, copying, and references

Create a comprehensive program that demonstrates object lifecycle:

```cpp
// Template provided:
#include <cstdio>
#include <cstring>

struct Avatar {
    char title[100];
    char class_name[50];
    int level;
    double power;
};

// TODO: Write a function 'create_avatar' that takes title, class_name, level, power
// and returns an Avatar (by value)

// TODO: Write a function 'print_avatar_info' that takes a const Avatar reference
// and prints all avatar information

// TODO: Write a function 'apply_buff' that takes an Avatar reference and 
// buff percentage, then increases the power

// TODO: Write a function 'clone_avatar' that takes a const Avatar reference and
// returns a new Avatar with the same information but prefix "Clone of " to title

int main() {
    printf("=== Creating original avatar ===\n");
    // TODO: Create an avatar "Storm Walker" of class "Mage", level 30, power 49.99
    
    printf("\n=== Original avatar info ===\n");
    // TODO: Print the original avatar info
    
    printf("\n=== Applying 20%% buff ===\n");
    // TODO: Apply 20% buff to original avatar
    // TODO: Print updated info
    
    printf("\n=== Creating a clone ===\n");
    // TODO: Create a clone of the buffed avatar
    // TODO: Print clone info
    
    printf("\n=== Modifying clone only ===\n");
    // TODO: Apply 10% buff to clone only
    // TODO: Print both original and clone to show they're different
    
    return 0;
}
```

**Expected Output:**
```
=== Creating original avatar ===

=== Original avatar info ===
Title: Storm Walker
Class: Mage
Level: 30
Power: 49.99

=== Applying 20% buff ===
Title: Storm Walker
Class: Mage
Level: 30
Power: 59.99

=== Creating a clone ===
Title: Clone of Storm Walker
Class: Mage
Level: 30
Power: 59.99

=== Modifying clone only ===
Original - Title: Storm Walker, Power: 59.99
Clone - Title: Clone of Storm Walker, Power: 65.99
```

---

## File Organization

Create your solutions in the following structure:
```
chapter_03_solutions/
├── problem_1_1_basic_references.cpp
├── problem_1_2_references_vs_copies.cpp
├── problem_1_3_multiple_references.cpp
├── problem_2_1_const_references.cpp
├── problem_2_2_modifying_references.cpp
├── problem_3_1_reference_returns.cpp
└── problem_3_2_object_lifecycle.cpp
```

## Compilation Instructions

**Choose your workflow:**

**Docker/Command Line:**
```bash
g++ -std=c++17 -Wall -Wextra -o program_name source_file.cpp
```

**VS Code (any workflow):**
- Press `Ctrl+Shift+B` (or `Cmd+Shift+B` on macOS)
- Or use Terminal → Run Build Task

**CMake (if using assignment templates):**
```bash
mkdir -p build && cd build
cmake .. && make
```

**For reference debugging, add debug symbols:**
```bash
g++ -std=c++17 -g -Wall -Wextra -o program_name source_file.cpp
```

**VS Code Debugging Tips for Chapter 3:**
- Set breakpoints at reference declarations to watch alias creation
- Use Variables panel to see both variable and reference values
- Add `&variable` and `&reference` to Watch panel to confirm same address
- Step through functions to see reference parameter behavior

## Success Checklist

After completing all problems, you should be able to:
- [ ] Create references and understand they're aliases
- [ ] Use const references for read-only access
- [ ] Write functions that take reference parameters
- [ ] Return references from functions safely
- [ ] Understand when objects are copied vs referenced
- [ ] Apply const correctness principles
- [ ] Debug common reference-related errors

## Common Pitfalls to Avoid

1. **Uninitialized References**: References must be initialized when declared
2. **Returning Dangling References**: Don't return references to local variables
3. **Confusing Reference Syntax**: `&` in declaration, not in usage
4. **Const Violations**: Can't modify through const references
5. **Thinking References Can Be Reassigned**: References are permanent aliases

## Getting Help

If you get stuck:
1. Check the chapter's quick help guide on Canvas
2. Review the chapter's lecture notes on Canvas for concept explanations
3. Look at compiler error messages carefully
4. Test with simple examples first
5. Use the debugger to step through your code

---

## Evaluation Criteria

**Total: 16 Points (4 points per outcome criteria)**

1. **Correctness** (4 points): Programs compile -- confirmed by a green CI build check -- and work as specified
2. **Code Quality** (4 points): Clean, readable, well-organized code
3. **Best Practices** (4 points): Following C++ idioms and conventions
4. **Documentation** (4 points): Appropriate comments and clear output
