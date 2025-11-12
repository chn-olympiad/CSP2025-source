#include <algorithm>
#include <cstdio>
#include <cctype>
using ll = long long;
constexpr int N = 1e5 + 3;
int read() {
  static int x; static char c; x = 0;
  while (!isdigit(c = getchar()));
  while (isdigit(c)) x = 10 * x + c - 48, c = getchar();
  return x;
}
int a[N][3], b[N][3];
int pos[N];
int cnt[3];
void task() {
  int n = read();
  cnt[0] = cnt[1] = cnt[2] = 0;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
    b[i][0] = 0, b[i][1] = 1, b[i][2] = 2;
    std::sort(b[i], b[i] + 3, [&](int x, int y) {
      return a[i][x] > a[i][y];
    });
    ++cnt[b[i][0]];
    ans += a[i][b[i][0]];
  }
  if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2)
    printf("%d\n", ans);
  else {
    int p = cnt[0] <= n / 2 ? cnt[1] <= n / 2 ? 2 : 1 : 0;
    int m = 0;
    for (int i = 1; i <= n; ++i) {
      if (b[i][0] == p) pos[++m] = i;
    }
    std::sort(pos + 1, pos + m + 1, [&](int x, int y) {
      return a[x][b[x][0]] - a[x][b[x][1]] <
             a[y][b[y][0]] - a[y][b[y][1]];
    });
    for (int i = 1; i <= cnt[p] - n / 2; ++i) {
      ans += a[pos[i]][b[pos[i]][1]] - a[pos[i]][b[pos[i]][0]];
    }
    printf("%d\n", ans);
  }
}
int main() {
#ifdef _tqx
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#else
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
#endif
  int T = read();
  while (T--) task();
  return 0;
}