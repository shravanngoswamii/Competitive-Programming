// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/R

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int years = n/365;
	int months = (n%365)/30;
	int days = (n%365)%30;

	cout << years << " years" << endl;
	cout << months << " months" << endl;
	cout << days << " days";
}