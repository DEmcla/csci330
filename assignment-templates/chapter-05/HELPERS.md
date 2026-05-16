# Chapter 5: Assignment Helpers - Runtime Polymorphism

## Purpose
Scaffolding and hints for the polymorphism assignments. Use when stuck or to
verify your approach. The three sections below line up one-to-one with the three
problem sets in this template's `README.md`.

---

## Key Concepts Reminder

### Virtual Function Rules
```cpp
struct Base {
    virtual ~Base() = default;   // Virtual destructor essential for polymorphism!
    virtual void func() { }      // Can be overridden
    virtual void pure() = 0;     // Pure virtual - must be overridden
};

struct Derived : Base {
    void func() override { }     // override keyword (C++11) - catches typos
    void pure() override { }     // Implements the pure virtual
};
```

### Polymorphism Requirements
1. **Inheritance** - the derived class inherits from the base
2. **Virtual functions** - enable dynamic (run-time) binding
3. **Pointer or reference** - access the object through a base pointer/reference
4. **Matching signatures** - same name, parameters, return type, and const-ness

---

## Problem Set 1: Basic Inheritance and Virtual Functions

This set asks for an `Animal` base class and `Dog` / `Cat` derived classes.

### Base and Derived Classes
```cpp
#include <iostream>

struct Animal {
    virtual ~Animal() = default;             // virtual destructor

    virtual void make_sound() const {
        std::cout << "Some generic animal sound\n";
    }
};

struct Dog : Animal {
    void make_sound() const override {       // override catches signature typos
        std::cout << "Woof!\n";
    }
};

struct Cat : Animal {
    void make_sound() const override {
        std::cout << "Meow!\n";
    }
};
```

### The `override` keyword (Problem 1.2)
If you misspell the function (`make_soud`) or change its signature, `override`
turns a silent "this is a brand-new function" mistake into a **compiler error**.
Always use it on functions meant to override a base virtual.

### Polymorphic Behavior Through Base Pointers (Problem 1.3)
```cpp
Animal* zoo[3] = { new Dog(), new Cat(), new Animal() };

for (Animal* a : zoo) {
    a->make_sound();        // calls the correct override at run time
}

for (Animal* a : zoo) {
    delete a;               // virtual ~Animal() ensures correct cleanup
}
```

---

## Problem Set 2: Abstract Classes and Pure Virtual Functions

This set asks for an abstract `Shape` class with `Rectangle` and `Circle`.

### Abstract Base Class
```cpp
#include <iostream>
#include <cmath>      // for M_PI

struct Shape {
    virtual ~Shape() = default;

    // Pure virtual functions => Shape is abstract, cannot be instantiated
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // A concrete function the base can implement using the pure virtuals
    virtual void display_info() const {
        std::cout << "Area: " << area()
                  << ", Perimeter: " << perimeter() << "\n";
    }
};
```

### Concrete Shapes
```cpp
struct Rectangle : Shape {
    double width, height;

    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override      { return width * height; }
    double perimeter() const override { return 2 * (width + height); }
};

struct Circle : Shape {
    double radius;

    Circle(double r) : radius(r) {}

    double area() const override      { return M_PI * radius * radius; }
    double perimeter() const override { return 2 * M_PI * radius; }
};
```

### Polymorphic Shape Collection (Problem 2.3)
```cpp
#include <vector>

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(5.0, 4.0));
    shapes.push_back(new Circle(2.0));

    for (const Shape* s : shapes) {
        s->display_info();          // polymorphic call
    }

    for (Shape* s : shapes) {
        delete s;                   // virtual destructor -> correct cleanup
    }
}
```

---

## Problem Set 3: Advanced Logging System

This set asks for a `Logger` interface, three concrete loggers, and an
`Application` that is configured with whichever logger you pass it.

### Logger Interface
```cpp
#include <iostream>
#include <fstream>
#include <string>

struct Logger {
    virtual ~Logger() = default;
    virtual void log(const std::string& message) const = 0;

    // Convenience function implemented once, in the base
    virtual void log_error(const std::string& message) const {
        log("ERROR: " + message);
    }
};
```

### Concrete Loggers
```cpp
struct ConsoleLogger : Logger {
    void log(const std::string& message) const override {
        std::cout << "[Console] " << message << "\n";
    }
};

struct FileLogger : Logger {
    std::string filename;
    FileLogger(const std::string& file) : filename(file) {}

    void log(const std::string& message) const override {
        std::ofstream out(filename, std::ios::app);
        if (out) {
            out << "[File] " << message << "\n";
        }
    }
};

// SilentLogger: satisfies the interface but produces no output.
// Useful for tests, or to switch logging off without changing other code.
struct SilentLogger : Logger {
    void log(const std::string&) const override {
        // intentionally empty
    }
};
```

### Configurable Application (Problem 3.3)
```cpp
struct Application {
    Logger* logger;                          // not owned - just used
    Application(Logger* log) : logger(log) {}

    void run() {
        logger->log("Application started");
        logger->log_error("Something went wrong!");
        logger->log("Application finished");
    }
};

int main() {
    ConsoleLogger console;
    SilentLogger  silent;

    Application app1(&console);   // same Application code...
    app1.run();

    Application app2(&silent);    // ...different logging behavior
    app2.run();
}
```

The point: `Application::run()` never changes, yet its logging behavior is
selected entirely by which `Logger` you hand it. That is polymorphism solving a
real design problem.

---

## Common Patterns

### Factory Function
A factory hides the `new` and the type choice behind one call:
```cpp
Logger* make_logger(const std::string& kind) {
    if (kind == "console") return new ConsoleLogger();
    if (kind == "silent")  return new SilentLogger();
    return new FileLogger("app.log");        // default
}
```

### Interface Segregation
Keep interfaces small and focused; a class can implement several:
```cpp
struct Drawable {
    virtual ~Drawable() = default;
    virtual void draw() const = 0;
};

struct Resizable {
    virtual ~Resizable() = default;
    virtual void resize(double factor) = 0;
};

struct Sprite : Drawable, Resizable {
    // implements both interfaces
};
```

---

## Debugging Tips

### Track Virtual Calls
```cpp
struct Base {
    virtual ~Base() = default;
    virtual void func() {
        std::cout << "Base::func() called\n";
    }
};

struct Derived : Base {
    void func() override {
        std::cout << "Derived::func() called\n";
        Base::func();  // call the parent version if you need it
    }
};
```

### Verify Polymorphism (and watch out for slicing)
```cpp
Derived d;
Base* ptr = &d;
Base& ref = d;

ptr->func();   // calls Derived::func()  -- polymorphic
ref.func();    // calls Derived::func()  -- polymorphic

Base b = d;    // SLICING! copies only the Base part
b.func();      // calls Base::func()     -- not polymorphic
```
Access objects through **pointers or references** to get polymorphic behavior.

---

## Checklist

- [ ] Every base class with virtual functions has a virtual destructor
- [ ] All pure virtual functions are implemented in each concrete class
- [ ] `override` is used on every overriding function
- [ ] Objects are accessed through base pointers/references (no slicing)
- [ ] Function signatures match exactly across the hierarchy (including `const`)
- [ ] Every `new` in a polymorphic collection has a matching `delete`
