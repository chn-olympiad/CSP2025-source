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
#define int long long
using namespace std ;
using ll = long long ;
using ull = unsigned long long ;
const int maxn = 2e4 + 5 ;
//const int inf = ;
//const int mod = ;
//const int base = ;

int n, m, k ;
struct E {
	int u, v, w ;
	bool operator < (const E &tmp) {
		return w < tmp.w ;
	}
}; 
vector<E> adj ;

struct dsu {
	int f[maxn], g[maxn] ;
	void init(int n ) {
		rep(i, 1 ,n) {
			f[i] = i ;
			g[i] = 1 ;
		}
	}
	int fnd(int x) {
		if(x == f[x]) return x ;
		f[x] = fnd(f[x]) ;
		return f[x] ;
	}
	void merge(int x, int y) {
		x = fnd(x), y = fnd(y) ;
		if(x == y) return;
		if(g[x] < g[y]) swap(x, y) ;
		f[y] = f[x] ;
		g[x] += g[y] ; 
	}
}d;

int ch[15] ;

int kru (vector<E> &x, int sz) {
	int cnt = 0  ;
	int res = 0 ;
	for(auto tmp : x) {
		int u = tmp.u, v = tmp.v, w = tmp.w ;
		if(d.fnd(u) == d.fnd(v)) continue ;
		cnt ++ ; res += w ; d.merge(u, v) ;
		if(cnt == sz - 1) return res ;
	}
}

int c[15], a[15][maxn] ;


//void subA() {
//	for(auto tmp : adj) {
//		int u = tmp.u, v = tmp.v, w = tmp.w ;
//		if()
//	}
//}

void solve() {
	cin >> n >> m >> k ;
	rep(i, 1, m) {
		int u, v, w ; cin >> u >> v >> w ;
		adj.push_back({u, v, w}) ;
	}
	rep(i, 1, k) {
		cin >> c[i] ;
		rep(j, 1, n) {
			cin >> a[i][j] ;
		}
	}
	bool vis = 1 ;
	rep(i, 1, k) {
		if(c[i]) {
			vis = 0 ;
			break ;
		}
	}
//	if(vis) {
//		subA() ;
//		return ;
//	}
	int tot = 4e18 ;
	rep(msk, 0, (1 << k) - 1ll) {
		rep(i, 1, k) {
			ch[i] = 0 ;
		}
		rep(i, 0, k - 1) {
			if((msk >> i) & 1ll) {
				ch[i+1] = 1 ;
			}
		}
		vector<E> ed = adj ;
		int ans = 0 ;
		int sz = n ;
		rep(i, 1, k) {
			if(ch[i] == 1) {
				ans += c[i] ;
				rep(j, 1, n) {
					ed.push_back({i + n, j, a[i][j]}) ;
				}
				sz ++ ;
			}
		}
//		cout << ans << endl ;
		sort(ed.begin(), ed.end()) ;
		d.init(n + k) ;
		int ans1 = kru(ed,sz) ;
//		cout << ans1 << endl ;
		tot = min(tot, ans1 + ans) ;
	}
	cout << tot << '\n' ;
}
signed main() {
	freopen("road.in", "r", stdin) ;
	freopen("road.out", "w", stdout) ;
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

