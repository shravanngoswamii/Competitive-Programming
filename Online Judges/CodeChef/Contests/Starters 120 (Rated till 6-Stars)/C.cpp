#include <iostream>
using namespace std;

long long largestK(long long x, long long y) {
    // If both x and y are 0, there is no binary string to construct, so return 0
    if (x == 0 && y == 0) {
        return 0;
    }

    // If only x is 0, there are no zeros, so return 0 as well.
    if (x == 0) {
        return 0;
    }

    // Calculate the minimum number of ones between zeros
    long long min_ones_between_zeros = (y - 1) / x;

    // Calculate the remaining ones after distributing them among the zeros
    long long remaining_ones = y - 1 - min_ones_between_zeros * x;

    // If the remaining ones are greater than or equal to the minimum ones
    // between zeros, it means there won't be enough ones to place between
    // zeros, so the result is 0.
    if (remaining_ones >= min_ones_between_zeros) {
        return 0;
    } else {
        return min_ones_between_zeros;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, y;
        cin >> x >> y;

        cout << largestK(x, y) << endl;
    }

    return 0;
}
