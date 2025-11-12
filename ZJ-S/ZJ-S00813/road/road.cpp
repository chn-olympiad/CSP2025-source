#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define lop(i,a,b) for(int i = (a);i <  (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define lnt long long
#define f32 float
#define f64 double
#define f80 long double
#define snt short
#define hnt char
#define fn void
#define lb lower_bound
#define ub upper_bound
#define TCSmain signed main()
#define ret return
#define If ((
#define Then )?(
#define Else ):(
#define Eif ))
#define pb push_back
#define pp pop_back
#define elif else if
#define i64 1ll
#define TCSdbg(x) cout << #x << " " << (x) << "\n";
#define IOSFST std::ios::sync_with_stdio(0)
#define FaILurEg(s) freopen(s ".in", "r", stdin);freopen(s ".out", "w", stdout);
using std::cin;using std::cout;
# define int long long
int n, m, k;
std::pair<int, std::pair<int, int> > E[2000005];
int C[15], A[15][10005], Fv[15][10005][2];// 0 for upd 1 for calc
lnt ans = 0x3f3f3f3f3f3f3f3f;

int f[20005];
int find(int x){return If f[x] == x Then x Else f[x] = find(f[x]) Eif;}

int DDDD = 0;
fn ADD(int K,int M) {
   rep(i, 1, n) E[m + M + i] = {A[K][i], {n + K, i}};
}
std::string s;
fn D(int I, int M, int N) {
   if(I == k + 1) {
      //cout << s << "\n";
      rep(i, 1, n + k) f[i] = i;
      std::sort(E + 1, E + 1 + m + M);
      int cnt = 0, res = 0;
      rep(i, 1, m + M) {
         int U = E[i].second.first, V = E[i].second.second, W = E[i].first;
         if(find(U) == find(V)) continue;
         else cnt ++, f[f[U]] = f[V], res += W;//, cout << U << "->" << V << "\n";
         if(cnt == n + N - 1) break;
      }
      //cout << res + DDDD << "\n";
      ans = std::min(ans, res + DDDD);
      ret;
   }
   D(I + 1, M, N);
   ADD(I, M);
   DDDD += C[I];
   D(I + 1, M + n, N + 1);
   DDDD -= C[I];
}

TCSmain {
   FaILurEg("road");
   cin >> n >> m >> k;
   rep(i, 1, m) {int u, v, w;cin >> u >> v >> w;E[i] = {w, {u, v}};}
   //std::sort(E + 1, E + 1 + m);
   // int cnt = 0;
   // rep(i, 1, m) {
   //    int U = E[i].second.first, V = E[i].second.second, W = E[i].first;
   //    if(find(U) == find(V)) continue;
   //    else cnt ++, f[f[U]] = f[V], G[U].pb({V, W}), G[V].pb({U, W});
   //    if(cnt == n - 1) continue;
   // }
   rep(i, 1, k) {cin >> C[i];rep(j, 1, n) cin >> A[i][j];}
   //DFS(1, 0);
   D(1, 0, 0);
   cout << ans << "\n";
   ret 0;
}