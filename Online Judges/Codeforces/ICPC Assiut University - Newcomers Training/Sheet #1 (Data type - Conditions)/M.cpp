// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/M

#include <bits/stdc++.h>
using namespace std;

int main(){
	char c;
	cin >> c;
	for(int i=48; i<=57; i++){
		if(int(c)==i){
			cout << "IS DIGIT";
		}
	}

	for(int i=65; i<=90; i++){
		if(int(c)==i){
			cout << "ALPHA" << endl << "IS CAPITAL";
		}
	}

	for(int i=97; i<=122; i++){
		if(int(c)==i){
			cout << "ALPHA" << endl << "IS SMALL";
		}
	}
}