# CSCI 330 — C++ Programming (Summer 2026)

This repository is your **workbench** for CSCI 330: the assignment templates you
build from, the workspace where your work lives, the build and CI configuration,
and the capstone project guides.

**Course reading lives on Canvas.** Lecture notes, the syllabus, assessment
information, and the textbook edition note are delivered through the Canvas
course site. Use Canvas to *learn* the material; use this repo to *do the work*.

> **Edition note:** the course uses *C++ Crash Course*, 1st edition (Josh
> Lospinoso, 2019), which covers C++17, and the Docker container is pinned to
> `-std=c++17`. Canvas has the full explanation of what C++20/23 add and why
> they are out of scope.

## Quick Start for Students

1. **Fork this repository** on GitHub.
2. **Clone your fork:** `git clone https://github.com/YOUR_USERNAME/csci330_u26.git && cd csci330_u26`, then open the folder in VS Code.
3. **Set up your environment:** follow [setup/DEVELOPMENT_SETUP.md](setup/DEVELOPMENT_SETUP.md).
4. **Learn the Git workflow:** read [setup/GIT_WORKFLOW.md](setup/GIT_WORKFLOW.md) — this is how you submit every assignment.
5. **Skim the common pitfalls:** [setup/STUDENT_PITFALLS.md](setup/STUDENT_PITFALLS.md).
6. **Do the Week 0 GitHub Onboarding assignment first:** [assignment-templates/HW_01/README.md](assignment-templates/HW_01/README.md). It is graded and is a prerequisite for HW 1 — it proves you can drive the submission workflow before real work counts.
7. **Then start Week 1** from the Canvas course site.

## What's in this repo

```
csci330_u26/
├── assignment-templates/   # Starter code + the spec for each assignment
├── assignments/            # YOUR submission workspace (you create your folder here)
├── project/                # The 3-phase capstone project guides
├── setup/                  # Environment setup + Git workflow guides
├── reference/              # Git commands, the code-review guide, catch-up materials
├── .devcontainer/          # Docker dev-environment config
└── .github/                # PR template + the CI checks that run on your work
```

Lecture notes, the syllabus, assessment details, and all course reading are on
**Canvas**, not in this repo.

## 6-Week Schedule

| Week | Chapters | Theme | Major Deliverable |
|------|----------|-------|-------------------|
| 1 | Ch 1 + 2 | Foundations: environment, types | HW 1 |
| 2 | Ch 3 + 4 | Memory model: references, RAII | HW 2 · Capstone Phase 1 |
| 3 | Ch 5 + 6 | Polymorphism: virtual, templates | HW 3 · **Midterm** |
| 4 | Ch 7 + 8 + 9 | Language mechanics: expressions, functions, lambdas | HW 4 · Capstone Phase 2 |
| 5 | Ch 11 + 12 + 13 | Modern C++: smart pointers, utilities, containers | HW 5 |
| 6 | Ch 14 + 15 | STL: iterators, strings; wrap-up | HW 6 · **Final** · Capstone Phase 3 |

The Canvas course site is the authoritative schedule and the home of all lecture
material.

## How you submit work

Every homework assignment and capstone phase is submitted as a **GitHub Pull
Request**:

1. Sync your fork, then create a feature branch (`weekNN-short-description`).
2. Copy the week's template into `assignments/CSCI330_First_Last/weekNN/` and do your work **there**.
3. Build and test in the Dev Container (`cmake -B build && cmake --build build`).
4. Commit, push, and open a Pull Request **in your own fork**.
5. Wait for the **CI checks** on the PR to go green.
6. Submit the **PR URL** in Canvas.

The CI checks confirm two things automatically: your work stays inside your own
week folder, and your code compiles. **A submission with red CI is not
complete.** See [reference/correct-submission.md](reference/correct-submission.md)
for what a correct PR looks like, and [setup/GIT_WORKFLOW.md](setup/GIT_WORKFLOW.md)
for the full workflow.

## Assessment model

Your grade combines two cumulative assessments (midterm + final), the three-phase
capstone project, async discussion and participation, and weekly homework. The
**official weighting and grading scale are in the syllabus on Canvas.** No weekly
quizzes this term.

## Learning Objectives

By the end of this course, you will be able to:

- Write modern C++17 programs using the standard library with confidence
- Apply RAII and smart-pointer patterns for correct memory management
- Use runtime and compile-time polymorphism appropriately
- Build multi-file projects with CMake
- Submit work professionally via Git and Pull Requests
- Design and deliver an ambitious project across three iterative phases

## Prerequisites

- One semester of prior programming experience (Python, Java, C#, etc.)
- Comfort with the command line
- A computer with 4 GB+ RAM and disk space for Docker Desktop

## Getting Help (asynchronous)

1. Check the chapter's quick-help page on Canvas for common issues
2. Post questions in the Canvas course discussion boards
3. Email the instructor (response within 24 hours on weekdays)
4. Request a virtual 1:1 meeting with the instructor if you are stuck for more than an hour

## Resources

- [cppreference.com](https://en.cppreference.com/) — authoritative C++ reference
- [Book companion site: cppcrash.com](https://cppcrash.com/)
- [Docker Documentation](https://docs.docker.com/)
- [CMake Documentation](https://cmake.org/documentation/)

---

**Course Version:** Summer 2026
