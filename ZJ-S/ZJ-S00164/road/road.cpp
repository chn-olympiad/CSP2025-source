#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e4 + 55;
constexpr int K = 10;
constexpr int M = 1e6 + 5;

int n, m, k, c[K], to[K][N], fa[N], cnte;

ll ans;

ll anss;

tuple<int, int, int> e[M], reale[M];

template <typename T>
int read(T& u) {
  u = 0;
  char ch = getchar();
  bool neg = false;
  for (; !isdigit(ch); ch = getchar()) {
    neg |= (ch == '-');
  }
  for (; isdigit(ch); ch = getchar()) {
    u = u * 10 + (ch & 15);
  }
  if (neg) u = -u;
  return u;
}

void init() {
  for (int i = 1; i <= n + k; ++i) fa[i] = -1;
}

int find(int x) {
  return fa[x] < 0 ? x : fa[x] = find(fa[x]);
}

inline bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  if (fa[u] > fa[v]) swap(u, v);
  fa[u] += fa[v], fa[v] = u;
  return true;
}

int main() {
  assert(freopen("road.in", "r", stdin));
  assert(freopen("road.out", "w", stdout));
  // cin.tie(nullptr)->sync_with_stdio(false);
  read(n), read(m), read(k);
  // cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= m; ++i) {
    read(u), read(v), read(w);
    // cin >> u >> v >> w;
    e[i] = make_tuple(w, u, v);
  }
  sort(e + 1, e + m + 1);
  for (int i = 0; i < k; ++i) {
    read(c[i]);
    // cin >> c[i];
    for (int j = 1; j <= n; ++j) {
      read(to[i][j]);
      // cin >> to[i][j];
    }
  }
  init();
  for (int i = 1; i <= m; ++i) {
    int w = get<0>(e[i]), u = get<1>(e[i]), v = get<2>(e[i]);
    if (merge(u, v)) {
      ans += w;
      e[++cnte] = e[i];
    }
  }
  for (int i = 1; i < (1 << k); ++i) {
    for (int j = 1; j < n; ++j) {
      reale[j] = e[j];
    }
    int d = n - 1;
    anss = 0;
    cnte = n - 1;
    for (int j = 0; j < k; ++j) {
      if (i >> j & 1) {
        ++d;
        anss += c[j];
        for (int x = 1; x <= n; ++x) {
          reale[++cnte] = make_tuple(to[j][x], j + n + 1, x);
        }
      }
    }
    sort(reale + 1, reale + cnte + 1);
    init();
    for (int i = 1; i <= cnte; ++i) {
      int w = get<0>(reale[i]), u = get<1>(reale[i]), v = get<2>(reale[i]);
      if (merge(u, v)) {
        anss += w;
        if (--d == 0) break;
      }
    }
    ans = min(ans, anss);
  }
  cout << ans;
  return 0;
}