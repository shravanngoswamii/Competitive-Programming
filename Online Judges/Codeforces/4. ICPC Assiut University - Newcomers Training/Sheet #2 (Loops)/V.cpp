// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/V

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
		for(int j=1; j<=n*4; j++){
			if(j%4==0){
				cout << "PUM" << endl;
			}			
			else{
				cout << j << " ";
			}
		}
	}