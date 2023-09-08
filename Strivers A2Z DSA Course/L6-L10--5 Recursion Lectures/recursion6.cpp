// Sum of 1st N number

#include <bits/stdc++.h>
using namespace std;

//Parameterised Recursionn

void func(int i, int sum){
	if(i<1){
		cout << sum << endl;
		return;
	}
	func(i-1, sum+i);
}

int main(){
	int n;
	cin >> n;
	func(n,0);
	return 0;
}


// // Functional Recursion

// #include <bits/stdc++.h>
// using namespace std;

// int sum(int n){
// 	if (n==0){
// 		return 0;
// 	}
// 	else{
// 		return n+sum(n-1);
// 	}
// }

// int main(){
// 	int n;
// 	cin >> n;
// 	cout << sum(n);
// }


// // #include <bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n;
// 	cin >> n;
// 	cout << n*(n+1)/2;
// }