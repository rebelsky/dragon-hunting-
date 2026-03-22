/*
 * World.cpp
 *   A simple world of dragons, intended as a way to help assess
 *   solutions.
 * Samuel A. Rebelsky
 * 2026-03-21
 */

// +---------+-------------------------------------------------------
// | Prelude |
// +---------+

#include <vector>
#include <iostream>
#include <stdexcept>

#include "World.hpp"

using namespace std;

// +--------------+--------------------------------------------------
// | Constructors |
// +--------------+

World::World(int n, int k) {
    // Sanity checks
    if (k < 0) {
        throw out_of_range("k < 0; The dragon must have burned zero or more farms");
    } // if
    if (n < 1) {
        throw out_of_range("n < 0; you must have at least one farm");
    } // if
    if (k >= n) {
        throw out_of_range("k > n; it's not possible to burn more farms than there are");
    } // if

    // Remember the position of the dragon
    d = k - 1;

    // Set up the farms
    farms.resize(n);
    for (int i = 0; i < k; i++) {
        farms[i] = BURNED;
    } // for
    farms[k] = DRAGON;
    for (int i = k+1; i < n; i++) {
        farms[i] = OK;
    } // for
} // World::World   

// +---------+-------------------------------------------------------
// | Methods |
// +---------+

void World::useOneBasedIndexing() {
    offset = 1;
} // useOneBasedIndexing()

void World::reportActivity() {
    verbose = true;
} // reportActivity

FarmState World::get(int i) {
    // Switch to zero-based offset
    int j = i - offset;

    // Sanity checks
    if (j < 0) {
        throw out_of_range("get: index " + to_string(i) + " is too small");
    } // if
    if (j >= farms.size()) {
        throw out_of_range("get: index " + to_string(i) + " is too large");
    } // if

    // Move the dragon, burning the farm as appropriate
    if ((d >= 0) && (d < farms.size())) {
        farms[d] = BURNED;
    } // if
    d = d + 1;
    if (d < farms.size()) {
        farms[d] = DRAGON;
    } // if

    // Did the dragon win?
    if (d >= farms.size()) {
        throw runtime_error("everything has been burned");
    } // if

    // If we're being verbose
    if (verbose) {
        // Show the state of the world
        printState();
        // Show the knight and indices
        for (int k = 0; k < farms.size(); k++) {
           if (j == k) {
             cout << "^";
           } else {
             cout << to_string((k + offset) % 10);
           }
        } // for
        // And the line, add a blank line, and force output
        cout << endl << endl << flush;
    } // verbose

    // Keep track of number of steps.
    ++count;

    // Determine if we've found the dragon
    if (farms[j] == DRAGON) {
        found = true;
    } // if

    // Return the appropriate value
    return farms[j];
} // get(int)

int World::size() {
    return farms.size();
} // size()

int World::steps() {
    return count;
} // steps()

bool World::dragonFound() {
    return found;
} // dragonFound()

void World::printState() {
    for (int i = 0; i < farms.size(); i++) {
        FarmState state = farms[i];
        switch (state) {
            case INVALID:
                cout << "?";
                break;
            case OK:
                cout << "O";
                break;
            case DRAGON:
                cout << "!";
                break;
            case BURNED:
                cout << ".";
                break;
            default:
                cout << "X";
                break;
        } // switch
    } // for
    cout << endl;
} // printState()

void World::note(string msg) {
  if (verbose) {
      cout << msg << endl << flush;
  } // if
} // not(string)
