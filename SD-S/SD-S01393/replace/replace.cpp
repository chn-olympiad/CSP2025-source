#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);i++)
#define sz(x) (int((x).size()))
using namespace std;
constexpr int N = 2e5 + 5, MM = 5e6 + 5;
const int M[2] = {1000000009, 998244853}, B = 233;
using ll = long long;
int n, q;
vector<int> S[40 * 40];
string s[N][3];
ll h[MM][3], ht[MM][3], b[MM][3];
inline int g(char a, char b) {
  return (a - 'a' + 1) * 26 + b - 'a' + 1;
}
inline ll qry(int l, int r, int m) {
  return (ht[r][m] - ht[l - 1][m] * b[r - l + 1][m] % M[m] + M[m]) % M[m];
}
void work() {
  string t1, t2;
  cin >> t1 >> t2;
  int len = sz(t1), tlen = len;
  if (len == 1) {
    int ans = 0;
    fo(i, 1, n) ans += ((s[i][1] == t1) && (s[i][2] == t2));
    cout << ans << "\n";
    return ;
  }
  t1 = " " + t1 + "a";
  t2 = " " + t2 + "a";
  int l = len, r = 1;
  fo(i, 1, len)
  if (t1[i] != t2[i])
    l = min(l, i), r = max(r, i);
  fo(mod, 0, 1) fo(i, 1, len) ht[i][mod] = (ht[i - 1][mod] * B + g(t1[i], t2[i])) % M[mod];
  int ans = 0;
  fo(i, 1, l) {
    int x = t1[i], y = t1[i + 1];
    for (int j : S[g(x, y)]) {
      int len = s[j][1].size();
      if (i + len >= tlen) continue;
      ll hs1 = qry(i, i + len - 1, 0), hs2 = qry(i, i + len - 1, 1);
      if (hs1 == h[j][0] && hs2 == h[j][1] && len + i - 1 >= r) ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> q;
  b[0][0] = b[0][1] = 1;
  fo(i, 1, 2000000) fo(j, 0, 1)
  b[i][j] = b[i - 1][j] * B % M[j];
  fo(i, 1, n) {
    cin >> s[i][1] >> s[i][2];
    int len = s[i][1].size();
    if (len == 1)
      fo(j, 'a', 'z') S[g(s[i][1][0], j)].push_back(i);
    else
      S[g(s[i][1][0], s[i][1][1])].push_back(i);
    s[i][1] = " " + s[i][1];
    s[i][2] = " " + s[i][2];
    fo(mod, 0, 1) {
      fo(j, 1, len) h[i][mod] = (h[i][mod] * B + g(s[i][1][j], s[i][2][j])) % M[mod];
    }
  }
  while (q--)  work();

  return 0;
}

