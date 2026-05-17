# 🚀 Development Environment Setup Guide

## ✅ Happy-Path Checklist

When everything is set up correctly, you can:

- [ ] Launch **Docker Desktop** and see "Docker Desktop is running" in your system tray or menu bar
- [ ] Open **VS Code** with the `csci330/` folder, get a "Reopen in Container" prompt, click it, and see a new bottom-left indicator that says `Dev Container: C++ Development`
- [ ] Open a VS Code integrated terminal and type `g++ --version` — you should see GCC 11.x
- [ ] `cd assignment-templates/chapter-02 && cmake -B build && cmake --build build` builds without errors
- [ ] `git remote -v` lists both `origin` (your fork) and `upstream` (DEmcla/csci330)

If any of those five fail, work through the matching Part of this guide below.

---

## 🎯 Overview

Welcome to your C++ development journey! This guide will help you set up a professional C++ development environment using Docker, Git, and VSCode. By the end of this setup, you'll have a consistent development environment that works the same way regardless of whether you're using Windows, macOS, or Linux. **You've got this!**

### 📚 What You'll Learn to Use

- **🐳 Docker**: Creates a consistent development environment in a "container" (think of it as a clean, isolated computer just for your C++ work!)
- **📝 Git**: Tracks changes to your code and enables collaboration (like Google Docs for code!)
- **💻 VSCode**: A powerful code editor that integrates with Docker and Git (your new best friend for writing code!)

### ⏱️ Time Investment
- **Initial setup**: 30-45 minutes
- **Daily use**: Instant startup once configured!

---

## 📦 Part 1: Required Software Installation

Let's get the tools you need installed. Don't worry if this seems like a lot - we'll take it step by step!

### 1.1 Install Docker Desktop 🐳

Docker creates isolated environments called "containers" where your code runs consistently across different computers. Think of it as a virtual computer inside your computer!

#### 🪟 For Windows Users:

1. **Enable WSL2** (Windows Subsystem for Linux):
   - Open PowerShell as Administrator
   - Run: `wsl --install`
   - Restart your computer when prompted
   - ✅ This gives Windows some Linux superpowers!

2. **Download Docker Desktop**:
   - Go to [docker.com](https://docker.com)
   - Download "Docker Desktop for Windows"
   - During installation, ensure "Use WSL 2 instead of Hyper-V" is checked
   - Restart when prompted
   - 💡 **Tip**: Docker needs these restarts to properly integrate with Windows

3. **Configure Docker Desktop**:
   - Open Docker Desktop
   - Go to Settings → Resources → WSL Integration
   - Enable integration with your default WSL distro
   - Allocate at least 4GB of memory
   - ⚡ More memory = faster builds!

#### 🍎 For macOS Users:

1. **Download Docker Desktop**:
   - Go to [docker.com](https://docker.com)
   - Choose the correct version:
     - **Apple Silicon (M1/M2/M3 Macs)**: Docker Desktop for Apple Silicon
     - **Intel Macs**: Docker Desktop for Intel
   - Drag the app to your Applications folder
   - 🎯 Not sure which Mac you have? Click  → About This Mac

2. **Configure Docker Desktop**:
   - Launch Docker Desktop
   - Go to Preferences → Resources → Advanced
   - Allocate at least 4GB of memory
   - Grant necessary permissions when prompted
   - ✅ macOS will ask for permissions - say yes to all!

### 1.2 Install VSCode and Extensions 💻

VSCode is a free, powerful code editor that will integrate with your Docker environment. It's what professional developers use!

1. **Download VSCode**:
   - Go to [code.visualstudio.com](https://code.visualstudio.com)
   - Download for your operating system
   - Install with default settings

2. **Install Required Extensions**: 
   
   Open VSCode and install these extensions (press `Ctrl+Shift+X` on Windows, `Cmd+Shift+X` on macOS):
   
   - 🔧 **C/C++ Extension Pack** (includes everything you need for C++)
   - 📦 **Dev Containers** (for Docker integration)
   - 🐳 **Docker** (for managing containers)
   - 📊 **GitLens** (enhances Git capabilities)
   
   💡 **Pro tip**: Just search for each name and click the blue "Install" button!

### 1.3 Install Git 📝

Git tracks changes to your code and enables you to submit assignments. It's like a time machine for your code!

#### 🪟 For Windows Users:
- Download from [git-scm.com](https://git-scm.com)
- Use default installation options
- **⚠️ Important**: Configure line endings by running this in Command Prompt:
  ```bash
  git config --global core.autocrlf input
  git config --global core.eol lf
  ```
  🎯 This prevents the dreaded "^M" characters in your files!

#### 🍎 For macOS Users:

**Option 1**: Install via Homebrew (if you have it):
```bash
brew install git
```

**Option 2**: Install Xcode Command Line Tools:
```bash
xcode-select --install
```

#### 🌍 Configure Git (All Platforms):

Set up your identity (use your real name and school email):
```bash
git config --global user.name "Your Full Name"
git config --global user.email "your.email@university.edu"
```

✅ **Check**: Run `git --version` to verify installation!

---

## 🏗️ Part 2: Setting Up Your Development Environment

Now let's get your actual C++ workspace ready!

### 2.1 Set Up Git Workflow for Assignment Submissions 📚

This course uses **Pull Requests** for assignment submissions - the same workflow used by professional development teams!

#### **Step 1: Fork the Course Repository**
1. Go to the course repository on GitHub: `https://github.com/DEmcla/csci330`
2. Click the "Fork" button to create your personal copy
3. This creates `https://github.com/YOUR_USERNAME/csci330`

#### **Step 2: Clone Your Fork**
```bash
# Navigate to where you want to store your coursework
cd Desktop  # or wherever you prefer

# Clone YOUR fork (replace YOUR_USERNAME)
git clone https://github.com/YOUR_USERNAME/csci330.git
cd csci330
```

#### **Step 3: Add Upstream Connection**
```bash
# This connects you to the main course repository for updates
git remote add upstream https://github.com/DEmcla/csci330.git

# Verify your connections
git remote -v
# Should show both 'origin' (your fork) and 'upstream' (course repo)
```

#### **Step 4: Configure Git Identity for Course**
```bash
# Use course-specific identity (important for grading!)
git config user.name "FirstName LastName - CSCI330"
git config user.email "your.email@university.edu"
```

#### **Step 5: Create Your Assignment Directory**
```bash
# Replace FirstName and LastName with your actual name
# (You're already inside csci330/ after Step 2)
mkdir -p assignments/CSCI330_FirstName_LastName
```

🎉 **Success!** You now have the professional Git workflow set up!

### 2.2 Build Your Docker Environment 🐳

This creates your C++ development environment:

```bash
# Build the Docker container (this may take a few minutes the first time)
docker-compose build

# Test that it works
docker-compose run cpp-dev
```

☕ **First build taking a while?** This is normal! Docker is downloading and setting up everything you need. Grab a coffee!

If successful, you should see a Linux command prompt inside the container. Type `exit` to return to your normal terminal.

✅ **Victory!** If you see the Linux prompt, your environment is ready!

### 2.3 Dev Container Integration 🔗

**Good news:** the course already ships a `.devcontainer/` folder in `csci330/` with everything configured. You do **not** need to create any VS Code config yourself.

Just:
1. Open the `csci330/` folder in VS Code (File → Open Folder → select `csci330`)
2. When VS Code prompts "Reopen in Container", click it. If no prompt appears, press `Cmd+Shift+P` / `Ctrl+Shift+P` and run **Dev Containers: Reopen in Container**.
3. Wait for the container to build on first launch (a few minutes). Subsequent launches are fast.

💡 **What's happening?** VS Code reads `.devcontainer/devcontainer.json`, builds the course Docker image from `setup/Dockerfile`, mounts your code inside it, and gives you a terminal that runs inside the container. All C++ tools (g++, cmake, gdb, valgrind, clang-format) are available in that terminal.

> ⚠️ Do **not** manually create a `.vscode/devcontainer.json` -- the `.devcontainer/` folder is the supported config. Creating a separate one under `.vscode/` will conflict.

---

## 🎯 Part 3: Your Daily Development Workflow

Here's how you'll work with your environment every day - it becomes second nature quickly!

### 3.1 Starting Your Development Environment 🚀

1. **Open your project in VSCode**:
   - Open VSCode
   - File → Open Folder
   - Select your course directory

2. **Start the development container**:
   - Press `Ctrl+Shift+P` (Windows) or `Cmd+Shift+P` (macOS)
   - Type "Dev Containers: Reopen in Container"
   - Select it and wait for the container to start
   - 🎯 First time? This might take a minute. Future starts are much faster!

3. **You're ready to code!** 🎉
   - The terminal inside VSCode is now running in your Docker container
   - All your C++ tools are ready to use
   - Your files automatically sync between your computer and the container

### 3.2 Building and Testing Your Code 🔨

Navigate to an assignment-template directory and build. The layout in this course is:

- **Templates** (starting code, read-only reference): `assignment-templates/chapter-NN/`
- **Your work** (what you edit and submit): `assignments/CSCI330_FirstName_LastName/chapter-NN/`

For a typical workflow -- copy the template, enter your copy, build:

```bash
# Copy the chapter's template into your personal directory (do this once per chapter)
cp -r assignment-templates/chapter-02 assignments/CSCI330_FirstName_LastName/chapter-02/

# Go to your copy
cd assignments/CSCI330_FirstName_LastName/chapter-02/

# Configure and build (CMake ≥ 3.10 is provided by the container)
cmake -B build
cmake --build build

# Run the compiled program
./build/Chapter02_Types   # exact name depends on the CMakeLists project() line
```

✅ **Success indicators**:
- `cmake -B build` should say "Build files have been written to: .../build"
- `cmake --build build` should end with "[100%] Built target ..."
- Running the executable should print the program's expected output

### 3.3 Basic Git Workflow 📝

Git helps you track changes and submit assignments. Here's the basic workflow:

#### 🧠 Understanding Git Concepts:
- **Repository (repo)** 📁: A folder that Git is tracking
- **Commit** 📸: A snapshot of your code at a specific time
- **Branch** 🌿: A separate line of development
- **Push** ☁️: Upload your changes to GitHub/GitLab

#### 💻 Daily Git Commands:

1. **Check the status of your files** 🔍:
   ```bash
   git status
   ```

2. **Create a new branch for your assignment** 🌿 (do this for each assignment):
   ```bash
   git checkout -b assignment-01
   ```

3. **Add your changes** ➕:
   ```bash
   # Add specific files
   git add src/main.cpp
   
   # Or add all changed files
   git add .
   ```

4. **Commit your changes** 📸:
   ```bash
   git commit -m "Implement basic calculator functions"
   ```
   💡 **Good commit messages** describe WHAT changed and WHY!

5. **Push your work to the remote repository** ☁️:
   ```bash
   git push origin assignment-01
   ```

---

## 📤 Part 4: Assignment Submission via Pull Requests

This course uses **Pull Requests** for assignment submissions - the same professional workflow used in industry!

### 4.1 Before Each Assignment: Sync with Course Updates 🔄

```bash
# Always start by getting the latest course materials
git checkout main
git pull upstream main
git push origin main
```

### 4.2 Assignment Workflow ✍️

#### **Step 1: Create Feature Branch** 🌿
```bash
# Create branch with descriptive name
git checkout -b chapter-02-types-and-arrays
```

#### **Step 2: Set Up Assignment Files** 📁
```bash
# Copy the chapter's template into your directory.
# (replace FirstName_LastName with your name)
cp -r assignment-templates/chapter-02 assignments/CSCI330_FirstName_LastName/chapter-02/

# Navigate to your assignment directory
cd assignments/CSCI330_FirstName_LastName/chapter-02/
```

#### **Step 3: Complete Your Work** 💻
- Use VSCode with the Dev Container
- Build and test frequently: `cmake -B build && cmake --build build`
- Commit regularly with meaningful messages:
  ```bash
  git add .
  git commit -m "Implement fundamental type exercises"
  ```

#### **Step 4: Submit Pull Request** 🚀
```bash
# Final push to your fork
git push origin chapter-02-types-and-arrays
```

Then on GitHub:
1. Go to your fork on GitHub
2. Click "Compare & pull request" 
3. **Fill out the PR template completely** (auto-generated)
4. Submit the pull request

### 4.3 Pull Request Requirements 📋

Your PR must include:
- ✅ **Proper title**: "Chapter NN Assignment - FirstName LastName"
- ✅ **Complete PR template**: All sections filled out
- ✅ **Working code**: Compiles without errors/warnings
- ✅ **All tests pass**: Run `make test` to verify
- ✅ **Code in correct directory**: `assignments/CSCI330_YourName/chapter-NN/`

### 4.4 Code Review and Grading Process 👨‍🏫

1. **Instructor Reviews**: Line-by-line code feedback
2. **Address Feedback**: Make requested changes and push to same branch
3. **Approval**: Once approved, **you merge your own PR**
4. **Grading**: Final grade recorded in Canvas
5. **Clean Up**: Delete branch after merging

### 4.5 After Assignment is Graded 🧹

```bash
# Switch back to main and clean up
git checkout main
git pull upstream main
git push origin main

# Delete old feature branch
git branch -d chapter-02-types-and-arrays
git push origin --delete chapter-02-types-and-arrays
```

**📖 Full Details**: See [`GIT_WORKFLOW.md`](GIT_WORKFLOW.md) for complete instructions!

---

## 🛠️ Part 5: Troubleshooting Common Issues

Don't panic! Every developer faces these issues. Here's how to fix them:

### 5.1 Docker Issues 🐳

#### 🪟 Windows-Specific Problems:

**Docker Desktop won't start:**
- ✅ Make sure WSL2 is enabled
- ✅ Check that "Windows Subsystem for Linux" and "Virtual Machine Platform" are enabled in Windows Features
- ✅ Restart Docker Desktop
- 💡 Still stuck? Try restarting Windows - it often helps!

**Permission errors:**
```bash
# In WSL2 terminal
sudo chown -R $USER:$USER /path/to/your/project
```

#### 🍎 macOS-Specific Problems:

**Docker needs permissions:**
- Go to System Preferences → Security & Privacy → Privacy
- Grant Docker Desktop access to your folders
- 🔑 macOS is protective - this is normal!

**Performance issues:**
- Increase memory allocation in Docker Desktop settings
- Enable "Use gRPC FUSE for file sharing"
- 💡 M1/M2 Macs? Make sure you downloaded the Apple Silicon version!

### 5.2 VSCode Issues 💻

**Container won't start:**
- ✅ Make sure Docker Desktop is running
- Try "Dev Containers: Rebuild Container" from Command Palette
- If still having issues:
  ```bash
  docker-compose down -v
  docker system prune -af
  ```
  ⚠️ This cleans everything - you'll need to rebuild!

**Code completion not working:**
- Make sure you're working inside the container
- Try reloading: "Developer: Reload Window" from Command Palette
- 🔄 Sometimes VSCode just needs a refresh!

### 5.3 Git Issues 📝

**"Repository not found" error:**
- ✅ Check that you have access to the repository
- ✅ Make sure you're using the correct URL
- ✅ Verify your Git credentials
- 💡 Try cloning with HTTPS instead of SSH

**Merge conflicts:**
- Always work in separate branches for each assignment (they prevent most conflicts)
- When you do hit one: `GIT_WORKFLOW.md` has a step-by-step recovery section showing what `<<<<<<<` markers mean and how to resolve them
- If you are stuck after 10 minutes, email the instructor with a screenshot of `git status` — don't force-push or reset, which usually makes recovery harder

**Large files / build artifacts sneaking into commits:**
- The course `.gitignore` already excludes `build/`, `*.o`, `*.exe`, `*.dylib`, `.DS_Store`, etc.
- Never use `git add -f` to force-add an ignored file
- Prefer `git add <specific-path>` over `git add .` to keep your commits tight
- If you already committed junk, see `GIT_WORKFLOW.md` → "Accidentally committed a build/ directory" for the recovery steps

---

## 🆘 Part 6: Getting Help

### 6.1 When Things Don't Work 🤔

1. **Read error messages carefully** 👀 - they often tell you exactly what's wrong
2. **Check the troubleshooting section above** 📖
3. **Ask classmates** 👥 - they might have encountered the same issue
4. **Search online** 🔍 - include the specific error message in your search
5. **Ask your instructor** 👨‍🏫 - provide the specific error message and what you were trying to do

💡 **Remember**: Every expert was once a beginner. Don't hesitate to ask for help!

### 6.2 Best Practices 🌟

- 📝 **Commit your work frequently** - at least after completing each function or major change
- 💬 **Use descriptive commit messages** - "Fix calculator bug" is better than "update"
- 🧪 **Test your code before submitting** - make sure it compiles and runs
- 📁 **Keep your repository organized** - don't commit unnecessary files
- ⏰ **Start assignments early** - setup issues are easier to resolve when you have time

---

## 📋 Quick Reference

### Essential Commands 🎯

**Docker:**
```bash
# Build your environment
docker-compose build

# Start development container
docker-compose run cpp-dev

# If on Windows and having issues, try:
docker-compose run --platform linux/amd64 cpp-dev
```

**Git:**
```bash
# Check status
git status

# Create new branch
git checkout -b assignment-name

# Add and commit changes
git add .
git commit -m "Descriptive message"

# Push to remote
git push origin assignment-name
```

**Building C++ Code:**
```bash
# In your assignment directory (contains a CMakeLists.txt)
cmake -B build
cmake --build build
./build/<executable-name>   # exact name is from the project() line in CMakeLists.txt
```

**VSCode:**
- **Windows**: `Ctrl+Shift+P` opens Command Palette
- **macOS**: `Cmd+Shift+P` opens Command Palette
- Use "Dev Containers: Reopen in Container" to start development environment

---

## 🎉 Summary

**Congratulations!** You now have a professional C++ development environment that:
- ✅ Works consistently across different computers
- ✅ Integrates modern development tools
- ✅ Prepares you for industry-standard workflows
- ✅ Makes assignment submission straightforward

Remember: the initial setup might feel overwhelming, but once configured, this environment will make your C++ development much smoother throughout the course!

**You've got this! Happy coding!** 🚀💻🎯