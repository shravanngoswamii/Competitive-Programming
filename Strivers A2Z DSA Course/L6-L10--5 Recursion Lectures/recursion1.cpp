#include <bits/stdc++.h>
using namespace std;

int cnt=0;
void name(int n){
	if (cnt==n) return;
	cnt++;
	cout << "shravan" << endl;
	name(n);
}

int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		int n;
		cin >> n;
		name(n);
		cnt = 0;
		cout <<  endl;
	}

}