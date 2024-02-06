#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> find_different_pair(int n, vector<int>& arr, vector<pair<int, int>>& queries) {
    unordered_map<int, int> last_occurrence;
    for (int i = 0; i < n; ++i) {
        last_occurrence[arr[i]] = i;
    }

    vector<pair<int, int>> results;
    for (auto& query : queries) {
        bool found = false;
        int l = query.first - 1;
        int r = query.second - 1;
        for (int i = l; i <= r; ++i) {
            if (last_occurrence[arr[i]] != i) {
                results.push_back({i + 1, last_occurrence[arr[i]] + 1});
                found = true;
                break;
            }
        }
        if (!found) {
            results.push_back({-1, -1});
        }
    }
    return results;
}

int main() {
    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; ++test_case) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int q;
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i].first >> queries[i].second;
        }

        // Output
        vector<pair<int, int>> results = find_different_pair(n, arr, queries);
        for (auto& result : results) {
            cout << result.first << " " << result.second << endl;
        }
        cout << endl; // Empty line between test cases
    }

    return 0;
}
