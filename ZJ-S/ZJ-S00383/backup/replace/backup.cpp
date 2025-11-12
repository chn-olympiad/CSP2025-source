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
constexpr ll bs1 = 37, mod1 = 998244353, bs2 = 31, mod2 = 1e9 + 7;
int n, Q;
map<tuple<int, int, int, int>, int> cnt;
void append(pll &x, int v) {
  x.fi = (x.fi * bs1 + v) % mod1;
  x.se = (x.se * bs2 + v) % mod2;
}
void Main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> Q;
  For(i, 1, n) {
    static string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
      continue;
    pll v1{}, v2{};
    int p = 0, q = ssz(s1) - 1;
    while (s1[p] == s2[p])
      p++;
    while (s1[q] == s2[q])
      q--;
    assert(p <= q);
    For(j, p, q)
      append(v1, s1[j] - 'a' + 1), append(v2, s2[j] - 'a' + 1);
    cnt[{v1.fi, v1.se, v2.fi, v2.se}]++;
  }
  For(_, 1, Q) {
    static string t1, t2;
    cin >> t1 >> t2;
    if (_ == 101)
      cerr << t1 << ' ' << t2 << '\n';
    if (ssz(t1) != ssz(t2)) {
      cout << "0\n";
      continue;
    }
    int p = 0, q = ssz(t1) - 1;
    while (t1[p] == t2[p])
      p++;
    while (t1[q] == t2[q])
      q--;
    pll v1{}, v2{};
    For(j, p, q)
      append(v1, t1[j] - 'a' + 1), append(v2, t2[j] - 'a' + 1);
    tuple<int, int, int, int> key{v1.fi, v1.se, v2.fi, v2.se};
    auto it = cnt.find(key);
    cout << ((it != cnt.end()) ? it->se : 0) << '\n';
  }
}
}

int main() { return Main(), 0; }