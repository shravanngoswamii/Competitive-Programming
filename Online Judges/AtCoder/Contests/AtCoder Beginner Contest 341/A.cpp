#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int count0 = 0;
	int count1 = 0;
	while(true){
		if(count1<=(n+1)){
			cout << 1;
			count1++;
		}
		if(count0<=n){
			cout << 0;
			count0++;
		}
		else{
			break;
		}
	}
}