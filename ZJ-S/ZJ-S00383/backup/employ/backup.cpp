#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define il inline
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define ssz(x) ((signed)((x).size()))
#define beg2ed(x) x.begin(), x.end()
#define For(i, j, k) for (int i = (j); i <= (k); i++)
#define ForDown(i, j, k) for (int i = (j); i >= (k); i--)

template <typename T> il void cmin(T &x, const T &y) { x = min(x, y); }
template <typename T> il void cmax(T &x, const T &y) { x = max(x, y); }

namespace {
constexpr int mod = 998244353;
int n, m, f[2][105][105][105], sum[505], C[505][505], A[505][505], fac[505], a[505];
char S[505];
il void add(int &x, int y) {
  ((x += y) >= mod) ? (x -= mod) : 0;
}
void Main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> (char(&)[504])S[1];
  m = n - m;
  fac[0] = 1;
  For(i, 1, n) fac[i] = fac[i - 1] * ll(i) % mod;
  For(i, 1, n) {
    C[i][0] = C[i][i] = 1;
    For(j, 1, i - 1) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  For(i, 1, n) For(j, 0, i) A[i][j] = C[i][j] * ll(fac[j]) % mod;
  For(i, 1, n) cin >> a[i], sum[a[i]]++;
  For(i, 1, n + 1) sum[i] += sum[i - 1];
  f[0][0][0][0] = 1;
  For(i, 1, n) {
    int cur = i & 1, pre = cur ^ 1;
    memset(f[cur], 0, sizeof f[cur]);
    For(j, 0, n) For(c1, 0, m) For(c2, 0, m - c1) if (f[pre][j][c1][c2]) {
      ll val = f[pre][j][c1][c2];
      if (S[i] == '1') {
        add(f[cur][j][c1][c2], val * (sum[n] - sum[j] - c2) % mod);
        For(p, 0, min(c2, sum[j + 1] - sum[j]))
          add(f[cur][min(j + 1, n)][c1 + p + 1][c2 - p], val * (sum[j] - c1) % mod * A[c2][p] % mod);
      } else {
        For(p, 0, min(c2, sum[j + 1] - sum[j])) {
          add(f[cur][min(j + 1, n)][c1 + p + 1][c2 - p], val * (sum[j + 1] - c1 - p) % mod * A[c2][p] % mod);
          add(f[cur][min(j + 1, n)][c1 + p][c2 - p + 1], val * A[c2][p] % mod);
        }
      }
    }
    For(j, 0, n) For(c1, 0, m) For(c2, 0, m - c1) if (f[cur][j][c1][c2])
      cerr << i << ' ' << j << ' ' << c1 << ' ' << c2 << ' ' << f[cur][j][c1][c2] << '\n';
  }
  int ans = 0;
  For(i, 0, n) For(j, 0, m) For(k, 0, m - j) add(ans, f[n & 1][i][j][k]);
  cout << ans << '\n';
}
}

int main() { return Main(), 0; }