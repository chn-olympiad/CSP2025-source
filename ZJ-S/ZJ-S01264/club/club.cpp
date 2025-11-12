#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define FILENAME []() -> string {string t = __FILE__; t.erase(t.find_last_of('.')); t.erase(0, t.find_last_of('/') + 1); return t;}()
#define INPUT (FILENAME + ".in").c_str()
#define OUTPUT (FILENAME + ".out").c_str()
#define FILEIO freopen(INPUT, "r", stdin), freopen(OUTPUT, "w", stdout)
#define fin cin
#define fout cout
int T;
void solve() {
    int n;
    fin >> n;
    vector<vector<pair<int, int>>> a;
    vector<pair<int, int>> b;
    for (int i = 0, x, y, z; i < n; ++i) {
        fin >> x >> y >> z;
        a.push_back(vector<pair<int, int>>{make_pair(x, 0), make_pair(y, 1), make_pair(z, 2)});
        sort(a[i].begin(), a[i].end(), greater<>());
        // cerr << a[i][0].first << " " << a[i][1].first << " " << a[i][2].first << "\n";
        // cerr << a[i][0].second << " " << a[i][1].second << " " << a[i][2].second << "\n";
        // cerr << "\n";
        b.emplace_back(a[i][0].first, i);
    }
    sort(b.begin(), b.end(), greater<>());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q[3];
    int sum[3] = {};
    int ans = 0;
    for (auto [v, k] : b) {
        // cerr << "calc v " << v << " k " << k << " id " << a[k][0].second << "\n";
        if (sum[a[k][0].second] == n / 2) {
            if (q[a[k][0].second].top().first < a[k][0].first - a[k][1].first) {
                auto [vt, kt] = q[a[k][0].second].top();
                q[a[k][0].second].pop();
                --sum[a[kt][0].second];
                ++sum[a[kt][1].second];
                q[a[kt][1].second].emplace(a[kt][1].first - a[kt][2].first, kt);
                ans -= vt;
                // cerr << "regret at " << k << " for " << kt << " v " << v << " vt " << vt 
                //      << " id " << a[kt][0].second << " to " << a[kt][1].second << "\n";
                // 反悔
            }
            else {
                ans += a[k][1].first;
                ++sum[a[k][1].second];
                q[a[k][1].second].emplace(a[k][1].first - a[k][2].first, k);
                // cerr << "usesec at " << k << " v " << a[k][1].first << "\n";
                continue;
                // 退而求其次
            }
        }
        ans += v;
        ++sum[a[k][0].second];
        q[a[k][0].second].emplace(a[k][0].first - a[k][1].first, k);
    }
    fout << ans << "\n";
    // cerr << ans << "\n";
}
auto main() -> int {
    FILEIO;
    ios::sync_with_stdio(false);
    fin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
