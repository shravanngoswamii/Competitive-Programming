// #include <iostream>

// using namespace std;

// string canDivideWatermelon(int weight) {
//     // Check if the weight is even and greater than 2
//     if (weight % 2 == 0 && weight > 2) {
//         return "YES";
//     } else {
//         return "NO";
//     }
// }

// int main() {
//     int w;
//     cin >> w;

//     // Check if the watermelon can be divided as required
//     string result = canDivideWatermelon(w);

//     // Print the result
//     cout << result << endl;

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int i = 1;
void printNos(int N) {

        if (i>N) return;
        i++;
        printNos(N);
        cout << i-1 << " ";
    }

int main(){
    int T;
    cin >> T;

    while(T--) {
        int N;

        cin >> N;

        printNos(N);
        cout << "\n";
    }
    return 0;
}