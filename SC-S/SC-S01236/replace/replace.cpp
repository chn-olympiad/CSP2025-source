#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e4 + 10;

int n, q;
string s1[MAXN], s2[MAXN];

signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s1[i] >> s2[i];
  }
  while (q--) {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int j = 0; j < s.length(); j++) {
      bool fl = 0;
      for (int i = 1; i <= n; i++) {
        int k = 0;
        while (k < s1[i].length() && j + k < s.length() && s[j + k] == s1[i][k]) {
          k++;
        }
        if (k >= s1[i].length()) {
          bool flag = 1;
          for (int k = 0; k < s1[i].length(); k++) {
//            cout << s2[i][k] << t[j + k] << endl;
            if (s2[i][k] != t[j + k]) flag = 0;
          }
          for (int k = j + s1[i].length(); k < s.length(); k++) {
            if (s[k] != t[k]) flag = 0;
          }
          ans += flag;
        }
      }
      if (s[j] != t[j]) break;
    }
    cout << ans << endl;
  }
  return 0;
}