#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
using ll = long long;
constexpr int N = 1e4 + 15, M = 1e6 + 15;
constexpr ll inf = 1e18;
struct Edge {
  int u, v;
  ll w;
} E[M], C[M];
int fa[N], n, m, k, top;
ll a[12][N], c[N];
inline int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  fo(i, 1, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    E[i] = {u, v, w};
  }
  fo(i, 1, k) {
    cin >> c[i];
    fo(j, 1, n) cin >> a[i][j];
  }
  fo(i, 1, n + k) fa[i] = i;
  sort(E + 1, E + m + 1, [](Edge a, Edge b) {
    return a.w < b.w;
  });
  fo(i, 1, m) {
    int u = E[i].u, v = E[i].v;
    ll w = E[i].w;
    if (find(u) == find(v))
      continue;
    C[++top] = {u, v, w};
    fa[find(u)] = find(v);
  }
  ll ans = inf;
  fo(i, 0, (1 << k) - 1) {
    int tp2 = 0;
    fo(i, 1, n - 1) E[++tp2] = C[i];
    ll res = 0;
    fo(j, 1, k) {
      if ((i >> (j - 1)) & 1) {
        res += c[j];
        fo(u, 1, n)
        E[++tp2] = {u, j + n, a[j][u]};
      }
    }
    fo(j, 1, n + k) fa[j] = j;
    sort(E + 1, E + tp2 + 1, [](Edge a, Edge b) {
      return a.w < b.w;
    });
    fo(j, 1, tp2) {
      int u = E[j].u, v = E[j].v;
      ll w = E[j].w;
      if (find(u) == find(v))
        continue;
      fa[find(u)] = find(v);
      res += w;
    }
    ans = min(ans, res);
  }
  cout << ans;
}

