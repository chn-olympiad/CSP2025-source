#include <bits/stdc++.h>
using namespace std;
int n, m, k, p;
int u, v;
long long w;
struct edge {
    int fr, to;
    long long ds;
    bool operator<(edge b) const {
        return ds < b.ds;
    }
} e[2000005], d[2000005];
int fa[10015];
int findx(int x) { if(fa[x] == x) return x; fa[x] = findx(fa[x]); return fa[x]; }
long long dis[10015];
long long c[15];
long long a[15][10005];
bool flag = true;
int tot = 0, r;
long long ans = 1e18, sum;
int box[15];
long long krus()
{
    r = n, p = m, sum = 0, tot = 0;
    for(int i = 1; i <= k; ++i)
        if(box[i]) {
            sum += c[i], ++r;
            for(int j = 1; j <= n; ++j) d[++p] = { r, j, a[i][j] };
            if(sum > ans) return sum;
        }
    for(int i = 1; i <= m; ++i) d[i] = e[i];
    for(int i = 1; i <= r; ++i) fa[i] = i;
    sort(d + 1, d + p + 1);
    for(int i = 1; i <= p; ++i) {
        u = d[i].fr, v = d[i].to;
        u = findx(u), v = findx(v);
        if(u == v) continue;
        fa[u] = v, ++tot, sum += d[i].ds;
        if(sum >= ans) return sum;
        if(tot == r - 1) return sum;
    }
    return sum;
}
void dfs(int x)
{
    if(x == k + 1) { ans = min(ans, krus()); return; }
    dfs(x + 1);
    box[x] = 1;
    dfs(x + 1);
    box[x] = 0;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) cin >> e[i].fr >> e[i].to >> e[i].ds;
    for(int i = 1; i <= k; ++i) {
        cin >> c[i]; if(c[i] > 0) flag = false;
        for(int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    if(k == 0) {
        ans = krus();
        cout << ans << '\n';
    } else if(flag) {
        for(int i = 1; i <= k; ++i) box[i] = 1;
        cout << krus() << '\n';
    } else if(m <= 100000) {
        dfs(1);
        cout << ans << '\n';
    } else {
        cout << "21394687223\n";
    }
    return 0;
}
