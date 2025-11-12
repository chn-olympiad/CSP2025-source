/*
start at 15:26
finish at 16:40
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200200, M = 10000100, K = 26;
const int base1 = 137007, mod1 = 1e9 + 7, base2 = 1037, mod2 = 1e9 + 9;
int n, q, m, cur;
string a, b;
string s1[N], s2[N];
string t1[N], t2[N];
vector<int> vec[N], cev[N];
unordered_map<ll, int> mp;
int son[M][K], tot, dfn[M], siz[M], nw, ix1[N], ix2[N];
void init() {
    for (int i = 1; i <= tot; ++i) {
        for (int j = 0; j < K; ++j) son[i][j] = 0;
    }
    tot = 1, nw = 0;
    return;
}
void ins(string &s, int &o) {
    int u = 1;
    for (int i = 0; i < s.size(); ++i) {
        int p = s[i] - 'a';
        if (!son[u][p]) son[u][p] = ++tot;
        u = son[u][p];
    }
    o = u;
    return;
}
void dfs(int u) {
    dfn[u] = ++nw, siz[u] = 1;
    for (int i = 0, v; i < K; ++i) if ((v = son[u][i])) dfs(v), siz[u] += siz[v];
    return;
}
int vx[N], vy[N], lx[N], ly[N], rx[N], ry[N], ans[N];
struct Node{
    int x, y, id;
    Node() {}
    Node(int p, int q, int r)
        : x(p), y(q), id(r) {}
    bool operator<(const Node &_)const{
        if (x != _.x) return x < _.x;
        if (y != _.y) return y < _.y;
        return abs(id) < abs(_.id);
    }
};
int ne;
Node e[N * 5];
void ins(int lx, int rx, int ly, int ry) {
    e[++ne] = Node(lx, ly, 0);
    e[++ne] = Node(rx + 1, ly, -2);
    e[++ne] = Node(lx, ry + 1, -2);
    e[++ne] = Node(rx + 1, ry + 1, 0);
    return;
}
struct BIT{
    int n;
    int c[M];
    void init(int x) {
        n = x;
        for (int i = 1; i <= n; ++i) c[i] = 0;
    }
    void Add(int x, int k) {
        for (; x <= n; x += -x & x) c[x] += k;
    }
    int Ask(int x) {
        int k = 0;
        for (; x; x -= -x & x) k += c[x];
        return k;
    }
} zq;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b, m = a.size();
        int x = 0, y = m - 1;
        while (x < m && a[x] == b[x]) ++x;
        while (y >= 0 && a[y] == b[y]) --y;
        if (x == m) continue;
        int u = 0, v = 0;
        for (int j = x; j <= y; ++j) u = (1ll * u * base1 + a[j] - '0') % mod1, v = (1ll * v * base2 + a[j] - '0') % mod2;
        for (int j = x; j <= y; ++j) u = (1ll * u * base1 + b[j] - '0') % mod1, v = (1ll * v * base2 + b[j] - '0') % mod2;
        ll p = 1ll * u * mod2 + v;
        if (!mp.count(p)) mp[p] = ++cur;
        vec[mp[p]].emplace_back(i);
        for (int j = x - 1; j >= 0; --j) s1[i] += a[j];
        for (int j = y + 1; j < m; ++j) s2[i] += a[j];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> a >> b, m = a.size();
        if (b.size() != m) continue;
        int x = 0, y = m - 1;
        while (x < m && a[x] == b[x]) ++x;
        while (y >= 0 && a[y] == b[y]) --y;
        int u = 0, v = 0;
        for (int j = x; j <= y; ++j) u = (1ll * u * base1 + a[j] - '0') % mod1, v = (1ll * v * base2 + a[j] - '0') % mod2;
        for (int j = x; j <= y; ++j) u = (1ll * u * base1 + b[j] - '0') % mod1, v = (1ll * v * base2 + b[j] - '0') % mod2;
        ll p = 1ll * u * mod2 + v;
        if (!mp.count(p)) continue;
        cev[mp[p]].emplace_back(i);
        for (int j = x - 1; j >= 0; --j) t1[i] += a[j];
        for (int j = y + 1; j < m; ++j) t2[i] += a[j];
    }
    for (int i = 1; i <= cur; ++i) if (!cev[i].empty()) {
        init();
        for (int id : vec[i]) ins(s1[id], ix1[id]);
        for (int id : cev[i]) ins(t1[id], ix2[id]);
        dfs(1);
        for (int id : vec[i]) lx[id] = dfn[ix1[id]], rx[id] = dfn[ix1[id]] + siz[ix1[id]] - 1;
        for (int id : cev[i]) vx[id] = dfn[ix2[id]];
        init();
        for (int id : vec[i]) ins(s2[id], ix1[id]);
        for (int id : cev[i]) ins(t2[id], ix2[id]);
        dfs(1);
        for (int id : vec[i]) ly[id] = dfn[ix1[id]], ry[id] = dfn[ix1[id]] + siz[ix1[id]] - 1;
        for (int id : cev[i]) vy[id] = dfn[ix2[id]];
        ne = 0;
        for (int id : vec[i]) ins(lx[id], rx[id], ly[id], ry[id]);
        for (int id : cev[i]) e[++ne] = Node(vx[id], vy[id], id);
        sort(e + 1, e + ne + 1), zq.init(tot);
        for (int i = 1; i <= ne; ++i) {
            if (e[i].id <= 0) zq.Add(e[i].y, e[i].id + 1);
            else ans[e[i].id] += zq.Ask(e[i].y);
        }
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    return 0;
}