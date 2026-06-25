#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int num_tests;
    cin >> num_tests;
    
    while (num_tests--) {
        int size, divisor1, divisor2;
        cin >> size >> divisor1 >> divisor2;
        
        vector<int> elements(size);
        unordered_map<int, int> remainder1_count, remainder2_count;
        
        for (int i = 0; i < size; ++i) {
            cin >> elements[i];
            ++remainder1_count[elements[i] % divisor1];
            ++remainder2_count[elements[i] % divisor2];
        }
        
        long long pair_count = 0;
        for (int i = 0; i < size; ++i) {
            int remainder1 = elements[i] % divisor1;
            int remainder2 = elements[i] % divisor2;
            pair_count += (remainder1_count[remainder1] - 1) * (remainder2_count[remainder2] - 1);
        }
        
        cout << (pair_count / 2) << '\n';
    }
    return 0;
}
