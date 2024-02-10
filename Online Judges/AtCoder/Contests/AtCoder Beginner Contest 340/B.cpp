#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    vector<int> A;
    vector<int> queries;

    for (int i = 0; i < Q; ++i) {
        int type, x;
        cin >> type >> x;
        
        if (type == 1) {
            A.push_back(x);
        } else if (type == 2) {
            int k = x;
            cout << A[A.size() - k] << endl;
        }
    }

    return 0;
}
