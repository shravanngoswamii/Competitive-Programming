#include <bits/stdc++.h>
using namespace std;

struct Stage {
    int index, parent;
    long long time;
    bool operator<(const Stage& other) const {
        return time > other.time;
    }
};

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, long long>>> graph(N + 1);
    for (int i = 1; i < N; ++i) {
        int ai, bi, xi;
        cin >> ai >> bi >> xi;
        graph[i].push_back({i + 1, ai});
        graph[i].push_back({xi, bi});
    }

    vector<long long> distances(N + 1, numeric_limits<long long>::max());
    vector<int> parents(N + 1, -1);
    distances[1] = 0;

    priority_queue<Stage> pq;
    pq.push({1, -1, 0});

    while (!pq.empty()) {
        Stage current = pq.top();
        pq.pop();
        if (current.time > distances[current.index]) continue;

        for (const auto& [next, time] : graph[current.index]) {
            long long newDistance = current.time + time;
            if (newDistance < distances[next]) {
                distances[next] = newDistance;
                parents[next] = current.index;
                pq.push({next, current.index, newDistance});
            }
        }
    }

    if (distances[N] == numeric_limits<long long>::max()) {
        cout << "Impossible" << endl;
    } else {
        cout << distances[N] << endl;
    }

    return 0;
}
