// Print numbers from n to 1 using backracking

#include <bits/stdc++.h>
using namespace std;

void num(int i, int n){
	if (i>n){
		return;
	}
	else{
		i++;
		num(i,n);
		cout << i-1 << endl;
	}
}

int main(){
	int n;
	cin >> n;
	int i;
	i=1;
	num(i,n);
}
