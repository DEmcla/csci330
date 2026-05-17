# CSCI 330 - Capstone C++ Project

## Overview

This is an audacious project: I'm asking you to build a substantial C++ application over the course of the term using professional software development practices. This project runs parallel to your coursework - you can use whatever C++ features you've learned (or research on your own) at any point. AI is a tool and you can use AI, but you must credit where you use AI and be able to explain every aspect of your code, your development environment, and the development process.

**Structure**: 3 phases, each anchored to a chapter in the course sequence
**Weight**: 35% of course grade (300 points)
**Philosophy**: This is a serious project, so I expect you to build something real, substantial, and portfolio-worthy

> **A note on the calendar.** This guide describes the capstone in terms of *chapters*, not weeks or dates. The capstone is *introduced* after Chapter 2; its three phases are anchored at Chapter 5, Chapter 11, and Chapter 17 (course end). The actual due dates — and how the chapters are spread across a term — are set per offering in Canvas. A short, intensive offering and a full-semester offering run the *same* 3-phase capstone, on different calendars.

> **How to Use These Documents:**
> - Start here for the complete project overview ("map of the world")
> - Use the individual phase guides (PROJECT_PHASE_1.md through PROJECT_PHASE_3.md) for detailed todo checklists
> - Each phase guide breaks the work into a manageable set of tasks
> - Check off items as you complete them to track your progress

## Important: Two Parallel Learning Paths

**This project runs parallel to, not in lockstep with, the course chapters.** You're encouraged to use ANY C++ features you need at ANY point - whether from research, AI assistance, or looking ahead in the textbook.

- **The Chapters** (from *C++ Crash Course* 1st edition, C++17) provide deep, systematic understanding of C++ concepts (types, memory models, function mechanics, container internals)
- **The Project** provides real-world context where you use whatever works to solve problems

You might use `std::vector` in Phase 1 before studying the container chapter in detail. This is by design and mirrors professional development - you often use tools to solve problems first, then later develop deeper understanding of their internals. The "lightbulb moment" when you formally study something you've already used in your project is valuable learning.

**Bottom line**: Don't wait for permission from the chapters to use a feature. If you need it, research it, use it, and document it. The formal study will come later and deepen your understanding. Stick to C++17 features so your code compiles cleanly in the course Docker container.

## The Three Phases

Each phase has its own detailed guide with todo checklists to keep you on track:

### Phase 1: Planning & Proof of Concept
**Anchor**: Chapter 5
**Points**: 40 (13%)
**Focus**: Validate your idea works
**Detailed Todo List**: PROJECT_PHASE_1.md

### Phase 2: MVP & Feature Development
**Anchor**: Chapter 11
**Points**: 130 (43%)
**Focus**: Core functionality complete, then the features that make it interesting
**Detailed Todo List**: PROJECT_PHASE_2.md

### Phase 3: Robustness, Polish & Presentation
**Anchor**: Chapter 17 (course end)
**Points**: 130 (43%)
**Focus**: Production quality, professional finish, and reflection
**Detailed Todo List**: PROJECT_PHASE_3.md

---

## Phase 1: Planning & Proof of Concept

### Goal
Prove your idea is feasible and worth building. Get the hard part working first. You cannot afford to spend a large chunk of the term discovering your idea doesn't work.

### Deliverables

#### 1.1 Project Proposal (early in Phase 1)
A solid plan that shows you've thought this through:
- **What**: Clear description of what you're building
- **Why**: Problem it solves or need it fills
- **How**: Technical approach and architecture
- **Risks**: What might go wrong and backup plans
- **Success Criteria**: How we'll know it works

#### 1.2 Proof of Concept (Phase 1 deliverable)
Working code that proves the hardest part is solvable:
- The core algorithm works
- The key technical challenge is solved
- Basic I/O or interface is functional
- Can be ugly, but must work
- Includes simple tests

**Examples**:
- Game project: Basic game loop with player movement
- Database: Store and retrieve records from disk
- Compiler: Parse and evaluate simple expressions
- Network app: Establish connection and exchange messages

#### 1.3 Project Collaboration Hub Participation
- **Share your project idea** in the Project Collaboration Hub discussion for community feedback
- **Post proof-of-concept screenshots** or demos to get early input
- **Help others** troubleshoot their Phase 1 challenges
- **Build connections** with the classmates who will co-examine your phase defenses

#### Asynchronous Instructor Check-In
**Required**: Submit a short written/video check-in via Canvas as part of the Phase 1 submission
- **Discuss**: Project proposal and proof of concept
- **Review**: Technical feasibility and scope appropriateness
- **Plan**: Adjustments needed for Phase 2
- **Follow-up**: If needed, schedule virtual office hours by appointment or email the instructor for one-on-one guidance

#### Phase Defense
At the Chapter 5 anchor week, the weekly synchronous meeting becomes a **Phase 1 defense**:
- You **present and defend your phase work** — proposal and proof of concept — to the instructor and your classmates.
- **Classmates act as co-examiners**, questioning your work from the published co-examiner question set.
- Expect to **walk through a function of the instructor's choosing** and **justify a design decision**.
- Share your code in advance so co-examiners can prepare. See the **Weekly Defense Guide** (`reference/code-review-guide.md`) for how a defense runs.
- The phase deliverable is due a few days before the defense meeting; the Canvas calendar sets the exact dates for each offering.

### Grading (40 points)

The point-by-point rubric for this phase lives in its phase guide, **`project/phases/PROJECT_PHASE_1.md`** -- that guide is the single source of truth for how the 40 points are awarded. Read it before you start so you know exactly what is being graded.

---

## Phase 2: MVP & Feature Development

### Goal
Build a complete MVP, then add the features that make your project interesting and differentiate it from a toy implementation. This is the longest-running phase of the capstone because it combines core build-out with feature enrichment.

### Deliverables

#### Complete Core Functionality (MVP)
- All essential features working
- Proper class structure and organization
- Memory management handled correctly
- Basic error handling
- Configuration files or settings
- Can be used start-to-finish for basic use case

#### Enhanced Functionality (Features)
- 3-5 significant features beyond MVP
- Improved user experience
- Performance-conscious design where needed
- Advanced C++17 features used appropriately (templates, STL, modern C++)

#### Examples of Features to Add
- **Game**: Multiple levels, save/load, achievements, AI opponents
- **Database**: Indexing, transactions, query optimization, joins
- **Tool**: Multiple input formats, batch processing, plugins, scripting
- **Network App**: Authentication, encryption, multiple clients, protocols

#### Quality Foundations
- Comprehensive error handling for common cases
- Logging system
- Configuration management
- Better algorithms/data structures where they matter

#### Documentation
- README with build and run instructions
- Basic user guide
- Code comments for complex logic

#### Testing
- Unit tests for core components
- At least one integration test
- No memory leaks (valgrind clean or equivalent)

#### Project Collaboration Hub Participation
- **Share MVP progress** with screenshots and key functionality demos
- **Ask for architecture feedback** before implementing major features
- **Showcase advanced features** you've implemented
- **Discuss design patterns** and architectural decisions
- **Help others** debug their MVP and feature challenges

#### Asynchronous Instructor Check-In
**Required**: Submit a mid-phase check-in via Canvas partway through Phase 2, and a check-in with the Phase 2 submission itself
- **Demo**: Core MVP functionality working, then new features added
- **Discuss**: Architecture decisions, code organization, and C++ features used
- **Review**: Progress toward Phase 3 goals
- **Follow-up**: Virtual office hours by appointment, Canvas discussion board, or email the instructor for deeper feedback

#### Phase Defense
At the Chapter 11 anchor week, the weekly synchronous meeting becomes a **Phase 2 defense**:
- You **present and defend your MVP and new features** to the instructor and your classmates.
- **Classmates act as co-examiners**, questioning your work from the published co-examiner question set.
- Expect to **walk through a function of the instructor's choosing** and **justify a design decision**.
- Share your code in advance so co-examiners can prepare. See the **Weekly Defense Guide** (`reference/code-review-guide.md`) for how a defense runs.
- The phase deliverable is due a few days before the defense meeting; the Canvas calendar sets the exact dates for each offering.

### Grading (130 points)

The point-by-point rubric for this phase lives in its phase guide, **`project/phases/PROJECT_PHASE_2.md`** -- that guide is the single source of truth for how the 130 points are awarded. Read it before you start so you know exactly what is being graded.

---

## Phase 3: Robustness, Polish & Presentation

### Goal
Make it production-ready, create a professional finish, and reflect on your journey. In this final phase you'll harden the code, polish the user experience, and deliver a presentation-quality artifact.

### Deliverables

#### Robustness
- Handles expected edge cases gracefully
- Input validation comprehensive
- Recovery from errors
- Stress testing attempted on key paths
- Security considerations addressed (if applicable)

#### Performance
- Profiling completed on at least one critical path
- Bottlenecks identified and addressed where reasonable
- Memory usage responsible
- Response times acceptable
- Scales to reasonable limits

#### Professional Quality
- Consistent coding style
- Test suite with meaningful coverage on core logic
- CI/CD pipeline (GitHub Actions) - recommended
- Static analysis clean (or documented exceptions)
- Documentation complete

#### 3.1 Final Polish
- User experience refined
- Professional README with screenshots/demos
- Installation guide
- API documentation (if applicable)
- Example use cases or tutorials

#### Project Collaboration Hub Participation
- **Share debugging and profiling experiences**
- **Post performance benchmarks** and optimization results
- **Share your final project showcase** with demos and screenshots
- **Reflect on your development journey** in the discussion
- **Help others** prepare for their final submissions
- **Thank classmates** who supported you through the term

#### 3.2 Final Project Presentation & Defense (Phase 3 deliverable)
**Required**: At the Chapter 17 anchor week, the weekly synchronous meeting becomes your **Phase 3 defense** — and that defense *is* the final project presentation. You give a **10-12 minute** presentation live to the instructor and your classmates, who act as co-examiners. The structure below is what to cover; expect live follow-up questions, including a walk-through of a function of the instructor's choosing and a justification of a design decision. Share your code in advance so co-examiners can prepare.

**Live Demo** (~5 minutes)
- Show it working end-to-end
- Demonstrate key features
- Show it handling errors gracefully
- Highlight most impressive functionality

**Technical Deep Dive** (~5 minutes)
- Architecture overview and evolution across all three phases
- Most challenging problems solved and how you solved them
- Sophisticated C++17 features utilized and why you chose them
- Performance characteristics and optimization results
- Code walkthrough of your best implementations
- AI collaboration throughout the project

**Reflection** (~2 minutes)
- What you'd do differently
- Reflection on growth as a C++ developer

Instructor and co-examiner follow-up questions are part of the live defense. If anything needs more discussion afterward, you may request virtual office hours by appointment.

#### 3.3 Comprehensive Reflection Paper (2-3 pages)

**Technical Section**
- Architecture decisions and trade-offs
- Algorithms and data structures chosen
- C++17 features that were most valuable
- What you'd do differently technically

**Process Section**
- Project management approach across the three phases
- Time estimation vs. reality
- Biggest surprises
- Most valuable learning moments

**AI Collaboration Analysis** (integrated throughout phases)
- Evolution of AI usage from Phase 1 to Phase 3
- Specific examples of valuable AI assistance
- Times when AI led you astray or provided poor guidance
- What you learned about effective AI collaboration
- Your refined philosophy on AI in professional development
- Documentation of AI usage in each phase deliverable

**Future Work**
- What you'd add with more time
- How you'd refactor or redesign
- Potential real-world applications

### Grading (130 points)

The point-by-point rubric for this phase lives in its phase guide, **`project/phases/PROJECT_PHASE_3.md`** -- that guide is the single source of truth for how the 130 points are awarded. Read it before you start so you know exactly what is being graded.

---

## Project Scope Guidelines

### Expected Complexity by Phase

| Phase | Approximate Lines | Classes/Modules | Features |
|-------|-------------------|------------------|----------|
| 1 | 200-500 | 2-3 | 1 (core) |
| 2 | 800-1800 | 8-14 | 5-8 |
| 3 | 1500-2500+ | 14-20+ | All polished |

Target: **~1500-2500 lines** for a complete, polished project. Quality over quantity.

### Good Project Characteristics
- **Interesting enough** to sustain a term of sustained work
- **Complex enough** to demonstrate various C++17 features
- **Practical enough** that someone might actually use it
- **Scoped appropriately** - challenging but achievable within the term
- **Extensible** - can grow naturally over phases

### Project Categories & Inspiration

#### Systems Programming
Projects that interact closely with the operating system or implement system-level functionality. Think about tools you use daily that could be reimplemented or improved.

#### Games & Simulations
Interactive applications with real-time requirements. Consider both entertainment and educational simulations that model real-world systems.

#### Developer Tools
Software that helps programmers be more productive. What tools do you wish existed for your own development workflow?

#### Data Processing & Analysis
Applications that handle, transform, and analyze data. Consider the data challenges in your field of interest.

#### Network & Distributed Systems
Applications involving multiple computers or network communication. Think about collaboration tools or distributed processing.

#### Computer Graphics & Visualization
Projects that generate visual output or process images. Consider both 2D and 3D applications, or data visualization tools.

#### Language Processing
Compilers, interpreters, or tools that process structured text. Think about domain-specific languages or code analysis tools.

#### Security & Cryptography
Applications focused on data protection, security analysis, or cryptographic implementations.

---

## AI Usage Policy

### Philosophy
Use AI as you would in a professional setting - as a tool to enhance productivity while maintaining ownership and understanding of your code.

### Required Documentation (Integrated into Phase Deliverables)
Each phase submission must include an AI usage section documenting:
- Significant AI interactions during this phase
- Specific prompts used and responses received
- What you implemented vs. what AI suggested
- What you learned from these interactions
- How your AI usage evolved from the previous phase

### Guidelines
- **Always Allowed**: Debugging, syntax help, documentation generation
- **Document When Used**: Algorithm suggestions, design patterns, optimization
- **Not Acceptable**: Having AI write entire features without understanding

### Project-Long AI Documentation
Track your AI collaboration evolution:
- Phase 1: Learning C++17 basics and project planning
- Phase 2: Architecture decisions, implementation help, and advanced feature development
- Phase 3: Debugging, performance tuning, robustness, and reflection on the entire AI collaboration experience

---

## Grading Rubric Summary

### Distribution (300 points)
- Phase 1: 40 points (13%) - Planning & Proof of Concept
- Phase 2: 130 points (43%) - MVP & Feature Development
- Phase 3: 130 points (43%) - Robustness, Polish & Presentation

**Note**: Project Discussion collaboration is graded separately as part of the course's Participation & Engagement component.

### Late Policy
- 24 hours: -10%
- 48 hours: -20%
- 72 hours: -30%
- >72 hours: -50%
- Final phase: No late submissions

### Bonus Opportunities (up to 15 points)
- Exceptional innovation: +5
- Outstanding documentation: +3
- Helping classmates (documented): +3
- Extra features beyond requirements: +4

---

## Success Tips

### Start with the Hard Part
Don't build the easy UI first. Solve the core technical challenge in Phase 1. This is non-negotiable.

### Keep It Working
Never break your build for more than a day. Always have a working version.

### Test as You Go
Don't save testing for the end. Write tests with your features.

### Use Version Control Properly
- Commit often with meaningful messages
- Use branches for major features
- Tag each phase submission

### Get Feedback Early
- Show your project to others
- Get user feedback
- Don't work in isolation

### Document Decisions
Keep notes on why you made certain choices - you'll need them for the reflection.

### Use the Project Collaboration Hub
- **Post progress updates** (aim for twice per week) to get community feedback and stay motivated
- **Ask technical questions** when you're stuck - your classmates may have solved similar problems
- **Share breakthroughs and discoveries** - help others learn from your experience
- **Help others debug** - explaining solutions reinforces your own understanding
- **Build professional relationships** - your classmates today are your network tomorrow

### When You Need Help
Because this course is fully online and asynchronous:
- **Canvas discussion board**: First stop for questions that peers might answer
- **Email instructor**: For private or urgent concerns
- **Virtual office hours by appointment**: Schedule a live call when you need one-on-one guidance

---

## FAQ

**Q: Can I change my project idea after Phase 1?**
A: Yes, but email the instructor first. Better to pivot early than fail later.

**Q: What if my Phase 1 proof of concept reveals my idea won't work?**
A: That's valuable! Pivot to your backup plan. Finding out early is the point.

**Q: Can I use external libraries?**
A: Yes! Document them and be able to explain what they do.

**Q: How much should I use AI?**
A: As much as helps you learn and be productive. Document it all.

**Q: What if I'm way ahead/behind schedule?**
A: Post in the Canvas discussion board or email the instructor. We can adjust scope or provide extra challenges.

**Q: Can I work on something related to my research/job?**
A: Absolutely! Real projects are the best projects.

**Q: Why C++17 and not newer?**
A: The course Docker container targets C++17, matching *C++ Crash Course* 1st edition. Staying on C++17 guarantees your code compiles in the graded environment.

---

**Remember**: This is YOUR project. Make something you're proud of, that you'll want to show in job interviews, and that demonstrates your growth as a C++ developer.
