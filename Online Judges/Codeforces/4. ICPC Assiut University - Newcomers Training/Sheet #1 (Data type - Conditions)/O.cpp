// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/O

#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	char s;
	cin >> a >> s >> b;
	if(s=='+')
		cout << a+b;
	else if(s=='-')
		cout << a-b;
	else if(s=='*')
		cout << a*b;
	else
		cout << a/b;
}