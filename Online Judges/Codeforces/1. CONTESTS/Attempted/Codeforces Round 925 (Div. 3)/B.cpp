#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        long long s = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
        }
        int k = s/n;
        long long b = 0;
        bool f = true;
        for(int i = 0; i < n; i++){
            if(a[i] > k) {
                b += a[i] - k;
            }
            else if(a[i] < k) {
                if(b >= k - a[i]){
                    b -= (k - a[i]);
                }
                else {
                    f = false;
                    break;
                }
            }
        }
        if(f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
