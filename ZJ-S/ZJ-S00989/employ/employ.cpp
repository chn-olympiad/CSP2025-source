#include <bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
#define ForDown(i, j, k) for(int i = (j); i >= (k); i--)
#define LJY main
#define within :
using namespace std;
typedef long long ll;
const int N = 505, mod = 998244353;
ll qpow(ll a, int k) {ll s = 1; while(k) {if(k & 1) s = s * a % mod; a = a * a % mod; k >>= 1;} return s;}
int read() {
  int x = 0, f = 1; char ch = getchar();
  while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
  while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int n, m, c[N], lim[N], sum[N], cnt[N]; char s[N];
ll fac[N], ifac[N], f[3][N][N];
signed LJY() {
  freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
  n = read(), m = read(); scanf("%s", s + 1);
  fac[0] = 1; For(i, 1, n) fac[i] = fac[i - 1] * i % mod; ifac[n] = qpow(fac[n], mod - 2);
  ForDown(i, n, 1) ifac[i - 1] = ifac[i] * i % mod;
  For(i, 1, n) c[i] = read(), cnt[c[i]]++;
  sum[0] = cnt[0]; For(i, 1, n) sum[i] = sum[i - 1] + cnt[i];
  f[0][0][0] = 1; int c0 = 0;
  For(i, 1, n) {
    if(s[i] == '0') {
      For(j, 0, c0) For(p, 1, cnt[i - j]) For(k, 1, c0) if(f[0][j][k])
        f[0][j][k - 1] = (f[0][j][k - 1] + k * f[0][j][k]) % mod;
    } else {
      memset(f[1], 0, sizeof(f[1])); memcpy(f[2], f[0], sizeof(f[2]));
      For(j, 0, c0) For(k, 0, c0) if(f[0][j][k]) f[1][j + 1][k + 1] = (f[1][j + 1][k + 1] + f[0][j][k]) % mod;
      For(j, 0, c0) For(k, 0, c0) if(f[2][j][k]) f[2][j][k] = f[2][j][k] * max(0, sum[i - j - 1] - (c0 - k)) % mod;
      For(j, 0, c0) For(p, 1, cnt[i - j]) For(k, 1, c0) if(f[2][j][k])
        f[2][j][k - 1] = (f[2][j][k - 1] + k * f[2][j][k]) % mod;
      c0++; For(j, 0, c0) For(k, 0, c0) f[0][j][k] = (f[1][j][k] + f[2][j][k]) % mod;
    }
  } ll ans = 0;
  For(j, 0, c0) For(p, 1, n - sum[n - j]) For(k, 1, c0) if(f[0][j][k])
    f[0][j][k - 1] = (f[0][j][k - 1] + k * f[0][j][k]) % mod;
  For(i, m, c0) ans = (ans + f[0][i][0]) % mod; printf("%lld\n", ans * fac[n - c0] % mod);
}