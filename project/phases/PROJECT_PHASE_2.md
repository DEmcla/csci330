# Phase 2: Minimum Viable Product + Feature Development
**Duration**: Weeks 3-4
**Due**: End of Week 4
**Points**: 130 of 300 (≈43% of project grade)

### Grading Breakdown (130 pts)
| Component | Points |
|---|---|
| MVP works end-to-end for the core use case | 40 |
| 2-3 differentiating features working correctly | 35 |
| C++ practices (RAII, const-correctness, appropriate STL use) | 20 |
| No memory leaks / undefined behavior under normal inputs | 10 |
| README updated with usage + build instructions | 10 |
| GitHub hygiene (frequent commits, `main` stays buildable) | 10 |
| Discussion post + 2 peer reviews on classmates' submissions | 5 |
**Goal**: Get your project to a complete, working MVP, then add the features that make it actually interesting.

This phase merges what was two phases in the 15-week course (MVP + Features) into one in the summer version. You are building the bulk of the project here.

## Your Phase 2 Todo List

### Week 3: Build Core / MVP (~5-6 hours)
- [ ] Create the main classes, structures, and modules
- [ ] Get the basic end-to-end flow working
- [ ] Apply C++ practices you have just learned:
  - RAII and proper destructors (Ch 4)
  - References and const-correctness (Ch 3)
  - Appropriate use of inheritance or templates (Ch 5, Ch 6)
- [ ] Handle the obvious bad inputs so your program does not crash on them

### Week 4: Add Interesting Features (~7-9 hours)
- [ ] Add **2-3 features** that move your project from "works" to "actually useful or fun"
- [ ] Use C++ features from the curriculum where they naturally fit:
  - STL containers (vector, map) -- you will formally study these in Week 5
  - Smart pointers if you have dynamic allocation -- you will formally study these in Week 5
  - Templates if you have repeated logic over types -- Week 3 material
- [ ] Improve error messages so a user can diagnose what went wrong without reading your code
- [ ] Run `valgrind --leak-check=full` once and fix major leaks if any appear
- [ ] Make sure another student could clone the repo, run `cmake -B build && cmake --build build`, and launch it

### Before Submission
- [ ] Push all code to GitHub (small, frequent commits are better than one giant commit)
- [ ] Update the `README.md` with usage examples and a screenshot or terminal transcript
- [ ] Post a short "what my MVP does + one feature I am proud of" update to the Canvas Project Discussion board
- [ ] Comment on at least **2** classmates' submissions
- [ ] Submit the GitHub repo URL + discussion-post link to Canvas

## What Success Looks Like

- Your program works end-to-end for the core use case
- At least 2-3 features beyond the bare-minimum MVP work correctly
- You apply proper C++ practices (RAII, const-correctness, references, appropriate STL use)
- No memory leaks or undefined behavior under normal inputs
- Another student could clone, build, and run your project from the README
- The README explains what the project does, how to build it, and how to use it
- Your code is organized into coherent files -- a 500-line `main.cpp` is a smell

## Common Pitfalls to Avoid

- Feature creep: adding a sixth half-working feature instead of polishing three working ones
- Ignoring memory management "until later" -- later is Phase 3, and it is less forgiving
- Hardcoding values (file paths, magic numbers) instead of taking arguments or config
- Skipping the README update "to save time" -- your peers cannot review what they cannot run
- Using advanced C++ features (variadic templates, template metaprogramming) **just to use them**

## Feature Ideas by Project Type
- **Games**: Levels, simple AI, save/load, persistent high scores
- **Tools**: Multiple input formats, batch processing, a plugin hook
- **Databases / Storage**: Indexing, simple query language, transaction-like commits
- **Simulations**: Configurable parameters, data export, visualization via text
- **Network / IPC**: Multiple clients, basic protocol, a command-line client

---
*Remember: an MVP is "barely works but actually works." Features on top are what makes it interesting. Do both here, in that order.*
