#include <iostream>
using namespace std;

bool can_construct_triangle(int a, int b, int x, int y) {
    // Check if square B is inside square A
    if (x < 0 || y < 0 || x + b > a || y + b > a) {
        return false;
    }

    // Construct the triangle T
    int t1_x = 0, t1_y = 0;
    int t2_x = 0, t2_y = a;
    int t3_x = a, t3_y = a;

    // Check if square B is inside the triangle
    if (x >= t1_x && x <= t3_x && y >= t1_y && y <= t3_y &&
        x + b <= t3_x && y + b <= t3_y) {
        return true;
    }

    // Check if square B overlaps with the triangle
    if (x <= t3_x && x + b >= t1_x && y <= t3_y && y + b >= t1_y) {
        return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        cout << (can_construct_triangle(a, b, x, y) ? "yes" : "no") << endl;
    }
    return 0;
}