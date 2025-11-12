#include <bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
#define ForDown(i, j, k) for(int i = (j); i >= (k); i--)
#define LJY main
#define within :
using namespace std;
typedef long long ll;
const int N = 10015, M = 1e6 + 5, inf = 1e9 + 5;
char buf[M << 2], *p1, *p2;
#define getchar() ((p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, M << 2, stdin), p1 == p2)) ? 0 : *p1++)
int read() {
  int x = 0, f = 1; char ch = getchar();
  while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
  while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int n, m, k, fa[N]; int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
array<int, 3> e[M];
int c[15]; ll sum[1 << 10];
vector<array<int, 3> > vec[15];
vector<array<int, 3> > f[1 << 10], g;
signed LJY() {
  freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
  n = read(), m = read(), k = read();
  For(i, 1, m) e[i][1] = read(), e[i][2] = read(), e[i][0] = read();
  int tmp = 0; For(i, 1, n) fa[i] = i;
  sort(e + 1, e + 1 + m);
  For(i, 1, m) {
    int x = find(e[i][1]), y = find(e[i][2]);
    if(find(x) != find(y)) fa[find(x)] = find(y), e[++tmp] = e[i];
  } f[0] = vector<array<int, 3> >(e + 1, e + n);
  For(i, 1, k) {
    c[i] = read(); sum[1 << i - 1] = c[i];
    vec[i].resize(n); For(j, 1, n) vec[i][j - 1] = {read(), j, i + n};
    sort(vec[i].begin(), vec[i].end());
  } sum[0] = 0; For(S, 1, (1 << k) - 1) sum[S] = sum[S & -S] + sum[S & (S - 1)];
  For(S, 1, (1 << k) - 1) {
    int pcnt = __builtin_popcount(S); g.resize(pcnt + 2 * n - 2);
    merge(f[S & (S - 1)].begin(), f[S & (S - 1)].end(), vec[__lg(S & -S) + 1].begin(), vec[__lg(S & -S) + 1].end(), g.begin());
    For(i, 1, n + k) fa[i] = i;
    f[S].resize(pcnt + n - 1); int c = 0;
    for(auto [w, u, v] within g) {
      u = find(u), v = find(v);
      if(find(u) != find(v)) {
        fa[find(u)] = find(v), f[S][c++] = {w, u, v};
        if(c == pcnt + n - 1) break;
      }
    }
  } ll ans = 1e18;
  For(S, 0, (1 << k) - 1) {
    ll res = sum[S];
    for(auto [w, u, v] within f[S]) res += w; ans = min(ans, res);
  } printf("%lld\n", ans);
}