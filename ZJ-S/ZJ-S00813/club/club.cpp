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
int n, a[100005][3];
std::vector<int> G[3];
bool TCmpS0(int x, int y) {// x < y -> Deltax < Deltay        To make Delta less goto front
   return std::min(a[x][0] - a[x][1], a[x][0] - a[x][2]) < std::min(a[y][0] - a[y][1], a[y][0] - a[y][2]); }
bool TCmpS1(int x, int y) {// x < y -> Deltax < Deltay        To make Delta less goto front
   return std::min(a[x][1] - a[x][0], a[x][1] - a[x][2]) < std::min(a[y][1] - a[y][0], a[y][1] - a[y][2]); }
bool TCmpS2(int x, int y) {// x < y -> Deltax < Deltay        To make Delta less goto front
   return std::min(a[x][2] - a[x][0], a[x][2] - a[x][1]) < std::min(a[y][2] - a[y][0], a[y][2] - a[y][1]); }
fn solve() {
   //std::cerr << "SOLVE" << std::endl;
   lnt ans = 0;
   cin >> n;G[0].clear(), G[1].clear(), G[2].clear();
   rep(i, 1, n) cin >> a[i][0] >> a[i][1] >> a[i][2],
      If std::max({a[i][0],a[i][1],a[i][2]}) == a[i][0] Then G[0].pb(i), ans += a[i][0]
      Else If std::max({a[i][0],a[i][1],a[i][2]}) == a[i][1] Then G[1].pb(i), ans += a[i][1]
      Else G[2].pb(i), ans += a[i][2]
      Eif Eif;//Thats very ok
   if(G[0].size() > n / 2) {
      std::sort(G[0].begin(), G[0].end(), TCmpS0);
      // 0 ~ size - n/ 2 - 1
      lop(i, 0, G[0].size() - n / 2) 
         ans -= std::min(a[G[0][i]][0] - a[G[0][i]][1], a[G[0][i]][0] - a[G[0][i]][2]);
   }
   elif(G[1].size() > n / 2) {
      std::sort(G[1].begin(), G[1].end(), TCmpS1);
      // 0 ~ size - n/ 2 - 1
      lop(i, 0, G[1].size() - n / 2) 
         ans -= std::min(a[G[1][i]][1] - a[G[1][i]][0], a[G[1][i]][1] - a[G[1][i]][2]);
   }
   elif(G[2].size() > n / 2){
      std::sort(G[2].begin(), G[2].end(), TCmpS2);
      // 0 ~ size - n/ 2 - 1
      lop(i, 0, G[2].size() - n / 2) 
         ans -= std::min(a[G[2][i]][2] - a[G[2][i]][0], a[G[2][i]][2] - a[G[2][i]][1]);
   }
   cout << ans << "\n";
}
TCSmain {
   FaILurEg("club");
   IOSFST;
   int T;cin >> T;
   while(T --) 
      solve();
   ret 0;
}