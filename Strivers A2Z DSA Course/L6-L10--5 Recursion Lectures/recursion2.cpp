#include <bits/stdc++.h>
using namespace std;

int cnt=0;
void name(int n){
	if (cnt==n) return;
	cnt++;
	cout << cnt << "\n";
	name(n);
}

int main(){
	// int t;
	// cin >> t;
	// for (int i=1; i<=t; i++){
		int n;
		cin >> n;
		name(n);
	// cnt = 0;
	// cout <<  endl;
	}
// }

// #include<bits/stdc++.h>
// using namespace std;

// void func(int i, int n){
   
//    // Base Condition.
//    if(i>n) return;
//    cout<<i<<"\n";

//    // Function call to print i till i increments to n.
//    func(i+1,n);

// }

// int main(){
  
//   // Here, let’s take the value of n to be 4.
//   int n;
//   cin >> n;
//   func(1,n);
//   return 0;

// }