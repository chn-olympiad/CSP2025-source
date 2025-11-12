#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2 + 10, mod = 998244353;
int n, m, b[N], c[N], p[11], fac[N], fgA = 1;
int bu[N];
int f[(1 << 18) + 5][19];
signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    char ch; cin >> ch; b[i] = (ch == '1');
    fgA &= (ch == '1');
  }
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
  for (int i = 1; i <= n; ++i) cin >> c[i], bu[c[i]]++;
  for (int i = 1; i <= n; ++i) bu[i] += bu[i - 1];
  if (n <= 10) {
    iota(p + 1, p + n + 1, 1);
    int ans = 0;
    do {
      int pre = 0;
      for (int i = 1; i <= n; ++i) {
        if (c[p[i]] <= pre || !b[i]) pre++;
      } 
      if (n - pre >= m) ans++;
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans << endl;
    return 0;
  }
  if (n <= 18) {
    
    return 0;
  }
}