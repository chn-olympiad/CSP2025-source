#include <algorithm>
#include <cstdio>
#include <cctype>
#include <vector>
#include <utility>
using ll = long long;
using PILL = std::pair<int, ll>;
int read() {
  static int x; static char c; x = 0;
  while (!isdigit(c = getchar()));
  while (isdigit(c)) x = 10 * x + c - 48, c = getchar();
  return x;
}
constexpr int M = 1100003;
struct DisjointSet {
  int fa[10013];
  void init(int n) {
    for (int i = 1; i <= n; ++i) fa[i] = i;
  }
  int find(int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
  }
  void merge(int u, int v) {
    fa[find(u)] = find(v);
  }
} djs;

struct Edge {
  int u, v; ll w;
} e[M];
std::vector<PILL> g[10003];
ll wmax[10003];
ll c[13], a[13][10013];
bool mrk[10013];
int main() {
#ifdef _tqx
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#else
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
#endif
  int n, m, k; n = read(), m = read(), k = read();
  djs.init(n + k);
  for (int i = 1; i <= m; ++i) {
    e[i].u = read(), e[i].v = read(), e[i].w = read();
  }
  // for (int i = 1; i <= n; ++i) {
  //   std::sort(g[i].begin(), g[i].end(), [](PILL& a, PILL& b) {
  //     return a.first < b.first;
  //   });
  // }
  bool f = true;
  int mm = m;
  for (int i = 1; i <= k; ++i) {
    c[i] = read();
    f &= !c[i];
    bool ff = false;
    for (int j = 1; j <= n; ++j) {
      a[i][j] = read();
      e[++m] = {n + i, j, a[i][j]};
      ff |= !a[i][j];
    }
    f &= ff;
    // int cnt = 0;
    // for (int u = 1; u <= n; ++u) {
    //   // if (c[i] + a[i][u] > wmax[u]) continue;
    //   ll tmp = 0;
    //   bool f = false;
    //   for (PILL p : g[u]) {
    //     int v = p.first; ll w = p.second;
    //     // printf("%lld %lld\n", a[i][v], w);
    //     if (w >= a[i][v]) tmp += w - a[i][v], f = mrk[v] = true, ++cnt;
    //   }
    //   if (f) mrk[u] = true;
    // }
    // if (cnt < 2) continue;
    // printf("%lld\n", ans);
    // ll cur = ans;
    // for (int u = 1; u <= n; ++u) {
    //   if (mrk[u]) {
    //     for (PILL p : g[u]) {
    //       if (p.first < u) continue;
    //       if (mrk[p.first]) ans -= p.second;
    //     }
    //     ans += a[i][u];
    //   }
    // }
    // ans += c[i];
    // printf("%lld\n", ans);
    // puts("");
    // if (ans > cur) ans = cur;
    // for (int j = 1; j <= n; ++j) mrk[j] = false;
  }
  if (f) {
    std::sort(e + 1, e + m + 1, [](Edge& a, Edge& b) {
      return a.w < b.w;
    });
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
      if (djs.find(e[i].u) == djs.find(e[i].v)) continue;
      ans += e[i].w;
      // wmax[e[i].u] = std::max(wmax[e[i].u], e[i].w);
      // wmax[e[i].v] = std::max(wmax[e[i].v], e[i].w);
      // g[e[i].u].emplace_back(e[i].v, e[i].w);
      // g[e[i].v].emplace_back(e[i].u, e[i].w);
      djs.merge(e[i].u, e[i].v);
    }
    printf("%lld\n", ans);
  } else {
    m = mm;
    std::sort(e + 1, e + m + 1, [](Edge& a, Edge& b) {
      return a.w < b.w;
    });
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
      if (djs.find(e[i].u) == djs.find(e[i].v)) continue;
      ans += e[i].w;
      wmax[e[i].u] = std::max(wmax[e[i].u], e[i].w);
      wmax[e[i].v] = std::max(wmax[e[i].v], e[i].w);
      g[e[i].u].emplace_back(e[i].v, e[i].w);
      g[e[i].v].emplace_back(e[i].u, e[i].w);
      djs.merge(e[i].u, e[i].v);
    }
    for (int i = 1; i <= k; ++i) {
      int cnt = 0;
      for (int u = 1; u <= n; ++u) {
        if (c[i] + a[i][u] > wmax[u]) continue;
        ll tmp = 0;
        bool f = false;
        for (PILL p : g[u]) {
          int v = p.first; ll w = p.second;
          // printf("%lld %lld\n", a[i][v], w);
          if (w >= a[i][v]) tmp += w - a[i][v], f = mrk[v] = true, ++cnt;
        }
        if (f) mrk[u] = true;
      }
      if (cnt < 2) continue;
      ll cur = ans;
      for (int u = 1; u <= n; ++u) {
        if (mrk[u]) {
          for (PILL p : g[u]) {
            if (p.first < u) continue;
            if (mrk[p.first]) ans -= p.second;
          }
          ans += a[i][u];
        }
      }
      ans += c[i];
      if (ans > cur) ans = cur;
      for (int j = 1; j <= n; ++j) mrk[j] = false;
    }
    printf("%lld\n", ans);
  }
  return 0;
}