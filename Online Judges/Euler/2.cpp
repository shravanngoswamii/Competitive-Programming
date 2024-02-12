// https://projecteuler.net/problem=2
//Solve it by your own and I am only providing this solution because Project Euler maintainers allowed to explore first 100 problems publicly!!

#include <bits/stdc++.h>
using namespace std;

int main(){
	int a=1;
	int b=2;
	int sum=2;
	while(true){
		int temp=a+b;
		if(temp>4000000){
			break;
		}
		else if(temp%2==0){
			sum += temp;
		}
		a=b;
		b=temp;
	}
	cout << sum;
}