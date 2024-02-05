// Print numbers from 1 to n using backracking

#include <bits/stdc++.h>
using namespace std;


void num(int cnt, int n){
	if(cnt<1) return;
	cnt--;
	num(cnt, n);
	cout << cnt+1 << " ";
}

int main(){
	int n;
	cin >> n;
	num(n, n);
}

// vs

// #include<bits/stdc++.h>
// using namespace std;

// void func(int i, int n){
   
//    // Base Condition.
//    if(i<1) return;
   
//    // Function call to print (n-1) integers.
//    func(i-1,n);
//    cout<<i<<endl;

// }

// int main(){
  
//   // Here, let’s take the value of n to be 4.
//   int n = 4;
//   func(n,n);
//   return 0;

// }