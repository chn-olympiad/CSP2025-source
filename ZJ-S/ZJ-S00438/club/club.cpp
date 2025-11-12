#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  int t;
  cin >> t;
  while (t --) {
    int n;
    long long ans = 0;
    cin >> n;
    vector<vector<pair<int, int>>> w(n, vector<pair<int, int>>(3));
    for (vector<pair<int, int>> &x : w) {
      cin >> x[0].first >> x[1].first >> x[2].first;
      x[0].second = 0;
      x[1].second = 1;
      x[2].second = 2;
      int nmax = max({x[0].first, x[1].first, x[2].first});
      ans += nmax;
      for (int i = 0; i < 3; i ++) {
        (x[i].first -= nmax) *= -1;
      }
      sort(x.begin(), x.end());
    }
    sort(w.begin(), w.end(), [](vector<pair<int, int>> a, vector<pair<int, int>> b) {
      if (a[1].first == b[1].first) {
        return a[2].first > b[2].first;
      } else {
        return a[1].first > b[1].first;
      }
    });
    vector<int> cnt = {0, 0, 0};
    for (int i = 0; i < n; i ++) {
      if (cnt[w[i][0].second] < n / 2) {
        cnt[w[i][0].second] ++;
      } else {
        cnt[w[i][1].second] ++;
        ans -= w[i][1].first;
      }
    }
    cout << ans << endl;
  }
}