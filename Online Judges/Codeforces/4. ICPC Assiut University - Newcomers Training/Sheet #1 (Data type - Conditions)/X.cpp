// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/X

#include <bits/stdc++.h>

using namespace std;

int main() {
  int l1, r1, l2, r2;

  cin >> l1 >> r1 >> l2 >> r2;

  int max_start = max(l1, l2);
  int min_end = min(r1, r2);

  if (max_start <= min_end) {
    cout << max_start << " " << min_end;
  } else {
    cout << -1;
  }

  return 0;
}
