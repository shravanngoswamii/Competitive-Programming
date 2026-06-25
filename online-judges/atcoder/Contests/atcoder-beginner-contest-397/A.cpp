// Author: Shravan Goswami

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    float x;
    cin >> x;
    if(x>=38.0){
    	cout << "1" << endl;
    }
    else if (x>=37.5){
    	cout << "2" << endl;
    }
    else{
    	cout << "3" << endl;
    }
    return 0;   
}