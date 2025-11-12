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
int n = 1e4, m = n - 1, k = 10, V = 1e9 + 1;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void Main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << n << ' ' << m << ' ' << k << '\n';
  For(i, 2, n) cout << rnd() % (i - 1) + 1 << ' ' << i << ' ' << rnd() % V << '\n';
  // For(i, n, m) cout << rnd() % n + 1 << ' ' << rnd() % n + 1 << ' ' << rnd() % V << '\n';
  For(i, 1, k) For(j, 0, n) cout << rnd() % 100000 << " \n"[j == n];
}
}

int main() { return Main(), 0; }