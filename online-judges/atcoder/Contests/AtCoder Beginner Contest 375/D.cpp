// D - ABA /

// Time Limit: 2 sec / Memory Limit: 1024 MB

// It is prohibited to directly input all or part of the information issued as problems in ongoing AtCoder contests into software. Please refer to this post for details.

// Score :

// 400 points
// Problem Statement

// You are given a string

// S consisting of uppercase English letters.

// Find the number of integer triples

// (i,j,k) satisfying both of the following conditions:

// 1≤i<j<k≤∣S∣
// The length-
// 3 string formed by concatenating Si​, Sj​, and

//     Sk​ in this order is a palindrome.

// Here,
// ∣S∣ denotes the length of S, and Sx​ denotes the x-th character of

// S.
// Constraints

// S is a string of length between 1 and

//     2×105, inclusive, consisting of uppercase English letters.

// Input

// The input is given from Standard Input in the following format:

// S

// Output

// Print the answer.
// Sample Input 1
// Copy

// ABCACC

// Sample Output 1
// Copy

// 5

// The triples satisfying the conditions are

// (i,j,k)=(1,2,4),(1,3,4),(3,4,5),(3,4,6),(3,5,6).
// Sample Input 2
// Copy

// OOOOOOOO

// Sample Output 2
// Copy

// 56

// Sample Input 3
// Copy

// XYYXYYXYXXX

// Sample Output 3
// Copy

// 75

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> count(26, vector<int>(n + 1, 0));
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            count[c][i + 1] = count[c][i] + (s[i] - 'A' == c);
        }
    }

    for (int j = 1; j < n - 1; j++) {
        for (int c = 0; c < 26; c++) {
            int left = count[c][j];
            int right = count[c][n] - count[c][j + 1];
            ans += (long long)left * right;
        }
    }

    cout << ans << endl;
    return 0;
}