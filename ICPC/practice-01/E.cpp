#include <iostream>
#include <vector>
using namespace std;

int maxFinalSum(vector<int>& a, int k) {
    int sum = 0;
    int countAboveK = 0;

    // Calculate the initial sum and count of elements greater than k
    for (int x : a) {
        sum += x;
        if (x > k) {
            countAboveK++;
        }
    }

    // Maximum possible reductions from the connected component
    int maxReductions = countAboveK / 2;
    
    // Calculate the final sum after all possible reductions
    int finalSum = sum - 2 * maxReductions;
    return finalSum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << maxFinalSum(a, k) << endl;
    }
    return 0;
}
