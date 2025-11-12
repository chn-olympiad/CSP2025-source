#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
#define FILENAME []() -> string {string t = __FILE__; t.erase(t.find_last_of('.')); t.erase(0, t.find_last_of('/') + 1); return t;}()
#define INPUT (FILENAME + ".in").c_str()
#define OUTPUT (FILENAME + ".out").c_str()
#define FILEIO freopen(INPUT, "r", stdin), freopen(OUTPUT, "w", stdout)
#define fin cin
#define fout cout
int T;
auto find(vector<int> &fa, int x) -> int {
    return fa[x] == x ? x : (fa[x] = find(fa, fa[x]));
}
void solve() {
    int n, m, k;
    basic_string<pair<long long, pair<int, int>>> mp;
    vector<long long> c;
    fin >> n >> m >> k;
    for (int i = 0, x, y, z; i < m; ++i) {
        fin >> x >> y >> z;
        mp.push_back(make_pair(1LL * z, make_pair(x - 1, y - 1)));
    }
    for (int i = 0, v; i < k; ++i) {
        fin >> v;
        c.push_back(1LL * v);
        for (int j = 0; j < n; ++j) {
            fin >> v;
            mp.push_back(make_pair(1LL * v, make_pair(n + i, j)));
        }
    }
    sort(mp.begin(), mp.end());
    long long ans = 0x7f7f7f7f7f7f7f7f;
    vector<int> fa(n + k);
    for (int t = 0; t < (1 << k); ++t) {
        long long res = 0;
        for (int i = 0; i < k; ++i) {
            if ((t & (1 << i)) != 0) {
                res += c[i];
            }
        }
        iota(fa.begin(), fa.end(), 0);
        for (auto [v, p] : mp) {
            auto [x, y] = p;
            if (x >= n && (t & (1 << (x - n))) == 0) {
                continue;
            }
            int fx = find(fa, x), fy = find(fa, y);
            if (fx == fy) {
                continue;
            }
            fa[fx] = fy;
            res += v;
        }
        // cerr << t << " " << res << " " << ans << "\n";
        ans = min(ans, res);
    }
    fout << ans << "\n";
}
auto main() -> int {
    FILEIO;
    ios::sync_with_stdio(false);
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
