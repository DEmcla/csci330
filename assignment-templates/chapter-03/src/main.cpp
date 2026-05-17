// Chapter 03: References - Assignment Template
// Domain: Game Player State
// TODO: Complete the exercises as specified in this template's README.md

#include <iostream>
using namespace std;

// TODO: Add any other includes you need (cstring, ...)

// Game player state. References let you read and mutate a Player
// without making an expensive copy of the whole struct.
struct Player {
    char name[50];
    int level;
    double score;
};

// TODO: Problem 2.1 - display a Player through a const reference
// void display_player(const Player& player) { ... }

// TODO: Problem 2.1 - return true if score >= 3.5
// bool is_top_player(const Player& player) { ... }

// TODO: Problem 2.2 - modify a Player through a non-const reference
// void update_score(Player& player, double new_score) { ... }
// void level_up(Player& player) { ... }

int main() {
    cout << "Chapter 03: References" << endl;
    cout << "========================" << endl;

    // TODO: Implement assignment problems
    // Problem Set 1: basic references (alias an int health/score value)
    // Problem Set 2: const and non-const reference parameters on a Player
    // Problem Set 3: reference returns into a roster, object lifecycle
    // See this template's README.md for requirements

    Player alice = {"Alice the Brave", 20, 3.8};
    (void)alice;  // TODO: remove once you use the player

    return 0;
}
