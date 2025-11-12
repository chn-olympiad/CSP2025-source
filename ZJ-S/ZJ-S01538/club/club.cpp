#include <bits/stdc++.h>

using u32 = unsigned;

constexpr u32 N{100000};

u32 t, n, m, c[3]; int a[N][3], ans;

inline std::pair<int, std::array<u32, 3>> calc(const std::array<int, 3> &d, const std::array<u32, 3> &o)
{
  int ans{0}; std::array<u32, 3> c{0, 0, 0}; int x[3];
  for (u32 i{0}; i < n; i++)
  {
    for (u32 j : {0, 1, 2}) { x[j] = a[i][j] - d[j]; }
    u32 y{o[0]}; int z{x[y]}; for (const u32 &j : o) { if (x[j] > z) { y = j; z = x[j]; } }
    c[y]++; ans += z;
  }
  return std::make_pair(ans, c);
}

signed main(void)
{
  freopen("club.in", "r", stdin); freopen("club.out", "w", stdout); std::cin.tie(nullptr) -> sync_with_stdio(false);
  for (std::cin >> t; t; t--)
  {
    std::cin >> n; for (u32 i{0}; i < n; i++) { std::cin >> a[i][0] >> a[i][1] >> a[i][2]; } m = n >> 1;
    std::array<int, 3> d{0, 0, 0}; std::array<u32, 3> o; auto p{calc(d, {0, 1, 2})}; auto c{p.second};
    if (c[0] <= m && c[1] <= m && c[2] <= m) { std::cout << p.first << '\n'; continue; }
    u32 x; for (u32 j : {0, 1, 2}) { if (c[j] > m) { x = j; } } for (u32 j : {0, 1, 2}) { o[j] = (x + j + 1) % 3; }
    int l{0}, r{20000}; while (l < r) { d[x] = (l + r) / 2; (calc(d, o).second[x] > m) ? (l = d[x] + 1) : (r = d[x]); }
    d[x] = l; p = calc(d, o); std::cout << p.first + d[x] * p.second[x] << '\n';
  }
  return 0;
}
