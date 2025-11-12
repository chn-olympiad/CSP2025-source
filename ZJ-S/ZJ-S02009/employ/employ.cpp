#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int N = 505;
constexpr u32 P = 998244353;

u32 f[N][N][N];

void inc(u32 &a, u32 b) {
  a += b;
  if (a >= P) {
    a -= P;
  }
}

u32 qmi(u32 a, int k) {
  u32 ans = 1;
  for ( ; k; k /= 2, a = 1ULL * a * a % P) {
    if (k % 2) {
      ans = 1ULL * ans * a % P;
    }
  }
  return ans;
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::string s;
  std::cin >> s;

  std::vector<int> c(n);
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
  }

  // const int mask = 1 << n;
  // std::vector<std::vector<u32>> dp(mask, std::vector<u32>(n + 1));
  // dp[0][0] = 1;
  // for (int s = 1; s < mask; s++) {
  //   int t = __builtin_popcount(s);
  //   for (int i = 0; i < n; i++) {
  //     if (s >> i & 1) {
  //       for (int j = 0; j <= n; j++) {
  //         if (S[t - 1] == '1' && c[i] >= t - j + 1) {
  //           if (j) {
  //             inc(dp[s][j], dp[s ^ 1 << i][j - 1]);
  //           }
  //         } else {
  //           inc(dp[s][j], dp[s ^ 1 << i][j]);
  //         }
  //       }
  //     }
  //   }
  // }

  // u32 ans = 0;
  // for (int i = m; i <= n; i++) {
  //   inc(ans, dp[mask - 1][i]);
  // }
  // std::cout << ans << "\n";

  // std::vector<int> d(n + 1);
  // for (int i = 0; i < n; i++) {
  //   int c;
  //   std::cin >> c;
  //   d[c]++;
  // }
  // for (int i = 1; i <= n; i++) {
  //   d[i] += d[i - 1];
  // }

  // std::vector<u32> fac(n + 1), invfac(n + 1);
  // fac[0] = 1;
  // for (int i = 1; i <= n; i++) {
  //   fac[i] = 1ULL * fac[i - 1] * i % P;
  // }
  // invfac[n] = qmi(fac[n], P - 2);
  // for (int i = n; i; i--) {
  //   invfac[i - 1] = 1ULL * invfac[i] * i % P;
  // }

  // auto calc = [&](int n, int m) -> u32 {
  //   if (n < m) {
  //     return 0;
  //   }
  //   return 1ULL * fac[n] * invfac[n - m] % P;
  // };

  // int t = 0;
  // f[0][0][0] = 1;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     for (int k = 0; k <= j; k++) {
  //       if (s[i - 1] == '1') {
  //         if (j) {
  //           inc(f[i][j][k], f[i - 1][j - 1][k]);
  //         }
  //       }
  //       int c = i - 1 - j;
  //       for (int x = 0; x <= k; x++) {
  //         inc(f[i][j][k], 1ULL * f[i - 1][j][k - x] * (s[i - 1] == '0' ? 1 : d[c] - (k - x) - (t - j)) % P * (c == 0 ? calc(0, x) : calc(d[c + 1] - d[c], x) % P));
  //       }
  //     }
  //   }
  //   // for (int j = 1; j <= n; j++) {
  //   //   for (int k = 0; k <= j; k++) {
  //   //     std::cout << i << " " << j << " " << k << " " << f[i][j][k] << "\n";
  //   //   }
  //   // }
  //   t += s[i - 1] == '1';
  // }

  // u32 ans = 0;
  // for (int i = m; i <= n; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     int c = n - i - 1;
  //     // std::cout << i << " " << j << " " << f[n][i][j] << "\n";
  //     inc(ans, f[n][i][j] * calc(n - (c < 0 ? 0 : d[c]), i - j));
  //   }
  // }
  // ans = 1ULL * ans * fac[n - t] % P;
  // std::cout << ans << "\n";

  int ans = 0;
  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  do {
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && c[p[i]] >= i + 1 - j) {
        j++;
      }
    }
    if (j >= m) {
      ans++;
    }
  } while (std::next_permutation(p.begin(), p.end()));
  std::cout << ans << "\n";

  return 0;
}