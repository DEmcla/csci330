# Phase 3: Robustness, Polish & Presentation
**Anchor**: Chapter 17 (course end) -- final submission + presentation
**Points**: 130 of 300 (≈43% of project grade)
**Goal**: Make the project solid, make it look professional, and present it convincingly.

This phase combines robustness work with polish and presentation. It is the culminating work of the course -- there is no separate final exam. The calendar date this phase is due is set per offering in Canvas; it is the last day of class.

> ⚠️ **Sequence the final stretch deliberately.** Do not save everything for the final day:
> - **First:** lock your project code (no new features after this point; only fixes)
> - **Then:** record your demo video and finalize your reflection paper
> - **Last:** submit the project before the deadline
>
> Students who cram the demo and reflection into the final day consistently lose points. Lock the code early so the polish and presentation get the time they need.

### Grading Breakdown (130 pts)
| Component | Points |
|---|---|
| Robustness (handles bad/weird inputs gracefully, no crashes) | 25 |
| Code quality on final pass (consistent style, no dead code, clean build) | 15 |
| Documentation (final README, usage examples, credits section) | 15 |
| Reflection paper (specific, self-aware, ~3 pages covering the 4 sections) | 25 |
| Demo video: program demonstration + code walk-through | 25 |
| Tests expanded / informal testing evidence | 10 |
| Final peer reviews on 2 classmates' projects | 10 |
| Tag v1.0 release on GitHub + final submission complete in Canvas | 5 |

## Your Phase 3 Todo List

### Stage 1 -- Make It Robust (~6-7 hours)
- [ ] Test with bad/weird inputs -- it should not crash:
  - Empty inputs, very long inputs, malformed inputs
  - Boundary conditions (max int, negative numbers, unicode where relevant)
  - Missing files, unreadable files, files with wrong format
- [ ] Fix the most important bugs
- [ ] Add graceful error handling where you were just crashing before
- [ ] Run `valgrind --leak-check=full` again and fix anything that appears
- [ ] Write or expand tests for the **main** functions (informal is fine -- you can use `assert()` or write small driver programs; no need to adopt a formal framework unless you want to)
- [ ] Optional: profile a slow path with `time` or `perf` and make at least one meaningful optimization

### Stage 2 -- Polish, Document, Present (~7-10 hours)

#### Final Polish (~3 hours)
- [ ] Consistent code style across all files (run `clang-format` if you have it)
- [ ] Remove dead code, commented-out experiments, debug `printf` statements
- [ ] Verify the build from a fresh clone works: `git clone ... && cd <repo> && cmake -B build && cmake --build build && ./build/<exe>`

#### Documentation (~2 hours)
- [ ] Final `README.md` update, covering:
  - What the project does (1-paragraph hook)
  - How to build and run it (exact commands)
  - Example usage with screenshot or terminal transcript
  - Features list
  - Known limitations
  - Credits (libraries used, AI assistance disclosed, peer input acknowledged)

#### Reflection Paper (~1-2 hours, ~3 pages)
- [ ] **Technical Journey**: What architecture choices you made and why. What C++ features you ended up using that you did not expect to.
- [ ] **Development Process**: What was harder than expected, what was easier. Where you got stuck and how you got unstuck.
- [ ] **AI Collaboration**: Where you used AI, what worked, what gave you wrong answers, how you verified output. Specific prompts and responses are encouraged.
- [ ] **Future Vision**: What you would add with more time, what you would refactor, whether you would choose C++ again for this domain.

#### Presentation (~1-2 hours prep + ~12 min video)
- [ ] Record a **10-12 minute** video demo: live demo of the program running, then a walk through 2-3 pieces of code you are proud of. Submit the video link via Canvas.
- [ ] **Or**, if instructor approves, schedule a live 10-12 min presentation via Zoom during end-of-course virtual office hours.

### Before Final Submission
- [ ] Push everything to GitHub
- [ ] Tag a final release: `git tag v1.0 && git push origin v1.0`
- [ ] Submit to Canvas:
  1. GitHub repository URL
  2. Reflection paper (PDF)
  3. Demo video link (or confirmation of scheduled live presentation)
- [ ] Complete final peer reviews on 2 classmates' projects

## What Success Looks Like

- Your program does not crash on reasonable bad inputs
- Performance is acceptable for the intended use (no 30-second hangs on normal input)
- Another developer could clone, build, and extend your project from the README alone
- Your reflection shows genuine self-awareness about what you built and learned
- Your demo video is crisp: shows the project working, walks through interesting code, explains choices
- You are proud enough of this project to include it in a portfolio

## Testing Checklist
- [ ] Boundary conditions (zero, one, max, min)
- [ ] Empty / null inputs
- [ ] Very large inputs
- [ ] Invalid inputs (wrong type, unexpected format)
- [ ] Interrupted operations (Ctrl-C, pipe closed)
- [ ] Resource exhaustion if relevant (full disk, no memory)

## Common Pitfalls to Avoid

- Cramming new features into the final stretch instead of polishing what exists
- Weak documentation: if a classmate cannot run it, it does not count as finished
- Unprepared demo: rehearse the recording once, at minimum
- Over-optimizing before profiling: measure first

## Reflection Paper Hint

Reflections that get high marks are specific. "I learned about pointers" is not specific. "I spent 90 minutes on a segfault that turned out to be a use-after-free when my destructor freed a member that had already been moved from" is specific.

---
*Remember: Phase 3 is where you separate a student project from a professional-looking project. Make it portfolio-ready.*
