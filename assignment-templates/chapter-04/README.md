# Chapter 4: Object Lifecycle - Problem Sets

> **Stuck or want to check your approach?** See [`HELPERS.md`](HELPERS.md) in this folder for scaffolding and hints paired with these assignments.

## 📋 Before You Begin

**✅ Prerequisites Check:**
- [ ] **Completed textbook reading**: Chapter 4 "Object Lifecycle"
- [ ] **Worked through lecture notes**: All core concepts and hands-on problems
- [ ] **Development environment ready**: VS Code + compiler setup verified

**🚫 Don't start these assignments until you've completed the textbook and lecture notes!**

## ✨ Assignment Structure
**Three focused problem sets**, each building on the last:
- **Problem Set 1**: Constructors and Destructors (45 minutes) - REQUIRED
- **Problem Set 2**: RAII and Resource Management (60 minutes) - REQUIRED
- **Problem Set 3**: Move Semantics Introduction (30 minutes) - REQUIRED

**Total Core Time**: 2.25 hours

> **Scope note:** Everything in these problem sets is Chapter 4 material -- constructors,
> destructors, copy semantics, RAII, exceptions, and move semantics. You do **not** need
> inheritance, virtual functions, or templates here; those come in Chapters 5 and 6.

---

## 🎯 Problem Set 1: Constructors and Destructors (45 minutes)
*Understand object lifecycle by building one well-behaved class*

### Problem 1.1: A Bank Account That Manages Its Own Memory (25 minutes)
**Objective**: Practice the constructor/destructor/copy lifecycle on a single class

Create a program called `banking_system.cpp` with **one** class, `BankAccount`
(no inheritance -- just this class):

1. **Data members**
   - `int account_number` -- assigned automatically (see static counter below)
   - `char owner_name[64]`
   - `double balance`
   - `int* transaction_history` -- a **dynamically allocated** array (`new int[]`)
   - `int transaction_count`

2. **Constructors**
   - Default constructor: empty name, `balance` 0
   - Parameterized constructor: `BankAccount(const char* name, double opening_balance)`
   - Both must allocate the `transaction_history` array

3. **Copy constructor** -- perform a **deep copy** of `transaction_history`
   (allocate a new array; do not just copy the pointer)

4. **Copy assignment operator** -- handle **self-assignment**, free the old
   array, then deep-copy the new one

5. **Destructor** -- `delete[]` the `transaction_history` array and print a
   `[Destructor]` line

6. **Static members**
   - `static int next_account_number` -- starts at 1001, increments per account
   - `static int accounts_open` -- increment in every constructor, decrement in
     the destructor; print the running total

Then in `main()`:
- Create two accounts with the parameterized constructor
- Inside a **nested `{ }` scope**, make a copy of one account, so you can watch
  the copy's constructor and destructor fire at scope entry/exit
- Print a summary line at the end

**Expected Output** (your numbers/names will differ):
```
=== Bank Account Lifecycle Demo ===
[Constructor] Account #1001 opened for Alice, balance $500.00
[Constructor] Account #1002 opened for Bob, balance $1500.00
  -- entering nested scope --
[Copy Constructor] Account #1003 deep-copied from #1001
  -- leaving nested scope --
[Destructor] Account #1003 closed (1 account still open: ... )
[Destructor] Account #1002 closed
[Destructor] Account #1001 closed
Summary: 3 accounts opened, 3 accounts closed
```

### Problem 1.2: Prove Your Copy Is Deep (20 minutes)
**Objective**: Show that a shallow copy is a bug, and that yours is not

Using the `BankAccount` from 1.1:
1. Make a copy of an account
2. Record a transaction on the **copy** (append to its `transaction_history`)
3. Print both accounts' transaction counts to show the original is **unchanged**
4. In a comment, explain what would go wrong (double `delete[]`, corrupted data)
   if you had relied on the compiler-generated shallow copy instead

**Skills Developed**: Multiple constructors, the Rule of Three (destructor + copy
constructor + copy assignment), deep copy, static members, scope-based lifetime.

---

## 🎯 Problem Set 2: RAII and Resource Management (60 minutes)
*Let constructors and destructors manage resources for you -- even when things go wrong*

### Problem 2.1: An RAII Transaction Logger (30 minutes)
**Objective**: Tie a file resource to an object's lifetime

Create `raii_demo.cpp` with a `TransactionLogger` class:
1. The **constructor** takes a filename and opens that file for appending
   (`std::ofstream` or `fopen`)
2. A `log(const std::string& entry)` method writes one timestamped-style line
3. The **destructor** closes the file and prints `[RAII] log closed`
4. Disable copying: `TransactionLogger(const TransactionLogger&) = delete;` and
   `TransactionLogger& operator=(const TransactionLogger&) = delete;`
   (a file handle should have a single owner)

Demonstrate in `main()` that creating a `TransactionLogger` inside a `{ }` block
opens the file, and that **leaving the block** closes it automatically -- you
never call a `close()` yourself.

### Problem 2.2: RAII Survives Exceptions (30 minutes)
**Objective**: Show why RAII beats manual cleanup

Add a function `void run_risky_transfer(TransactionLogger& log, bool should_fail)`:
1. It logs `"transfer started"`
2. If `should_fail` is `true`, it `throw`s a `std::runtime_error`
3. Otherwise it logs `"transfer completed"`

In `main()`:
- Create a `TransactionLogger` in a scope
- Call `run_risky_transfer` inside a `try { } catch { }`, once with
  `should_fail = true`
- Show that **even when the exception is thrown**, the logger's destructor still
  runs and the file is still closed when the scope ends
- In a comment, contrast this with a manual `open()` / `close()` pair, where an
  exception between them would leak the file handle

**Skills Developed**: RAII, deleting copy operations, deterministic destruction,
exception safety. No templates or inheritance required.

---

## 🎯 Problem Set 3: Move Semantics Introduction (30 minutes)
*Transfer ownership instead of copying it*

### Problem 3.1: A Movable Buffer (30 minutes)
**Objective**: Implement a move constructor and move assignment

Create `move_semantics.cpp` with a class `Buffer` that owns a dynamically
allocated array:
- Data members: `char* data;` and `size_t size;`
- **Regular constructor** `Buffer(size_t n)` -- allocates `new char[n]`
- **Destructor** -- `delete[] data` and print `[~Buffer]`
- **Copy constructor** -- deep copy; print `[copy] Buffer copied`
- **Move constructor** `Buffer(Buffer&& other) noexcept` -- **steal** `other`'s
  pointer, then set `other.data = nullptr` and `other.size = 0`; print
  `[move] Buffer moved`
- **Move assignment** `Buffer& operator=(Buffer&& other) noexcept` -- free your
  own data, steal `other`'s, leave `other` empty

Write a factory function `Buffer make_buffer(size_t n)` that constructs a
`Buffer` and returns it by value.

In `main()`:
1. Call `make_buffer(...)` and observe that returning by value uses the **move**
   constructor, not the copy constructor
2. Explicitly `std::move()` one `Buffer` into another and watch the message
3. After a move, print the moved-from buffer's `size` to confirm it is safely
   left at 0 (a valid, empty state)

**Expected Output** (order/messages will reflect your code):
```
make_buffer: constructing a 128-byte Buffer
[move] Buffer moved        <- return value moved out, not copied
b2 = std::move(b1)
[move] Buffer moved
moved-from buffer size is now 0 (safe, empty state)
[~Buffer]
[~Buffer]
```

**Skills Developed**: Move constructor and move assignment, `noexcept`, `std::move`,
the difference between copying and transferring ownership, leaving a moved-from
object in a valid state.

---

## 🏆 Challenge Exercises (OPTIONAL - for advanced students)

These are not graded and not required. Pick one if you finish early and want to
go deeper -- all stay within Chapter 4 concepts.

### Challenge A: A Move-Only Owning Pointer (45 minutes)
Build a tiny `OwningPtr` class that holds a single `new`-allocated object,
deletes it in the destructor, **deletes** its copy operations, and **implements**
move construction/assignment. This is the core idea behind `std::unique_ptr`,
which you will meet formally in Chapter 11.

### Challenge B: The Three Exception-Safety Guarantees (40 minutes)
Take a class with a resource and write three versions of one mutating operation:
basic guarantee (no leaks), strong guarantee (rolls back on throw), and a
`noexcept` no-throw version. Document which is which and why.

### Challenge C: Copy-and-Swap Idiom (30 minutes)
Reimplement `BankAccount`'s copy assignment using the copy-and-swap idiom (take
the parameter by value, `swap`, return). Explain why this gives you the strong
exception guarantee and self-assignment safety for free.

---

## 🎯 Success Criteria

Before moving to Chapter 5, ensure you can:

**Constructor/Destructor Mastery:**
- [ ] Implement default and parameterized constructors appropriately
- [ ] Write destructors that release every resource the object owns
- [ ] Implement copy constructors and copy assignment with correct deep-copy behavior
- [ ] Debug constructor/destructor call order across nested scopes

**RAII Expertise:**
- [ ] Design classes that acquire a resource in the constructor and release it in the destructor
- [ ] Write exception-safe code that relies on RAII for cleanup
- [ ] Disable copying when an object should have a single owner of its resource
- [ ] Explain stack vs heap object lifetime differences

**Move Semantics:**
- [ ] Implement a `noexcept` move constructor and move assignment operator
- [ ] Explain when a copy happens and when a move happens
- [ ] Leave a moved-from object in a valid, empty state

**Professional Development:**
- [ ] Apply the Rule of Three / Rule of Five consistently
- [ ] Write robust, exception-safe, leak-free C++ code
- [ ] Design maintainable, resource-safe classes

---

## 💡 Study Strategy

This is one week's homework -- work the three problem sets in order, since each
builds on the last.

1. **Problem Set 1 (constructors/destructors)** -- start here. Use the debugger
   to watch constructor and destructor calls fire as objects enter and leave scope.
2. **Problem Set 2 (RAII)** -- build on Problem Set 1's lifecycle understanding;
   the key idea is that the destructor runs *automatically*, even on an exception.
3. **Problem Set 3 (move semantics)** -- shortest set; focus on *why* moving is
   cheaper than copying for a resource-owning class.

If you are taking much longer than 2.25 hours, prioritize understanding over
perfection and ask for help on the Canvas discussion board.

**Remember**: Object lifecycle is fundamental to C++ mastery. Invest the time to
truly understand these concepts - they form the foundation for everything else.

---

## Evaluation Criteria

**Total: 16 Points (4 points per outcome criteria)**

1. **Correctness** (4 points): Programs compile -- confirmed by a green CI build check -- and work as specified
2. **Code Quality** (4 points): Clean, readable, well-organized code
3. **Best Practices** (4 points): Following C++ idioms and conventions
4. **Documentation** (4 points): Appropriate comments and clear output
