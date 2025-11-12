#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e5 + 5;
int n, a[N][3], b[N], cnt[3];

void solve() {
  cin >> n;
  ll ans = 0;
  cnt[0] = cnt[1] = cnt[2] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    b[i] = max_element(a[i], a[i] + 3) - a[i];
    ans += a[i][b[i]];
    cnt[b[i]]++;
  }
  int it = max_element(cnt, cnt + 3) - cnt;
  if (cnt[it] > n / 2) {
    vector<ll> S;
    for (int i = 1; i <= n; i++) {
      if (b[i] == it) {
        int w = -1e9;
        for (int j = 0; j < 3; j++) {
          if (j != it) {
            w = max(w, a[i][j]);
          }
        }
        S.push_back(a[i][it] - w);
      }
    }
    sort(S.begin(), S.end());
    for (int i = 0; i < cnt[it] - n / 2; i++) {
      ans -= S[i];
    }
  }
  cout << ans << "\n";
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
}
// g++ -o club club.cpp -O2 -std=c++14 -fsanitize=undefined