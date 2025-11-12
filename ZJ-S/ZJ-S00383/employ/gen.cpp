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
int n = 3;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void Main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << n << ' ' << rnd() % n + 1 << '\n';
  For(i, 1, n) cout << rnd() % 2;
  cout << '\n';
  For(i, 1, n) cout << rnd() % (n + 1) << " \n"[i == n];
}
}

int main() { return Main(), 0; }