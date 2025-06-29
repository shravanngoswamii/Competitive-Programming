#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> nums;  // List to store valid tile values
ll dp[400002];  // dp array to store the number of ways to achieve a score

// Function to compute the combination sum using dynamic programming
void combinationSum(ll x) {
    // Initialize the list of valid tile values (powers of 2 starting from 2)
    nums.push_back(2);  // The smallest tile is 2
    
    // Generate all tiles 2^1, 2^2, 2^3, ..., until the tile value exceeds x
    for (int i = 1; ; i++) {
        ll tile_value = 1LL << (i + 1);  // Calculate 2^(i+1) using left shift
        if (tile_value > x) break;  // Stop if the tile value exceeds x
        nums.push_back(tile_value);
    }
    
    // Initialize the dp array to store the number of ways to reach each score
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;  // There's exactly one way to get a score of 0 (do nothing)

    // Process each tile value in nums
    for (ll tile_value : nums) {
        for (ll weight = tile_value; weight <= x; weight++) {
            dp[weight] = (dp[weight] + dp[weight - tile_value]) % 998244353;
        }
    }
}

// Function to solve each individual test case
void solve() {
    ll n;
    cin >> n;
    cout << dp[n] << endl;  // Output the number of ways to achieve score n
}

int main() {
    combinationSum(400000);  // Precompute the possible score combinations up to 400,000
    ll t;
    cin >> t;  // Read the number of test cases
    while (t--) {
        solve();  // Solve each test case
    }
    return 0;
}
