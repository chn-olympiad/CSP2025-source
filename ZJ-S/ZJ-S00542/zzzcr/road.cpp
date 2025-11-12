#include <bits/stdc++.h>
using namespace std;

#define file(name) assert(freopen(#name".in", "r", stdin)), assert(freopen(#name".out", "w", stdout))
#define _f(i, a, b) for(int i = a; i <= b; ++i)
#define _d(i, a, b) for(int i = a; i >= b; --i)
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define all(container) container.begin(), container.end()

constexpr int N = 1e4 + 105, M = 1e6 + 5;

int n, m, k, idx, ind[11], siz[11], c[11];
ll ans, ret;
struct edge { int u, v, w; } e[M], a[11][N];
struct dsu {
    int fa[N], siz[N], cnt;
    void init(int n) { 
        cnt = n;
        _f(i, 1, n) fa[i] = i, siz[i] = 1;
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return ;
        --cnt;
        if(siz[x] > siz[y]) swap(x, y);
        fa[x] = y, siz[y] += siz[x];
    }
} d;

void solve() {
    cin >> n >> m >> k, d.init(n);
    _f(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
    _f(i, 1, k) {
        cin >> c[i];
        _f(j, 1, n) cin >> a[i][j].w, a[i][j].u = j, a[i][j].v = i + n;
    }
    _f(i, 1, k) sort(a[i] + 1, a[i] + n + 1, [&](edge x, edge y) { return x.w < y.w; });
    sort(e + 1, e + m + 1, [&](edge x, edge y) { return x.w < y.w; });
    ret = 0;
    _f(i, 1, m) {
        if(d.find(e[i].u) != d.find(e[i].v)) {
            ret += e[i].w;
            d.merge(e[i].u, e[i].v);
            a[0][++idx] = e[i];
        }
    }
    siz[0] = n - 1;
    _f(i, 1, k) siz[i] = n;
    // assert(idx == n - 1);
    ans = ret;
    _f(mask, 1, (1 << k) - 1) {
        _f(i, 0, k) ind[i] = 1;
        d.init(n + k), ret = 0;
        vector<int> vec;
        vec.emplace_back(0);
        _f(i, 0, k - 1) if(mask >> i & 1) vec.emplace_back(i + 1), ret += c[i + 1];
        if(ret >= ans) continue;
        d.cnt = n + __builtin_popcount(mask);
        while(d.cnt > 1) {
            int vl = 1e9 + 1, ps = -1;
            for(auto x : vec) {
                while(ind[x] <= siz[x] && d.find(a[x][ind[x]].u) == d.find(a[x][ind[x]].v)) ++ind[x];
                if(ind[x] <= siz[x] && a[x][ind[x]].w < vl) vl = a[x][ind[x]].w, ps = x;
            }
            // cout << a[ps][ind[ps]].u << ' ' << a[ps][ind[ps]].v << ' ' << vl << '\n';
            d.merge(a[ps][ind[ps]].u, a[ps][ind[ps]].v);
            ret += vl;
            if(ret >= ans) break;
        }
        // cout << mask << ' ' << ret << '\n';
        ans = min(ans, ret);
    }
    cout << ans << '\n';
}

signed main() {
    file(road);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}