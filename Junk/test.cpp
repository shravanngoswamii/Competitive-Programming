#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if((a>=30 && a<=40 && b>=30 && b<=40) || (a>=50 && a<=60 && b>=50 && b<=60)){
        cout << true;
    }
    else{
        cout << false;
    }
}