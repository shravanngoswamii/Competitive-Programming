#include <bits/stdc++.h>
using namespace std;

int cnt=0;
void name(int n){
	if (cnt==n) return;
	cnt++;
	cout << "Name";
	name(n);
}

int main(){
	int n;
	cin >> n;
	name(n);
}