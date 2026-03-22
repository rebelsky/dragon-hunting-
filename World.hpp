/*
 * World.hpp
 *   A simple world of dragons, intended as a way to help assess
 *   solutions.
 * Samuel A. Rebelsky
 * 2026-03-21
 */

// +---------+-------------------------------------------------------
// | Prelude |
// +---------+

#pragma once

#include <string>
#include <vector>

using namespace std;

// +-------+---------------------------------------------------------
// | Types |
// +-------+

/**
 * States of the farm.
 */
enum FarmState{INVALID, OK, DRAGON, BURNED};

/*
 * World class for the simulation.
 */
class World {

    public:
        /**
         * Create a new world with n farms, k of which have been burned.
         */
        World(int n, int k);

        /**
         * Ensure that we use one-based indexing rather than zero-based
         * indexing (intended to support those more mathematically 
         * inclinded).
         */
        void useOneBasedIndexing();

        /**
         * Indicate that the World should report its state each
         * time get is called.
         */
        void reportActivity();

        /**
         * Advance the dragon and check the state of farm i. 
         *
         * Inputs
         *   i, the farm number. 
         *     with zero-based indexing, 0 <= i < n
         *     with one-based indexing, 1 <= i <= n
         *
         * Returns
         *   The state of the farm
         *
         * Exception
         *   If all the farms are burned or the index is invalid.
         */
        FarmState get(int i);

        /**
         * Get the size of the world (the number of farms).
         *
         * Returns
         *   The number of farms.
         */
        int size();

        /**
         * Get the number of times `get` has been called.
         */
        int steps();

        /**
         * Determine if the dragon has been found.
         */
        bool dragonFound();

        /**
         * Print the state of the world.
         */
        void printState();

        /**
         * Print a note (only if reportActivity has been called).
         */
        void note(string msg);

    private:
      /* The index offset (to support one-based indexing */
      int offset = 0;

      /* Are we doing verbose reporting? */
      bool verbose = false;

      /* The position of the dragon. */
      int d = -1;

      /* The farms. */
      vector<FarmState> farms;

      /* The number of times `get` has been called. */
      int count = 0;

      /* Have we found the dragon? */
      bool found = false;
};

