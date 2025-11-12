#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 15, M = 1e6 + 10;

int n, m, k, c[10], a[10][N], f[N], cnt[1024];
bool vi[M];

struct Node { int u, v; ll w; } e_[M], e[1024][N << 1];
int fd(int x) { return x == f[x] ? x : f[x] = fd(f[x]); }

signed main() {

  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);

  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i ++)
    scanf("%d%d%lld", &e_[i].u, &e_[i].v, &e_[i].w);
  sort(e_ + 1, e_ + m + 1, [&](Node x, Node y) { return x.w < y.w; });

  iota(f, f + n + 1, 0);
  for (int i = 1; i <= m; i ++) {
    int u = e_[i].u, v = e_[i].v;
    if (fd(u) ^ fd(v)) vi[i] = 1, f[fd(u)] = fd(v);
  }

  for (int i = 1; i <= m; i ++)
    if (vi[i]) e[0][++ cnt[0]] = e_[i];

  for (int i = 0; i < k; i ++) {
    scanf("%d", &c[i]);
    for (int j = 1; j <= n; j ++)
      scanf("%d", &a[i][j]);
  }
  
  ll ans = 1e18;
  for (int s = 0; s < (1 << k); s ++) {
    if (s != 0) {
      int d = __lg(s & -s), t = s ^ (1 << d);
      cnt[s] = cnt[t];
      for (int i = 1; i <= cnt[t]; i ++)
        e[s][i] = e[t][i];
      for (int i = 1; i <= n; i ++)
        e[s][++ cnt[s]] = Node {i, n + d + 1, a[d][i]};
      sort(e[s] + 1, e[s] + cnt[s] + 1, [&](Node x, Node y) { return x.w < y.w; });
    }

    ll res = 0;
    for (int i = 0; i < k; i ++)
      if (s >> i & 1) res += c[i];

    iota(f, f + n + k + 1, 0);
    for (int i = 1; i <= cnt[s]; i ++) {
      int u = e[s][i].u, v = e[s][i].v; vi[i] = 0;
      if (fd(u) ^ fd(v)) vi[i] = 1, f[fd(u)] = fd(v), res += e[s][i].w;
    }

    int tmp = cnt[s]; cnt[s] = 0;
    for (int i = 1; i <= tmp; i ++)
      if (vi[i]) e[s][++ cnt[s]] = e[s][i];
    ans = min(ans, res);
  }

  printf("%lld\n", ans);
}