// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	for(int i=1; i<=n; i++){
		if(i%2==0){
			cout << i << endl;
		}
		else if(n==1){
			cout << -1;
		}
	}
}