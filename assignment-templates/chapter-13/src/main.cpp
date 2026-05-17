// Chapter 13: Containers - Assignment Template
// Domain: transit-network graph (stations and lines)
// TODO: Complete the exercises as specified in this template's README.md

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ============================================================================
// Problem Set 1: Sequence Containers
// ============================================================================

// Problem 1.2: Dynamic Array Operations -- std::vector
// A transit line is an ordered sequence of station names.
class TransitLine {
private:
    std::vector<std::string> stations;

public:
    void addStation(const std::string& name) {
        // TODO: append a station to the end of the line
        (void)name;
    }

    void insertStation(const std::string& name, size_t position) {
        // TODO: insert a station at the given position (a new mid-line stop)
        (void)name; (void)position;
    }

    void removeStation(const std::string& name) {
        // TODO: find the station by name and erase it
        (void)name;
    }

    void displayStations() const {
        // TODO: print every station with its position index
    }
};

// ============================================================================
// Problem Set 2: Associative Containers
// ============================================================================

// Problem 2.2: Set Operations -- std::set
// Each line serves a set of station IDs.
std::set<int> setUnion(const std::set<int>& line1, const std::set<int>& line2) {
    // TODO: return all station IDs on either line
    (void)line1; (void)line2;
    return {};
}

std::set<int> setIntersection(const std::set<int>& line1, const std::set<int>& line2) {
    // TODO: return transfer stations -- IDs on both lines
    (void)line1; (void)line2;
    return {};
}

std::set<int> setDifference(const std::set<int>& line1, const std::set<int>& line2) {
    // TODO: return station IDs only on line1
    (void)line1; (void)line2;
    return {};
}

// ============================================================================
// Problem Set 3: Unordered Containers and Integration Project
// ============================================================================

// Problem 3.2: Custom Hash Function -- std::unordered_set
struct Station {
    std::string name;
    int id;
    std::string zone;

    bool operator==(const Station& other) const {
        // TODO: two stations are equal when name, id, and zone all match
        (void)other;
        return false;
    }
};

struct StationHash {
    std::size_t operator()(const Station& s) const {
        // TODO: combine the hashes of name, id, and zone
        (void)s;
        return 0;
    }
};

int main() {
    cout << "Chapter 13: Containers (Transit Network)" << endl;
    cout << "========================================" << endl;

    // TODO: Implement assignment problems
    // See this template's README.md for requirements

    return 0;
}
