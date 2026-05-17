# CSCI 330 Git Workflow Guide

This guide is what you follow for every chapter assignment. **Read it once at the start of the term. Bookmark it. Come back when you get stuck.**

Total skim time: 10 minutes. Total doing-the-setup time (one-time): ~15 minutes.

---

## TL;DR — the whole loop on one page

```
one time, start of term:
  fork → clone → add upstream → GitHub Onboarding assignment

every assignment:
  git checkout main
  git pull upstream main
  git checkout -b chapter-NN-short-description
  (do the work inside assignments/CSCI330_First_Last/chapter-NN/)
  git add <specific files, not .>
  git commit -m "Chapter NN: brief description"
  git push origin chapter-NN-short-description
  (open PR on github.com → fill out the template → wait for CI checks to go green)
  (submit the PR URL to Canvas)
```

**Your submission is one artifact: the Pull Request.** You open a PR in your fork,
the PR's CI checks (scope + build) run automatically, and once they are green you
submit the **PR URL** to Canvas. There is no separate "directory URL" — the PR is
the submission, and it is not complete until the CI checks pass.

**Before HW 1, do the GitHub Onboarding assignment first.**
`assignment-templates/HW_01/` is the GitHub Onboarding assignment — a tiny
Hello-World project that walks you through one full submission cycle. It is a
**graded prerequisite**: HW 1 is not accepted until your onboarding PR passes its
CI checks. Do it during setup, before the first chapter assignment.

If you already know Git, that box is everything. The rest of this file is "why" and "help, I broke it."

---

## One-time setup

### 1. Fork the course repository

1. Open the course repository on GitHub: `https://github.com/DEmcla/csci330`
2. Click the **Fork** button (top-right of the page).
3. GitHub creates `https://github.com/YOUR_USERNAME/csci330` — your personal copy. This is where you'll push your work.

**"Fork" vs "clone" vs "upstream" in one sentence each:**
- **Fork** = a copy of the course repo that belongs to you on GitHub.
- **Clone** = a copy on your laptop so you can edit files.
- **Upstream** = a pointer from your clone back to the instructor's original repo, so you can pull updates.

### 2. Clone your fork onto your laptop

```bash
# Pick a sensible location; Desktop is fine
cd ~/Desktop

# Replace YOUR_USERNAME with your GitHub handle
git clone https://github.com/YOUR_USERNAME/csci330.git
cd csci330
```

### 3. Add the upstream remote

```bash
git remote add upstream https://github.com/DEmcla/csci330.git

# Sanity check -- you should see BOTH of these
git remote -v
# origin    https://github.com/YOUR_USERNAME/csci330.git (fetch)
# origin    https://github.com/YOUR_USERNAME/csci330.git (push)
# upstream  https://github.com/DEmcla/csci330.git (fetch)
# upstream  https://github.com/DEmcla/csci330.git (push)
```

If either line is missing, redo step 3. If both say `YOUR_USERNAME` or both say `DEmcla`, you probably typo'd a URL — fix with `git remote set-url <name> <correct-url>`.

### 4. Set your Git identity for the course

```bash
git config user.name "FirstName LastName"
git config user.email "your.email@mcla.edu"
```

### 5. Make your personal assignment directory

```bash
# Inside the csci330/ clone directory you just cd'd into
mkdir -p assignments/CSCI330_FirstName_LastName
```

⚠️ **Use exactly this naming pattern:** `CSCI330_FirstName_LastName`
- ✅ `CSCI330_Jane_Doe`
- ✅ `CSCI330_John_Smith`
- ❌ `jane_doe` (wrong case, missing prefix)
- ❌ `JaneDoe` (missing underscore prefix)
- ❌ `330_Jane` (wrong prefix)

The naming matters because the grader uses it to find your work. Non-matching names get flagged as late/missing.

---

## The per-assignment loop

Do this for every chapter assignment, in order.

### Step 1: Sync your fork with the course

Before you start a new assignment, pull in anything new from the instructor:

```bash
git checkout main
git pull upstream main
git push origin main
```

If this step prints merge-conflict messages, see **Help, I broke it → Merge conflicts** at the bottom.

### Step 2: Create a feature branch

```bash
# Pattern: chapter-NN-short-description (all lowercase, hyphen-separated)
git checkout -b chapter-02-types-and-arrays

# Sanity check -- you should be on your new branch, NOT on main
git branch
# * chapter-02-types-and-arrays       ← the asterisk should be here
#   main
```

> ⚠️ **Never commit on `main`.** If you do, your work will be rejected. See "Forgot to branch" below.

### Step 3: Copy the chapter's template into your directory

```bash
cp -r assignment-templates/chapter-02 assignments/CSCI330_FirstName_LastName/chapter-02/

cd assignments/CSCI330_FirstName_LastName/chapter-02/
```

The full assignment specification is the `README.md` **inside that template**
(e.g. `assignment-templates/chapter-02/README.md`) — it is copied along with the
template, so the spec sits right next to the code you edit. There is no separate
assignment file to hunt down.

### Step 4: Do the work

- Edit source files (`src/main.cpp`, etc.)
- Write a short `README.md` in your chapter directory explaining what you did
- Build and test frequently:
  ```bash
  cmake -B build
  cmake --build build
  ./build/<executable-name>
  ```

### Step 5: Commit -- be specific about what you stage

❌ **Don't do this** (stages everything, including build artifacts, .DS_Store, editor state):
```bash
git add .
```

✅ **Do this instead** (stage only source files you actually wrote):
```bash
# From the repo root
cd ~/Desktop/csci330

git status     # see what changed
git add assignments/CSCI330_FirstName_LastName/chapter-02/src/
git add assignments/CSCI330_FirstName_LastName/chapter-02/README.md
git status     # confirm -- should show ONLY your source files and README

git commit -m "Chapter 02: types and arrays assignment"
```

The course `.gitignore` excludes `build/`, `*.o`, `.DS_Store`, `.vscode/*.user.json`, and other junk. But `git add .` sometimes tries to sneak new files past it. Stage specific paths; avoid surprises.

### Step 6: Push your branch to your fork

```bash
git push origin chapter-02-types-and-arrays
```

### Step 7: Open a Pull Request

1. Go to `https://github.com/YOUR_USERNAME/csci330` in your browser.
2. GitHub will show a banner: *"Compare & pull request"* for your just-pushed branch. Click it.
3. **Critical:** the PR target should be **your fork's `main` branch**, not the instructor's upstream. GitHub sometimes defaults to the wrong base — double-check.
4. Fill out the PR template completely. Partial submissions lose points for process even if the code is right.
5. Click **Create pull request**.

### Step 8: Wait for the CI checks, then submit the PR URL to Canvas

Once the PR is open, GitHub runs **CI checks** on it automatically:

- **Scope check** — confirms you only touched files inside your own
  `assignments/CSCI330_FirstName_LastName/chapter-NN/` folder.
- **Build check** — confirms your code compiles.

**Both checks must be green for your submission to be complete.** If a check is
red, click it, read the output, fix the problem, and `git push` again to the same
branch — the checks re-run automatically on the updated PR.

When both checks are green, copy the **PR URL** from your browser and submit it on
Canvas. The PR URL is the one artifact you hand in — there is no separate
directory URL to submit.

Your grade comes from the review comments on that PR plus Canvas.

---

## Checklist: your PR should look like this

Before you hit Submit, run through this list. A clean PR saves you and the grader 20 minutes of back-and-forth.

- [ ] PR title follows the format: `Chapter NN Assignment - FirstName LastName`
- [ ] PR targets **your fork's `main`**, not `upstream/main`
- [ ] Only files inside `assignments/CSCI330_FirstName_LastName/chapter-NN/` are touched
- [ ] No `build/` directory, `.o` files, `.exe`, or `.DS_Store` in the file list
- [ ] No modifications to `assignment-templates/`, `setup/`, `project/`, or any other course directory (those are the course's; leave them alone)
- [ ] `README.md` in your chapter directory explains what the assignment does and how to build/run it
- [ ] Code compiles without warnings under `-Wall -Wextra`
- [ ] The PR template is filled out, including the AI-assistance disclosure
- [ ] The PR's CI checks (scope + build) are **green** — fix and re-push if not
- [ ] The PR URL has been submitted on Canvas

---

## Help, I broke it

### Forgot to branch — committed on main

Symptom: `git branch` shows `* main`, and you have uncommitted or committed work on main.

Fix:
```bash
# Create a branch from your current state (this preserves your work)
git checkout -b chapter-02-forgot-to-branch

# If you had already committed to main, reset main back to upstream
git checkout main
git reset --hard upstream/main     # ⚠️ destructive, only on main

# Now switch back to your feature branch -- your work is safe there
git checkout chapter-02-forgot-to-branch
```

### Merge conflicts when pulling upstream

Symptom: `git pull upstream main` prints `CONFLICT` and your files have `<<<<<<<` markers in them.

What a conflict looks like in a file:
```
<<<<<<< HEAD
your version of the line
=======
the instructor's version of the line
>>>>>>> upstream/main
```

Fix (straightforward case):
1. Open the conflicted files in VS Code. Conflicts are highlighted.
2. For each conflict, decide which version (or a blend) is correct. Delete the `<<<<<<<`, `=======`, and `>>>>>>>` markers.
3. Save the file.
4. `git add <the-file>`
5. When all conflicts are resolved: `git commit` (Git will fill in a merge-commit message automatically — just save and close the editor)
6. `git push origin main`

If you're genuinely lost, **don't force-push or reset** — email the instructor with a screenshot of `git status` and a short description of what you did last. Recovery is almost always possible from whatever state you're in.

### "It says upstream branch is ahead — can't push"

Symptom: `git push origin main` is rejected because upstream has new commits.

Fix:
```bash
git pull upstream main         # merge instructor's new commits
# resolve conflicts if any (see above)
git push origin main
```

### Accidentally committed a build/ directory or other junk

Symptom: `git status` shows you added 200 files in `build/` to your last commit.

Fix:
```bash
# Undo the commit (keeps your file changes but uncommits them)
git reset HEAD~1

# Remove the build/ directory from the index
git rm -r --cached build/

# Double-check .gitignore has build/ listed (it does by default)
grep "^build/" .gitignore

# Re-stage only what you meant to commit
git add assignments/CSCI330_FirstName_LastName/chapter-02/src/
git commit -m "Chapter 02: types and arrays"
```

### My fork is wildly out of sync with upstream

Nuclear option (only if you are sure your own work is safe on a feature branch):
```bash
git fetch upstream
git checkout main
git reset --hard upstream/main
git push --force origin main
```
⚠️ **Only do this to `main`, never to a branch with your work.** If your work is on `chapter-02-something`, it is not affected by this.

---

## Branch management (after a PR is merged)

Once the instructor merges your PR:

```bash
# Go back to main and pull the merged change
git checkout main
git pull upstream main
git push origin main

# Delete the feature branch locally and remotely
git branch -d chapter-02-types-and-arrays
git push origin --delete chapter-02-types-and-arrays
```

Then for the next assignment, start from step 1 of **The per-assignment loop** above.

---

## Common Git commands cheat sheet

| Command | Purpose |
|---------|---------|
| `git status` | Show which branch you're on + what's changed |
| `git branch` | List all local branches (`*` marks the current one) |
| `git checkout main` | Switch to the main branch |
| `git checkout -b <name>` | Create and switch to a new branch |
| `git add <path>` | Stage a file or directory for the next commit |
| `git commit -m "msg"` | Record the staged changes |
| `git push origin <branch>` | Send a branch up to your fork on GitHub |
| `git pull upstream main` | Pull instructor's updates into your current branch |
| `git log --oneline -20` | See your last 20 commits |
| `git diff` | Show changes you haven't staged yet |
| `git diff --cached` | Show changes you have staged but not committed |

See also `reference/git-commands.md` for a longer reference.

---

## Important rules

### ⚠️ Never do these

- Commit directly to `main` (always use a feature branch)
- Share your GitHub fork URL with other students (makes peer plagiarism trivial)
- Copy code from another student's repository
- Force-push (`git push --force`) to a branch that already has a PR open
- Commit files that are in `.gitignore` using `git add -f` (defeats the whole point)

### ✅ Always do these

- Work in feature branches named `chapter-NN-description`
- Stage specific files with `git add <path>`, not `git add .`
- Fill out the PR template completely
- Keep your fork synchronized before starting a new assignment
- Use meaningful commit messages ("Implement polymorphic shape hierarchy" not "stuff")

---

## Academic integrity via Git

Git provides the grader with perfect timestamped records of every commit. This is good for you (it documents your process and protects you from false accusations) and bad for plagiarism (copy-pasting someone's work shows up immediately in the commit pattern).

- Commits at 3 AM the morning of the deadline with no prior history = red flag
- Commits spread across the week with incremental progress = what we want to see
- Single monolithic "final submission" commit with no intermediate history = not ideal; commit early and often

---

## FERPA compliance

- Your code is public (your fork is public by default — this is a feature for portfolios)
- Your grades and instructor feedback stay in Canvas (private)
- Never commit personal information (SSN, home address, etc.) in code or comments

---

## Getting help

- **Git error messages** — Google them; most are well-documented. Include the exact error text in your search.
- **Stuck on the workflow** — email the instructor with a screenshot of `git status` and `git branch -a`. Never force-push to "fix" something you don't understand; it usually makes recovery harder.
- **Peer collaboration** — you may discuss *concepts* with classmates in Canvas discussions. You may not share code.

---

**Success tip:** run `git status` before you do anything destructive. It is the single most useful Git command. If `git status` output surprises you, stop and figure out why before running the next command.
