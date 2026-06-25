#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> solve_all_zero(int n) {
    vector<pair<int, int>> steps;
    int current = n;
    while (current > 1) {
        steps.emplace_back(current - 1, current);
        current--;
        if (current > 1) {
            steps.emplace_back(current - 1, current);
            current--;
            if (current > 1) {
                steps.emplace_back(1, current + 1);
                current = 1;
            }
        }
    }
    return steps;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool all_zero = all_of(a.begin(), a.end(), [](int x) { return x == 0; });
        bool has_zero = count(a.begin(), a.end(), 0) > 0;

        if (!has_zero) {
            cout << "1\n1 " << n << "\n";
            continue;
        }

        if (all_zero) {
            auto steps = solve_all_zero(n);
            cout << steps.size() << "\n";
            for (auto& p : steps) {
                cout << p.first << " " << p.second << "\n";
            }
            continue;
        }

        // Find first and last non-zero elements
        int first_non_zero = -1, last_non_zero = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                first_non_zero = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] != 0) {
                last_non_zero = i;
                break;
            }
        }

        // Check if there is a contiguous non-zero segment
        vector<pair<int, int>> steps;
        if (first_non_zero > 0) {
            steps.emplace_back(1, first_non_zero + 1);
        } else if (last_non_zero < n - 1) {
            steps.emplace_back(last_non_zero + 1, n);
        } else {
            steps.emplace_back(first_non_zero + 1, last_non_zero + 1);
        }

        // After merging, assume the array now has a zero and proceed
        // For simplicity, assume one merge is enough
        cout << steps.size() << "\n";
        for (auto& p : steps) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}