# CSCI 330 — C++ Programming

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
2. **Clone your fork:** `git clone https://github.com/YOUR_USERNAME/csci330.git && cd csci330`, then open the folder in VS Code.
3. **Set up your environment:** follow [setup/DEVELOPMENT_SETUP.md](setup/DEVELOPMENT_SETUP.md).
4. **Learn the Git workflow:** read [setup/GIT_WORKFLOW.md](setup/GIT_WORKFLOW.md) — this is how you submit every assignment.
5. **Skim the common pitfalls:** [setup/STUDENT_PITFALLS.md](setup/STUDENT_PITFALLS.md).
6. **Do the GitHub Onboarding assignment first:** [assignment-templates/HW_01/README.md](assignment-templates/HW_01/README.md). It is graded and is a prerequisite for the Chapter 1 homework — it proves you can drive the submission workflow before real work counts.
7. **Then start Chapter 1** from the Canvas course site.

## What's in this repo

```
csci330/
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

## Chapter Sequence

CSCI 330 is organized as a sequence of chapters from *C++ Crash Course*. The
chapter is the unit of work — each carries lecture notes (on Canvas), a homework
assignment (in this repo), and a low-stakes chapter quiz (on Canvas).

| # | Chapter | Topic |
|---|---------|-------|
| 1 | Up and Running | Environment, first programs, compilation |
| 2 | Types | Fundamental types, arrays, memory layout |
| 3 | Reference Types | Pointers, references |
| 4 | Object Lifecycle | Constructors, destructors, RAII, move semantics |
| 5 | Runtime Polymorphism | Inheritance, virtual functions |
| 6 | Compile-Time Polymorphism | Templates, generic programming |
| 7 | Expressions | Operators, operator overloading |
| 8 | Statements | Control flow, exceptions |
| 9 | Functions | Lambdas, function objects |
| 11 | Smart Pointers | `unique_ptr`, `shared_ptr`, `weak_ptr` |
| 12 | Utilities | `optional`, `variant`, `tuple`, `chrono` |
| 13 | Containers | STL containers |
| 14 | Iterators | Iterator patterns, algorithms |
| 15 | Strings | String handling, text processing |
| 16 | Streams | File I/O, string streams, formatted output |
| 17 | Filesystems | Paths, directory iteration, file operations |

The capstone project is introduced after Chapter 2; its three phases are
anchored to Chapters 5, 11, and 17. Supplemental chapters (Ch 10 Testing;
Ch 18 STL Algorithms) are optional, available for capstone needs.

**The Canvas course site is the authoritative schedule** — it maps this chapter
sequence onto your term's weeks and due dates — and the home of all lecture
material.

## How you submit work

Every homework assignment and capstone phase is submitted as a **GitHub Pull
Request**:

1. Sync your fork, then create a feature branch (`chapter-NN-short-description`).
2. Copy the chapter's template into `assignments/CSCI330_First_Last/chapter-NN/` and do your work **there**. (The GitHub onboarding assignment goes in `assignments/CSCI330_First_Last/onboarding/`.)
3. Build and test in the Dev Container (`cmake -B build && cmake --build build`).
4. Commit, push, and open a Pull Request **in your own fork**.
5. Wait for the **CI checks** on the PR to go green.
6. Submit the **PR URL** in Canvas.

The CI checks confirm two things automatically: your work stays inside your own
chapter folder, and your code compiles. **A submission with red CI is not
complete.** See [reference/correct-submission.md](reference/correct-submission.md)
for what a correct PR looks like, and [setup/GIT_WORKFLOW.md](setup/GIT_WORKFLOW.md)
for the full workflow.

## Assessment model

This course uses a **no-exam** model — there is no midterm and no final exam.
Your grade combines the three-phase capstone project (35%), participation in
the weekly synchronous meeting (30%), per-chapter homework plus the GitHub
onboarding assignment (25%), and one low-stakes pacing quiz per chapter on
Canvas (10%). Every offering of CSCI 330 — both the short, intensive pace and
the full-semester pace — includes a mandatory weekly synchronous meeting where
you defend your work; see [reference/code-review-guide.md](reference/code-review-guide.md).
The **official weighting and grading scale are in the syllabus on Canvas.**

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

