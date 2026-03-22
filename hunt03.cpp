/*
 * hunt03.cpp
 *   A simple (incorrect and inefficient) mechanism for hunting dragons.
 *   Advances by 2, hoping to catch the dragon that way.
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
    int i = 0;
    while (true) {
        switch (w.get(i)) {
           case DRAGON:
               return true;
           case OK:
               i = i - 1;
               break;
           case BURNED:
               i = i + 2;
               break;
           default:
               break;
        } // switch
    } // while
    return false;       // Never reached
} // huntDragon(World)
