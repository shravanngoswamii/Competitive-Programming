#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    string pi = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    while (t--) {
        string n;
        cin >> n;
        n += "#";

        for (size_t i = 0; i < n.length(); ++i) {
            if (pi[i] != n[i]) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
