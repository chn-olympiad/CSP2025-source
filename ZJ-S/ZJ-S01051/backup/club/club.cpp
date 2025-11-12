#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using pii = pair <int, int>;

constexpr int N = 1e5 + 7;

int T, n, a[N][3], vis[N];
vector <pii> mx[3];
vector <int> t;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i ++) 
    for (int j = 0; j < 3; j ++)
      cin >> a[i][j];
  
  t.clear(), t.reserve(n);
  for (auto &j : mx) j.clear(), j.reserve(n);

  for (int i = 1; i <= n; i ++) {
    vis[i] = 0;
    int maxx = max({a[i][0], a[i][1], a[i][2]});
    for (int j = 0; j < 3; j ++)
      if (maxx == a[i][j]) mx[j].emplace_back(maxx, i);
  }

  bool fl = false;
  
  for (int j = 0; j < 3; j ++) {
    if ((int)mx[j].size() > n / 2) {
      // cout << ":" << j << '\n';
      fl = true;
      for (int i = 0; i < (int)mx[j].size(); i ++)
        vis[mx[j][i].second] = 1;
    }
  }

  i64 ans = 0;
  for (int i = 1; i <= n; i ++) {
    sort (a[i], a[i] + 3);
    // cout << a[i][2] << ' ' << vis[i] << ':' << ans << '\n';
    if (vis[i]) t.push_back(a[i][2] - a[i][1]), ans += a[i][1];
    else ans += a[i][2];
  }

  if (fl) {
    sort(t.begin(), t.end(), greater <int> ());
    for (int i = 0; i < n / 2; i ++) 
      ans += t[i];
  }
  

  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  for (cin >> T; T --; ) solve();
  return 0;
}

// time : 15 - 43.