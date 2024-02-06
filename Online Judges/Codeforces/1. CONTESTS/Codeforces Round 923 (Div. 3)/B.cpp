#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

string constructString(vector<int>& trace) {
    int n = trace.size();
    string S(n, ' ');

    // Map to store the indices of characters encountered so far
    unordered_map<char, int> lastSeenIndex;

    // Set to store the characters encountered so far
    set<char> encountered;

    // Iterate through the trace array
    for (int i = 0; i < n; ++i) {
        char ch = 'a';
        int count = trace[i];

        // Find the earliest occurrence of the character
        while (count > 0 || encountered.count(ch) > 0) {
            if (encountered.count(ch) > 0)
                --count;
            ++ch;
        }

        // Update the string and sets
        S[i] = ch;
        encountered.insert(ch);
        lastSeenIndex[ch] = i;
    }

    return S;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> trace(n);

        for (int i = 0; i < n; ++i) {
            cin >> trace[i];
        }

        string result = constructString(trace);
        cout << result << endl;
    }

    return 0;
}
