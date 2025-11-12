#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4;
const int M = 1e6;
const int K = 10;
int n, m, k, a[K + 1];

struct edge {
  int x, y, w;
} e[M + K * N + 1];

const ll INF = (ll)1e18;
ll ans;

struct DSU {
  int fa[N + K + 1];
  
  void init() {
    for (int i = 1; i <= n + k; i++) {
      fa[i] = i;
    }
    return;
  }
  
  int fd(int x) {
    return fa[x] == x ? x : fa[x] = fd(fa[x]);
  }
  
  bool meg(int x, int y) {
    x = fd(x);
    y = fd(y);
    if (x == y) {
      return 0;
    }
    fa[x] = y;
    return 1;
  }
} dsu;

ll cal(int s) {
  ll res = 0;
  vector<int> eid;
  int vn = n;
  for (int i = 1; i <= k; i++) {
    if (s >> i - 1 & 1 ^ 1) {
      continue;
    }
    ++vn;
    res += a[i];
    for (int j = 1; j <= n; j++) {
      eid.push_back(m + (i - 1) * n + j);
    }
  }
  sort(eid.begin(), eid.end(), [](int x, int y) {
    return e[x].w < e[y].w;
  });
  dsu.init();
  int j = 1, cnt = 0;
  for (int i : eid) {
//    cout << i << "*\n";
    while (j <= m && e[j].w <= e[i].w && cnt < vn - 1) {
      res += dsu.meg(e[j].x, e[j].y) ? ++cnt, e[j].w : 0;
      ++j;
    }
    res += dsu.meg(e[i].x, e[i].y) ? ++cnt, e[i].w : 0;
  }
  while (j <= m && cnt < vn - 1) {
    res += dsu.meg(e[j].x, e[j].y) ? ++cnt, e[j].w : 0;
    ++j;
  }
//  cout << res << "\n";
  return res;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].x >> e[i].y >> e[i].w;
  }
  sort(e + 1, e + m + 1, [](edge x, edge y) {
    return x.w < y.w;
  });
  int t = m;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      e[++t] = {i + n, j, x};
    }
  }
  ans = INF;
  for (int s = 0; s < 1 << k; s++) {
    ans = min(ans, cal(s));
  }
  cout << ans;
  return 0;
}