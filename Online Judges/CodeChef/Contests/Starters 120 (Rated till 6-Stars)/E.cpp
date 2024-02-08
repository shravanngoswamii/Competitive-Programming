#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> permutation(N);
        for (int i = 0; i < N; ++i)
            cin >> permutation[i];

        unordered_map<int, int> prefixSumCount;
        int sum = 0;
        long long total = 0; // Using long long to handle large sums

        // Count subarrays with sum i for each i from 1 to N
        for (int i = 0; i < N; ++i) {
            sum += permutation[i];
            if (sum == 0) total++; // Adding 1 to account for the subarray consisting of single element
            total += prefixSumCount[sum];
            prefixSumCount[sum]++;
        }

        // Output the counts
        for (int i = 1; i <= N; ++i) {
            cout << total << " ";
            total -= prefixSumCount[i]; // Subtract the count of subarrays with sum i to get the count for sum i+1
        }
        cout << endl;
    }

    return 0;
}
