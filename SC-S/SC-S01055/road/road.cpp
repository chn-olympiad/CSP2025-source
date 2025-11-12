#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 1e6 + 6;

bool flg = 1;
int n, m, k, a[11][N], c[11];
array<ll, 3> ed[N];
ll ans, add;

struct DSU {
    vector<int> f, siz;
    DSU (int si) : f(si), siz(si, 1){
        iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb)
            return;
        f[fb] = fa;
        siz[fa] += siz[fb];
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

void solve1() {
    DSU ds(n + 1);
    for (int i = 1; i <= m; i ++) {
        if (!ds.same(ed[i][1], ed[i][2])) {
            ds.merge(ed[i][1], ed[i][2]);
            ans += ed[i][0];
        }
    }
    cout << ans;
    exit(0);
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) 
        cin >> ed[i][1] >> ed[i][2] >> ed[i][0];
    sort(ed + 1, ed + 1 + m, [&] (array<ll, 3> a, array<ll, 3> b) {
        return a[0] < b[0];
    });
    if (k == 0)
        solve1();
    for (int i = 1; i <= k; i ++) {
        cin >> c[i];
        if (c[i] != 0)
            flg = 0;
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            if (a[i][j] != 0)
                flg = 0;
        }
    }
    if (flg) {
        cout << 0;
        return 0;
    }
    ans = 1e18 + 78;
    for (int i = 0; i <= (1 << k) - 1; i ++) {
        vector<array<ll, 3>> ned;
        add = 0;
        for (int j = 0; j < k; j ++) {
            if ((i >> j) & 1) {
                add += c[j + 1];
                for (int u = 1; u <= n; u ++) {
                    for (int v = u + 1; v <= n; v ++) {
                        array<ll, 3> ow;
                        ow[1] = u; ow[2] = v;
                        ow[0] = a[j + 1][u] + a[j + 1][v];
                        ned.push_back(ow);
                    }
                }
            }
        }
        sort(ned.begin(), ned.end(), [&] (array<ll, 3> a, array<ll, 3> b) {
            return a[0] < b[0];
        });
        DSU ds(n + 1);
        int id1 = 1, id2 = 0;
        while(1) {
            if (ned.size() && ned[id2][0] < ed[id1][0]) {
                ds.merge(ned[id2][1], ned[id2][2]);
                add += ned[id2][0];
                if (ds.siz[ds.find(ned[id2][1])] == n) {
                    ans = min(ans, add);
                    break;
                }
                if (id2 != ned.size() - 1)
                    id2 ++;
            }
            else {
                ds.merge(ed[id1][1], ed[id1][2]);
                add += ed[id1][0];
                if (ds.siz[ds.find(ed[id1][1])] == n) {
                    ans = min(ans, add);
                    break;
                }
                if (id1 != m)
                    id1 ++;
            }
        }
    }
    cout << ans;
    return 0;
}