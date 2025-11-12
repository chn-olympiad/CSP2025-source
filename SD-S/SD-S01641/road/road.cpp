#include <bits/stdc++.h>
using namespace std;

struct Dsu {
  vector<size_t> par, siz;

  Dsu(size_t size) : par(size), siz(size, 1) {
    iota(par.begin(), par.end(), 0);
  }

  size_t getf(size_t x) {
    while (x != par[x])
      x = par[x] = par[par[x]];
    return x;
  }

  bool merge(size_t x, size_t y) {
    x = getf(x), y = getf(y);
    if (x == y)
      return false;
    if (siz[x] > siz[y])
      swap(x, y);
    par[x] = y, siz[y] += siz[x];
    return true;
  }
};

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.badbit | cin.failbit);
  size_t n, m, k;
  cin >> n >> m >> k;

  vector<tuple<uint32_t, size_t, size_t>> edges;
  edges.reserve(m);
  for (size_t i = 0; i < m; ++i) {
    size_t u, v;
    uint32_t w;
    cin >> u >> v >> w, --u, --v;
    edges.emplace_back(w, u, v);
  }
  sort(edges.begin(), edges.end());

  vector<vector<uint32_t>> villages(k);
  for (size_t i = 0; i < k; ++i) {
    villages[i].resize(n + 1);
    cin >> villages[i].back();
    for (size_t j = 0; j < n; ++j)
      cin >> villages[i][j];
  }

  uint64_t best_cost = 0;

  Dsu dsu(n + k);
  vector<tuple<uint32_t, size_t, size_t>> key_edges;
  key_edges.reserve(n - 1);
  for (size_t i = 0; i < m; ++i)
    if (dsu.merge(get<1>(edges[i]), get<2>(edges[i])))
      key_edges.push_back(edges[i]), best_cost += get<0>(edges[i]);

  for (uint32_t o = 1; o < (1u << k); ++o) {
    uint64_t cost = 0;

    auto v_edges = key_edges;
    v_edges.reserve(n * (__builtin_popcount(o) + 1));

    for (size_t i = 0; i < k; ++i) {
      if ((o >> i) & 1) {
        cost += villages[i].back();
        for (size_t j = 0; j < n; ++j)
          v_edges.emplace_back(villages[i][j], j, n + i);
      }
    }

    if (cost >= best_cost)
      continue;

    Dsu v_dsu(n + k);
    sort(v_edges.begin(), v_edges.end());
    for (size_t i = 0; i < v_edges.size(); ++i)
      if (v_dsu.merge(get<1>(v_edges[i]), get<2>(v_edges[i])))
        cost += get<0>(v_edges[i]);

    best_cost = min(best_cost, cost);
  }

  cout << best_cost << '\n';
  return 0;
}

