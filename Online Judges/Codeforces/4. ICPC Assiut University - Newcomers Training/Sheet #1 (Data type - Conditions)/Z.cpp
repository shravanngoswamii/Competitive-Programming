// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/Z

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if((b*log(a))>(d*log(c))){
        cout << "YES";
    }
    else
        cout << "NO";
}