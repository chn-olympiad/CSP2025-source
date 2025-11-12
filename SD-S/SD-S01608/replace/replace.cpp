#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define int ll
const int N = 2e5 + 10;
int n, q;
unordered_map<string, string> mp;
string s1, s2;
signed main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++ i) {
    cin >> s1 >> s2;
    mp[s1] = s2;
    mp[s2] = s1;
  }
  while (q --) {
    int ans = 0;
    cin >> s1 >> s2;
    int m = s1.size();
    for (int l = 0; l < m; ++ l) {
      for (int len = 1; len <= m - l; ++ len) {
        string s = s1.substr(l, len);
        if (mp.count(s)) {
          if (s1.substr(0, l) + mp[s] + s1.substr(l + len) == s2){
            ++ ans;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}


