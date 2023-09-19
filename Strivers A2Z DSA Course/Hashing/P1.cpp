#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int hash[13] = {0};
	for(int i=0; i<n; i++){
		hash[arr[i]] += 1;
	}


	int m;
	cin >> m;
	while(m--){
		int num;
		cin >> num;
		cout << hash[num] << endl;
	}
	return 0;
}