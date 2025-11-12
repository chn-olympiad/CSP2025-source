#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2e6 + 5;
int n, m, k;
int tot;
struct Edge {
  int u, v, w;
} e[N], f[N], g[N], h[N];
bool operator < (Edge A, Edge B) { return A.w < B.w; }
int cost[N];

struct DSU {
  int f[N];
  void init(int n) { iota(f + 1, f + n + 1, 1); }
  int find(int u) {
    while (u != f[u])
      u = f[u] = f[f[u]];
    return u;
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    f[v] = u;
  }
} d;

int type[N];

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    auto& [u, v, w] = e[i];
    cin >> u >> v >> w;
  }
  sort(e + 1, e + m + 1);
  d.init(n);
  vector<pair<Edge, int>> E;
  for (int i = 1; i <= m; i++) {
    if (d.find(e[i].u) != d.find(e[i].v)) {
      d.merge(e[i].u, e[i].v);
      // f[++tot] = e[i];
      E.push_back({e[i], -1});
    }
  }
  for (int i = 1; i <= k; i++) {
    cin >> cost[i];
    for (int j = 1; j <= n; j++) {
      int w; cin >> w;
      E.push_back({{n + i, j, w}, i});
    }
  }
  sort(E.begin(), E.end());
  // cerr << "time = " << clock() * 1e3 / CLOCKS_PER_SEC << " ms\n";
  ll ans = 1e18;

  for (int S = 0; S < 1 << k; S++) {
    ll res = 0;
    for (int i = 1; i <= k; i++) {
      if (S >> (i - 1) & 1) {
        res += cost[i];
      }
    }
    // int cnt = 0;
    // for (auto [edge, i] : E) {
    //   if (S >> (i - 1) & 1) {
    //     g[++cnt] = edge;
    //   }
    // }
    // merge(f + 1, f + tot + 1, g + 1, g + cnt + 1, h + 1);
    d.init(n + k);
    for (auto [edge, i] : E) {
      if (i != -1 && !(S >> (i - 1) & 1)) continue;
      auto [u, v, w] = edge;
      if (d.find(u) != d.find(v)) {
        d.merge(u, v);
        res += w;
      }
    }
    ans = min(ans, res);
  }
  cout << ans << "\n";
  // cerr << "time = " << clock() * 1e3 / CLOCKS_PER_SEC << " ms\n";
}
// g++ -o road road.cpp -O2 -std=c++14 -fsanitize=undefined