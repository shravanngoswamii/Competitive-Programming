#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--){
        int r,w;
        int ms=-1;
        int msi=-1;
        for(int i=1; i<=22; i++){
            cin >> r >> w;
            int tp = r + (w*20);
            if(tp>ms){
                ms=tp;
                msi=i;
            }
        }
        cout << msi << endl;
    }
}