// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/H

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int count=0;
	for(int i=1; i<=n; i++){
		if(n%i==0){
			count++;
		}
	}
	if(count==2){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
}