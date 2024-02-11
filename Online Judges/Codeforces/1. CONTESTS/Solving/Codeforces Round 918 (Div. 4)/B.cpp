// https://codeforces.com/contest/1915/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	char a, b, c;
	for(int i=0; i<t; i++){
		for(int j=1; j<=3; j++){
			cin >> a >> b >> c;
			if(a=='?' || b=='?' || c=='?'){
				if(a=='A' || b=='A' || c=='A'){
					if(a=='B' || b=='B' || c=='B'){
						cout << 'C' << endl;
					}
				}
				if(a=='A' || b=='A' || c=='A'){
					if(a=='C' || b=='C' || c=='C'){
						cout << 'B' << endl;
					}
				}
				else{
					cout << 'A' << endl;
				}
			}
		}
		
	}
}