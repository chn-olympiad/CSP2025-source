#include <bits/stdc++.h>
using namespace std;
int main() {
  double time = clock();
  cin.tie(0)->sync_with_stdio(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    vector<vector<tuple<int, int, int>>> graph(n);
    vector<tuple<int, int, int>> road(m);
    for (int i = 0; i < m; i ++) {
      auto &[u, v, w] = road[i];
      cin >> u >> v >> w;
      graph[u - 1].emplace_back(v - 1, w, i);
      graph[v - 1].emplace_back(u - 1, w, i);
    }
    vector<pair<int, vector<int>>> country(k);
    for (int i = 0; i < k; i ++) {
      cin >> country[i].first;
      for (int j = 0; j < n; j ++) {
        cin >> (country[i].second)[j];
      }
    }
    if (k == 0) {
      vector<int> fix(m, 0);
      vector<vector<int>> used(k, vector<int>(n, 0));
      vector<long long> min_dist(n, LONG_LONG_MAX);
      min_dist[0] = 0;
      priority_queue<pair<long long, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//dist pos
      pq.emplace(0, 0);
      while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        for (auto [v, w, i] : graph[u]) {
          if (min_dist[v] <= dist + w) continue;
          min_dist[v] = dist + w;
          fix[i] = 1;
          pq.emplace(dist + w, v);
        }
      }
      long long ans = 0;
      for (int i = 0; i < m; i ++) {
        if (fix[i]) {
          ans += get<2>(road[i]);
        }
      }
      cout << ans << endl;
    }
  } else {
    vector<vector<long long>> graph(n, vector<long long>(n, LONG_LONG_MAX));
    for (int i = 0; i < m; i ++) {
      long long u, v, w;
      cin >> u >> v >> w;
      graph[u - 1][v - 1] = min(graph[u - 1][v - 1], w);
      graph[v - 1][u - 1] = min(graph[v - 1][u - 1], w);
    }
    vector<long long> costctr(k);
    vector<vector<long long>> ctry(k, vector<long long>(n));
    for (int i = 0; i < k; i ++) {
      cin >> costctr[i];
      for (long long &x : ctry[i]) {
        cin >> x;
      }
    }
    long long ans = LONG_LONG_MAX;
    for (int kn = 0; kn < (1 << k); kn ++) {
      if (accumulate(costctr.begin(), costctr.end(), 0) == 0) kn = (1 << k) - 1;
      auto solve = [](vector<vector<long long>> graph, int kn, vector<vector<long long>> &ctry, int n, int m, int k, vector<long long> costctr) -> long long {
        long long cost = 0;
        for (int i = 0; i < k; i ++) {
          if (kn & (1 << i)) {
            cost += costctr[k - i - 1];
            for (int x = 0; x < n; x ++) {
              for (int y = 0; y < n; y ++) {
                if (x == y) continue;
                graph[x][y] = min(graph[x][y], ctry[i][x] + ctry[i][y]);
                graph[y][x] = min(graph[y][x], ctry[i][y] + ctry[i][x]);
              }
            }
          }   
        }
        vector<long long> min_dist(n, LONG_LONG_MAX);
        min_dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> costs(n, LONG_LONG_MAX);
        costs[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
          auto [dist, u] = pq.top();
          pq.pop();
          for (int v = 0; v < n; v ++) {
            if (v == u) continue;
            long long w = graph[u][v];
            if (min_dist[v] <= dist + w) continue;
            min_dist[v] = dist + w;
            costs[v] = min(costs[v], w);
            pq.emplace(dist + w, v);
          }
        }
        cost += accumulate(costs.begin(), costs.end(), 0ll);
        return cost;
      };
      ans = min(ans, solve(graph, kn, ctry, n, m, k, costctr));
      if (time >= 0.95) break;
    }
    cout << ans << endl;
  }
}