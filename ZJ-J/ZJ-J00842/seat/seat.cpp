#include <bits/stdc++.h>
#define endl '\n'
using i32 = int;
using i64 = long long;
using f64 = double;
signed main() {
  std::cin.tie(0)->sync_with_stdio(false);
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
  i32 n, m, tar;
  std::cin >> n >> m;
  std::vector<i32> a(n * m + 2, 0);
  for (i32 i = 1; i <= n * m; i++) std::cin >> a[i];
  tar = a[1];
  std::sort(a.begin() + 1, a.begin() + n * m + 1, std::greater<i32>());
  i32 pos = 1;
  while (a[pos] != tar) pos++;
  i32 x = ceil((f64)pos / n), y = pos % n;
  if (y == 0) y = n;
  if (x % 2 == 0) y = n - y + 1;
  std::cout << x << " " << y << endl;
  return 0;
}
// *800.
