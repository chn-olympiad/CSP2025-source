#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int mod = 998244353;

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  vector<int> c(n);
  string raw_s;
  cin >> raw_s;
  for (int i = 0; i < n; i++) s[i] = raw_s[i] - '0';
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(c.rbegin(), c.rend());  // dec

  if (n <= 18) {
    vector<int> plans(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
      int total = 0;
      for (int i = 0; i < n; i++) {
        if (mask >> i & 1) {
          if (!s[i]) {
            total = -1;
            break;
          }
          total++;
        }
      }
      if (total == -1) {
        plans[mask] = -1;
        continue;
      }
      int fails = n - total;
      int plan = 1;
      int ok = 0, ac = 0;
      for (int i = n - 1; i >= 0; i--) {
        if (mask >> i & 1) {
          while (ok < n && c[ok] > fails) ok++;
          if (ok <= ac) {
            plan = 0;
            break;
          }
          plan = plan * (ok - ac) % mod;
          ac++;
        } else {
          fails--;
        }
      }
      plans[mask] = plan;
    }
    for (int i = 0; i < (1 << n); i++)
      if (~plans[i]) {
        cerr << "pre " << i << ": " << plans[i] << "\n";
      }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1 << n); j++) {
        if (j >> i & 1 && ~plans[j] && ~plans[j ^ (1 << i)]) {
          plans[j] = (plans[j] + mod - plans[j ^ (1 << i)]) % mod;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++)
      if (~plans[i]) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
          if (i >> j & 1) cnt++;
        // cerr << i << ": " << plans[i] << "\n";
        if (cnt >= m) ans += plans[i];
      }
    cout << ans % mod << "\n";
    return 0;
  }
  return 0;
}
