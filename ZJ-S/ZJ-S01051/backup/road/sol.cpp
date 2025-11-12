#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define int long long

using namespace std;
using i64 = long long;
using pii = pair <int, int> ;

constexpr int N = 1.1e4;
constexpr int M = 1.3e6;

int n, m, k, ans, dis[N], vis[N], us[11], c[11];
vector <pii> e[N];
priority_queue <pii, vector <pii>, greater <pii> > q;

signed main() {
  cin.tie(nullptr) -> sync_with_stdio(false);

  cin >> n >> m >> k;
  for (int i = 1; i <= m; i ++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }

  for (int i = 1; i <= k; i ++) {
    int w;
    cin >> c[i];
    for (int j = 1; j <= n; j ++) {
      cin >> w;
      e[n + i].emplace_back(j, w);
      e[j].emplace_back(n + i, w + c[i]);
    }
  }

  memset (dis, 0x3f, sizeof(dis));
  q.emplace(dis[1] = 0, 1);

  while (!q.empty()) {
    int u = q.top().second;
    vis[u] = true;
    q.pop();
    
    for (auto ie : e[u]) {
      int v = ie.first, w = ie.second;
      if (w < dis[v] && !vis[v]) {
        if (u > n) {
          us[u - n] = true;
        }
        // if (u > n) w += c[u - n];
        dis[v] = w;
        
        q.emplace(dis[v], v);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i ++) {
    ans += dis[i];
  }

  for (int i = 1; i <= k; i ++) {
    if (us[i]) {
      // cout << i << '\n';
      ans += dis[i + n];
    }
  }

  // for (int i = 1; i <= n + k; i ++) {
  //   cout << dis[i] << '\n';
  // }
  
  cout << ans << '\n';
  return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/
