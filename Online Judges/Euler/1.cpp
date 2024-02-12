// https://projecteuler.net/problem=1
//Solve it by your own and I am only providing this solution because Project Euler maintainers allowed to explore first 100 problems publicly!!

#include <bits/stdc++.h>
using namespace std;

int main(){
	int sum=0;
	for(int i=1; i<1000; i++){
		if(i%3==0 || i%5==0){
			sum+=i;
		}
	}
	cout << sum;
}