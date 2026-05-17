# Chapter 5: Runtime Polymorphism - Problem Sets

> **Stuck or want to check your approach?** See [`HELPERS.md`](HELPERS.md) in this folder for scaffolding and hints paired with these assignments.

## 📋 Before You Begin

**✅ Prerequisites Check:**
- [ ] **Completed textbook reading**: Chapter 5 "Runtime Polymorphism"
- [ ] **Worked through lecture notes**: All core concepts and hands-on problems
- [ ] **Development environment ready**: VS Code + compiler setup verified

**🚫 Don't start these assignments until you've completed the textbook and lecture notes!**

## Instructions
- Complete these problems after reading Chapter 5 and working through the lesson
- Each problem builds on concepts from inheritance and virtual functions
- **Time expectation**: 2.25 hours total for all three problem sets
- Test all programs thoroughly and pay attention to virtual function behavior

---

## Problem Set 1: Basic Inheritance and Virtual Functions (45 minutes)

### Problem 1.1: Your First Virtual Function
**Objective**: Practice basic inheritance with virtual functions

Create a base class `MediaItem` with:
- A virtual function `play()` that prints "Playing a generic media item"
- A virtual destructor

Create a derived class `Song` that:
- Inherits from `MediaItem`
- Overrides `play()` to print "Now playing a song"

**Template to get you started**:
```cpp
#include <iostream>

struct MediaItem {
    virtual ~MediaItem() = default;
    virtual void play() const {
        std::cout << "Playing a generic media item\n";
    }
};

struct Song : MediaItem {
    // Your override here
};

int main() {
    MediaItem* item = new Song();
    item->play();  // Should print "Now playing a song"
    delete item;
    return 0;
}
```

**Python/Java Note**: Unlike Python/Java where all methods are virtual by default, C++ requires the `virtual` keyword for polymorphic behavior.

### Problem 1.2: Understanding Override
**Objective**: Learn the importance of the `override` keyword

Take your solution from 1.1 and:
1. Add the `override` keyword to your `Song::play()` function
2. Deliberately introduce a typo in the function name (like `ploy`)
3. Observe the compiler error
4. Fix the typo and verify everything works

**Key Learning**: The `override` keyword helps catch mistakes at compile time!

### Problem 1.3: Base Class Pointers
**Objective**: Practice polymorphic behavior through base class pointers

Create an array of `MediaItem*` pointers containing different media types:
```cpp
MediaItem* playlist[3] = {
    new Song(),
    new MediaItem(),
    // Add a Podcast class that prints "Streaming a podcast episode"
};
```

Loop through the array and call `play()` on each item. Don't forget to clean up memory!

---

## Problem Set 2: Abstract Classes and Pure Virtual Functions (60 minutes)

### Problem 2.1: Creating an Abstract Track Class
**Objective**: Work with pure virtual functions and abstract base classes

Create an abstract `Track` class with:
- Pure virtual function `int duration() const = 0` (length in seconds)
- Pure virtual function `std::string title() const = 0`
- Virtual destructor

**Template**:
```cpp
#include <iostream>
#include <string>

struct Track {
    virtual ~Track() = default;
    // Add your pure virtual functions here

    // This can be implemented in base class
    virtual void display_info() const {
        std::cout << "Title: " << title() << ", Duration: " << duration() << "s\n";
    }
};
```

### Problem 2.2: Implementing Concrete Tracks
**Objective**: Create concrete implementations of abstract interface

Implement two derived classes:

**AudioTrack**:
```cpp
struct AudioTrack : Track {
    std::string name;
    int seconds;

    AudioTrack(const std::string& n, int s) : name(n), seconds(s) {}

    // Implement title() and duration()
};
```

**VideoTrack**:
```cpp
struct VideoTrack : Track {
    std::string name;
    int seconds;

    VideoTrack(const std::string& n, int s) : name(n), seconds(s) {}

    // Implement title() and duration()
    // For VideoTrack, override display_info() to also print "[video]"
};
```

### Problem 2.3: Polymorphic Track Collection
**Objective**: Use polymorphism with collections of objects

Create a program that:
1. Creates a vector or array of `Track*` containing different track types
2. Loops through and calls `display_info()` on each track
3. Properly cleans up memory

**Expected output example**:
```
Title: Intro Theme, Duration: 95s
Title: Episode 1, Duration: 1820s [video]
```

---

## Problem Set 3: Configurable Media Player (60 minutes)

### Problem 3.1: MediaItem Interface Design
**Objective**: Create a practical media-player system using polymorphism

Create an abstract `Playable` base class:
```cpp
#include <iostream>
#include <string>

struct Playable {
    virtual ~Playable() = default;
    virtual void play() const = 0;

    // Convenience function implemented in base
    virtual void play_with_announcement() const {
        std::cout << "Up next: ";
        play();
    }
};
```

### Problem 3.2: Multiple Playable Implementations
**Objective**: Implement different media types

Create three concrete classes:

**Song**:
```cpp
struct Song : Playable {
    void play() const override {
        std::cout << "[Song] track is playing\n";
    }
};
```

**Podcast** (Starter code provided):
```cpp
struct Podcast : Playable {
    std::string episode;

    Podcast(const std::string& ep) : episode(ep) {}

    void play() const override {
        std::cout << "[Podcast] streaming episode: " << episode << "\n";
    }
};
```

**SilentItem** (for testing/debugging — a placeholder slot that plays nothing):
```cpp
struct SilentItem : Playable {
    // Implement this - it should do nothing but satisfy the interface
};
```

### Problem 3.3: Player with Configurable Content
**Objective**: Use polymorphism to create flexible, configurable systems

Create a simple player class that uses a `Playable`:

```cpp
struct Player {
    Playable* item;

    Player(Playable* media) : item(media) {}

    void start() {
        std::cout << "Player started\n";
        play_current();
        std::cout << "Player finished\n";
    }

private:
    void play_current() {
        item->play();
        // Announce the next item using the base-class convenience function
        item->play_with_announcement();
    }
};
```

**Your task**: Create a main function that:
1. Creates different `Playable` types
2. Runs the player with each item
3. Demonstrates how the same player code works with different media types
4. Properly manages memory

**Test cases to verify**:
- A `Song` plays its track output
- A `Podcast` streams the configured episode
- A `SilentItem` produces no playback output
- `play_with_announcement()` prefixes "Up next: " then dispatches polymorphically

---

## Submission Guidelines

**For each problem set**:
1. Include source code with clear comments explaining virtual function usage
2. Show compilation commands used
3. Provide sample output demonstrating polymorphic behavior
4. Explain any challenges you encountered with virtual functions

**File organization**:
```
chapter05_solutions/
├── problem_set_1/
│   ├── problem_1_1.cpp
│   ├── problem_1_2.cpp
│   └── problem_1_3.cpp
├── problem_set_2/
│   ├── problem_2_1.cpp
│   ├── problem_2_2.cpp
│   └── problem_2_3.cpp
├── problem_set_3/
│   ├── problem_3_1.cpp
│   ├── problem_3_2.cpp
│   └── problem_3_3.cpp
└── README.md (with compilation notes and observations)
```

**Expected time commitment**: 2.25 hours total for all problem sets. If you're taking longer, focus on understanding the core concepts rather than perfect implementation, and ask for help!

### Evaluation Criteria

**Total: 16 Points (4 points per outcome criteria)**

1. **Correctness** (4 points): Programs compile -- confirmed by a green CI build check -- and work as specified
2. **Code Quality** (4 points): Clean, readable, well-organized code
3. **Best Practices** (4 points): Following C++ idioms and conventions
4. **Documentation** (4 points): Appropriate comments and clear output

## Key Concepts to Demonstrate

By completing these problems, you should be comfortable with:
- Declaring and implementing virtual functions
- Using the `override` keyword for safety
- Creating abstract base classes with pure virtual functions
- Working with polymorphic objects through base class pointers
- Understanding when and why virtual destructors are needed
- Applying polymorphism to solve real-world design problems
