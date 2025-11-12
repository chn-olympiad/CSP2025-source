#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int, int>
#define mk(a, b) makr_pair(a, b)
using namespace std;
template<typename P>
inline void read(P &x) {
    P res = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        res = (res << 3) + (res << 1) + (ch ^ 48);
        ch = getchar();
    }
    x = res * f;
}
template<typename PP, typename ...Arg>
inline void read(PP &x, Arg &...args) { read(x); read(args...); }
int T = 1;

const int N = 1e4 + 10, M = 1e6 + 10;

int n, m, k;
struct edge {
    int u, v;
    ll w;
    bool operator < (const edge &b) const {
        return w < b.w;
    }
} e[M * 2], e1[M * 2];
int c[12][N], tot = 0;
int w[12];
int fa[N + 20];
int find(int x) { return (fa[x] == x) ? x : fa[x] = find(fa[x]); }
void unionn(int a, int b) {
    int x = find(a), y = find(b);
    fa[y] = x;
}

ll Kruskal(int num) {
    for (int i = 1; i <= n + 12; ++i) fa[i] = i;
    sort(e + 1, e + tot + 1);
    int cnt = 0;
    ll ww = 0;
    for (int i = 1; i <= tot; ++i) {
        int u = e[i].u, v = e[i].v;
        if (find(u) != find(v)) {
            unionn(u, v);
            ww += e[i].w;
            cnt++;
            if (cnt == num - 1) return ww;
        }
    }
}
ll ans = 0x3f3f3f3f3f3f3f3f;

bool vis[N];

void dfs(int x, bool is, int cnt) {
    if (x > k) return;
    if (is) vis[x] = 1;
    if (x == k) {
        ll res = 0;
        for (int i = 1; i <= k; ++i) {
            if (vis[i]) {
                res += w[i];
                for (int j = 1; j <= n; ++j) e[++tot] = {i + n, j, c[i][j]};
            }
        }
        ll tmp = Kruskal(cnt + n);
        for (int i = 1; i <= tot; ++i) e[i] = e1[i];
        ans = min(tmp + res, ans);
        tot = m;
        vis[x] = 0;
        return;
    }
    dfs(x + 1, 0, cnt);
    dfs(x + 1, 1, cnt + 1);
    vis[x] = 0;
}

void solve() {
    read(n, m, k);
    tot = m;
    for (int i = 1; i <= m; ++i) read(e[i].u, e[i].v, e[i].w);
    bool f1 = 1, f2 = 1;
    for (int i = 1; i <= k; ++i) {
        read(w[i]);
        if (w[i] != 0) f1 = 0;
        int p = 0;
        for (int j = 1; j <= n; ++j) {
            read(c[i][j]);
            if (c[i][j] == 0) p = j;
        }
        if (p == 0) f2 = 0;
    }
    if (f1 && f2) {
        for (int i = 1; i <= k; ++i) {
            int p = 0;
            for (int j = 1; j <= n; ++j) if (c[i][j] == 0) p = j;
            for (int j = 1; j <= n; ++j) e[++tot] = {p, j, c[i][j]};
        }
        ans = Kruskal(n);
        cout << ans << endl;
    }
    else {
        for (int i = 1; i <= tot; ++i) e1[i] = e[i];
        dfs(1, 1, 1);
        dfs(1, 0, 0);
        cout << ans << endl;
    }
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    // read(T);
    while (T--) solve();
    return 0;
}