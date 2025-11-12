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
constexpr int MAXN = 1e5 + 5;
int T, n, a[MAXN][3];
vector<int> dlt[3];
void Main() {
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> n;
    dlt[0].clear(), dlt[1].clear(), dlt[2].clear();
    ll sum = 0;
    For(i, 1, n) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
      if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
        sum += a[i][0], dlt[0].eb(a[i][0] - max(a[i][1], a[i][2]));
      else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2])
        sum += a[i][1], dlt[1].eb(a[i][1] - max(a[i][0], a[i][2]));
      else
        assert(a[i][2] >= a[i][0] && a[i][2] >= a[i][1]),
        sum += a[i][2], dlt[2].eb(a[i][2] - max(a[i][0], a[i][1]));
    }
    For(o, 0, 2) if (ssz(dlt[o]) > n / 2) {
      sort(beg2ed(dlt[o]));
      For(i, 0, ssz(dlt[o]) - n / 2 - 1)
        sum -= dlt[o][i];
      break;
    }
    cout << sum << '\n';
  }
}
}

int main() { return Main(), 0; }