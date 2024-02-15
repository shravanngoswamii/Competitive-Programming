#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], cnt = 1, cnt1 = 1;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n == 1) {
            cout << "0" << endl;
            continue;
        }
        for (int i = 1; i < n; i++)
            if (a[0] == a[i])
                cnt++;
            else
                break;
        for (int i = n - 2; i >= 0; i--)
            if (a[n - 1] == a[i])
                cnt1++;
            else
                break;
        if (a[0] == a[n - 1])
            cout << max(0, n - cnt - cnt1) << endl;
        else
            cout << n - max(cnt, cnt1) << endl;
    }
}
