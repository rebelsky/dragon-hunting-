/*
 * hunt02.cpp
 *   A simple (incorrect and inefficient) mechanism for hunting dragons.
 *   Always looks at the middle space.
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
    int i = w.size() / 2;
    while (true) {
        if (w.get(i) == DRAGON) {
            return true;
        } // if
    } // while
    return false;       // Never reached
} // huntDragon(World)
