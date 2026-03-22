/*
 * hunt00.cpp
 *   A simple (incorrect and inefficient) mechanism for hunting dragons.
 *   Looks backwards from the last space to the first.
 *   Uses zero-based indexing.
 * Samuel A. Rebelsky
 * 2026-03-21
 */

// +---------+-------------------------------------------------------
// | Prelude |
// +---------+

#include <stdexcept>

#include "hunt.hpp"
#include "World.hpp"

using namespace std;

// +---------+-------------------------------------------------------
// | Methods |
// +---------+

bool huntDragon(World& w) {
    for (int i = w.size() - 1; i >= 0; i--) {
        w.note("Looking at farm " + to_string(i));
        if (w.get(i) == DRAGON) {
            return true;
        } // if
    } // for
    return false;                       // This shouldn't happen
} // huntDragon(World)
