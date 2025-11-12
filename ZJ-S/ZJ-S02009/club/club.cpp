#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr int inf = 1E9;

void solve() {
  int n;
  std::cin >> n;

  int ans = 0;
  std::vector<int> p[3];
  std::vector<int> val(n, inf);
  for (int i = 0; i < n; i++) {
    int a[3];
    for (int j = 0; j < 3; j++) {
      std::cin >> a[j];
    }
    int mx = *std::max_element(a, a + 3);
    ans += mx;
    for (int j = 0; j < 3; j++) {
      if (a[j] == mx) {
        p[j].push_back(i);
        for (int k = 0; k < 3; k++) {
          if (j != k) {
            val[i] = std::min(val[i], a[j] - a[k]);
          }
        }
        break;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    if (p[i].size() > n / 2) {
      std::vector<int> q;
      for (auto j : p[i]) {
        q.push_back(val[j]);
      }
      std::sort(q.begin(), q.end());
      for (int j = 0; j < p[i].size() - n / 2; j++) {
        ans -= q[j];
      }
      break;
    }
  }
  std::cout << ans << "\n";
}

int main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}