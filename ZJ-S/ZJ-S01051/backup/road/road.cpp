#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;
using i64 = long long;

constexpr int N = 1e4 + 7;
constexpr int M = 1.3e6;

int n, m, k, t, a[N];
struct edge { int u, v, w; } e[M];

int fa[N * 2];

int find(int i) {
  if (fa[i] == i) return fa[i];
  else return fa[i] = find(fa[i]);
}

signed main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i ++) 
    cin >> e[i].u >> e[i].v >> e[i].w;

  for (int i = 1; i <= n; i ++) fa[i] = i;

  sort (e + 1, e + m + 1, [](edge u, edge v) {
    return u.w < v.w;
  });

  int cnt = 0;
  i64 ans = 0;

  for (int i = 1; i <= m; i ++) {
    int u = e[i].u, v = e[i].v;
    if (find(u) == find(v)) continue;
    fa[find(u)] = fa[find(v)];
    cnt ++;
    ans += e[i].w;
    if (cnt == n - 1) break;
  }

  cout << ans << '\n';
  return 0;
}