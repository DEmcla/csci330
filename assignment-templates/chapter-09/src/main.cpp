// Chapter 09: Functions - Assignment Template
// TODO: Complete the exercises as specified in this template's README.md
//
// Theme: a text-driven command / filter pipeline.
// This file provides TODO stubs for the problem sets. It compiles as-is under
// C++17; replace the stub bodies with your implementations.

#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

// ---------------------------------------------------------------------------
// Problem 1.1: Command Dispatcher with Function Pointers
// ---------------------------------------------------------------------------
// TODO: Implement each command handler, then build an array of function
// pointers and dispatch by command name.
string cmd_head(const string& line, int arg) {
    // TODO: keep the first arg characters
    (void)arg;
    return line;
}

string cmd_reverse(const string& line, int arg) {
    // TODO: reverse the line (arg ignored)
    (void)arg;
    return line;
}

string cmd_count(const string& line, int arg) {
    // TODO: return the line length as text
    (void)arg;
    return line;
}

string cmd_upper(const string& line, int arg) {
    // TODO: upper-case the line (arg ignored)
    (void)arg;
    return line;
}

// ---------------------------------------------------------------------------
// Problem 1.3: Sorting with Custom Comparators
// ---------------------------------------------------------------------------
// TODO: Return true if a should come before b.
bool ascending(int a, int b) {
    // TODO: implement
    (void)a;
    (void)b;
    return false;
}

bool descending(int a, int b) {
    // TODO: implement
    (void)a;
    (void)b;
    return false;
}

int main() {
    cout << "Chapter 09: Functions" << endl;
    cout << "========================" << endl;

    // TODO: Implement assignment problems
    // See this template's README.md for requirements
    //
    // Problem Set 1: command dispatcher, event system, comparator sort
    // Problem Set 2: STL algorithms with lambdas, capture modes, generic lambdas
    // Problem Set 3: function objects, and the std::function pipeline project

    return 0;
}
