#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 500 + 5, mod = 998244353;
namespace Basic {
  int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
  int dec(int x, int y) { x -= y; if (x < 0) x += mod; return x; }
  void ad(int& x, int y) { x += y; if (x >= mod) x -= mod; }
  void de(int& x, int y) { x -= y; if (x < 0) x += mod; }

  int qpow(int a, int b) {
    int r = 1;
    while (b) {
      if (b & 1) r = 1ll * r * a % mod;
      a = 1ll * a * a % mod; b >>= 1;
    }
    return r;
  }
  int inv(int x) { return qpow(x, mod - 2); }

  int fac[N], ifac[N];
  void fac_init(int n = N - 1) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
      fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    ifac[n] = inv(fac[n]);
    for (int i = n - 1; i >= 0; i--) {
      ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    }
  }
  int binom(int n, int m) {
    if (n < m || m < 0) return 0;
    return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
  }
}
using namespace Basic;

int n, m, a[N], c[N], cnt[N];
int pref[N];
int total(int l, int r) {
  return pref[r] - (l ? pref[l - 1] : 0);
}

namespace M1 {
  void solve() {
    int ans = 1, sum = n;
    for (int i = 1, j = -1, tot = 0; i <= n; i++) {
      if (a[i] == 1) {
        sum--;
        while (j < i - 1) tot += cnt[++j];
        ans = 1ll * ans * tot % mod, tot--;
      }
    }
    ans = 1ll * ans * fac[sum] % mod;
    cout << dec(fac[n], ans) << "\n";
  }
}
namespace MN {
  void solve() {
    if (count(a + 1, a + n + 1, 1) == n) cout << fac[n] << "\n";
    else cout << 0 << "\n";
  }
}
namespace Brute {
  // constexpr int M = 100 + 5;
  // int f[M][M][M];
  // void solve() {
  //   f[0][0][0] = 1;
  //   vector<int> p = {0};
  //   int m = 0;
  //   for (int i = 1; i <= n; i++) {
  //     if (a[i]) {
  //       p.push_back(i);
  //       m++;
  //     }
  //   }
  //   for (int i = 1; i <= m; i++) {
  //     for (int j = 0; j <= i - 1; j++) {
  //       for (int k = 0; k <= i - 1; k++) {
  //         if (!f[i - 1][j][k]) continue;
  //         int all = total(p[i] - j, i == m ? n : (p[i + 1] - j - 1));
  //         for (int t = 0; t <= all && t <= k; t++) {
  //           ad(f[i][j][k - t], 1ll * f[i - 1][j][k] * (total(0, p[i] - j - 1) - (i - 1 - k)) % mod * binom(k, t) % mod * binom(all, t) % mod * fac[t] % mod);
  //         }
  //         all = total(p[i] - j, i == m ? n : (p[i + 1] - j - 2));
  //         for (int t = 0; t <= all && t <= k + 1; t++) {
  //           ad(f[i][j + 1][k + 1 - t], 1ll * f[i - 1][j][k] * binom(k + 1, t) % mod * binom(all, t) % mod * fac[t] % mod);
  //         }
  //       }
  //     }
  //   }
  //   int ans = 0;
  //   for (int j = m; j <= n; j++) {
  //     ad(ans, 1ll * f[m][j][0] * fac[n - m] % mod);
  //   }
  //   cout << ans << "\n";
  // }
}
namespace N18 {
  int f[1 << 18][20];
  void solve() {
    f[0][0] = 1;
    for (int S = 0; S < (1 << n) - 1; S++) {
      int i = __builtin_popcount(S);
      for (int j = 0; j <= i; j++) {
        for (int k = 1; k <= n; k++) {
          if (S >> (k - 1) & 1) continue;
          ad(f[S | (1 << (k - 1))][j + (a[i + 1] == 1 && i - j < c[k])], f[S][j]);
        }
      }
    }
    int ans = 0;
    for (int i = m; i <= n; i++) {
      ad(ans, f[(1 << n) - 1][i]);
    }
    cout << ans << "\n";
  }
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  fac_init();

  cin >> n >> m;
  string difficulties; cin >> difficulties;
  for (int i = 1; i <= n; i++) {
    a[i] = difficulties[i - 1] - '0';
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    cnt[c[i]]++;
  }
  pref[0] = cnt[0];
  for (int i = 1; i <= n; i++) {
    pref[i] = cnt[i] + pref[i - 1];
  }
  if (count(a + 1, a + n + 1, 0) == n)
    return cout << 0 << "\n", 0;

  if (m == 1) return M1::solve(), 0;
  if (m == n) return MN::solve(), 0;
  return N18::solve(), 0;
  // return Brute::solve(), 0;
}
// g++ -o employ employ.cpp -O2 -std=c++14 -fsanitize=undefined