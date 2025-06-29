/*Maximize Diversity of an Array

Problem Statement (Solve in C++)

You are given an array A. The diversity of the array A is defined as the number of pairs
i, j (i < j) such that Ai not equal to Aj .
You want to maximize the diversity of the array. For that, you are allowed to make
at most K operations on it. In each operation, you can select a particular element and
change its value to any integer in the range 1 to 10^9, both inclusive.
Find out the maximum diversity of the array that you can obtain.

Input Format

- The first line contains T , the number of test cases.

- Each test case consists of
	– The first line contains two integers N, K, where N is the length of the array A, and K is the maximum number of operations allowed.
	– The second line contains N space-separated integers representing the elements of the array A.

Output Format

For each test case, output a single line containing an integer corresponding to the maximum possible diversity of the array.


Constraints

1 ≤ T ≤ 20
0 ≤ K ≤ 10^9
2 ≤ N ≤ 10^5
1 ≤ Ai ≤ 10^9

Example Input

3
3 10
1 2 3
4 2
1 1 2 2
6 2
2 3 3 2 4 4

Example Output

3
6
14

Explanation

Testcase 1: The array is already diverse, and no operations are required. Hence, the answer is 3.
Testcase 2: By performing 2 operations, you can make all the elements distinct (e.g., change 1 to 3 and 2 to 4). Hence, the maximum diversity is 6.
Testcase 3: With 2 operations, you can maximize the distinctness of the array to achieve a diversity of 14.*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

typedef long long l;
using namespace std;

struct F {
    l f;
    l v;
};

bool operator<(const F& a, const F& b) {
    return (a.f - 1) < (b.f - 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        l n, k;
        cin >> n >> k;
        vector<l> a(n);
        unordered_map<l, l> m;
        for (l i = 0; i < n; ++i) {
            cin >> a[i];
            m[a[i]]++;
        }

        l tp = n * (n - 1) / 2;
        l s = 0;
        priority_queue<F> pq;

        for (auto it : m) {
            l f = it.second;
            s += f * (f - 1) / 2;
            if (f > 1) {
                pq.push({f, it.first});
            }
        }

        l r = k;
        while (r > 0 && !pq.empty()) {
            F c = pq.top();
            pq.pop();
            l fi = c.f;
            l red = min(r, 1LL);
            r -= red;
            fi -= red;

            l oldp = c.f * (c.f - 1) / 2;
            l newp = fi * (fi - 1) / 2;
            s -= (oldp - newp);

            if (fi > 1) {
                pq.push({fi, c.v});
            }
        }

        l d = tp - s;
        cout << d << "\n";
    }
    return 0;
}
