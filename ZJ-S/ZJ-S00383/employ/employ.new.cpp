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
int n, m, f[2][105][105], sum[505], C[505][505], A[505][505], fac[505], a[505];
char str[505];
il void add(int &x, int y) {
  ((x += y) >= mod) ? (x -= mod) : 0;
}

namespace Brute {
int f[2][1 << 18][19];
void solve() {
  f[0][0][0] = 1;
  For(i, 1, n) {
    int cur = i & 1, pre = cur ^ 1;
    memset(f[cur], 0, sizeof f[cur]);
    For(S, 0, (1 << n) - 1) For(j, 0, i - 1) if (f[pre][S][j]) {
      int val = f[pre][S][j];
      For(o, 0, n - 1) if (!(S >> o & 1)) {
        if (str[i] == '1' && i - 1 - j < a[o + 1])
          add(f[cur][S | 1 << o][j + 1], val);
        else
          add(f[cur][S | 1 << o][j], val);
      }
    }
  }
  int ans = 0;
  For(i, m, n) add(ans, f[n & 1][(1 << n) - 1][i]);
  cout << ans << '\n';
}
}

void Main() {
  // freopen("employ.in", "r", stdin);
  // freopen("employ.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> (char(&)[504])str[1];
  fac[0] = 1;
  For(i, 1, n) fac[i] = fac[i - 1] * ll(i) % mod;
  C[0][0] = 1;
  For(i, 1, n) {
    C[i][0] = C[i][i] = 1;
    For(j, 1, i - 1) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  For(i, 0, n) For(j, 0, i) A[i][j] = C[i][j] * ll(fac[j]) % mod;
  For(i, 1, n) cin >> a[i], sum[a[i]]++;
  For(i, 1, n + 1) sum[i] += sum[i - 1];

  m = n - m;
  f[0][0][0] = 1;
  For(i, 1, n) {
    int cur = i & 1, pre = cur ^ 1;
    memset(f[cur], 0, sizeof f[cur]);
    For(j, 0, i - 1) For(k, 0, i - 1 - j) if (f[pre][j][k]) {
      ll val = f[pre][j][k];
      if (str[i] == '1') {
        add(f[cur][j][k + 1], val * (k + 1) % mod);
        For(p, 0, min(k, sum[j + 1] - sum[j]))
          add(f[cur][j + 1][k - p], val * (sum[j] - i + 1 + k) % mod * C[sum[j + 1] - sum[j]][p] % mod);
      } else {
        For(p, 0, min(k, sum[j + 1] - sum[j])) {
          add(f[cur][j + 1][k - p], val * (sum[j] - i + 1 + k + sum[j + 1] - sum[j] - p) % mod * C[sum[j + 1] - sum[j]][p] % mod);
          add(f[cur][j + 1][k - p + 1], val * (k - p + 1) % mod * C[sum[j + 1] - sum[j]][p] % mod);
          if (i == 2 && !p)
            cerr << j << ' ' << p << ' ' << val << ' '  << (k - p + 1) << ' ' << C[sum[j + 1] - sum[j]][p] << '\n';
        }
      }
    }
    For(j, 0, i) For(k, 0, i - j) if (f[cur][j][k])
      cerr << i << ' ' << j << ' ' << k << ' ' << f[cur][j][k] << '\n';
  }
  int ans = 0;
  For(i, 0, m) For(j, 0, n) if (j == n - sum[i]) add(ans, ll(f[n & 1][i][j]) % mod);
  cout << ans << '\n';
}
}

int main() { return Main(), 0; }