#include <bits/stdc++.h>
#define endl '\n'
// using std::endl;
using i32 = int;
using i64 = long long;
using p32 = std::pair<i32, i32>;
const i64 inf64 = 2e18;
void solve(i32 _);
signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  i32 T = 1;
  // std::cin >> T;
  for (i32 i = 1; i <= T; i++) solve(i);
}
struct node {
  i32 u, v, w;
  bool operator<(const node &y) const {
    return w == y.w ? (u == y.u ? v < y.v : u < y.u) : w < y.w;
  }
};
struct DSU {
  std::vector<i32> pre, siz;
  void reset() {
    for (i32 i = 1; i < pre.size(); i++) pre[i] = i, siz[i] = 1;
  }
  DSU(i32 n) {
    pre.resize(n + 2), siz.resize(n + 2);
    reset();
  }
  inline i32 root(i32 x) {
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
  }
  inline bool check(i32 x, i32 y) {
    return root(x) == root(y);
  }
  inline void merge(i32 x, i32 y) {
    if (check(x, y)) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pre[root(x)] = root(y);
    siz[y] += siz[x];
  }
};
i32 a[15][10005];
i32 c[15];
DSU pre(10100);
void solve(i32 _) {
  i32 n, m, k;
  i64 ans = 0;
  std::set<node> st;
  pre.reset();
  std::cin >> n >> m >> k;
  for (i32 i = 1, u, v, w; i <= m; i++) {
    std::cin >> u >> v >> w;
    st.insert({u, v, w});
  }
  std::set<node> g;
  for (auto it = st.begin(); it != st.end(); it++) {
    if (pre.check(it->u, it->v)) continue;
    else pre.merge(it->u, it->v), ans += it->w, g.insert({it->u, it->v, it->w});
  }
  for (i32 i = 1; i <= k; i++) {
    std::cin >> c[i];
    for (i32 j = 1; j <= n; j++) std::cin >> a[i][j];
  }
  for (i32 i = 0; i < (1 << k); i++) {
    i32 t = __builtin_popcount(i);
    i64 tmp = 0;
    for (i32 j = 0; j < k; j++) {
      if ((i >> j) & 1 > 0) {
        tmp += c[j + 1];
        for (i32 l = 1; l <= n; l++) g.insert({j + n + 1, l, a[j + 1][l]});
      }
    }
    // std::cerr << tmp << endl;
    i32 cnt = 0;
    pre.reset();
    // std::cerr << g.size() << endl;
    for (auto it = g.begin(); it != g.end(); it++) {
      if (pre.check(it->u, it->v)) continue;
      else pre.merge(it->u, it->v), tmp += it->w, cnt++;
      // if (cnt >= n + t - 1) break;
    }
    ans = std::min(ans, tmp);
    for (i32 j = 0; j < k; j++) {
      if ((i >> j) & 1 > 0) {
        for (i32 l = 1; l <= n; l++) g.erase({j + n + 1, l, a[j + 1][l]});
      }
    }
  }
  std::cout << ans << endl;
}
// g++ road.cpp -o road -O2 -static -std=c++14