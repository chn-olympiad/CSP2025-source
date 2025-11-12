#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> ump;
  while (n --) {
    string s, t;
    cin >> s >> t;
    ump[s] = t;
  }
  while (m --) {
    string s, t;
    cin >> s >> t;
    int l = s.size(), ans = 0;
    for (int i = 0; i < l; i ++) {
      for (int j = 1; i + j <= l; j ++) {
        // if (ump.find(s.substr(i, i + j))) {
        string rep = s;
        rep.replace(i, j, ump[s.substr(i, j)]);
        // cout << i << ' ' << j << ' ' << rep << ' ' << s.substr(i, j) << endl;
        ans += (rep == t);
        // }
      }
    }
    cout << ans << endl;
  }
}