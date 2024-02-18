// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/J

#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        if (isPrime[p])
            cout << p << " ";
    }
}

int main() {
    int N;
    cin >> N;
    sieveOfEratosthenes(N);
    return 0;
}
