#include <bits/stdc++.h>
#define int long long

using namespace std;

const int P = 998244353, N = 500 + 10;

int n, m, c[N], fac[N], fin[N], inv[N], sum[N];
int cnt[N], f[N][N], g[N][N], C[N][N], A[N][N]; char s[N];

void init() {
  for (int i : {0, 1}) inv[i] = fac[i] = fin[i] = 1;
  for (int i = 2; i < N; i ++)
    inv[i] = (P - P / i) * inv[P % i] % P,
    fac[i] = fac[i - 1] * i % P, fin[i] = fin[i - 1] * inv[i] % P;

  for (int n = 0; n < N; n ++)
    for (int m = 0; m < N; m ++)
      C[n][m] = n < m ? 0 : fac[n] * fin[m] % P * fin[n - m] % P,
      A[n][m] = n < m ? 0 : fac[n] * fin[n - m] % P;
}

signed main() {

  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  
  init(), scanf("%lld%lld%s", &n, &m, s + 1);
  for (int i = 1; i <= n; i ++) {
    int x; scanf("%lld", &x), cnt[x] ++;
  }

  for (int i = n; ~i; i --) 
    sum[i] = sum[i + 1] + cnt[i];

  f[0][cnt[0]] = 1;
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j <= i; j ++)
      for (int x = 0; x <= n - i; x ++) if (f[j][x]) {
        int y = sum[j + 1] - ((n - i) - x);
        if (s[i + 1] == '1') {
          (g[j][x] += f[j][x]) %= P; int tmp = f[j][x] * x % P;
          if (x) for (int t = 0; t <= min(cnt[j + 1], y); t ++) {
            int r = cnt[j + 1] - t;
            (g[j + 1][x + r - 1] += tmp * C[cnt[j + 1]][t] % P * A[y][t]) %= P;
          }
        } else {
          for (int t = 0; t <= min(cnt[j + 1], y); t ++) {
            int r = cnt[j + 1] - t, coef = A[y][t] * C[cnt[j + 1]][t] % P;
            if (r) (g[j + 1][x + r - 1] += f[j][x] * C[y][t] % P * A[cnt[j + 1]][t + 1]) %= P; 
            if (x) (g[j + 1][x + r - 1] += f[j][x] * x % P * coef) %= P; 
            (g[j + 1][x + r] += f[j][x] * coef) %= P;
          }
        }
      }
    
    for (int j = 0; j <= i + 1; j ++)
      for (int x = 0; x <= n - (i + 1); x ++)
        f[j][x] = g[j][x], g[j][x] = 0; 
  }

  int ans = 0;
  for (int i = 0; i <= n - m; i ++)
    (ans += f[i][0] * fac[sum[i + 1]]) %= P;

  printf("%lld\n", ans);
}