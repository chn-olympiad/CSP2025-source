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
int n, m, a[25], f[2][1 << 18][19];
char str[25];
il void add(int &x, int y) {
  ((x += y) >= mod) ? (x -= mod) : 0;
}
void Main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> (char(&)[24])str[1];
  For(i, 0, n - 1) cin >> a[i];
  f[0][0][0] = 1;
  For(i, 1, n) {
    int cur = i & 1, pre = cur ^ 1;
    memset(f[cur], 0, sizeof f[cur]);
    For(S, 0, (1 << n) - 1) For(j, 0, i - 1) if (f[pre][S][j]) {
      int val = f[pre][S][j];
      For(o, 0, n - 1) if (!(S >> o & 1)) {
        if (str[i] == '1' && i - 1 - j < a[o])
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

int main() { return Main(), 0; }