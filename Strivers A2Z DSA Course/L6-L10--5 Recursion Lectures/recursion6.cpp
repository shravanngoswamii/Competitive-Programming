//Sum of 1st N number

#include <bits/stdc++.h>
using namespace std;

//Parameterised Recursionn


//Functional Recursion
int sum(int n){
	if (n==0){
		return 0;
	}
	else{
		return n+sum(n-1);
	}
}

int main(){
	int n;
	cin >> n;
	cout << sum(n);
}