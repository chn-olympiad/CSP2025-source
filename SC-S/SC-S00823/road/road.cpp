#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
const int N = 1e4 + 10, M = 2e6 + 10, K = 10 + 5;
const int INF = 1e17 + 10; 

struct edge {
  int u, v, w, last;
} e[M << 1];

int head[N], cnt, c[N], a[K][N];
int dis[N];
void add(int u, int v, int w) {
  e[++cnt].w = w;
  e[cnt].v = v;
  e[cnt].u = u;
  e[cnt].last = head[u];
  head[u] = cnt;
}
int n, m, k;

struct node {
  int u, eg;
  friend bool operator <(node a, node b) {
    return a.eg > b.eg;
  }
};
std::priority_queue<node> q;
bool vis[N];
int MST() {
  int res = 0;
  node tmp;
  tmp.u = 1, tmp.eg = 0;
  q.push(tmp);
  dis[1] = 0;
  while(!q.empty()) {
    node h = q.top();
    q.pop();
    int u = h.u, me = h.eg;
    if (vis[u]) continue;
    vis[u] = true;
    res += me;
    for (int i = head[u]; i; i = e[i].last) {
      int v = e[i].v, w = e[i].w;
      if (dis[v] > w) {
        dis[v] = w;
        node tmpp;
        tmpp.u = v, tmpp.eg = dis[v];
        q.push(tmpp);
      }
    }
  }
  return res;
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout); 
  std::cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    add(u, v, w);
    add(v, u, w); 
  }
  
  for (int i = 1; i <= k; ++i) {
    std::cin >> c[i];
    for (int j = 1; j <= n; ++j) {
      std::cin >> a[i][j];
    }
  }
  
  for (int i = 1; i <= n; ++i) dis[i] = INF;
  if (k == 0) {
    int mst = MST();
    std::cout << mst << '\n';
    return 0;
  }
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      int mn = INF;
      for (int z = 1; z <= k; ++z) {
        mn = std::min(mn, (int)(a[z][i] + a[z][j] + c[z]));
      }
      add(i, j, mn);
    }
  }
  
  int mst = MST();
  std::cout << mst << '\n';
  fclose(stdin);
  fclose(stdout);
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/