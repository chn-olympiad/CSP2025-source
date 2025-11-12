#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 10;
int n, ans;
struct node {
  int val[3];
} a[N];
vector<int> v[3];
void solve() {
  cin >> n;
  for (int i = 0; i < 3; ++i) v[i].clear();
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    int mx = 0;
    for (int j = 0; j < 3; ++j) cin >> a[i].val[j], mx = max(mx, a[i].val[j]);
    if (a[i].val[0] == mx) v[0].push_back(i);
    else if (a[i].val[1] == mx) v[1].push_back(i);
    else v[2].push_back(i);
    ans += mx;
  }
  int mx = max(v[0].size(), max(v[1].size(), v[2].size()));
  if (mx <= n / 2) {
    return cout << ans << endl, void();
  }
  int o = 2;
  if (mx == v[0].size()) o = 0;
  else if (mx == v[1].size()) o = 1;
  vector<pii> v2;
  for (int i : v[o]) {
    int mx2 = 0;
    for (int j = 0; j < 3; ++j) if (j != o) mx2 = max(mx2, a[i].val[j]);
    v2.push_back({mx2 - a[i].val[o], i});
  }
  sort(v2.begin(), v2.end(), greater<pii>());
  for (int i = 0; i < (int)(v[o].size() - n / 2); ++i) ans += v2[i].first;
  cout << ans << endl;
} 
int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int T; cin >> T; while (T--) solve();
}