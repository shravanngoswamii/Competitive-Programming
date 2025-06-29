/*
Yet Another GCD Problem (Solve in C++)

Chef was trying to solve a famous problem, counting co-prime pairs, for his friend. The problem is straightforward:

Given an array A of size N, find the total number of pairs of indices (i,j) such that Ai and Aj are co-prime, i.e., gcd(Ai, Aj) = 1.

Being too busy with his delicious recipes, Chef didn't have enough time to solve the problem. So, instead of actually solving it, he guessed the answer and gave it to his friend. Since he already told the answer to his friend, he can't take his words back, but he can change the array to make it correspond to the answer he gave.

Chef needs your help to construct an array A of size N, containing only elements between 2 and 2×10^6, such that the number of co-prime pairs in it is exactly K.

Input Format

    The first line of input will contain a single integer T, denoting the number of test cases.
    Each test case consists of a single line containing two space-separated integers N and K — the size of the required array and the number of co-prime pairs in it.

Output Format

For each test case, output on a new line, N space-separated integers denoting the elements of array A you constructed.

If no such array exists, print the single integer −1.

Constraints

    1 ≤ T ≤ 10
    1 ≤ N ≤ 10^5
    2 ≤ Ai ≤ 2×10^6 for each 1 ≤ i ≤ N
    1 ≤ K ≤ 10^9
    Sum of N over all testcases is ≤ 10^5

Sample 1:
Input
4
5 10
4 13
2 1
6 7

Output
6 19 85 77 3887
-1
2 3
5 2 2 7 10 50 

Explanation:

    In first case each number is co-prime with others so total number of co-prime pairs are 10.
    In second case it's not possible to create an array with given N and K.
    In third case seven pairs of indices {(1,2),(1,3),(1,4),(2,4),(3,4),(4,5),(4,6)} contain co-prime pairs of elements.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool p(int x) {
    if(x <= 1) return false;
    for(int i = 2; i * i <= x && i <= 1000; ++i) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        ll n, K;
        cin >> n >> K;
        ll mp = n * (n - 1) / 2;
        if(K > mp || K < 0) {
            cout << -1 << endl;
            continue;
        }
        vector<int> A(n, 4);
        if(K == 0) {
            for(int i = 0; i < n; ++i) {
                cout << 4 << " ";
            }
            cout << endl;
            continue;
        }
        if(K == mp) {
            vector<int> p;
            int m = 2;
            while(p.size() < n) {
                bool f = true;
                for(int i = 2; i * i <= m; ++i) {
                    if(m % i == 0) {
                        f = false;
                        break;
                    }
                }
                if(f) {
                    p.push_back(m);
                }
                ++m;
            }
            for(int i = 0; i < n; ++i) {
                cout << p[i] << " ";
            }
            cout << endl;
            continue;
        }
        ll cp = 0;
        int idx = n - 1;
        while(cp < K && idx >= 0) {
            A[idx] = 3;
            cp += n - idx - 1;
            idx--;
        }
        if(cp < K) {
            cout << -1 << endl;
            continue;
        }
        ll ep = cp - K;
        if(ep > 0) {
            for(int i = idx + 1; i <= idx + ep; ++i) {
                A[i] = 9;
            }
        }
        for(int i = 0; i < n; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
