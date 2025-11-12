#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
void rd(T &x) {
  T f = 0; x = 0; char ch = getchar();
  while (ch < '0' || ch > '9') if (ch == '-') f = -1;
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
}
const int N = 2e4 + 100, M = 1e6 + 10;
int n, m, k, c[N], a[11][N], ans = 1e18;
struct edges {
  int u, v, w;
  bool operator< (const edges x) const {
    return w < x.w;
  }
} e[M + N * 11];
int tot, fa[N];
bool ban[N];
int find(int x) {
  return ((x == fa[x]) ? x : (fa[x] = find(fa[x])));
}
signed main() {
  // double st = clock();
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  // scanf("%lld%lld%lld", &n, &m, &k);
  rd(n), rd(m), rd(k);
  for (int i = 1, u, v, w; i <= m; ++i) {
    // scanf("%lld%lld%lld", &u, &v, &w);
    rd(u), rd(v), rd(w);
    e[++tot] = {u, v, w};
  }
  for (int i = 1; i <= k; ++i) {
    // scanf("%lld", &c[i]);
    rd(c[i]);
    for (int j = 1; j <= n; ++j) rd(a[i][j]), e[++tot] = {n + i, j, a[i][j]};
  }
  sort(e + 1, e + tot + 1);
  for (int i = 0; i < (1 << k); ++i) {
    int now = 0, cnt = 0, fw = n;
    for (int j = 1; j <= k; ++j) {
      if ((i >> (j - 1)) & 1) ban[n + j] = 1;
      else ban[n + j] = 0, now += c[j], fw++;
    }
    iota(fa + 1, fa + n + k + 1, 1);
    for (int j = 1; j <= tot; ++j) {
      int u = e[j].u, v = e[j].v, w = e[j].w;
      if (ban[u] || ban[v]) continue;
      int fu = find(u), fv = find(v);
      if (fu == fv) continue;
      now += w, fa[fu] = fv;
      cnt++;
      if (cnt == fw - 1) break;
    }
    ans = min(ans, now);
  }
  printf("%lld\n", ans);
  // cerr << (double)((double)clock() - st) / CLOCKS_PER_SEC << endl;
}
/*
1.349
1.411
0.327
what should i do???

but <1s after quick read

wan dan le bu hui Prim
Ahhhhhh!!!
*/