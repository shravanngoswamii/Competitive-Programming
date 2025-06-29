/*
### Problem Statement

There is a rooted tree with \(N + 1\) vertices numbered from \(0\) to \(N\). Vertex \(0\) is the root, and the parent of vertex \(i\) is vertex \(p_i\).

One of the vertices among vertex \(1\), vertex \(2\), ..., vertex \(N\) hides a treasure. The probability that the treasure is at vertex \(i\) is

\[
\frac{a_i}{\sum_{j=1}^{N} a_j}.
\]

Also, each vertex is in one of the two states: "searched" and "unsearched". Initially, vertex \(0\) is searched, and all other vertices are unsearched.

Until the vertex containing the treasure becomes searched, you perform the following operation:

- Choose an unsearched vertex whose parent is searched, and mark it as searched.

Find the expected number of operations required when you act to minimize the expected number of operations, modulo \(998244353\).

You are given \(T\) test cases; solve each of them.

---

#### How to find an expected value modulo \(998244353\)

It can be proved that the expected value is always a rational number. Under the constraints of this problem, it can also be proved that when the expected value is expressed as an irreducible fraction \(\frac{P}{Q}\), we have \(Q \not\equiv 0 \pmod{998244353}\). In this case, there is a unique integer \(R\) satisfying 

\[
R \times Q \equiv P \pmod{998244353}, \quad 0 \leq R < 998244353.
\]

Report this \(R\).


### Constraints
- \(1 \leq T \leq 2 \times 10^5\)
- \(1 \leq N \leq 2 \times 10^5\)
- \(0 \leq p_i < i\)
- \(1 \leq a_i\)
- \(\sum_{i=1}^{N} a_i \leq 10^8\)
- The sum of \(N\) over all test cases is at most \(2 \times 10^5\).
- All input values are integers.


Input

The input is given from Standard Input in the following format. Here, casei​ denotes the i-th test case.

T
case1
case2
⋮
caseT

Each test case is given in the following format:
N
p1 p2 … pN
a1 a2 … aN

Output
Print T lines. The i-th line should contain the answer for the i-th test case.

Sample Input 1
3
3
0 0 1
1 2 3
5
0 1 0 0 0
8 6 5 1 7
10
0 1 1 3 3 1 4 7 5 4
43 39 79 48 92 90 76 30 16 30

Sample Output 1
166374061
295776107
680203339

In the first test case, the expected number of operations is 13/6
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Function to calculate modular inverse
int mod_inverse(int a, int m) {
    // Implement this function
    int m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

int mod_add(int a, int b) {
    return (a + b) % MOD;
}

int mod_mul(int a, int b) {
    return (long long)a * b % MOD;
}

void solve() {
    int N;
    cin >> N;
    
    vector<int> parent(N + 1);
    vector<long long> a(N + 1);
    vector<vector<int>> children(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }
    
    long long sum_a = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        sum_a += a[i];
    }
    
    vector<int> dp(N + 1, 0);
    vector<int> subtree_sum(N + 1, 0);
    
    function<void(int)> dfs = [&](int node) {
        subtree_sum[node] = (node == 0) ? 0 : a[node];
        for (int child : children[node]) {
            dfs(child);
            subtree_sum[node] = mod_add(subtree_sum[node], subtree_sum[child]);
            dp[node] = mod_add(dp[node], mod_add(dp[child], subtree_sum[child]));
        }
    };
    
    dfs(0);
    
    int result = mod_mul(dp[0], mod_inverse(sum_a % MOD, MOD));
    cout << result << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
