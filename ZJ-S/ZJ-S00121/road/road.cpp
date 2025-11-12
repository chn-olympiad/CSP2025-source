/*

[2025-11-1 16:07] 通过所有样例
用时：62min
疑似 tle
满数据 4.7s

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 10015;
int n, m, k;
int c[20];
int dis[20][N];
struct Edge {
    int u, v, w;
} ;
vector<Edge> vec;
struct DSU {
    int fa[N];
    int find(int u) {
        if(u == fa[u]) return u;
        return fa[u] = find(fa[u]);
    }
    void init(int n) {
        for(int i = 1; i <= n; i ++) {
            fa[i] = i;
        }
    }
    void merge(int fu, int fv) {
        fa[fu] = fv;
    }
} dsu;
vector<Edge> tree;
vector<Edge> ls;
int calc(vector<Edge> &vec, int sz) {
    dsu.init(n + k);
    int res = 0;
    sort(vec.begin(), vec.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    }) ;
    for(Edge i : vec) {
        int u = i.u;
        int v = i.v;
        int fu = dsu.find(u);
        int fv = dsu.find(v);
        if(fu == fv) continue;
        dsu.merge(fu, fv);
        res += i.w;
        sz --;
        if(sz == 1) break;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    dsu.init(n);
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        vec.push_back({u, v, w});
    }
    for(int i = 1; i <= k; i ++) {
        cin >> c[i];
        for(int j = 1; j <= n; j ++) {
            cin >> dis[i][j];
        }
    }
    sort(vec.begin(), vec.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    }) ;
    int ans = 0;
    for(Edge i : vec) {
        int u = i.u;
        int v = i.v;
        int fu = dsu.find(u);
        int fv = dsu.find(v);
        if(fu == fv) continue;
        dsu.merge(fu, fv);
        tree.push_back(i);
        ans += i.w;
    }
    for(int i = 1; i < (1 << k); i ++) {
        ls = tree;
        int res = 0;
        int sz = n;
        for(int j = 1; j <= k; j ++) {
            if((i >> (j - 1)) & 1) {
                res += c[j];
                sz ++;
                for(int l = 1; l <= n; l ++) {
                    ls.push_back({j + n, l, dis[j][l]});
                }
            }
        }
        res += calc(ls, sz);
        ans = min(ans, res);
    }
    cout << ans << "\n";
    return 0;
}