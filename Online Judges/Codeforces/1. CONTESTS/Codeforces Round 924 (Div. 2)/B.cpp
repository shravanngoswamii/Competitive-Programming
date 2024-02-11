#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        set<int> se;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            se.insert(v[i]);
        }
        vector<int> l;
        for (auto x : se)
        {
            l.push_back(x);
        }
        int k = n;
        n = l.size();
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            int en = l[i] + k - 1;
            int it = upper_bound(l.begin(), l.end(), en) - l.begin() - i;
            ans = max(ans, it);
        }
        cout << ans << endl;
    }
}