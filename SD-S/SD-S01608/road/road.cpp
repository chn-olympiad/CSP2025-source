#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N = 1e4 + 20, M = 2e6 + 10, Inf = 0x3f3f3f3f3f3f3f3f;
signed n, m, k;
struct Edge {
  int u, v, nxt, w;
} e[M << 1];
signed hd[N], tot;
int ans = Inf;
int c[N];
bool flg = 1;
void add(int u, int v, int w) {
  e[++ tot] = {u, v, hd[u], w};
  hd[u] = tot;
}
int f[N];
int d[N];
int vis[N];
int find(int x) {
  if (x == f[x]) {
    return x;
  }
  return f[x] = find(f[x]);
}
void dfs(int x, int res) {
  if (x > k) {
    for (int i = 1; i <= n + k; ++ i) {
      f[i] = i;
      d[i] = 0;
    }
    for (int i = 1; i <= tot; ++ i) {
      if (find(e[i].u) == find(e[i].v)) {
        continue;
      }
      if (vis[e[i].v]) {
        continue;
      }
      f[find(e[i].u)] = find(e[i].v);
      res += e[i].w;
      ++ d[e[i].u];
      ++ d[e[i].v];
    }
    for (int i = 1; i <= k; ++ i) {
      if (d[i + n] == 1) {
        res -= c[i + n];
      }
    }
    for (int i = 1; i <= n; ++ i) {
      if (!d[i]) {
        return ;
      }
    }
    ans = min(ans, res);
    return ; 
  }
  dfs(x + 1, res + c[x + n]);
  vis[x + n] = 1;
  dfs(x + 1, res);
  vis[x] = 0;
}
signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= m; ++ i) {
    cin >> u >> v >> w;
    add(u, v, w);
  }
  for (int i = 1; i <= k; ++ i) {
    cin >> c[i + n];
    flg &= !c[i + n];
    for (int j = 1, a; j <= n; ++ j) {
      cin >> a;
      add(j, i + n, a);
    }
  }
  for (int i = 1; i <= n + k; ++ i) {
    f[i] = i;
  }
  if (flg) {
    ans = 0;
    sort(e + 1, e + tot + 1, [&](Edge x, Edge y) {
      return x.w < y.w;
    });
    for (int i = 1; i <= tot; ++ i) {
      if (find(e[i].u) == find(e[i].v)) {
        continue;
      }
      f[find(e[i].u)] = find(e[i].v);
      ans += e[i].w;
      ++ d[e[i].v];
    }
    for (int i = 1; i <= k; ++ i) {
      if (d[i + n] == 1) {
        ans -= c[i + n];
      }
    }
    cout << ans << endl;
    return 0; 
  }
  sort(e + 1, e + tot + 1, [&](Edge x, Edge y) {
    return x.w < y.w;
  });
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}


