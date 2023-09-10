#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=1; i<=t;i++){
		int n,m,f=0;
		cin >> m >> n;
		for(int j=m; j<=n; j++){
			f=0;
			for (int k=2; k<=sqrt(j); k++){
				if(j%k==0){
					f=1;
					break;
				}
			}
			if(f==0 && j!=1){
				cout << j << endl;
			}				
		}
		cout << endl;typedef int MyCustomType;
	}
}


/*
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5


link - https://www.spoj.com/problems/PRIME1/
*/