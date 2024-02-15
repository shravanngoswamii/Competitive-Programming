// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/E

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int maxNum = *max_element(nums, nums + n);
    cout << maxNum;
}
