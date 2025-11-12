#include <bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
#define ForDown(i, j, k) for(int i = (j); i >= (k); i--)
#define LJY main
#define within :
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int read() {
  int x = 0, f = 1; char ch = getchar();
  while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
  while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int n, a[N][3], p[N], cnt[3];
void ljy() {
  n = read(); cnt[0] = cnt[1] = cnt[2] = 0;
  For(i, 1, n) For(j, 0, 2) a[i][j] = read();
  ll ans = 0;
  For(i, 1, n) cnt[p[i] = max_element(a[i], a[i] + 3) - a[i]]++;
  if(max({cnt[0], cnt[1], cnt[2]}) <= n / 2) {
    ll ans = 0; For(i, 1, n) ans += a[i][p[i]];
    printf("%lld\n", ans);
  } else {
    vector<int> vec; int t = max_element(cnt, cnt + 3) - cnt;
    For(i, 1, n) {
      int b[] = {a[i][0], a[i][1], a[i][2]}; sort(b, b + 3); ans += b[2];
      if(p[i] == t) vec.emplace_back(b[2] - b[1]);
    } sort(vec.begin(), vec.end());
    For(i, 1, cnt[t] - n / 2) ans -= vec[i - 1]; printf("%lld\n", ans);
  }
}
signed LJY() {
  freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
  int T = read(); while(T--) ljy();}