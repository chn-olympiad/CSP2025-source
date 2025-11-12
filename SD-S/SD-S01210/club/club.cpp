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
#define fi first 
#define se second
#define int long long
using namespace std ;
using ll = long long ;
using ull = unsigned long long ;
const int maxn = 1e5 + 5 ;
const int inf = 2e9;
//const int mod = ;
//const int base = ;

int n ; 
pii a[maxn][5] ;

int id[maxn] ;
bool cmp(int x, int y) { 
return a[x][1].fi > a[y][1].fi ;
}
int cnt[5] , mn[5],  mnid[5];
priority_queue<int> q[4] ;
void solve() {
	cin >> n ;
	rep(i, 1, 3) {
		cnt[i] = 0, mn[i] = inf, mnid[i] = 0 ;
		while(!q[i].empty()) q[i].pop() ;
	}
	rep(i, 1, n) {
		rep(j, 1, 3) {
			cin >> a[i][j].fi ;
			a[i][j].se = j ;
		}
		sort(a[i] + 1, a[i] + 1 + 3, greater<pii>()) ;	
	}
	int ans = 0 ;
	rep(i, 1, n) {
		cnt[a[i][1].se] ++ ;
		ans += a[i][1].fi ;
		q[a[i][1].se].push(-(a[i][1].fi - a[i][2].fi)) ;
	}
	int l = n / 2, id = -1 ;
	rep(i, 1, 3) {
		if(cnt[i] > l) {
			id=  i ;
			break ;
		}
	}
	if(id == -1) {
		cout << ans << '\n' ;
		return ;
	}
	 
	rep(i, l + 1, cnt[id]) {
		ans += q[id].top() ;
//		cout << "err "   << q[id].top() << endl ;
		q[id].pop() ;
	}
	cout << ans << '\n' ;
}
signed main() {
	freopen("club.in", "r", stdin) ;
	freopen("club.out", "w", stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0), cout.tie(0) ;
	int T = 1 ;
	cin >> T ;
	while(T -- ) {
		solve() ;
	}
	return 0 ;
}


// rp++!!!

// i will win csps2025 /fendou

