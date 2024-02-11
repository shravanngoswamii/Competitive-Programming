// https://codeforces.com/contest/1915/problem/A

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	int a, b, c;
	for(int i=1; i<=t; i++){
		cin >> a >> b >> c;
		if(a==b)
			cout << c << endl;
		else if(a==c)
			cout << b << endl;
		else
			cout << a << endl;
	}
}