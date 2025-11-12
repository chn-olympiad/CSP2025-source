#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;

struct Edge {
    int u, v; ll w;
    bool operator<(const Edge &_) const {
        return w < _.w;
    }
};
vector<Edge> e;

int c[11];

// 对于不需要建造乡村的，直接跑 kruskal 即可过了
namespace solve1 {
struct Edge {
    int u, v; ll w;
    bool operator<(const Edge &_) const {
        return w < _.w;
    }
};

ll ans;
vector<int> fa;
// vector<int> sz;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void kruskal() {
    sort(e.begin(), e.end());
    for (auto [u, v, w] : e) {
        int x = find(u), y = find(v);
        if (x == y) { continue; }
        fa[y] = x;
        ans += w;
    }
}
void solve() {
    e.resize(m);
    fa.resize(n);
    // sz.resize(n);
    iota(fa.begin(), fa.end(), 0);
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    kruskal();
    cout << ans << endl;
}
}

// 对于特殊性质 A 另外求解
// 直接建边
namespace solve2{
vector<Edge> e;
ll ans;
vector<int> fa;
// vector<int> sz;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void kruskal() {
    sort(e.begin(), e.end());
    for (auto [u, v, w] : e) {
        int x = find(u), y = find(v);
        if (x == y) { continue; }
        fa[y] = x;
        ans += w;
    }
}
vector<vector<ll> > mat;
void solve() {
    e.resize(m+(n*(n-1)/2));
    fa.resize(n);
    // sz.resize(n);
    vector<vector<ll> >(n+1, vector<ll>(n+1, 0x3f3f3f3f)).swap(mat);
    mat.resize(n);
    iota(fa.begin(), fa.end(), 0);
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    int cnt = m;
    for (int i = 1; i <= k; ++i) {
        // cerr << "#################### I'm Running on " << i << " ###############################" << endl;
        cin >> c[i];
        vector<ll> tmp(n+1);
        for (int j = 1; j <= n; ++j) {
            cin >> tmp[j];
        }
        for (int x = 1; x <= n; ++x) {
            for (int y = x+1; y <= n; ++y) {
                mat[x][y] = mat[y][x] = min(mat[x][y], tmp[x] + tmp[y]);
            }
        }
    }
    // cerr << "################################################# Im running ##############################################################" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            e[cnt++] = {i, j, mat[i][j]};
        }
    }
    kruskal();
    cout << ans << endl;    
}
};

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    if (k == 0) {
        return solve1::solve(), 0;
    }

    solve2::solve();


    return 0;
}