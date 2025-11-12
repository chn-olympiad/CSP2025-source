#include <bits/stdc++.h>

using ll = long long;

struct Typewriter {
  int u;
  int v;
  int w;
  
  Typewriter(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) { }
  
  bool operator<(Typewriter c) const { return w < c.w; }
};

struct Muelsyse {
  std::vector<int> f;
  std::vector<int> s;
  
  Muelsyse(int n) {
    f.resize(n);
    s.assign(n, 1);
    std::iota(f.begin(), f.end(), 0);
  }
  
  int root(int x) { return f[x] == x ? x : f[x] = root(f[x]); }
  
  void link(int x, int y) {
    int u = root(x);
    int v = root(y);
    if (u == v) return;
    if (s[u] > s[v]) std::swap(u, v);
    f[u] = v;
    s[u] = s[v] = s[u] + s[v];
  }
};

void Advotya() {
  int n; std::cin >> n;
  int m; std::cin >> m;
  int k; std::cin >> k;
  std::vector<int> c(k);
  std::vector<Typewriter> e(m);
  std::vector<std::vector<Typewriter>> a(k + 1);
  ll tar = 0;
  for (int i = 0; i < m; ++i) {
    std::cin >> e[i].u >> e[i].v >> e[i].w; 
    --e[i].u;
    --e[i].v; 
  }
  for (int i = 0; i < k; ++i) {
    std::cin >> c[i];
    for (int j = 0; j < n; ++j) {
      int w; std::cin >> w;
      a[i].emplace_back(n + i, j, w);
    }
    std::stable_sort(a[i].begin(), a[i].end());
  }
  std::stable_sort(e.begin(), e.end());
  Muelsyse dsu(n);
  std::vector<Typewriter> origin;
  for (auto i : e) {
    if (dsu.root(i.u) == dsu.root(i.v)) continue;
    dsu.link(i.u, i.v);
    a[k].emplace_back(i.u, i.v, i.w);
    tar += i.w;
  }
  for (int i = 0; i <= k; ++i) a[i].emplace_back(-1, -1, 2e9);
  for (int i = 1; i < (1 << k); ++i) {
    std::vector<int> p;
    std::vector<int> loc(k + 1);
    int cnt = n - 1;
    ll ret = 0;
    for (int j = 0; j < k; ++j) {
      if (((i >> j) & 1) != 0) {
        p.push_back(j);
        ++cnt;
        ret += c[j];
      }
    }
    Muelsyse dsu(n + k);
    while (cnt != 0) {
      int best = k;
      for (int j = 0; j < p.size(); ++j) {
        if (a[p[j]][loc[p[j]]].w  < a[best][loc[best]].w) best = p[j];
      }
      int u = a[best][loc[best]].u;
      int v = a[best][loc[best]].v;
      int w = a[best][loc[best]].w;
      ++loc[best];
      if (dsu.root(u) != dsu.root(v)) {
        dsu.link(u, v);
        ret += w;
        --cnt;
      }
    }
    tar = std::min(tar, ret);
  }
  std::cout << tar << "\n";
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  Advotya();
  return 0;
}

