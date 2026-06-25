// https://codeforces.com/contest/1915/problem/C

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int n;
		long long a;
		cin >> n;
		long long sum = 0;
		for(int j=1; j<=n; j++){
			cin >> a;
			sum += a;
		}
		
		long long ps = sqrt(sum);
		if((ps*ps)==sum){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	
}