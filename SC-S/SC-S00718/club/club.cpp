#include<bits/stdc++.h>
#define int long long
#define file(a) freopen(#a".in", "r", stdin), freopen(#a".out", "w", stdout)
using namespace std;
int32_t main() {
    file(club);
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        struct People {
            int val[3], idx[3], cur;
            People(): val(), idx(), cur() {}
            void build() {
                vector<pair<int, int>>v;
                v.emplace_back(val[0], 0);
                v.emplace_back(val[1], 1);
                v.emplace_back(val[2], 2);
                sort(v.rbegin(), v.rend());
                for (int i = 0; i < 3; ++i) idx[i] = v[i].second;
                cur = 0;
            }
        };
        vector<People>v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i].val[0] >> v[i].val[1] >> v[i].val[2], v[i].build();
        priority_queue<int, vector<int>, greater<int>>q[3];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // cerr << "in case " << T << " we do that: ";
            if (q[v[i].idx[0]].size() + 1 > n / 2) {
                if (v[i].val[v[i].idx[0]] - q[v[i].idx[0]].top() <= v[i].val[v[i].idx[1]]) {
                    ans += v[i].val[v[i].idx[1]];
                    continue;
                }
                // cerr << "throw queue " << v[i].idx[0] << "'s top and cost " << q[v[i].idx[0]].top() << ';';
                ans -= q[v[i].idx[0]].top();
                q[v[i].idx[0]].pop();
            }
            // cerr << "add a number in queue" << v[i].idx[0] << " to add a number of " << v[i].val[v[i].idx[0]] << endl;
            ans += v[i].val[v[i].idx[0]];
            q[v[i].idx[0]].push(v[i].val[v[i].idx[0]] - v[i].val[v[i].idx[1]]);
        }
        cout << ans << endl;
    }
    return 0;
}