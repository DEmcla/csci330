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

This set asks for a `MediaItem` base class and `Song` / `Podcast` derived classes.

### Base and Derived Classes
```cpp
#include <iostream>

struct MediaItem {
    virtual ~MediaItem() = default;             // virtual destructor

    virtual void play() const {
        std::cout << "Playing a generic media item\n";
    }
};

struct Song : MediaItem {
    void play() const override {                // override catches signature typos
        std::cout << "Now playing a song\n";
    }
};

struct Podcast : MediaItem {
    void play() const override {
        std::cout << "Streaming a podcast episode\n";
    }
};
```

### The `override` keyword (Problem 1.2)
If you misspell the function (`ploy`) or change its signature, `override`
turns a silent "this is a brand-new function" mistake into a **compiler error**.
Always use it on functions meant to override a base virtual.

### Polymorphic Behavior Through Base Pointers (Problem 1.3)
```cpp
MediaItem* playlist[3] = { new Song(), new Podcast(), new MediaItem() };

for (MediaItem* m : playlist) {
    m->play();              // calls the correct override at run time
}

for (MediaItem* m : playlist) {
    delete m;               // virtual ~MediaItem() ensures correct cleanup
}
```

---

## Problem Set 2: Abstract Classes and Pure Virtual Functions

This set asks for an abstract `Track` class with `AudioTrack` and `VideoTrack`.

### Abstract Base Class
```cpp
#include <iostream>
#include <string>

struct Track {
    virtual ~Track() = default;

    // Pure virtual functions => Track is abstract, cannot be instantiated
    virtual int duration() const = 0;          // length in seconds
    virtual std::string title() const = 0;

    // A concrete function the base can implement using the pure virtuals
    virtual void display_info() const {
        std::cout << "Title: " << title()
                  << ", Duration: " << duration() << "s\n";
    }
};
```

### Concrete Tracks
```cpp
struct AudioTrack : Track {
    std::string name;
    int seconds;

    AudioTrack(const std::string& n, int s) : name(n), seconds(s) {}

    int duration() const override      { return seconds; }
    std::string title() const override { return name; }
};

struct VideoTrack : Track {
    std::string name;
    int seconds;

    VideoTrack(const std::string& n, int s) : name(n), seconds(s) {}

    int duration() const override      { return seconds; }
    std::string title() const override { return name; }

    // VideoTrack also overrides the regular virtual display_info()
    void display_info() const override {
        std::cout << "Title: " << title()
                  << ", Duration: " << duration() << "s [video]\n";
    }
};
```

### Polymorphic Track Collection (Problem 2.3)
```cpp
#include <vector>

int main() {
    std::vector<Track*> tracks;
    tracks.push_back(new AudioTrack("Intro Theme", 95));
    tracks.push_back(new VideoTrack("Episode 1", 1820));

    for (const Track* t : tracks) {
        t->display_info();          // polymorphic call
    }

    for (Track* t : tracks) {
        delete t;                   // virtual destructor -> correct cleanup
    }
}
```

---

## Problem Set 3: Configurable Media Player

This set asks for a `Playable` interface, three concrete media types, and a
`Player` that is configured with whichever item you pass it.

### Playable Interface
```cpp
#include <iostream>
#include <string>

struct Playable {
    virtual ~Playable() = default;
    virtual void play() const = 0;

    // Convenience function implemented once, in the base
    virtual void play_with_announcement() const {
        std::cout << "Up next: ";
        play();
    }
};
```

### Concrete Playable Types
```cpp
struct Song : Playable {
    void play() const override {
        std::cout << "[Song] track is playing\n";
    }
};

struct Podcast : Playable {
    std::string episode;
    Podcast(const std::string& ep) : episode(ep) {}

    void play() const override {
        std::cout << "[Podcast] streaming episode: " << episode << "\n";
    }
};

// SilentItem: satisfies the interface but produces no playback output.
// Useful for tests, or as an empty placeholder slot in a playlist.
struct SilentItem : Playable {
    void play() const override {
        // intentionally empty
    }
};
```

### Configurable Player (Problem 3.3)
```cpp
struct Player {
    Playable* item;                          // not owned - just used
    Player(Playable* media) : item(media) {}

    void start() {
        std::cout << "Player started\n";
        item->play();
        item->play_with_announcement();
        std::cout << "Player finished\n";
    }
};

int main() {
    Song    song;
    SilentItem silent;

    Player player1(&song);     // same Player code...
    player1.start();

    Player player2(&silent);   // ...different playback behavior
    player2.start();
}
```

The point: `Player::start()` never changes, yet its playback behavior is
selected entirely by which `Playable` you hand it. That is polymorphism solving
a real design problem.

---

## Common Patterns

### Factory Function
A factory hides the `new` and the type choice behind one call:
```cpp
Playable* make_item(const std::string& kind) {
    if (kind == "song")    return new Song();
    if (kind == "silent")  return new SilentItem();
    return new Podcast("Episode 1");         // default
}
```

### Interface Segregation
Keep interfaces small and focused; a class can implement several:
```cpp
struct Playable {
    virtual ~Playable() = default;
    virtual void play() const = 0;
};

struct Downloadable {
    virtual ~Downloadable() = default;
    virtual void download() const = 0;
};

struct OfflineSong : Playable, Downloadable {
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
