#include <iostream>
#include <unordered_map>

using namespace std;

long long solve(long long n, unordered_map<long long, long long>& memo) {
  if (memo.count(n)) {
    return memo[n];
  }

  if (n == 1) {
    return 0;
  }

  long long cost = n + solve(n / 2, memo) + solve((n + 1) / 2, memo);
  memo[n] = cost;

  return cost;
}

int main() {
  long long n;
  cin >> n;

  unordered_map<long long, long long> memo;
  long long total_cost = solve(n, memo);
  cout << total_cost << endl;

  return 0;
}
