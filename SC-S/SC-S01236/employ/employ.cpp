#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

const int MAXN = 500 + 10;
const int mod = 998244353;

int n, m, p[15], a[MAXN], ans;
char s[MAXN];
bool vis[MAXN], flag;

void dfs(int pos = 1) {
  if (pos > n) {
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
      if (i - tmp - 1 < a[p[i]] && s[i] == '1') tmp++;
      if (tmp >= m) {
        ans++;
        return;
      }
    }
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    p[pos] = i;
    dfs(pos + 1);
    vis[i] = 0;
  }
  return;
}

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  flag = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (s[i] != '1') flag = 0;
  }
  if (n <= 10) {
    dfs();
    cout << ans % mod << endl;
  } else if (flag){
    ans = 1;
    for (int i = 1; i <= n; i++) {
      ans *= i;
      ans %= mod;
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}