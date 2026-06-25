/*
Unsatisfying Array

You are given integers N and K, along with K triplets, where the i-th triplet is (Li, Ri, mi).

Find any array A of length N that satisfies the following conditions:

    1 ≤ Ai ≤ N for every i from 1 to N.
    For every j from 1 to K, the minimum of the contiguous subarray of A from index Lj to index Rj is not mj. That is, the condition min(ALj, ALj+1, …, ARj) ≠ mj should hold.

If there are multiple valid arrays that satisfy the above two conditions, you may find any of them.
Print -1 if no valid array exists.

Input Format:
    The first line of input will contain a single integer T, denoting the number of test cases.
    Each test case consists of multiple lines of input.
        The first line of each test case contains two space-separated integers N and K — the length of the array and the number of constraints.
        The next K lines describe the triples. The i-th of these K lines contains three space-separated integers Li, Ri, and mi.

Output Format:
    For each test case:
        If no valid array exists, print a single line containing the integer -1.
        Otherwise, print N space-separated integers A1, A2, …, AN — the elements of the array you're constructing.
        Each Ai must lie between 1 and N.

Constraints:
    1 ≤ T ≤ 1000
    1 ≤ N ≤ 2000
    1 ≤ K ≤ 2000
    1 ≤ Li ≤ Ri ≤ N
    1 ≤ mi ≤ N
    The sum of N and the sum of K over all test cases both won't exceed 2000.

Input
2
3 2
1 2 2
2 3 1
2 2
1 2 1
1 2 2

Output
1 2 3
-1

Explanation:
Test case 1: The constraints are that the minimum of [A1,A2] should not be 2, and the minimum of [A2,A3] should not be 1.

For the array A=[1,2,3], the minimum of [A1,A2] is 1, and the minimum of [A2,A3] is 2, so the conditions are satisfied.

More Info
Time limit: 1 secs
Memory limit: 1.5 GB
Source Limit: 50000 Bytes
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        
        // Initialize the array with values from 1 to N
        for (int i = 0; i < N; i++) {
            A[i] = i + 1;
        }

        // Process each constraint
        vector<pair<int, int>> constraints(K);
        vector<int> m(K);
        
        for (int i = 0; i < K; i++) {
            int L, R, mi;
            cin >> L >> R >> mi;
            constraints[i] = {L - 1, R - 1}; // Store 0-based indices
            m[i] = mi;
        }

        // Adjust the array based on constraints
        for (int i = 0; i < K; i++) {
            int L = constraints[i].first;
            int R = constraints[i].second;
            int mi = m[i];

            // Check if the minimum in the range [L, R] is mi
            while (true) {
                int current_min = *min_element(A.begin() + L, A.begin() + R + 1);
                if (current_min != mi) {
                    break; // No need to adjust if the condition is satisfied
                }

                // Adjust the first occurrence of mi in the range
                for (int j = L; j <= R; j++) {
                    if (A[j] == mi) {
                        // Change A[j] to a different valid number
                        A[j] = (mi == N) ? (mi - 1) : (mi + 1);
                        break; // Only adjust one element at a time
                    }
                }
            }
        }

        // Final validation to ensure all constraints are satisfied
        bool valid = true;
        for (int i = 0; i < K; i++) {
            int L = constraints[i].first;
            int R = constraints[i].second;
            int mi = m[i];
            int current_min = *min_element(A.begin() + L, A.begin() + R + 1);
            if (current_min == mi) {
                valid = false;
                break;
            }
        }

        // Output the result
        if (valid) {
            for (int i = 0; i < N; i++) {
                cout << A[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}