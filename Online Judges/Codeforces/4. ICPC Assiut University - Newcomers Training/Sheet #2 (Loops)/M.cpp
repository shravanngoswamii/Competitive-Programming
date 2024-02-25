// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/M

#include <bits/stdc++.h>
using namespace std;

bool is_lucky(int num) {
    string numStr = to_string(num);
    for (char digit : numStr) {
        if (digit != '4' && digit != '7') {
            return false;
        }
    }
    return true;
}

void print_lucky_numbers(int A, int B) {
    bool found = false;
    for (int num = A; num <= B; ++num) {
        if (is_lucky(num)) {
            found = true;
            cout << num << " ";
        }
    }
    if (!found) {
        cout << "-1";
    }
    cout << endl;
}

int main() {
    int A, B;
    cin >> A >> B;
    print_lucky_numbers(A, B);
    return 0;
}
