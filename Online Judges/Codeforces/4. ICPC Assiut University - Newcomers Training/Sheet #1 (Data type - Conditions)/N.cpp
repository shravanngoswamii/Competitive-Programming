// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/N

#include <bits/stdc++.h>
using namespace std;

int main(){
	char a;
	cin >> a;
	if(int(a)<=90){
		cout << char(a+32);
	}
	else{
		cout << char(a-32);
	}
}