#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
template<typename T>
void rd(T &x) {
  T f = 0; x = 0; char ch = getchar();
  while (ch < '0' || ch > '9') if (ch == '-') f = -1;
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
}
const int N = 2e5 + 10, base = 13331;
int n, q, tot;
string s, t;
map<pair<ull, ull>, int> mp;
map<ull, bool> mp2;
vector<ull> st[N];
mt19937_64 rnd(20100402);
int main() {
  // double sta = clock();
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  rd(n), rd(q);
  ull base2 = rnd();
  for (int i = 1; i <= n; ++i) {
    string p, q; cin >> p >> q;
    int m = p.size();
    ull h1 = 0, h2 = 0;
    int l = 0, r = m - 1;
    for (; l < m; ++l) if (p[l] != q[l]) break;
    for (; r >= 0; --r) if (p[r] != q[r]) break;
    for (int j = l; j <= r; ++j) {
      h1 = h1 * base + p[j], h2 = h2 * base + q[j];
    }
    ull h3 = 0, h4 = 0;
    for (int j = l - 1; j >= 0; --j) h3 = h3 * base + p[j];
    for (int j = r + 1; j < m; ++j) h4 = h4 * base + q[j];
    pair<int, int> tmp = {h1 * base2 + h2, h3};
    if (!mp[tmp]) mp[tmp] = ++tot;
    st[mp[tmp]].push_back(h4);
  }
  int cntt = 0;
  while (q--) {
    cin >> s >> t;
    cntt++;
    // if (cntt == 649) {
    //   cerr << s << ' ' << t << endl;
    // }
    if (s.size() != t.size()) { puts("0"); continue; }
    int m = s.size(), ans = 0;
    ull h1 = 0, h2 = 0;
    int l = 0, r = m - 1;
    for (; l < m; ++l) if (s[l] != t[l]) break;
    for (; r >= 0; --r) if (s[r] != t[r]) break;
    for (int j = l; j <= r; ++j) {
      h1 = h1 * base + s[j], h2 = h2 * base + t[j];
    }
    ull h3 = 0, h4 = 0;
    mp2.clear();
    mp2[0] = 1;
    for (int j = r + 1; j < m; ++j) h4 = h4 * base + s[j], mp2[h4] = 1;
    for (int j = l - 1; j >= 0; --j) {
      h3 = h3 * base + s[j];
      pair<int, int> tmp = {h1 * base2 + h2, h3};
      if (mp[tmp])
        for (auto k : st[mp[tmp]]) ans += mp2[k];
    }
    pair<int, int> tmp = {h1 * base2 + h2, 0};
    // if (cntt == 525) {
    //   cerr << l << ' ' << r << endl;
    // }
    if (mp[tmp])
      for (auto k : st[mp[tmp]]) ans += mp2[k];
    // if (cntt == 525) {
    //   cerr << ans << endl;
    // }
    cout << ans << endl;
  }
  // cerr << ((double)clock() - sta) / CLOCKS_PER_SEC << endl;
}
/*
gebduyucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrpavyxvtoobnaagrqnaqblorogkwljpaauytjbblfujxzjyeslmkgsrwhiwfdacprqrgofpanmgrhsitxppflpogfmgthoiovpqqxckapvgasnfepzcgkvtqfqyygcnjyhfpsapktq 
gebdnhvarpmcurogqsjnsymlzdmvilobyooplzkfvkhegxzrvcygauplfuyfkyakftyyxdsdswavyxvtoobnaagrqnaqblorogkwljpaauytjbblfujxzjyeslmkgsrwhiwfdacprqrgofpanmgrhsitxppflpogfmgthoiovpqqxckapvgasnfepzcgkvtqfqyygcnjyhfpsapktq

*/