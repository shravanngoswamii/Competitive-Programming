// Problem description (Solve in C++)
// This program tests the special floating point compare script accompanying DOMjudge.
// The problem input consists of first a line with a single integer, then that many lines,
// with on each line a floating point number (possibly also ± inf or nan). For each floating
// point number, a line should be written containing the reciprocal of the number, within
// 10^-6 precision.

// Sample input/output
// Sample input and output for this problem:

// Input:

// 8
// +0
// 1.0
// 2E0
// 3
// 4.0000000000000
// 5.0000000000001
// Inf
// nan



// Output:

// inf
// 1.0
// 0.50000000001
// 3.333333333E-1
// 0.25
// 2E-1
// 0
// NaN

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << setprecision(10);

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        string lowercase = input;
        for (char& c : lowercase) {
            c = tolower(c);
        }

        if (lowercase == "inf" || lowercase == "+inf") {
            cout << "0" << endl;
            continue;
        }
        if (lowercase == "-inf") {
            cout << "-0" << endl;
            continue;
        }
        if (lowercase == "nan") {
            cout << "NaN" << endl;
            continue;
        }

        double num = stod(input);
        
        if (num == 0) {
            cout << "inf" << endl;
        } else {
            double reciprocal = 1.0 / num;
            if (abs(reciprocal - round(reciprocal)) < 1e-10) {
                cout << fixed << round(reciprocal) << endl;
            } else {
                if (abs(reciprocal) < 0.0001 || abs(reciprocal) > 10000) {
                    cout << scientific << reciprocal << endl;
                } else {
                    cout << fixed << reciprocal << endl;
                }
            }
        }
    }

    return 0;
}
