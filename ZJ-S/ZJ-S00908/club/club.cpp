#include <bits/stdc++.h>
#define endl '\n'
using i32 = int;
using i64 = long long;
void solve(i32 _);
signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  i32 T;
  std::cin >> T;
  for (i32 i = 1; i <= T; i++) solve(i);
}
void solve(i32 _) {
  i32 n;
  i64 ans = 0;
  std::cin >> n;
  std::vector<std::vector<i32>> a(5, std::vector<i32>(n + 2, 0));
  std::vector<std::vector<i32>> g(5);
  for (i32 i = 1; i <= n; i++)
    for (i32 j = 1; j <= 3; j++) std::cin >> a[j][i];
  for (i32 i = 1; i <= n; i++) {
    auto [x, y, z] = (std::tuple<i32, i32, i32>){a[1][i], a[2][i], a[3][i]};
    i32 mx = std::max(x, std::max(y, z));
    ans += mx;
    if (mx == x) g[1].emplace_back(std::min(mx - y, mx - z));
    else if (mx == y) g[2].emplace_back(std::min(mx - x, mx - z));
    else g[3].emplace_back(std::min(mx - x, mx - y));
  }
  if ((i32)g[1].size() > n / 2) {
    auto &b = g[1];
    std::sort(b.begin(), b.end());
    for (i32 i = 0; i < (i64)b.size() - n / 2; i++) ans -= b[i];
  }
  else if ((i32)g[2].size() > n / 2) {
    auto &b = g[2];
    std::sort(b.begin(), b.end());
    for (i32 i = 0; i < (i64)b.size() - n / 2; i++) ans -= b[i];
  }
  else if ((i32)g[3].size() > n / 2) {
    auto &b = g[3];
    std::sort(b.begin(), b.end());
    for (i32 i = 0; i < (i64)b.size() - n / 2; i++) ans -= b[i];
  }
  std::cout << ans << endl;
}
// g++ club.cpp -o club -O2 -std=c++14 -static
