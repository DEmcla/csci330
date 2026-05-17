# Chapter 3: Assignment Helpers - References

## Purpose
Scaffolding and hints for the reference assignments. Use when stuck or to verify your approach.

**Domain reminder:** Every problem works with **game player state** - health, score, level, position. References let your code touch that state directly instead of copying it.

---

## Key Concepts Reminder

### Reference Rules
1. **Must be initialized**: `int& ref = variable;`
2. **Cannot be rebound**: Once set, always refers to same variable
3. **No null references**: Unlike pointers, must refer to something
4. **Automatic dereferencing**: No need for `*` operator

### Function Parameter Guidelines
```cpp
void by_value(Type x)           // Copies, safe but potentially slow
void by_reference(Type& x)       // No copy, can modify
void by_const_ref(const Type& x) // No copy, cannot modify
```

---

## Problem Set Solutions Structure

### Problem 1.1: Reference Fundamentals Helper
```cpp
int main() {
    int health = 85;
    int& health_ref = health;  // Reference MUST be initialized

    // Both refer to same memory location
    printf("Original health: %d, Reference: %d\n", health, health_ref);
    printf("Addresses: %p vs %p\n", &health, &health_ref);  // Same!

    health_ref = 92;  // Modifies original
    printf("Modified health: %d, Reference: %d\n", health, health_ref);
}
```

### Problem 1.2: Array References Helper
```cpp
// Function taking a roster array by reference (preserves size info!)
void boost_roster(int (&scores)[5]) {  // Note syntax: (&scores)[5]
    // sizeof(scores) works correctly here!
    for (int i = 0; i < 5; i++) {
        scores[i] *= 2;
    }
}
```

### Problem 2.1: Swap Function Pattern
```cpp
// Classic swap with references - useful for swapping player scores
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    // No return needed - originals are modified!
}

// Generic swap template (preview of templates)
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

### Problem 2.2: Struct Modification Pattern
```cpp
struct Player {
    char name[50];
    double score;
};

// Read-only access
void print_player(const Player& p) {
    // p.score = 4.0;  // ERROR: cannot modify const reference
    printf("%s: %.2f\n", p.name, p.score);
}

// Modification access
void update_score(Player& p, double new_score) {
    p.score = new_score;  // OK: non-const reference
}
```

### Problem 2.3: Reference Return Pattern
```cpp
// Safe: returning reference to parameter
int& max(int& a, int& b) {
    return (a > b) ? a : b;
}

// DANGEROUS: returning reference to local
int& bad_function() {
    int local = 42;
    return local;  // WARNING: local dies after function!
}

// Safe: returning reference to static/global
int& get_match_counter() {
    static int counter = 0;
    return counter;  // OK: static lives forever
}
```

---

## Common Patterns and Solutions

### Pattern 1: Const-Correctness Chain
```cpp
void read_only(const int& x) {
    // Cannot modify x
    print_value(x);  // OK if print_value also takes const&
}

void modifier(int& x) {
    x = 42;
    read_only(x);  // OK: can pass non-const to const function
}
```

### Pattern 2: Reference vs Pointer Decision
```cpp
// Use reference when:
void process(Player& player) {  // Never null, must exist
    player.score = 42;
}

// Use pointer when:
void process(Player* player) {  // Could be nullptr
    if (player) {
        player->score = 42;
    }
}
```

### Pattern 3: Large Object Optimization
```cpp
struct PlayerWorld {
    char terrain[10000];
};

// BAD: Makes expensive copy
void slow_function(PlayerWorld world) { }

// GOOD: No copy, read-only
void fast_function(const PlayerWorld& world) { }
```

---

## Debugging Tips

### Check Reference Binding
```cpp
int health = 5;
int& ref = health;
printf("health address: %p\n", &health);
printf("ref address: %p\n", &ref);  // Should be same!
```

### Trace Modifications
```cpp
void debug_swap(int& a, int& b) {
    printf("Before: a=%d, b=%d\n", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("After: a=%d, b=%d\n", a, b);
}
```

### Validate Const-Correctness
If you get "cannot bind non-const lvalue reference" errors:
- Check if you're trying to pass a temporary
- Check if you're mixing const and non-const incorrectly
- Consider adding const to your parameter

---

## Safety Checklist

Before submitting:
- [ ] No references to local variables returned
- [ ] All references initialized at declaration
- [ ] Const used for read-only parameters
- [ ] No attempts to rebind references
- [ ] Large objects passed by const reference
- [ ] Function signatures match intended usage
