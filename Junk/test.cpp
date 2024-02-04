#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    int n1, n2;
    n1 = 1;
    n2 = 1;
    cout << n1 << " " << n2 << " ";
    for (int i=2; i<=k; i++){
        cout << (i-1)+(i-2) << " ";
    }
}