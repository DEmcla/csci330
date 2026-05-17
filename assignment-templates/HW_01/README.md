# GitHub Onboarding Assignment

**This is a graded assignment.** It is worth **2% of your course grade** and is a
**prerequisite for HW 1** — HW 1 will not be accepted until your onboarding pull
request is verified green.

**Due:** see Canvas for the exact date.

## Why this exists

The C++ here is trivial — a Hello-World program. The point is not the code; it
is to prove you can drive the **whole submission workflow** before real
assignments count. Most lost points are lost to GitHub mistakes, not to C++. We
fix that here, first.

## What to do

Complete one full cycle of the course submission workflow:

1. **Fork** the course repository on GitHub.
2. **Clone** your fork and open it in the Dev Container (see `setup/DEVELOPMENT_SETUP.md`).
3. Create a branch: `git checkout -b onboarding`
4. **Copy this template** into your own onboarding folder (replace `First_Last` with your name):
   ```bash
   cp -r assignment-templates/HW_01 assignments/CSCI330_First_Last/onboarding
   ```
5. In `assignments/CSCI330_First_Last/onboarding/`, complete the `TODO` markers in
   `src/main.cpp` — print "Hello, World!", ask for the user's name, greet them.
6. **Build and test** in the Dev Container:
   `cmake -B build && cmake --build build`, then run `./build/hello_world`.
7. **Commit** your work and **push** the branch to your fork.
8. **Open a Pull Request** in your fork (`onboarding` → `main`).
9. Wait for the **CI checks** on the PR to finish — both must be **green**.
10. **Submit the PR URL** in Canvas.

## How it is graded

Your onboarding PR must show:

- A **green CI** result — the scope check and the build check both pass.
- A diff that contains **only** files inside `assignments/CSCI330_First_Last/onboarding/`.

If the CI is red, or the diff reaches outside your onboarding folder, the
submission is not complete — fix it and push again (the PR updates itself). See
`reference/correct-submission.md` for what a correct submission looks like, and
`setup/STUDENT_PITFALLS.md` if you get stuck.

## Files in this template

- `src/main.cpp` — the Hello-World skeleton with `TODO` markers
- `tests/test_main.cpp` — a sample test, so you see a test run pass
- `CMakeLists.txt` — build configuration
