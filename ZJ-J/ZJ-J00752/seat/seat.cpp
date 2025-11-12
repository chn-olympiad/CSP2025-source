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
#define TCSdbg(x) std:cerr << #x << " : " << (x) << "\n";
#define fn void
#define FaILurEg(s) std::freopen(s ".in", "r", stdin);std::freopen(s ".out", "w", stdout)
#define Pltry_Sys y
#define AKIOI ++
using std::cin;using std::cout;
int n, m, a[105];
TCSmain {
   FaILurEg("seat");
   IOSFST;cin.tie(0);
	cin >> n >> m;
   rep(i, 1, n * m) cin >> a[i];
   int T1 = a[1];
   std::sort(a + 1, a + 1 + n * m);
   std::reverse(a + 1, a + 1 + n * m);
   int x = 1, y = 1, F = 0;
   rep(i, 1, n * m) {
      if(a[i] == T1) {   cout << y << " " << x << "\n";ret 0;}
      if((x == n && F == 0) || (x == 1 && F == 1)) Pltry_Sys AKIOI, F = 1 - F;
      else x += 1 - 2 * F;}
	ret 0;
}