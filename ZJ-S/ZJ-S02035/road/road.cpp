#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Dsu {
  vector<int> fa;
  void init(int n) {
    fa.resize(n);
    for (int i = 0; i < n; i++) fa[i] = i;
  }
  int get(int x) {
    if (fa[x] == x) return x;
    return fa[x] = get(fa[x]);
  }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    fa[y] = x;
    return true;
  }
} dsu;

int take_tree(int n, vector<tuple<int, int, int>> *edges) {
  vector<tuple<int, int, int>> filtered_edges;
  dsu.init(n);
  int sum = 0;
  for (auto [w, u, v] : *edges)
    if (dsu.merge(u, v)) {
      filtered_edges.emplace_back(w, u, v);
      sum += w;
    }
  swap(*edges, filtered_edges);
  return sum;
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<int, int, int>> edges(m);
  for (auto &[w, u, v] : edges) cin >> u >> v >> w, --u, --v;
  sort(edges.begin(), edges.end());
  int ans = take_tree(n, &edges);

  vector<int> cost(k);
  for (int i = 0; i < k; i++) {
    cin >> cost[i];
    for (int j = 0; j < n; j++) {
      int w;
      cin >> w;
      edges.emplace_back(w, n + i, j);
    }
  }
  sort(edges.begin(), edges.end());
  vector<int> ban(n + k);
  for (int mask = 0; mask < (1 << k); mask++) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
      if (mask >> i & 1) {
        sum += cost[i];
        ban[n + i] = false;
      } else {
        ban[n + i] = true;
      }
    }
    dsu.init(n + k);
    for (auto [w, u, v] : edges) {
      if (ban[u]) continue;
      if (dsu.merge(u, v)) sum += w;
    }
    ans = min(ans, sum);
  }
  cout << ans << "\n";
  return 0;
}
