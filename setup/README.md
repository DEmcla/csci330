# Development Environment Setup - CSCI 330

**⚙️ Professional C++ Development Environment**

This directory contains everything needed to set up your complete C++ development environment using industry-standard tools.

---

## 🚀 Quick Setup (New Students)

### **Complete Setup Process**
1. **📋 [Development Environment Setup](DEVELOPMENT_SETUP.md)** - **START HERE**
   - Install Docker Desktop and VS Code
   - Configure C++ development environment
   - Set up Git and GitHub integration
   - **Time**: 30-45 minutes

2. **📖 [Git Workflow Guide](GIT_WORKFLOW.md)** - **CRITICAL FOR SUBMISSIONS**
   - Professional Pull Request workflow
   - Branching and submission strategies
   - Academic integrity guidelines
   - **Time**: 15-20 minutes to read, lifetime to master

3. **⚠️ [Common Student Pitfalls](STUDENT_PITFALLS.md)** - **LESSONS FROM PRIOR SEMESTERS**
   - Docker, VS Code, GitHub, and commit-scope mistakes F25 students made, with named fixes
   - Skim once before you start; come back when something breaks
   - **Time**: 5-10 minutes to skim, 30 seconds to look up a specific problem

4. **✅ [Environment Verification](test_integration.sh)** - **VALIDATE YOUR SETUP**
   ```bash
   cd setup/
   ./test_integration.sh
   ```
   All tests should pass (Docker daemon test may fail if Docker not running)

---

## 🛠️ Setup Components

### **Core Development Tools**
- **🐳 [Docker Environment](docker-compose.yml)** - Consistent C++ environment
- **⚙️ [Docker Configuration](Dockerfile)** - Container definition with all tools
- **💻 VS Code Integration** - Professional IDE with debugging support
- **📝 Git Workflow** - Industry-standard version control

### **Included Development Stack**
- **Compiler**: g++ pinned to C++17 (matches the course textbook)
- **Build System**: CMake for professional project management
- **Debugger**: GDB with VS Code integration
- **Testing**: Catch2 testing framework
- **Memory Tools**: Valgrind and Address Sanitizer
- **Code Quality**: clang-format for consistent styling

---

## 🎯 Development Approaches

### **🌟 Recommended: Docker + VS Code**
- **Pros**: Consistent environment, professional debugging, integrated tools
- **Best for**: Most students, cross-platform consistency
- **Setup Guide**: [DEVELOPMENT_SETUP.md](DEVELOPMENT_SETUP.md)

### **⚡ Alternative: Docker CLI**  
- **Pros**: Lightweight, fast startup, Linux expertise building
- **Best for**: Command-line enthusiasts, resource-constrained systems
- **Quick Start**:
  ```bash
  docker-compose up -d cpp-dev
  docker-compose exec cpp-dev bash
  ```

### **🖥️ Local Installation**
- **Pros**: No Docker overhead, direct system access
- **Cons**: Platform-specific issues, inconsistent environments
- **Not recommended** unless specific requirements

---

## 📋 Environment Features

### **Professional Debugging**
- **Visual debugging** with breakpoints and variable inspection
- **Memory visualization** for pointer and array operations
- **Step-through debugging** for understanding program flow
- **Integrated terminal** for quick testing

### **Build and Test Integration**
- **CMake integration** for professional project structure
- **Automated testing** with Catch2 framework
- **Continuous compilation** with file watching
- **Error highlighting** and IntelliSense support

### **Git Integration**
- **VS Code Git interface** for visual version control
- **Pull Request workflow** built into development process
- **Commit history visualization** and diff tools
- **Branch management** for feature development

---

## 🔧 Common Setup Issues

### **Docker Problems**
- **Windows**: Ensure WSL2 is enabled and Docker Desktop has proper permissions
- **macOS**: Grant Docker Desktop access to directories and verify correct architecture (Intel vs Apple Silicon)
- **Linux**: Ensure user is in docker group and Docker daemon is running

### **VS Code Integration**
- **Extensions**: Ensure C++ Extension Pack and Remote Containers are installed
- **Container Connection**: Use "Reopen in Container" command for Docker integration
- **IntelliSense**: May need to rebuild container or restart VS Code

### **Git Configuration**
- **Identity**: Set up course-specific Git identity with proper name format
- **Authentication**: Configure GitHub access tokens or SSH keys
- **Remotes**: Ensure both origin (your fork) and upstream (course repo) are configured

---

## 🆘 Troubleshooting Resources

### **Setup Issues**
- **🛠️ [Docker Troubleshooting](docker_troubleshooting.md)** - Common Docker problems and solutions
- **📖 [Development Setup Guide](DEVELOPMENT_SETUP.md)** - Step-by-step setup with troubleshooting
- **🏢 Async instructor support** - email the instructor (or book a virtual 1:1) for environment-specific issues

### **Usage Issues**  
- **📋 [Git Commands Reference](../reference/git-commands.md)** - Essential Git workflow commands
- **🔍 [Course References](../reference/)** - Quick references and troubleshooting guides

### **Emergency Recovery**
```bash
# Nuclear option: completely reset environment
docker-compose down -v
docker system prune -af
docker-compose build --no-cache
docker-compose up -d cpp-dev
```

---

## ✅ Verification Checklist

Before starting coursework, ensure all these work:

### **Environment Tests**
- [ ] **Docker**: Container starts and runs correctly
- [ ] **VS Code**: Opens project in container successfully
- [ ] **Compilation**: Can compile and run "Hello World" program
- [ ] **Debugging**: Can set breakpoints and step through code
- [ ] **Testing**: Can run unit tests with Catch2

### **Git Workflow Tests**
- [ ] **Repository**: Can clone course repository
- [ ] **Branches**: Can create and switch between branches
- [ ] **Commits**: Can add, commit, and push changes
- [ ] **Pull Requests**: Can create PR on GitHub
- [ ] **Integration**: test_integration.sh passes

### **Development Tests**
- [ ] **CMake**: Can configure and build projects
- [ ] **Libraries**: Can link and use external libraries
- [ ] **File Operations**: Can read/write files in container
- [ ] **Memory Tools**: Valgrind and sanitizers work

---

## 🎓 Professional Development Notes

### **Why This Setup?**
- **Industry Standard**: Docker + Git workflow used in professional development
- **Consistency**: Same environment for all students regardless of platform
- **Scalability**: Setup supports complex projects and team collaboration
- **Learning**: Prepares students for professional development practices

### **Skills You'll Gain**
- **Containerization**: Docker for consistent development environments
- **Professional IDEs**: Advanced debugging and development techniques
- **Version Control**: Industry-standard Git workflows
- **Build Systems**: Modern C++ project management with CMake
- **Testing**: Professional testing practices and frameworks

---

## 🧭 Navigation

**🏠 [Course Home](../README.md)** | **🎯 [Project](../project/)** | **📋 [Assignment Templates](../assignment-templates/)**

**🚀 Ready to set up?** Start with **[DEVELOPMENT_SETUP.md](DEVELOPMENT_SETUP.md)** now!

---

*Professional development starts with professional tools. This setup will serve you throughout your C++ journey and beyond.*