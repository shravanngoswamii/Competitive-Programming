// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/I

#include <bits/stdc++.h>
using namespace std;

int main(){
	string n;
	cin >> n;
	int len = n.length();
	bool c;
	for(int i=0; i<len/2; i++){
		if(n[i]!=n[len-i-1]){
			c=false;	
		}
		else{
			c=true;
		}
	}
	if(c==true){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	
}