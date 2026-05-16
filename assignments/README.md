# Assignment Submissions - CSCI 330 U26

This directory is where **your** weekly assignment work lives. Each student gets their own folder; week directories go inside that.

## Directory Structure

```
assignments/
└── CSCI330_FirstName_LastName/     ← your personal folder (you create this once)
    ├── week01/                      ← one folder per week
    ├── week02/
    ├── week03/
    └── ...
```

- **Folder name format:** `CSCI330_FirstName_LastName` — exact case and underscores matter. The grader uses this name to find your work.
- **Week folders:** `week00` for the GitHub Onboarding assignment, then `week01` through `week06` for the six homework weeks.

## Before HW 1: the Week 0 GitHub Onboarding assignment

**Do this first.** `assignment-templates/HW_01/` is the **Week 0 GitHub Onboarding
assignment** — a tiny Hello-World project that walks you through one full
fork → branch → copy → commit → push → PR cycle. It is a **graded prerequisite**:
HW 1 will not be accepted until your onboarding pull request passes its CI checks.
Copy it into `assignments/CSCI330_FirstName_LastName/week00/` and follow its
`README.md`.

## How you submit (every assignment)

Submission is **one artifact**: open a **Pull Request** in your fork, then submit
the **PR URL** to Canvas. There is no separate directory URL to submit — the PR
is the submission.

Your PR runs automated **CI checks (scope + build)**. **Both must be green** for
your submission to count. A red check means the submission is incomplete: read
the check output, fix the problem, and push again to the same branch.

The assignment specification for each week is the `README.md` inside that week's
template (for example, `assignment-templates/chapter-02/README.md`) — it travels
with the template when you copy it.

## Quick Start

### 1. Create your personal folder (one time, at the start of the term)

```bash
# From the csci330_u26/ repo root (i.e., your clone of the course fork)
mkdir -p assignments/CSCI330_FirstName_LastName
```

### 2. For each weekly assignment

```bash
# a) Start from an up-to-date main
git checkout main
git pull upstream main
git push origin main

# b) Create a feature branch for this week
git checkout -b week01-types-and-arrays

# c) Copy the chapter's template into your week folder
cp -r assignment-templates/chapter-02 assignments/CSCI330_FirstName_LastName/week01/

# d) Enter your week folder and do the work
cd assignments/CSCI330_FirstName_LastName/week01/

# e) Build and test inside the Dev Container
cmake -B build
cmake --build build
./build/<executable-name>

# f) Stage ONLY your week folder (not the whole repo)
cd ~/Desktop/csci330_u26     # go back to repo root
git add assignments/CSCI330_FirstName_LastName/week01/src/
git add assignments/CSCI330_FirstName_LastName/week01/README.md
git status                    # verify nothing sneaky got staged

# g) Commit and push
git commit -m "Week 01: types and arrays"
git push origin week01-types-and-arrays

# h) Open the PR on github.com; fill out the template completely
# i) Wait for the CI checks (scope + build) to go green, then submit the PR URL to Canvas
```

## Full workflow details

See [../setup/GIT_WORKFLOW.md](../setup/GIT_WORKFLOW.md) for:

- Fork + clone + upstream setup (do this once)
- Feature-branch naming conventions
- PR requirements and checklist
- "I broke it" recovery: forgot to branch, merge conflicts, accidentally committed build artifacts
- Cheat sheet of common Git commands

## Important rules

- Work only in `assignments/CSCI330_FirstName_LastName/` — never modify `assignment-templates/`, `setup/`, `project/`, or any other course directory
- One week per Pull Request — don't submit multiple weeks in one PR
- Never commit directly to `main`; always use a feature branch named `weekNN-short-description`
- Stage specific paths with `git add <path>`, not `git add .` — the `.gitignore` has your back but being explicit keeps commits clean
- Keep your fork synchronized at the start of each new assignment

## What to commit (and what not to)

**Commit:**
- Your source files in `src/` (.cpp, .h)
- Your `README.md` in the week folder explaining what you did
- Modified or added tests in `tests/` if the template has them
- Any other files the assignment specifically asks you to create

**Do NOT commit** (the `.gitignore` handles these automatically):
- `build/` directory and all CMake artifacts
- `.o`, `.exe`, `.dylib`, or other compiled binaries
- `.DS_Store`, `Thumbs.db`, editor swap files
- Personal `.vscode/*.user.json` settings
- Zip files or tarballs of your work

If you accidentally committed junk, see `../setup/GIT_WORKFLOW.md` → "Accidentally committed a build/ directory" for the recovery steps.

## Getting help

- **Git commands:** [../reference/git-commands.md](../reference/git-commands.md)
- **Assignment requirements:** the `README.md` inside that week's template — e.g. `../assignment-templates/chapter-02/README.md`
- **Async instructor support:** email the instructor or post on the Canvas discussion board; virtual 1:1 appointments available by request
