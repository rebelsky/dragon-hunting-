/*
 * strategy.hpp
 *   A strategy for hunting dragons.
 * Samuel A. Rebelsky
 * 2026-03-21
 */

// +---------+-------------------------------------------------------
// | Prelude |
// +---------+

#pragma once

#include "World.hpp"

using namespace std;

// +------------+----------------------------------------------------
// | Procedures |
// +------------+

/**
 * Hunt for a dragon in a world.
 *
 * Inputs:
 *    w, a World (see World.cpp for details)
 *
 * Returns:
 *    true, if it found the dragon
 *    false, if it could not
 */
bool huntDragon(World& w);
