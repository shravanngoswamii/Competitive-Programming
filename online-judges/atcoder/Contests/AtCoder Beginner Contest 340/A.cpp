#include <bits/stdc++.h>
using namespace std;

int main(){
	int A, B, D;
    cin >> A >> B >> D;

    cout << A;

    while (A + D <= B) {
        A += D;
        cout << " " << A;
    }

    cout << endl;

    return 0;
}