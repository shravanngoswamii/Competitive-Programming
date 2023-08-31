#include <bits/stdc++.h>
using namespace std;

int cnt;
void name(int n){
	if (cnt<1) return;
	cout << cnt << "\n";
	cnt--;
	name(n);
}

int main(){
	// int t;
	// cin >> t;
	// for (int i=1; i<=t; i++){
		int n;
		cin >> n;
		cnt = n;
		name(n);
		// cnt = n;
		// cout <<  endl;
	}
// }