#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        string s;
        cin >> s;

        int longest_segment = 0;
        int total_white_cells = 0;
        int current_segment = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') {
                current_segment++;
            } else {
                if (current_segment > 0) {
                    longest_segment = max(longest_segment, current_segment);
                    total_white_cells += current_segment;
                }
                current_segment = 0;
            }
        }

        if (current_segment > 0) {
            longest_segment = max(longest_segment, current_segment);
            total_white_cells += current_segment;
        }

        if (total_white_cells == 0) {
            cout << 0 << endl;
        } else {
            cout << total_white_cells + 1 << endl;
        }
    }

    return 0;
}
