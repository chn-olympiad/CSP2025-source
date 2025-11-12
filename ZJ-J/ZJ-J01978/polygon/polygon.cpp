#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5005;
const int M = 5001;
const int mod = 998244353;
const int debug_mode = false;
int n;
int dp[M + 5], pd[M + 5], ed[M + 5];
signed main() {
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 1; i <= M; i++) ed[i] = lower_bound(a.begin(), a.end(), i) - a.begin();

  dp[0] = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= M; j++) pd[j] = 0;
    for (int j = 0; j <= M; j++) pd[min(M, j + a[i])] += dp[j];
    for (int j = 0; j <= M; j++) {
      pd[j] %= mod;
      ans = (ans + pd[j] * max(ed[j] - i - 1, 0LL)) % mod;  // (i, ed[j])
      dp[j] = (dp[j] + pd[j]) % mod;
    }
  }
  cout << ans << "\n";
  return 0;
}
/*
5
1 2 3 4 5
1 2 3 4
*/
