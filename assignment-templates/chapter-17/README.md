# Chapter 17: Filesystems - Practice Problems

## 📋 Before You Begin

**✅ Prerequisites Check:**
- [ ] **Completed textbook reading**: Chapter 17 "Filesystems"
- [ ] **Worked through lecture notes**: All core concepts and hands-on problems
- [ ] **Development environment ready**: VS Code + compiler setup verified

**🚫 Don't start these assignments until you've completed the textbook and lecture notes!**

## Instructions

- These problems apply concepts from both the textbook and lecture notes.
- Each problem builds on the previous filesystem concepts.
- **Time expectation**: ~3 hours total for all four problems.
- All four programs use only the C++17 standard library (`<filesystem>` is
  standard in C++17 - no extra libraries needed).
- **Self-contained test data**: each program creates its own temporary
  directory (under the system temp directory), runs against it, and removes it
  on exit. Do not point these programs at directories you care about.
- Test all programs thoroughly before submission.

---

## Problem 1: Directory Size Calculator (40 minutes)

**Objective**: Recursively total the size of every file in a directory tree.

Write a function that walks a directory tree and reports the combined size of
all regular files it contains, plus a count of files and subdirectories.

```cpp
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

struct SizeReport {
    std::uintmax_t total_bytes = 0;
    std::size_t file_count = 0;
    std::size_t directory_count = 0;
};

// TODO: Recursively walk `root` and total the size of all regular files.
//   - Use fs::recursive_directory_iterator.
//   - Count regular files and directories separately.
//   - Use fs::file_size() only on regular files.
//   - Wrap filesystem calls in try/catch for fs::filesystem_error.
SizeReport calculate_directory_size(const fs::path& root) {
    /* your code here */
}

// TODO: Convert a byte count into a human-readable string.
//   Example: 2048 -> "2.00 KB", 1500000 -> "1.43 MB"
//   Units: B, KB, MB, GB (1 KB = 1024 B).
std::string format_size(std::uintmax_t bytes) {
    /* your code here */
}
```

**Expected Output** (sizes will vary with the generated test data):
```
Directory: /tmp/csci330_ch17_XXXXXX
Files:       6
Directories: 3
Total size:  1.43 KB
```

**Hints**:
- `entry.is_regular_file()` and `entry.is_directory()` classify each entry.
- `fs::file_size()` throws if called on a directory - guard with `is_regular_file()`.
- For `format_size`, divide by 1024 while the value is `>= 1024` and the unit
  index is below the last unit.

---

## Problem 2: File-Type Analyzer (40 minutes)

**Objective**: Report directory statistics grouped by file extension.

Scan a directory tree and produce a per-extension breakdown: how many files of
each extension there are and how many bytes they occupy in total.

```cpp
#include <filesystem>
#include <iostream>
#include <map>
#include <string>

namespace fs = std::filesystem;

struct ExtensionStats {
    std::size_t count = 0;
    std::uintmax_t total_bytes = 0;
};

class FileTypeAnalyzer {
public:
    // TODO: Recursively scan `root`. For each regular file, look up its
    //   extension (use "(none)" for files with no extension) and update the
    //   matching ExtensionStats entry.
    void analyze(const fs::path& root) {
        /* your code here */
    }

    // TODO: Print one line per extension, sorted by descending file count.
    //   Format each line as: <extension>  <count> files  <total bytes> bytes
    void print_report() const {
        /* your code here */
    }

private:
    std::map<std::string, ExtensionStats> stats_;
};
```

**Expected Output** (extensions and counts depend on the generated test data):
```
File-type breakdown:
  .txt    3 files   312 bytes
  .cpp    2 files   148 bytes
  (none)  1 files    20 bytes
```

**Hints**:
- `entry.path().extension()` returns a `fs::path`; convert with `.string()`.
- A `std::map` keeps extensions in sorted order; copy entries into a
  `std::vector` and `std::sort` by count for the descending report.

---

## Problem 3: Duplicate File Finder (40 minutes)

**Objective**: Detect files with identical content.

Two files are duplicates when they have the same size **and** the same content
hash. Group files first by size (a fast filter), then confirm matches by
hashing content.

```cpp
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

namespace fs = std::filesystem;

// TODO: Compute a content hash for the file at `path`.
//   Read the file in binary mode and feed its bytes to std::hash<std::string>,
//   or implement a simple rolling hash. Return the hash as a hex string.
std::string hash_file(const fs::path& path) {
    /* your code here */
}

// TODO: Find groups of duplicate files under `root`.
//   1. Recursively collect every regular file with its size.
//   2. Group files by size; sizes with only one file cannot have duplicates.
//   3. Within each size group, hash the files and group by hash.
//   4. Return only the groups that contain two or more files.
std::vector<std::vector<fs::path>> find_duplicates(const fs::path& root) {
    /* your code here */
}
```

**Expected Output** (paths depend on the generated test data):
```
Duplicate groups found: 1
Group 1 (2 files, 41 bytes each):
  /tmp/csci330_ch17_XXXXXX/a/notes.txt
  /tmp/csci330_ch17_XXXXXX/b/notes_copy.txt
```

**Hints**:
- Grouping by size first avoids hashing files that cannot possibly match.
- `std::ifstream` with `std::ios::binary` reads raw bytes; load the whole file
  into a `std::string` for small test files.
- `std::hash<std::string>` produces a `std::size_t`; format it with
  `std::hex` into an `std::ostringstream`.

---

## Problem 4: Backup Synchronizer (40 minutes)

**Objective**: Copy newer or changed files from a source tree into a backup tree.

Implement a one-way sync: walk the source directory, and for each file copy it
into the destination only when the destination copy is missing or older.

```cpp
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

struct SyncReport {
    std::size_t copied = 0;
    std::size_t skipped = 0;
};

// TODO: Synchronize `source` into `dest`.
//   For each regular file under `source`:
//     - Compute its path relative to `source` and the matching dest path.
//     - If the dest file does not exist, or the source file's
//       last_write_time() is newer, copy it (creating parent directories).
//     - Otherwise skip it.
//   Count copied and skipped files in the returned SyncReport.
SyncReport synchronize(const fs::path& source, const fs::path& dest) {
    /* your code here */
}
```

**Expected Output** (counts depend on the generated test data):
```
Backup synchronization complete.
  Copied:  4
  Skipped: 2
```

**Hints**:
- `fs::relative(entry.path(), source)` gives the path relative to the source root.
- `fs::create_directories(dest_path.parent_path())` ensures the target
  directory exists before `fs::copy_file`.
- Use `fs::copy_options::overwrite_existing` so an outdated backup is replaced.
- `fs::last_write_time()` returns a `fs::file_time_type` that compares directly
  with `<` and `>`.

---

## 📝 Submission Guidelines

1. **Code Quality**:
   - Use meaningful variable names.
   - Add comments for non-obvious filesystem logic.
   - Handle edge cases (empty directories, missing paths, permission errors).

2. **Testing**:
   - Each program must generate its own temporary test data and clean it up.
   - Verify behavior on empty directories and files with no extension.

3. **Error Handling**:
   - Catch `fs::filesystem_error` around every filesystem call that can fail.
   - Use `fs::directory_options::skip_permission_denied` when iterating.

---

## 💡 Hints and Tips

- **Always check first**: call `fs::exists()` before `file_size()` or iteration.
- **Recursive walks**: `fs::recursive_directory_iterator` visits the whole tree.
- **Path building**: use the `/` operator, never hard-coded separators.
- **Determinism**: run against a freshly created temp directory so output is
  predictable and your machine is never modified.

---

## Evaluation Criteria

**Total: 16 Points (4 points per outcome criteria)**

1. **Correctness** (4 points): Programs compile -- confirmed by a green CI build check -- and work as specified
2. **Code Quality** (4 points): Clean, readable, well-organized code
3. **Best Practices** (4 points): Following C++ idioms and conventions
4. **Documentation** (4 points): Appropriate comments and clear output
