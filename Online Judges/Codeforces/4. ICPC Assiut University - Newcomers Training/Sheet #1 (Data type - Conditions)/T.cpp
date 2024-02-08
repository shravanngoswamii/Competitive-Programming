// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/T

#include <bits/stdc++.h>
using namespace std;

int main(){
	int x[3];
	cin >> x[0] >> x[1] >> x[2];
	int y[] = {x[0],x[1],x[2]};
	sort(begin(y),end(y));
	for (int i : y){
		cout << i << endl;
	}
	cout << endl << x[0] << endl << x[1] << endl << x[2];
}