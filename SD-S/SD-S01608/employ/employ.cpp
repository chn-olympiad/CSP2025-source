#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
const int N = 20 + 10, P = 998244353;
int n, m;
int a[N];
int c[N];
int p[N];
int ans;
signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; ++ i) {
    char ch;
    cin >> ch;
    a[i] = ch ^ 48;
    p[i] = i;
  } 
  for (int i = 1; i <= n; ++ i) {
    cin >> c[i];
  } 
  do {
    int cnt = 0;
    for (int i = 1; i <= n; ++ i) {
      if (!a[i]) {
        continue;
      }
      int k = i - 1 - cnt;
      if (k > c[p[i]] || i - 1 > c[p[i]]) {
        continue;
      }
      ++ cnt;
    }
    ans += cnt >= m; 
  } while (next_permutation(p + 1, p + n + 1));
  cout << ans % P << endl;
  return 0;
}


