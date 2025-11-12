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
int n, q;
string s1[40005], s2[40005];
void Main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  For(i, 1, n) cin >> s1[i] >> s2[i];
  while (q--) {
    string t1, t2;
    cin >> t1 >> t2;
    if (ssz(t1) != ssz(t2)) {
      cout << "0\n";
      continue;
    }
    int ans = 0;
    For(i, 1, n) {
      For(j, 0, ssz(t1) - ssz(s1[i])) {
        if (t1.substr(j, ssz(s1[i])) == s1[i] && t1.substr(0, j) + s2[i] + t1.substr(j + ssz(s1[i])) == t2) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
}

int main() { return Main(), 0; }