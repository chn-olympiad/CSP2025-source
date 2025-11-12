#include<bits/stdc++.h>
#define fo(i,a,b) for(int i =(a);i<=(b);i++)
using namespace std;
const int N = 15, M = 998244353;
using ll = long long;
int n, m, c[N];
ll f[1 << 18][20];
string s;
int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m;
  cin >> s;
  s = " " + s;
  fo(i, 1, n) cin >> c[i];
  auto g = [](int i, int j) {
    return (i >> (j - 1)) & 1;
  };
  fo(i, 1, n) {
    f[1 << (i - 1)][s[1] == '1' && (c[i] != 0)] = 1;
  }
  fo(i, 1, (1 << n) - 1) {
    int tot = __builtin_popcount(i);
    fo(j, 0, tot) {
      fo(k, 1, n) {
        if (g(i, k) == 0) {
          int die = tot - j, ok = 1;
          if (die >= c[k] || s[tot + 1] == '0') ok = 0;
          f[i | (1 << (k - 1))][j + ok] += f[i][j] %= M;
        }
      }
    }
  }
  ll ans = 0;
  fo(i, m, n) ans = (ans + f[(1 << n) - 1][i]) % M;
  cout << ans;
}
