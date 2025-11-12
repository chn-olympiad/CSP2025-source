#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define bug(x) cerr << __LINE__ << ":" << (#x) << "=" << (x) << endl;
#define del cerr << endl;
#define int ll
using namespace std;
int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') w = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
const int N = 1e4 + 10;
struct DSU {
    int fa[N];
    DSU(const int& n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }
    int find(const int& x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }
    void merge(const int& x, const int& y) {
        if (find(x) != find(y)) {
            fa[find(x)] = find(y);
        }
    }
};
struct Edge {
    int u, v, w, tag, c;
    bool operator< (const Edge& x) const {
        return w < x.w;
    }
};
vector<Edge> e;
int n, m, k;
int inp[N];
int kruskal() {
    DSU dsu(n);
    bitset<N * N> vis;
    sort(e.begin(), e.end());
    int ans = 0;
    for (auto x : e) {
        int u = x.u, v = x.v, w = x.w, tag = x.tag;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
            if (tag) {
                if (vis[tag]) {
                    ans -= x.c;
                }
                vis[tag];
            }
//            bug(w);
            ans += w;
        }
    }
    return ans;
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        e.emplace_back(Edge{u, v, w, 0, 0});
//        e.emplace_back(Edge{v, u, w});
    }
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        int c = read();
        for (int j = 1; j <= n; j++) {
            inp[j] = read();
        }
        for (int j = 1; j < n; j++) {
            for (int l = i + 1; l <= n; l++) {
                e.emplace_back(Edge{j, l, inp[j] + inp[l] + c, ++cnt, c});
//                e.emplace_back(Edge{l, j, inp[j] + inp[l] + c});
            }
        }
    }
    write(kruskal()); putchar('\n');
//    cout << kruskal() << endl;
    return 0;
}

