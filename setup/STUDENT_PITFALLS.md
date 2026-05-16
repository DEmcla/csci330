# Common Student Pitfalls (Lessons from Prior Semesters)

> Read this once before you start. Skim it again when something breaks. Every pitfall below tripped multiple students in the Fall 2025 section; each has a named fix you can apply in under five minutes.

---

## 1. Getting Docker running

### 🟥 "Cannot connect to the Docker daemon"

**What's happening:** Docker Desktop isn't running. This is the #1 support ticket from prior terms.

**Fix:**
- **Windows:** Open Start menu → search "Docker Desktop" → click it. Wait for the whale icon in the system tray to show "Docker Desktop is running."
- **macOS:** Finder → Applications → double-click Docker. Wait for the whale icon in the menu bar (top-right).
- **Linux:** `sudo systemctl start docker`

Then re-run whatever command failed.

### 🟥 Apple Silicon Mac (M1/M2/M3): build fails or is very slow

**What's happening:** The course container is `linux/amd64`. On Apple Silicon that means it runs under Rosetta emulation — it works, but you need to download the right Docker Desktop build and enable Rosetta.

**Fix:**
1. Go to [docker.com/products/docker-desktop](https://www.docker.com/products/docker-desktop) and specifically download the **Apple Silicon** version (not Intel).
2. In Docker Desktop → Settings → General → enable **"Use Rosetta for x86/amd64 emulation on Apple Silicon."**
3. Restart Docker Desktop.

### 🟥 Windows: "WSL 2 installation is incomplete"

**Fix:**
1. Open PowerShell **as Administrator** and run:
   ```powershell
   wsl --install
   wsl --set-default-version 2
   ```
2. Restart. Then start Docker Desktop again.
3. If that fails, check your BIOS/UEFI to ensure **virtualization (Intel VT-x or AMD-V)** is enabled.

See `setup/docker_troubleshooting.md` for the full list of installation-time issues and their fixes.

---

## 2. Integrating Docker with VS Code

### 🟥 VS Code never prompted me to "Reopen in Container"

**What's happening:** Either VS Code can't see the `.devcontainer/` folder, or the Dev Containers extension isn't installed.

**Fix:**
1. Confirm the Dev Containers extension is installed: VS Code → Extensions → search `Dev Containers` → install if missing.
2. Make sure you opened the **`csci330_u26/` folder** (the one that contains `README.md`, `assignment-templates/`, `setup/`, etc.) — not a parent folder, not a subfolder.
3. Check `.devcontainer/devcontainer.json` exists: in VS Code's Explorer panel, show hidden files (click the gear) and verify the folder.
4. Manually trigger: `Cmd+Shift+P` (macOS) / `Ctrl+Shift+P` (Win/Linux) → type `Dev Containers: Reopen in Container` → press Enter.

### 🟥 I'm in "the container" but `g++` isn't found

**What's happening:** You probably have a terminal from your **host** OS, not from inside the container.

**Fix:**
- Your VS Code bottom-left corner should say `Dev Container: C++ Development`. If it says `WSL`, `SSH`, or nothing, you're not in the container.
- Open a new VS Code integrated terminal with `Ctrl+\`` (backtick) while the Dev Container indicator is showing.
- Inside the container, verify:
  ```bash
  g++ --version   # should show 11.x
  cmake --version # should show 3.22+
  ```

### 🟥 Two devcontainer configs are fighting each other

**What's happening:** In prior terms, a stale `.vscode/devcontainer.json` coexisted with the real `.devcontainer/devcontainer.json`, causing mysterious path mismatches (workspace at `/workspace` vs `/home/student/workspace`).

**U26 ships only the correct config.** If you find yourself with two, delete the one inside `.vscode/` — keep the one inside `.devcontainer/`.

---

## 3. GitHub: forking, branching, pulling updates

### 🟥 "Repository not found" or "Permission denied (publickey)"

**Fix:**
- Check you cloned **your fork** (URL contains your username), not the instructor's repo directly:
  ```bash
  git remote -v
  # origin should be https://github.com/YOUR_USERNAME/csci330_u26.git
  ```
- If the URL is wrong, fix it:
  ```bash
  git remote set-url origin https://github.com/YOUR_USERNAME/csci330_u26.git
  ```
- If you're using SSH and hitting "Permission denied (publickey)", the quick fix is to switch to HTTPS (the URL above). SSH setup is outside the scope of this course.

### 🟥 "Oh no, I committed to `main`"

**What's happening:** You forgot to create a feature branch. Very common in Week 1.

**Fix:** See `setup/GIT_WORKFLOW.md` → "Forgot to branch — committed on main." Two commands and you're back on a proper feature branch with your work intact.

### 🟥 Merge conflicts after `git pull upstream main`

**What's happening:** You and the instructor edited the same file. You need to reconcile.

**Fix:** Don't panic. See `setup/GIT_WORKFLOW.md` → "Merge conflicts when pulling upstream" for the step-by-step. The `<<<<<<<` markers are Git telling you exactly where the conflict is; edit each one, save, `git add`, `git commit`, done.

### 🟥 "I cloned the repo inside the repo"

**What's happening:** You ran `git clone` from inside your existing clone, creating a nested `csci330_u26/csci330_u26/` situation. This happened to several F25 students.

**Fix:**
```bash
# From your outer clone directory
rm -rf csci330_u26   # ⚠️ careful -- make sure you're deleting the nested copy, not yours
git status            # verify you're still inside your real clone
```

---

## 4. Submitting only the right stuff (commit scope)

### 🟥 I committed 300 files in `build/`

**What's happening:** `git add .` scooped up the `build/` directory, CMake caches, object files, and binaries. In F25 this produced 400-MB PRs.

**Fix now:** See `setup/GIT_WORKFLOW.md` → "Accidentally committed a build/ directory."

**Fix forever:** stop using `git add .`. Stage specific paths:
```bash
git add assignments/CSCI330_FirstName_LastName/week01/src/
git add assignments/CSCI330_FirstName_LastName/week01/README.md
```

The course `.gitignore` blocks `build/`, `*.o`, `*.exe`, `.DS_Store`, and a dozen other categories by default. Trust it.

### 🟥 I named my folder `john_doe` or `JohnDoe`

**What's happening:** The grader searches for `CSCI330_FirstName_LastName`. Other names are flagged as late/missing.

**Fix:**
```bash
# Rename with git mv (preserves history)
git mv assignments/john_doe assignments/CSCI330_John_Doe
git commit -m "Rename assignment folder to match convention"
```

### 🟥 I edited a template or a setup file by mistake

**What's happening:** You changed a file outside your own week folder — a file in `assignment-templates/`, `setup/`, or another student's folder. The PR's automatic scope check will fail it (see section 5).

**Fix:** work **only** inside `assignments/CSCI330_FirstName_LastName/weekNN/`. Never edit a template in place — copy it first, then edit the copy. If you want to take notes, keep a `NOTES.md` inside your own week folder.

### 🟥 My PR targets the wrong branch

**What's happening:** GitHub defaults to submitting PRs against the original upstream repository. For this course, you should target **your fork's `main`**, not `upstream/main`.

**Fix:** on the PR creation page, the "base" dropdown should say your username, not `DEmcla`. Change it before you submit.

### 🟥 My PR body is blank

**What's happening:** You submitted a blank PR body, or filled out only the title.

**Fix:** when you open a PR for this repo, the template auto-populates with a short checklist plus "What I did", "Hardest part", and an AI-disclosure prompt. Fill in every box and prompt. Partial PR bodies lose process points even when the code is perfect.

---

## 5. Reading the CI checks on your pull request

Every PR you open runs two automatic **CI checks**. You see them at the bottom of
the PR and in the **Actions** tab. **Both must be green** for the submission to
count — a red check means the submission is not yet complete.

### 🟥 Red "Your code compiles" check

**What's happening:** your code does not compile.

**Fix:** open the **Actions** tab on the PR, click the failed run, and read the
compiler error — it names the file and line. Fix it locally
(`cmake -B build && cmake --build build`), commit, and push again to the same
branch. The PR updates itself and the check re-runs.

### 🟥 Red "Work stays in your week folder" check

**What's happening:** your commit changed a file outside
`assignments/CSCI330_FirstName_LastName/weekNN/` — often an edited template, a
setup file, or two week folders in one PR. The check output lists the files.

**Fix:** restore those files to their original state (`git checkout -- <file>`),
keep all your work inside your own single week folder, commit, and push again.

A red check is normal and recoverable — it is the system catching a mistake
*before* your instructor does. Push a fix and it turns green.

---

## Before you submit — the 60-second check

```
✅ Is my PR title "Week NN Assignment - FirstName LastName"?
✅ Does my PR target MY fork's main (not DEmcla's main)?
✅ Does the "Files changed" tab show ONLY files under assignments/CSCI330_My_Name/weekNN/?
✅ Is there no build/, .o, .exe, .DS_Store, or .vscode/*.user.json in the file list?
✅ Did I fill out every section of the PR template, including AI disclosure?
```

If any answer is no, fix it before you click Submit.

---

## If you're truly stuck

1. Run `git status` and `git branch -a` — screenshot them.
2. Describe in 2-3 sentences what you did last.
3. Email the instructor with both.

Don't force-push. Don't `git reset --hard` on a branch that has work. Don't delete your clone and start over. Recovery from any Git state is almost always possible if you haven't pushed destructive operations up.
