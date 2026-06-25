#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> boxes(N);
    long long totalBalls = 0;

    for (int i = 0; i < N; ++i) {
        cin >> boxes[i];
        totalBalls += boxes[i];
    }

    for (int i = 0; i < M; ++i) {
        int B;
        cin >> B;
        totalBalls -= boxes[B];
        int next_box = (B + 1) % N;
        boxes[next_box] += boxes[B];
        boxes[B] = 0;
    }

    for (int i = 0; i < N; ++i)
        cout << boxes[i] + (i == 0 ? totalBalls : 0) << " ";
    cout << endl;

    return 0;
}
