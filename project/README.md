# Capstone Project - CSCI 330

**🎯 Build Something Ambitious**

The capstone project is your opportunity to apply everything you learn in a substantial, portfolio-worthy C++ application. It runs in **3 phases**, each anchored to a chapter in the course sequence. The capstone is *introduced* after Chapter 2; the three phases land at Chapter 5, Chapter 11, and Chapter 17 (course end).

> **A note on the calendar.** This guide describes the capstone in terms of *chapters*, not weeks. The actual dates for each phase — and how the chapters are spread across a term — are set per offering in Canvas. A short, intensive offering and a full-semester offering run the *same* 3-phase capstone, on different calendars.

---

## 📋 Project Overview

### **What You'll Build**
- **Substantial application** (~1500-2500 lines by the end)
- **Portfolio-quality code** with clear architecture
- **Progressive development** across three iterative phases

### **Core Requirements**
- Written in modern **C++17** (pinned to match the course textbook / Docker container)
- Demonstrates multiple course concepts from across the chapter sequence
- Uses appropriate tests (formal framework optional)
- Professional documentation (README, usage examples)
- Clean Git workflow with meaningful commits

---

## 📚 Project Resources

### **Planning and Design**
- **💡 [Brainstorming Guide](brainstorming-guide.md)** -- find a project idea that fits the time budget
- **📋 [Project Overview](semester-project.md)** -- complete requirements, phase anchors, rubric

### **Development Process**
- **🏗️ [3-Phase Development](phases/)** -- structured progression, each phase is a graded checkpoint
  - **[Phase 1](phases/PROJECT_PHASE_1.md)**: Planning + Proof of Concept (anchored at **Chapter 5**, 40 pts)
  - **[Phase 2](phases/PROJECT_PHASE_2.md)**: MVP + Feature Development (anchored at **Chapter 11**, 130 pts)
  - **[Phase 3](phases/PROJECT_PHASE_3.md)**: Robustness, Polish & Presentation (anchored at **Chapter 17**, course end, 130 pts)

### **Collaboration and Feedback**
- **👥 [Weekly Defense Guide](../reference/code-review-guide.md)** -- how the weekly synchronous meeting works, how to defend your own work, and the co-examiner question set

---

## 🎯 Project Categories

Choose something you are genuinely curious about. Categories are suggestions, not restrictions:

- **Games and Entertainment** -- text adventure, roguelike core, 2D puzzle engine
- **Developer Tools** -- lint checkers, code formatters, build-system helpers
- **Systems Programming** -- memory allocators, file utilities, process monitors
- **Data and Analytics** -- log analyzers, CSV/JSON processors, time-series summarizers
- **Domain-Specific** -- physics simulators, audio tools, graph algorithms, CLI games

If you have prior experience in a specific domain (web, ML, embedded, finance), pick something from there -- your context will make the project richer.

---

## ⏰ Project Phases

The capstone is introduced after Chapter 2 and runs parallel to the chapters from there. Each phase is anchored to a chapter; the calendar dates for those anchors are set per offering in Canvas.

At each of the three phase-anchor weeks (Chapters 5, 11, 17), a **capstone-phase defense** runs as its own dedicated session that week -- a separate session held in addition to the weekly homework-defense meeting, which still runs as usual. In the phase-defense session you present and defend your phase work, with classmates acting as co-examiners. Phase 3's session is the final project presentation. See the **[Weekly Defense Guide](../reference/code-review-guide.md)** for how a defense runs.

| Phase | Chapter Anchor | Points | Focus |
|-------|----------------|--------|-------|
| 1 -- Planning & PoC | Chapter 5 | 40 | Prove the idea works |
| 2 -- MVP + Features | Chapter 11 | 130 | Core functionality + interesting features |
| 3 -- Robustness + Polish + Presentation | Chapter 17 (course end) | 130 | Production-quality polish + demo |
| **Total** | | **300** | 35% of course grade |

---

## 📊 Assessment Criteria

Each phase rubric is in its own file. The project as a whole is evaluated against:

### **Technical Excellence (~40% of project score)**
- Code quality and architecture
- Appropriate use of C++17 features (RAII, references, STL, smart pointers)
- Performance acceptable for intended use
- Testing and reliability

### **Project Scope (~25%)**
- Appropriate complexity for the time budget (ambitious but finishable)
- Shows learning progression from Phase 1 to Phase 3
- Solves a meaningful problem or delivers a clear user experience

### **Development Process (~20%)**
- Consistent Git workflow across all three phases
- Meaningful commit messages
- Incremental, testable progress between phases
- Able to defend the work in the weekly meeting at each phase anchor

### **Presentation and Communication (~15%)**
- Clear README with build + run instructions
- Effective code walk-through in the Phase 3 demo video
- Reflection paper shows genuine self-awareness about the work

---

## 💡 Success Strategies

### **Choose Wisely (at the start)**
- Pick a project you are passionate about -- you'll put real time into it every week
- Scope it for **one term, not a career**. A smaller, finished project beats an ambitious, half-done one.
- If your first draft feels safe, make it a little scarier. The hard-to-solve piece is what will make it portfolio-worthy.

### **Plan Systematically**
- Follow the 3-phase process -- do not skip Phase 1 "to save time"
- Write down what "done" looks like before you write code
- Plan for testing and documentation from Phase 1, not as an afterthought in Phase 3

### **Develop Professionally**
- Commit frequently with meaningful messages
- Keep `main` buildable at all times (feature branches for experiments)
- Test the happy path; then test the unhappy path
- Seek peer feedback early and often

### **Learn Continuously**
- Connect project work to chapter concepts as you encounter them
- Research what you need from cppreference, AI tools, or the textbook's later chapters -- just document what you used
- Apply the debugging and profiling tools from the course

---

## 🔧 Technical Requirements

### **Code Standards**
- **C++17** -- use what the textbook covers (pinned via Docker container)
- Professional naming conventions (snake_case for functions/variables, PascalCase for types are common -- pick a style and be consistent)
- Meaningful comments for non-obvious decisions
- Proper error handling

### **Architecture**
- Clear separation of concerns (multiple .cpp/.h files once things grow)
- Appropriate design patterns (don't force them; use what fits)
- Extensible structure so Phase 3 does not require rewriting Phase 2
- Maintainable -- another student could extend it

### **Testing**
- Informal or formal tests are both acceptable
- At minimum: a small driver program that exercises main functionality
- Run `valgrind` at least once per phase

### **Documentation**
- README with build + run instructions
- Usage examples (screenshot or terminal transcript)
- Credits section: libraries used, AI assistance disclosed, peer feedback acknowledged

---

## 🆘 Getting Help (asynchronous)

### **Project Planning**
- Post ideas early in the Canvas Project Discussion board
- Bring scope questions to the weekly meeting for feedback during each phase
- Email instructor for a virtual 1:1 before major pivots

### **Technical Issues**
- Chapter materials + textbook for C++ concepts
- `quick-help.md` in each chapter for common issues
- `reference/git-commands.md` for Git cheatsheet
- Stack Overflow and cppreference.com for library / language specifics

### **Project Management**
- Async weekly check-in posts on Canvas
- A capstone-phase defense in the weekly meeting at each phase anchor (Chapters 5, 11, 17)
- Your own Git history -- use it to see how consistently you have been working

---

## 🌟 What Makes Projects Great

- **Solves a real problem** you actually face (tool that does what a broken tool does better)
- **Demonstrates growth** from Phase 1's "does the hard part work" to Phase 3's "this looks and feels professional"
- **Shows creativity** in applying course concepts to a domain you care about
- **Builds portfolio** -- something you would show an employer or graduate-school admissions reviewer

---

## 🧭 Navigation

**🏠 [Course Home](../README.md)** | **📝 [Assignments](../assignments/)** | **📋 [Templates](../assignment-templates/)**

**🚀 Ready to start?** Begin with the **[Brainstorming Guide](brainstorming-guide.md)**.

---

*Your capstone project is more than an assignment -- it is your chance to build something meaningful while mastering modern C++17.*
