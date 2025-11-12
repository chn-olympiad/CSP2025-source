#include <bits/stdc++.h>
#define endl '\n'
using i32 = int;
using i64 = long long;
using f64 = double;
const i64 p = 998244353;
inline i64 mod(i64 x) { return (x % p + p) % p; }
inline i64 qpow(i64 a, i64 b) {
  i64 ret = 1;
  while (b) {
    if (b & 1) ret = mod(ret * a);
    a = mod(a * a);
    b >>= 1;
  }
  return ret;
}
signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  i32 n, V;
  i64 ans = 0;
  std::cin >> n;
  std::vector<i32> a(n + 2, 0);
  for (i32 i = 1; i <= n; i++) std::cin >> a[i];
  std::sort(a.begin() + 1, a.begin() + n + 1);
  V = a[n];
  std::vector<std::vector<i64>> f(2, std::vector<i64>(V + 2, 0));
  for (i32 i = 1; i <= n; i++) {
    for (i32 j = 1; j <= a[i]; j++) ans = mod(ans + f[1][j]);
    for (i32 j = V - a[i]; j >= 0; j--)
      f[1][j + a[i]] = mod(f[1][j + a[i]] + f[1][j] + f[0][j]);
    f[0][a[i]]++;
  }
  std::cout << mod(qpow(2, n) - 1 - n - mod(mod(n * (n - 1)) * qpow(2, p - 2)) - ans) << endl;
  return 0;
}
// *1700. Why so ez?
// Ended at 2025/11/01 10:03(UTF+8).
// Expected score: 100 + 100 + 100 + 100 = 400.
// CSP 2025 RP++!
// ZJ-J00842 Terminal_P.
