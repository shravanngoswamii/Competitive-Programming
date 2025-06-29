// A Game of Robots

// Problem Statement (Solve in C++)

// You’ve built some robots and placed them on a one-dimensional grid with n cells. Their arrangement is
// given by a string s of length n. Each character of the string is either ‘.‘ or a digit in the range ‘0‘ to ‘9‘.
// A ‘.‘ represents that there is no robot at that cell initially. A digit represents a robot initially in that
// cell. Specifically, the digit x denotes that the range of the robot is from x cells to the left of its starting
// point to x cells to the right of its starting point.
// For example, suppose the 7th character of the string is ‘3‘, then that means there is a robot starting
// from the 7th cell, and its range is from the 4th cell (7 − 3 = 4) to the 10th cell (7 + 3 = 10) (both end
// points inclusive). The robots can only move within their range, and even if their range allows it, they
// cannot move out of the grid.

// You want to play a game with these robots. Before starting the game, you can give each robot a
// starting direction (either left or right). When the robot is initialized with a direction, it will move in
// that direction until it can’t (i.e., it can’t go past its range, and neither can it go outside the grid) and
// will reverse its direction and go as far as possible in that direction, then reverse again. It will continue
// moving like this forever, changing direction instantaneously.
// However, each robot can start their journey at any time. They don’t all have to start at the same
// second. A robot, once started, moves at a speed of one cell per second.
// The robots have gained consciousness and have begun questioning their purpose in life. Given a
// chance, they will collide with each other to end their misery. They can coordinate and decide when
// to start their journeys. Two robots are said to have collided if they are at the same cell at the same
// moment.
// You are wondering whether it is possible to give the robots the initial directions in such a way that
// no robots collide with each other (i.e., they will all be safe), or if some of them will inevitably collide
// regardless of the initial directions (i.e., unsafe).

// Input

// - The first line of the input contains an integer T denoting the number of test cases.
// - The only line of each test case contains a string s.

// Output

// For each test case, output a single line containing ”safe” if no robots will collide, or ”unsafe” if a collision
// is inevitable (without quotes).

// Constraints

// 1 ≤ T ≤ 3 × 10^4
// 1 ≤ length of s ≤ 50
// s[i] will be one of the following characters: {‘.‘, ‘0‘, ‘1‘, ‘2‘, ‘3‘, ‘4‘, ‘5‘, ‘6‘, ‘7‘, ‘8‘, ‘9‘}

// Examples

// Input:
// 4
// ....
// .2.....
// .2...2..
// 1.1.1.

// Output:
// safe
// safe
// unsafe
// unsafe

// Explanation
// Example 1: No robots are present, so everything is safe.
// Example 2: Only one robot is present, so everything is safe. Suppose you give it the starting
// direction as left and it decides to start moving at time = 5 seconds. Until t = 5, it remains at cell 2 (its
// starting position, 1-based indexing). At t = 6, it moves to cell 1. At t = 7, it returns to cell 2, then
// moves to cell 3 at t = 8, and so on, oscillating within its range.
// Example 3: No matter the initial directions, the two robots will eventually collide at cell 4.


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        
        vector<pair<int, int>> r;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != '.') {
                int x = s[i] - '0';
                r.push_back({i - x, i + x});
            }
        }
        
        if (r.empty()) {
            cout << "safe\n";
            continue;
        }

        sort(r.begin(), r.end());

        bool f = true;
        for (int i = 1; i < r.size(); ++i) {
            if (r[i].first <= r[i-1].second) {
                f = false;
                break;
            }
        }

        if (f) {
            cout << "safe\n";
        } else {
            cout << "unsafe\n";
        }
    }

    return 0;
}
