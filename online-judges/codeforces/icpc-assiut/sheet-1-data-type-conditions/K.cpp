// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/K

#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a, b, c;
	cin >> a >> b >> c;
	cout << min(a,min(b,c)) << " " << max(a,max(b,c));
	// if(a<b && a<c) cout << a;
	// else if(b<a && b<c) cout << b;
	// else cout << c;
	// cout << " ";
	// if(a>b && a>c) cout << a;
	// else if(b>a && b>c) cout << b;
	// else cout << c;
}