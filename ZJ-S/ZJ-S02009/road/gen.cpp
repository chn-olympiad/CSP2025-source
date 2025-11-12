#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

constexpr int V = 1E9 + 1;

int main() {
  // freopen("road.in", "r", stdin);
  // freopen("road.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n = 10000, m = 1000000, k = 10;
  std::cout << n << " " << m << " " << k << "\n";

  for (int i = 0; i < m; i++) {
    int u = rng() % n, v = rng() % n, w = rng() % V;
    std::cout << u << " " << v << " " << w << "\n";
  }

  for (int i = 0; i < k; i++) {
    std::cout << rng() % V << " ";
    for (int j = 0; j < n; j++) {
      std::cout << rng() % V << " \n"[j == n - 1];
    }
  }

  return 0;
}