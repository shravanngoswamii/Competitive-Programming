//  C - Spiral Rotation
/*
Problem Statement

You are given a grid with
N rows and N columns, where N is an even number. Let (i,j) denote the cell at the i-th row from the top and j-th column from the left.

Each cell is painted black or white. If Ai,j​= #, cell (i,j) is black; if Ai,j​= ., it is white.

Find the color of each cell after performing the following operation for i=1,2,…,N/2​ in this order.

- For all pairs of integers x,y between i and N+1−i, inclusive, replace the color of cell (y,N+1−x) with the color of cell (x,y). Perform these replacements simultaneously for all such pairs x,y.

Constraints

N is an even number between 2 and 3000, inclusive.
Each Ai,j​ is # or .

Input
The input is given from Standard Input in the following format:
```
N

A1,1​A1,2​…A1,N​

A2,1​A2,2​…A2,N​

⋮

AN,1​AN,2​…AN,N​
```

Output
After all operations, let Bi,j​= # if cell (i,j) is black, and Bi,j​= . if it is white. Print the grid in the following format:
```
B1,1​B1,2​…B1,N​

B2,1​B2,2​…B2,N​

⋮

BN,1​BN,2​…BN,N​
```

Sample Input 1
```
8
.......#
.......#
.####..#
.####..#
.##....#
.##....#
.#######
.#######
```

Sample Output 1
```
........
#######.
#.....#.
#.###.#.
#.#...#.
#.#####.
#.......
########
```

The operations change the colors of the grid cells as follows:
```
.......#   ........   ........   ........   ........
.......#   ######..   #######.   #######.   #######.
.####..#   ######..   #....##.   #.....#.   #.....#.
.####..# → ##..##.. → #....##. → #.##..#. → #.###.#.
.##....#   ##..##..   #..####.   #.##..#.   #.#...#.
.##....#   ##......   #..####.   #.#####.   #.#####.
.#######   ##......   #.......   #.......   #.......
.#######   ########   ########   ########   ########
```

Sample Input 2
```
6
.#.#.#
##.#..
...###
###...
..#.##
#.#.#.
```

Sample Output 2
```
#.#.#.
.#.#.#
#.#.#.
.#.#.#
#.#.#.
.#.#.#
```

Sample Input 3
```
12
.......#.###
#...#...#..#
###.#..#####
..#.#.#.#...
.#.....#.###
.......#.#..
#...#..#....
#####.......
...#...#.#.#
..###..#..##
#..#.#.#.#.#
.####.......
```

Sample Output 3
```
.#..##...##.
#.#.#.#.#...
###.##..#...
#.#.#.#.#...
#.#.##...##.
............
............
.###.###.###
...#...#.#..
.###...#.###
...#...#...#
.###...#.###
```
*/

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define nl(i,a,b) for(int i=a; i<b; i++)
#define f first
#define s second
#define pb push_back
#define mp make_pair
const int MOD =  1e9+7;
const int INF = LLONG_MAX >> 1;
using namespace std;

// ... existing code ...

void t(int n, vector<vector<char>>& g) {
    for (int i = 1; i <= n / 2; ++i) {
        vector<char> temp(4 * (n - 2*i + 1));
        int idx = 0;
        
        // Store the outer layer in temp
        for (int j = i - 1; j < n - i + 1; ++j) temp[idx++] = g[i-1][j];
        for (int j = i; j < n - i + 1; ++j) temp[idx++] = g[j][n-i];
        for (int j = n - i - 1; j >= i - 1; --j) temp[idx++] = g[n-i][j];
        for (int j = n - i - 1; j >= i; --j) temp[idx++] = g[j][i-1];
        
        // Rotate temp by n positions
        rotate(temp.begin(), temp.begin() + n - i + 1, temp.end());
        
        // Place rotated values back
        idx = 0;
        for (int j = i - 1; j < n - i + 1; ++j) g[i-1][j] = temp[idx++];
        for (int j = i; j < n - i + 1; ++j) g[j][n-i] = temp[idx++];
        for (int j = n - i - 1; j >= i - 1; --j) g[n-i][j] = temp[idx++];
        for (int j = n - i - 1; j >= i; --j) g[j][i-1] = temp[idx++];
    }
}

// ... rest of the code remains the same ...

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    t(n, g);

    for (const auto& r : g) {
        for (char c : r) {
            cout << c;
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;   
}