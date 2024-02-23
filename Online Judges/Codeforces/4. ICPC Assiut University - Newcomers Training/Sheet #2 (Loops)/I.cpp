// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/I

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& str) {
    return equal(str.begin(), str.begin() + str.size()/2, str.rbegin());
}

int main() {
    int N;
    cin >> N;

    string reversed;
    while (N % 10 == 0)
        N /= 10;
    while (N > 0) {
        reversed += (N % 10) + '0';
        N /= 10;
    }
    cout << reversed << endl;

    string original = reversed;
    reverse(original.begin(), original.end());
    if (isPalindrome(original))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
