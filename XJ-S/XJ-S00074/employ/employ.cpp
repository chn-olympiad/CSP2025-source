#include <algorithm>
#include <cstdio>
#include <cctype>
using ll = long long;
constexpr int P = 998244353;
int read() {
  static int x; static char c; x = 0;
  while (!isdigit(c = getchar()));
  while (isdigit(c)) x = 10 * x + c - 48, c = getchar();
  return x;
}
int a[503], p[503];
int s[503];
int main() {
#ifdef _tqx
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#else
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
#endif
  int n, m; n = read(), m = read();
  for (int i = 1; i <= n; ++i) scanf("%1d", &s[i]);
  int cnt = n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (!a[i]) --cnt;
    p[i] = i;
  }
  if (cnt < m) puts("0");
  else {
    int ans = 0;
    do {
      int cnt = 0;
      for (int i = 1; i <= n; ++i) {
        if (cnt >= a[p[i]] || !s[i])
          ++cnt;
        if (n - cnt < m) break;
      }
      if (n - cnt >= m) ++ans;
    } while (std::next_permutation(p + 1, p + n + 1));
    printf("%d\n", ans);
  }
  return 0;
}