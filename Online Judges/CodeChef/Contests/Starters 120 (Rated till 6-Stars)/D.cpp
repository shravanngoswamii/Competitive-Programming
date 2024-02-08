#include <iostream>
using namespace std;

/*int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        while (x != 0) {
            y %= x; // Equivalent to y = y % x
            swap(x, y); // Swap x and y
        }
        cout << y << endl;
    }
    return 0;
}
*/

int main(){
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		int x;
		cin >> x;
		int cv = 1;
		for(int j = 1; j<=7; j++){
			cv += cv+1;
		}
		if(cv>x){
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
}