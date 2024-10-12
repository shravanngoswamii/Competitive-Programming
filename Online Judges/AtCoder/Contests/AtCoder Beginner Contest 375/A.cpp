// Problem Statement

// There are
// N seats in a row, numbered

// 1,2,…,N.

// The state of the seats is given by a string
// S of length N consisting of # and .. If the i-th character of S is #, it means seat i is occupied; if it is ., seat

// i is unoccupied.

// Find the number of integers
// i between 1 and

// N−2, inclusive, that satisfy the following condition:

//     Seats 

// i and i+2 are occupied, and seat

//     i+1 is unoccupied.

// Constraints

// N is an integer satisfying
// 1≤N≤2×105.
// S is a string of length

//     N consisting of # and ..

// Input

// The input is given from Standard Input in the following format:

// N

// S

// Output

// Print the answer.
// Sample Input 1
// Copy

// 6
// #.##.#

// Sample Output 1
// Copy

// 2

// i=1 and 4 satisfy the condition, so the answer is

// 2.
// Sample Input 2
// Copy

// 1
// #

// Sample Output 2
// Copy

// 0

// Sample Input 3
// Copy

// 9
// ##.#.#.##

// Sample Output 3
// Copy

// 3


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == '#' && s[i + 1] == '.' && s[i + 2] == '#') ans++;
    }
    cout << ans << endl;
}

