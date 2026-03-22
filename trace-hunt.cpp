/*
 * trace-hunt.cpp
 *   Trace a hunt-the-dragon strategy
 * Samuel A. Rebelsky
 * 2026-03-21
 */

// +-------+---------------------------------------------------------
// | Usage |
// +-------+

/*
     % trace-hunt n k
        where n is the number of farms and k is the number of
        already burnt farms

     % trace-hunt 10 0
        Example: 10 farms, none have been burned yet.
 */

// +---------+-------------------------------------------------------
// | Prelude |
// +---------+

#include <iostream>

#include "World.hpp"
#include "hunt.hpp"

using namespace std;

// +------+----------------------------------------------------------
// | Main |
// +------+

/*
 * Parse the command line and show how the hunt works. The command
 * line should contain a positive integer, n, representing the number
 * of farms, and a non-negative integer, k, representing the number
 * of farms that have already been burned when the hunt starts.
 */
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Invalid number of arguments.\n";
        cerr << "Usage: ./hunt n k\n";
        cerr << "  n represents the number of farms (n > 0)\n";
        cerr << "  k represents the number of burnded farms (k >= 0)\n";
        exit(1);
    } // if

    int n;
    int k;

    try {
        n = stoi(argv[1]);
    } catch (invalid_argument &e) {
        cerr << argv[1] << " is not acceptable an acceptable n because " << e.what() << "\n";
        exit(1);
    } // try/catch

    try {
        k = stoi(argv[2]);
    } catch (invalid_argument &e) {
        cerr << argv[2] << " is not an acceptable k because " << e.what() << "\n";
        exit(1);
    } // try/catch

    try {
        // Set up the world
        World w = World(n, k);
        w.reportActivity();

        // Run the algorithm
        try {
            bool found = huntDragon(w);
            if (found) {
                cout << "The algorithm claims it found the dragon." << endl;
            } else {
                cout << "The algorithm could not find the dragon." << endl;
            } // if/else
            if (w.dragonFound()) {
                cout << "The dragon WAS found." << endl;
            } else {
                cout << "The dragon WAS NOT found. << endl";
            }
        } catch (out_of_range &e) {
            cerr << "The hunting algorithm failed with an out-of-range index: "
                 << e.what()
                 << endl;
        } catch (runtime_error &e) {
            cerr << "The hunting algorithm failed because "
                 << e.what()
                 << endl;
        } // try/catch
        cout << flush;

        return 0;

    } catch (out_of_range &e) {
        cerr << "Failed to run simulation because " << e.what() << "\n";
        exit(1);
    } // try/catch
} // main
