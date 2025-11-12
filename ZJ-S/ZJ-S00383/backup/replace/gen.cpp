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
int n = 10, q = 30;
string s1[35], s2[35];
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
void Main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << n << ' ' << q << '\n';
  For(i, 1, n) {
    int l = rnd() % 3 + 1;
    For(j, 1, l) s1[i] += char(rnd() % 4 + 'a');
    For(j, 1, l) s2[i] += char(rnd() % 4 + 'a');
    cout << s1[i] << ' ' << s2[i] << '\n';
  }
  For(i, 1, q) {
    int l = rnd() % 5 + 1;
    string t1 = "", t2 = "";
    For(j, 1, l) {
      char ch = rnd() % 4 + 'a';
      t1 += ch, t2 += ch;
    }
    int p = rnd() % n + 1;
    t1 += s1[p], t2 += s2[p];
    l = rnd() % 5 + 1;
    For(j, 1, l) {
      char ch = rnd() % 4 + 'a';
      t1 += ch, t2 += ch;
    }
    while (t1 == t2) t2.back() = rnd() % 4 + 'a';
    assert(islower(t2.back()));
    cout << t1 << ' ' << t2 << '\n';
  }
}
}

int main() { return Main(), 0; }