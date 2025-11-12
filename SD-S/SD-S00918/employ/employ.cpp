#include <bits/stdc++.h>

using ll = long long;

void Advotya() {
  int n; std::cin >> n;
  int m; std::cin >> m;
  std::string s; std::cin >> s;
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) std::cin >> c[i];
  std::vector<std::vector<std::vector<int>>> f(n, 
              std::vector<std::vector<int>>   (1 << n, 
                          std::vector<int>    (n + 1)));
  for (int i = 0; i < n; ++i) {
    bool succ = s[0] == '1' && c[i] > 0; 
    f[0][1 << i][succ ? 0 : 1] = 1;
  }
  for (int i = 1; i < n; ++i) {
    for (int msk = 0; msk < (1 << n); ++msk) {
      for (int j = 0; j < n; ++j) {
        if ((msk >> j & 1) != 0) continue;
        for (int k = 0; k <= i; ++k) {
          bool succ = s[i] == '1' && c[j] > k;
          int& dp = f[i][msk | (1 << j)][k + (succ ? 0 : 1)];
          dp = (dp + f[i - 1][msk][k]) % 998244353;
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= n; ++j) {
    if (n - j >= m) {
      ans = (ans + f.back().back()[j]) % 998244353;
    }
  }
  std::cout << ans << "\n";
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  Advotya();
  return 0;
}

