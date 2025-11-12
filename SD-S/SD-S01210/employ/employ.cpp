#include<bits/stdc++.h>
#define x1 Sun
#define y1 Jude
#define x0 rp
#define y0 GetWC
#define rep(i, a, b) for(int (i) = (a); (i) <= (b); (i) ++ )
#define per(i, a, b) for(int (i) = (a); (i) >= (b); (i) -- )
#define vi vector<int>
#define pii pair<int, int>
#define ls (x << 1)
#define rs (x << 1 | 1)
using namespace std ;
using ll = long long ;
using ull = unsigned long long ;
const int maxn = 105;
//const int inf = ;
const int mod = 998244353 ;
//const int base = ;

int n, m ;
string s ;
int c[maxn] ;
int p[maxn] ;
bool vis[maxn] ;
int ans ;
void dfs(int u) {
	if(u == n + 1) {
		int res =  0;
		int xxx =  0 ; 
		rep(i, 1, n) {
			if(s[i] == '0'  || c[p[i]] <= xxx) xxx++ ;
			else res ++ ;
		}
		if(res >= m) ans ++ ;
		return ;
	}
	rep(i, 1, n) {
		if(vis[i]) continue ;
		vis[i] = 1; 
		p[u] = i ;
		dfs(u + 1 ) ;
		vis[i] = 0 ;
	}
} 

void solve() {
	cin >> n >> m >> s;
	s= '#'+s ; 
	rep(i, 1, n) {
		cin >> c[i] ; 
	}
	dfs(1) ;
	cout << ans << endl ;
}
signed main() {
	freopen("employ.in", "r", stdin) ;
	freopen("employ.out", "w", stdout) ;
ios::sync_with_stdio(false) ;
	cin.tie(0), cout.tie(0) ;
	int T = 1 ;
//	cin >> T ;
	while(T -- ) {
		solve() ;
	}
	return 0 ;
}


// rp++!!!

// i will win csps2025 /fendou

