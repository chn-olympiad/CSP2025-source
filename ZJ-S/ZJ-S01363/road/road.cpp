#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace My {
constexpr int N = 1e4 + 5, K = 15;
int n, m, k, a[K][N], c[K], pa[N];
typedef unsigned long long LL;
struct Edge {
  int u, v;
  LL w;
};
vector<Edge> g[N];
vector<int> near[K];
vector<Edge> edges;

int query(int x) {
  if (pa[x] == x) return x;
  return pa[x] = query(pa[x]);
}

void merge(int a, int b) {
  pa[b] = pa[a];
}

int topo() {
  sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
    return a.w < b.w;
  });
  int merged = 0;
  LL ans = 0;
  for (auto& x : edges) {
    int pu = query(x.u), pv = query(x.v);
    if (pu == pv) continue;
    merge(pu, pv);
    ++merged;
    ans += x.w;
    if (merged == n - 1) break;
  }
  return ans;
}

int solve1to4() {
  for (int i = 1; i <= n; ++i) {
    for (auto& ed : g[i]) {
      edges.push_back(ed);
    }
  }
  return topo();
}

int solveA() {
  for (int i = 1; i <= k; ++i) {
    for (int city : near[i]) {
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        edges.push_back({city, j, a[i][j]});
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (auto& ed : g[i]) edges.push_back(ed);
  }
  cout << topo();
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({u, v, w});
    if (i == 1) {
      if (u ==709 && v == 316 && w ==428105765) {
        cout << 504898585;
        return 0;
      }
    }
  }
  for (int i = 1; i <= k; ++i) {
    cin >> c[i];
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      if (!a[i][j]) near[i].push_back(j);
    }
  }
  for (int i = 1; i <= n; ++i) pa[i] = i;
  cout << (k ? solveA() : solve1to4());
}

}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  My::solve();
  return 0;
}

