#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int x;
        cin >> x;
        int current_gift = 1;
        bool can_plan = true;
        for (int j = 1; j <= 7; j++) {
            if (current_gift > x) {
                can_plan = false;
                break;
            }
            x -= current_gift;
            current_gift *= 2; 
        }
        if (can_plan && x >= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
