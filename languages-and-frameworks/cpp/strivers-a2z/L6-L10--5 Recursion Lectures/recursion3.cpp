//Print numbers from n to 1

#include <bits/stdc++.h>
using namespace std;

int cnt;
void num(int n){
	if (cnt<1) return;
	cout << cnt << "\n";
	cnt--;
	num(n);
}

int main(){
	// int t;
	// cin >> t;
	// for (int i=1; i<=t; i++){
		int n;
		cin >> n;
		cnt = n;
		num(n);
		// cnt = n;
		// cout <<  endl;
	}
// }