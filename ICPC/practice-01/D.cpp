// Pen Pineapple Apple Pen

// Problem Statement (Solve in C++)

// There are K magical pens (numbered 1 through K). You are given strings P1, P2, . . . , PK (each of which
// consists of characters from ’a’, ’b’, ..., ’t’); for each valid i, the i-th pen can only write letters from the
// string Pi.
// You want to write a word S of length N . All the characters of S are between ’a’ and ’t’ inclusive.
// This string must be written from left to right. To write it, you pick up some pen and start writing; after
// you’ve written some prefix of S, you can put down that pen, pick up another pen, continue writing S
// from the point where you put down the previous pen, later pick up another pen (any pen) and continue
// writing S with that pen, and so on until you write the whole string S. You may pick up each pen any
// number of times, including zero.
// You have to find a way of writing the word S such that the number of times you change the pen (put
// down the pen you’re currently writing with and pick up another) is the smallest possible. If there are
// multiple solutions, you may find any one. It is guaranteed that it is possible to write S with the given
// pens.

// Input

// - The first line of the input contains a single integer T denoting the number of test cases. The
// description of T test cases follows.
// - The first line of each test case contains two space-separated integers N and K.
// - The second line contains a single string S.
// - For each valid i, the i-th of the next K lines contains a single string Pi.

// Output

// For each test case, print a single line containing N space-separated integers. For each valid i, the i-th of
// these integers should be the number of the pen with which you want to write the i-th character of S.
// Your output will be considered correct if each character can be written with the pen you want to
// write it with and the number of times you have to change the pen you are writing with is minimized.

// Constraints

// - 1 ≤ T ≤ 10
// - 1 ≤ N ≤ 10^6
// - 1 ≤ K ≤ 10^5
// - S, P1, P2, . . . , PK contain only characters ’a’, ’b’, ..., ’t’
// - 1 ≤ |Pi| ≤ 20 for each valid i
// - For each valid i, all characters of Pi are pairwise distinct
// - The sum of lengths of all the strings in the input does not exceed 2 · 10^6

// Example

// Input
// 3
// 4 2
// abcd
// ab
// cd
// 4 2
// baab
// ab
// ca
// 4 2
// acaa
// ab
// cd

// Output
// 1 1 2 2
// 1 1 1 1
// 1 2 1 1

// Explanation
// Example case 1: You can write the first two characters with the first pen and the next two characters
// with the second pen. This means you have to change the pen once (from pen 1 to pen 2).
// Example case 2: You can write the whole string S with the first pen, so you never have to change
// the pen you are writing with.
// Example case 3: You can write the first character with the first pen, the second character with the
// second pen, and then the last two characters again with the first pen. Thus, you have to change the pen
// twice (from pen 1 to pen 2 and then from pen 2 to pen 1).

#include <bits/stdc++.h>
using namespace std;

bool f(char c, string& p) {
    return p.find(c) != string::npos;
}

void s() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    unordered_map<char, vector<int>> char_to_pens;
    vector<string> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        for (char c : p[i]) {
            char_to_pens[c].push_back(i);
        }
    }

    vector<vector<int>> d(n + 1, vector<int>(k, INT_MAX));
    vector<vector<int>> v(n + 1, vector<int>(k, -1));

    for (int j : char_to_pens[s[0]]) {
        d[1][j] = 0;
    }

    for (int i = 2; i <= n; i++) {
        for (int j : char_to_pens[s[i-1]]) {
            for (int l : char_to_pens[s[i-2]]) {
                if (d[i-1][l] == INT_MAX) continue;

                int c = d[i-1][l] + (l != j);
                if (c < d[i][j]) {
                    d[i][j] = c;
                    v[i][j] = l;
                }
            }
        }
    }

    int m = INT_MAX, l = -1;
    for (int j : char_to_pens[s[n-1]]) {
        if (d[n][j] < m) {
            m = d[n][j];
            l = j;
        }
    }

    if (l == -1) {
        cout << "Error: No valid solution.\n";
        return;
    }

    vector<int> r(n);
    int p_curr = n, pen = l;

    while (p_curr > 0) {
        r[p_curr-1] = pen + 1;
        pen = v[p_curr][pen];
        p_curr--;
    }

    for (int i = 0; i < n; i++) {
        cout << r[i] << (i == n-1 ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        s();
    }
    return 0;
}
