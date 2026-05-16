# Summer Project - CSCI 330 (U26)

**🎯 Build Something Ambitious in 6 Weeks**

The capstone project is your opportunity to apply everything you learn in a substantial, portfolio-worthy C++ application. In the 6-week summer term, the project is compressed from 5 phases to **3 phases** but the total point value and the level of ambition remain the same.

---

## 📋 Project Overview

### **What You'll Build**
- **Substantial application** (~1500-2500 lines by the end)
- **Portfolio-quality code** with clear architecture
- **Progressive development** over 6 weeks (three iterative phases)

### **Core Requirements**
- Written in modern **C++17** (pinned to match the course textbook / Docker container)
- Demonstrates multiple course concepts from Weeks 1-6
- Uses appropriate tests (formal framework optional)
- Professional documentation (README, usage examples)
- Clean Git workflow with meaningful commits

---

## 📚 Project Resources

### **Planning and Design**
- **💡 [Brainstorming Guide](brainstorming-guide.md)** -- find a project idea that fits a 6-week budget
- **📋 [Project Overview](semester-project.md)** -- complete requirements, timeline, rubric

### **Development Process**
- **🏗️ [3-Phase Development](phases/)** -- structured progression, each phase is a graded checkpoint
  - **[Phase 1](phases/PROJECT_PHASE_1.md)**: Planning + Proof of Concept (due **end of Week 2**, 40 pts)
  - **[Phase 2](phases/PROJECT_PHASE_2.md)**: MVP + Feature Development (due **end of Week 4**, 130 pts)
  - **[Phase 3](phases/PROJECT_PHASE_3.md)**: Robustness, Polish & Presentation (due **end of Week 6**, 130 pts)

### **Collaboration and Feedback**
- **👥 [Code Review Guide](../reference/code-review-guide.md)** -- how to give a useful GitHub code review on a classmate's PR at each checkpoint

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

## ⏰ Project Timeline (6 weeks)

| Phase | Weeks | Due | Points | Focus |
|-------|-------|-----|--------|-------|
| 1 -- Planning & PoC | 1-2 | End of Week 2 | 40 | Prove the idea works |
| 2 -- MVP + Features | 3-4 | End of Week 4 | 130 | Core functionality + interesting features |
| 3 -- Robustness + Polish + Presentation | 5-6 | End of Week 6 | 130 | Production-quality polish + demo |
| **Total** | | | **300** | 30% of course grade |

---

## 📊 Assessment Criteria

Each phase rubric is in its own file. The project as a whole is evaluated against:

### **Technical Excellence (~40% of project score)**
- Code quality and architecture
- Appropriate use of C++17 features (RAII, references, STL, smart pointers)
- Performance acceptable for intended use
- Testing and reliability

### **Project Scope (~25%)**
- Appropriate complexity for a 6-week budget (ambitious but finishable)
- Shows learning progression from Phase 1 to Phase 3
- Solves a meaningful problem or delivers a clear user experience

### **Development Process (~20%)**
- Consistent Git workflow across all 6 weeks
- Meaningful commit messages
- Incremental, testable progress between phases
- Responsive to peer feedback

### **Presentation and Communication (~15%)**
- Clear README with build + run instructions
- Effective code walk-through in the Week 6 demo video
- Reflection paper shows genuine self-awareness about the work

---

## 💡 Success Strategies

### **Choose Wisely (in Week 1)**
- Pick a project you are passionate about -- you'll spend ~10-15 hrs/week on it
- Scope it for **6 weeks, not 15**. A smaller, finished project beats an ambitious, half-done one.
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
- Peer feedback on scope during each phase
- Email instructor for a virtual 1:1 before major pivots

### **Technical Issues**
- Chapter materials + textbook for C++ concepts
- `quick-help.md` in each chapter for common issues
- `reference/git-commands.md` for Git cheatsheet
- Stack Overflow and cppreference.com for library / language specifics

### **Project Management**
- Async weekly check-in posts on Canvas
- Peer reviews at each phase checkpoint
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

*Your capstone project is more than an assignment -- it is your chance to build something meaningful while mastering C++17 in six weeks.*
