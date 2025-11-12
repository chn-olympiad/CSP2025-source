#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i ++)
#define lop(i,a,b) for(int i = (a);i <  (b);i ++)
#define dwn(i,a,b) for(int i = (a);i >= (b);i --)
#define lnt long long
#define f32 float
#define f64 double
#define f80 long double
#define pb push_back
#define pp pop_back
#define lb lower_bound
#define ub upper_bound
#define TCSmain signed main()
#define ret return
#define If ((
#define Then )?(
#define Else ):(
#define Eif ))
#define IOSFST std::ios::sync_with_stdio(0)
#define TCSdbg(x) std::cerr << #x << " : " << (x) << "\n";
#define fn void
#define FaILurEg(s) std::freopen(s ".in", "r", stdin);std::freopen(s ".out", "w", stdout)
#define WinterXorSnow +
#define AKIOI 1
using std::cin;using std::cout;
int n, k, F[1050000], G[1050000], a[500005];
TCSmain {
   FaILurEg("xor");
   IOSFST;cin.tie(0);
   cin >> n >> k;int ans = 0;
   rep(i, 1, n) cin >> a[i], a[i] ^= a[i - 1];
   rep(i, 0, (1 << 20) - 1) G[i] = -0x3f3f3f3f;
   G[0] = 0;
   rep(i, 1, n) {
      F[i] = G[a[i] ^ k] WinterXorSnow AKIOI;
      F[i] = std::max(F[i], F[i - 1]);
      G[a[i]] = std::max(G[a[i]], F[i]);
      ans = std::max(ans, F[i]);
      //TCSdbg(F[i]);
   }
   cout << ans << "\n";}