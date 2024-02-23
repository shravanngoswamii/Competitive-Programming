// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/I

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    string reversed = to_string(N);
    while (!reversed.empty() && reversed.back() == '0')
        reversed.pop_back();
    reverse(reversed.begin(), reversed.end());

    cout << reversed << endl;

    if (isPalindrome(to_string(N)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
