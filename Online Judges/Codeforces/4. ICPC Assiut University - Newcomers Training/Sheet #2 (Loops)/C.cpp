// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/C

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int e;
	int ceven = 0;
	int codd = 0;
	int cp = 0;
	int cn = 0;
	for(int i=1; i<=n; i++){
		cin >> e;
		if(e%2==0){
			ceven++;
		}
		else{
			codd++;
		}
		if(e>0)
			cp++;
		else if(e<0)
			cn++;
	}
	cout << "Even: " << ceven << endl << "Odd: " << codd << endl << "Positive: " << cp << endl << "Negative: " << cn;
}