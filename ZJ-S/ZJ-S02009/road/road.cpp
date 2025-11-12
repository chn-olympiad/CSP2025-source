#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int N = 10010;
constexpr i64 inf = 1E16;

struct DSU {
  int p[N];
  DSU(int n) {
    init(n);
  }
  void init(int n) {
    std::iota(p, p + n, 0);
  }
  int find(int x) {
    if (p[x] != x) {
      p[x] = find(p[x]);
    }
    return p[x];
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
      return false;
    }
    p[u] = v;
    return true;
  }
};

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m, k;
  std::cin >> n >> m >> k;

  const int N = n + k;

  std::vector<std::array<int, 3>> e(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--;
    v--;
    e[i] = {w, u, v};
  }
  std::sort(e.begin(), e.end());

  std::vector<int> c(k);
  std::vector<std::vector<std::array<int, 3>>> a(k);
  for (int i = 0; i < k; i++) {
    std::cin >> c[i];
    for (int j = 0; j < n; j++) {
      int w;
      std::cin >> w;
      a[i].push_back({w, j, i + n});
    }
    std::sort(a[i].begin(), a[i].end());
  }

  DSU dsu(n);
  std::vector<std::array<int, 3>> f;
  for (auto [w, u, v] : e) {
    if (dsu.merge(u, v)) {
      f.push_back({w, u, v});
    }
  }

  auto merge = [&](std::vector<std::array<int, 3>> f, std::vector<std::array<int, 3>> g) {
    dsu.init(N);
    int n = f.size(), m = g.size();
    int i = 0, j = 0;
    std::vector<std::array<int, 3>> h;
    while (i < n || j < m) {
      if (i < n && (j == m || f[i][0] < g[j][0])) {
        if (dsu.merge(f[i][1], f[i][2])) {
          h.push_back(f[i]);
        }
        i++;
      } else {
        if (dsu.merge(g[j][1], g[j][2])) {
          h.push_back(g[j]);
        }
        j++;
      }
    }
    return h;
  };

  i64 ans = inf;
  auto dfs = [&](auto self, int x, i64 w, std::vector<std::array<int, 3>> f) -> void {
    if (x == k) {
      for (auto [c, _, __] : f) {
        w += c;
      }
      ans = std::min(ans, w);
      return;
    }
    self(self, x + 1, w, f);
    self(self, x + 1, w + c[x], merge(f, a[x]));
  };
  dfs(dfs, 0, 0, f);

  std::cout << ans << "\n";

  return 0;
}