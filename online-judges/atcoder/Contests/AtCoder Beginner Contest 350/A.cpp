#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string prefix = S.substr(0, 3);
    string suffix = S.substr(3, 3);

    if (prefix == "ABC" && suffix >= "001" && suffix <= "349" && suffix != "316") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
