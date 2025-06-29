#include <iostream>
#include <string>

bool query(int pos) {
    std::cout << "READ " << pos << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

void solve_testcase() {
    int n;
    std::cin >> n;
    
    // Skip the hidden array line in sample input
    std::string hidden_line;
    std::getline(std::cin, hidden_line);
    
    // We know array[0] is true and array[n-1] is false
    int left = 0;
    int right = n - 1;
    
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (query(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    // At this point, left points to a true value and right points to a false value
    // Therefore, left is our answer position
    std::cout << "OUTPUT " << left << std::endl;
}

int main() {
    int test_cases;
    std::cin >> test_cases;
    
    for (int t = 0; t < test_cases; t++) {
        solve_testcase();
    }
    
    return 0;
}