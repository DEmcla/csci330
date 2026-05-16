# Anatomy of a Correct Submission

Use this page to check your Pull Request **before** you submit the URL to Canvas.

## A correct PR

A correct submission is a Pull Request where:

- The **diff** (the "Files changed" tab) shows **only** files inside your own
  `assignments/CSCI330_First_Last/weekNN/` folder.
- Both **CI checks are green** — "Work stays in your week folder" and "Your code
  compiles".
- The branch is named `weekNN-short-description`.

If all three are true, you are done — submit the PR URL in Canvas.

> _[Instructor: insert an annotated screenshot of a correct PR here.]_

## The three classic mistakes

### 1. The diff shows the whole repo ("all my files")

**What you see:** the Files changed tab lists course chapters, templates, or
hundreds of files you did not write.

**Cause:** you copied your work to the wrong place, or committed changes to files
outside your week folder.

**Fix:** all your work must live in `assignments/CSCI330_First_Last/weekNN/` and
nowhere else. Move your files there, commit, and push again.

### 2. Red "Your code compiles" check

**What you see:** a red ✗ on the build check.

**Cause:** your code does not compile.

**Fix:** open the **Actions** tab on the PR, read the compiler error, fix it
locally (`cmake -B build && cmake --build build`), commit, and push again — the
PR updates itself.

### 3. Red "Work stays in your week folder" check

**What you see:** a red ✗ on the scope check, listing files.

**Cause:** your commit changed files outside your `weekNN/` folder — often an
edited template or a course file.

**Fix:** restore those files to their original state, keep your work inside your
own week folder, commit, and push again.

> _[Instructor: insert annotated screenshots of each failure here.]_

## Still stuck?

See `setup/STUDENT_PITFALLS.md` for step-by-step recovery, or post in the Canvas
course discussion.
