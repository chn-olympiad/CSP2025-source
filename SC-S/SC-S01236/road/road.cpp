#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

const int MAXN = 1e4 + 10;
const int MAXM = 1e6 + 10; 
const int MAXK = 15;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, m, k, c[MAXK], a[MAXK][MAXN], fa[MAXN], dp[(1 << 10) + 10][MAXN], 
    cst[MAXN][MAXK], tmp[(1 << 10) + 10], ans, idx;
vector<int> g[MAXN];

struct edge {
  int u, v, w;
  friend bool operator <(edge a, edge b) {
    return a.w < b.w;
  }
};
edge e[MAXM], t[MAXN];

int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

void kruskal() {
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int fu = find(e[i].u), fv = find(e[i].v);
    if (fu == fv) continue;
    fa[fu] = fv;
    t[++idx] = e[i];
    g[e[i].u].push_back(idx);
    g[e[i].v].push_back(idx);
  }
  return;
}

void dfs(int u, int f) {
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 1; j <= k; j++) {
      if ((i & (1 << (j - 1)))) {
        dp[i][u] += a[j][u];
      }
    }
  }
  for (int to = 0; to < g[u].size(); to++) {
    if (t[g[u][to]].u != u) {
      swap(t[g[u][to]].u, t[g[u][to]].v);
    }
    int v = t[g[u][to]].v, w = t[g[u][to]].w;
    if (v == f) continue;
    dfs(v, u);
    for (int i = 0; i < (1 << k); i++) {
      tmp[i] = INF;
    }
    for (int i = 0; i < (1 << k); i++) {
      tmp[i] = min(tmp[i], dp[i][u] + dp[i][v] + w);
      for (int j = 1; j <= k; j++) {
        if ((i & (1 << (j - 1))) == 0) {
          tmp[i | (1 << (j - 1))] = min(tmp[i | (1 << (j - 1))], 
                                        dp[i][u] + dp[i][v] + cst[g[u][to]][j]);
//          cout << dp[i | (1 << (j - 1))][u] + dp[i][v] + cst[j][v] << endl;
        } else {
          tmp[i] = min(tmp[i], dp[i][u] + dp[i][v]);
        }
      }
    }
    int minx = INF;
    for (int i = 0; i < (1 << k); i++) {
      dp[i][u] = tmp[i];
      minx = min(minx, tmp[i]);
//      cout << u << ' ' << v <<' '<<i<< ':' << tmp[i]<<endl;
    }
//    cout << u << ' ' << v <<' '<<(1 << k)<< ':' << minx<<endl;
    dp[(1 << k)][u] = minx;
  }
  return;
}

int dfs1(int id, int u, int f) {
  int ret = a[id][u];
  for (int to = 0; to < g[u].size(); to++) {
    if (t[g[u][to]].u != u) swap(t[g[u][to]].u, t[g[u][to]].v);
    int v = t[g[u][to]].v;
    if (v == f) continue;
    ret = min(ret, dfs1(id, v, u));
  }
  return ret;
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  for (int i = 1; i <= k; i++) {
    cin >> c[i];
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  kruskal();
  for (int i = 1; i <= idx; i++) {
    for (int j = 1; j <= k; j++) {
      cst[i][j] += dfs1(j, t[i].u, t[i].v);
      cst[i][j] += dfs1(j, t[i].v, t[i].u);
    }
  }
  dfs(1, 0);
  ans = INF;
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 1; j <= k; j++) {
      if (i & (1 << (j - 1))) dp[i][1] += c[j];
    }
    ans = min(ans, dp[i][1]);
  }
  cout << ans << endl;
  return 0;
}
