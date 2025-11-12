#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b ; i++)
#define reb(i, a, b) for (int i = a; i <= b ; i--)  
#define debug(x) cerr << #x << " = " << x << '\n' ; 
#define ddd cerr << "Done." ;

using ll = long long ; 

using namespace std ; 
const int N = 1e6 ; 
int n ; 
struct node {
	int x, y ; 
};
node a[N][5] ;

int cmp(node &a, node &b) {
	if (a.x == b.x) return a.y < b.y ; 
	return a.x > b.x ; 
}
int c[N], t[10]; 
void solve() { int ans = 0 ;
	memset(t, 0, sizeof t) ;//memset(c, 0, sizeof c) ;memset(a, 0, sizeof a) ;
	cin >> n ;
	rep(i, 1, n) {
		rep(j, 1, 3) {
			cin >> a[i][j].x ; 
			a[i][j].y = j ;
		}
		sort(a[i] + 1, a[i] + 3 + 1, cmp) ;  
//		rep(j, 1, 3) {
//			cerr <<  a[i][j].x << ' '; 
		//	a[i][j].y = j ;
		
//		} cerr << '\n' ; 
//		rep(j, 1, 3) {
//			cerr <<  a[i][j].y << ' '; 
		//	a[i][j].y = j ;
		
//		} cerr << '\n' ; 
		c[i] = a[i][1].x - a[i][2].x ;
		t[a[i][1].y] ++ ; ans += a[i][1].x ;
//		debug(a[i][1].x) ;// debug(a[i][1].y) ; 
//		debug(a[i][2].x) ;// debug(a[i][2].y) ; 
	//	debug(c[i]) ; 
	} 
//	debug(ans) ;
	int pos = -1 ; 
	rep(i, 1, 3) {
		if (t[i] > (n / 2))  pos = i ;  
	} 
//		debug(t[i]) ;  
	}
	if (pos == -1) {
		cout << ans << '\n' ;return ;
//	debug(pos) ; 
	int k = t[pos] - (n / 2) ; // cha duo sha 
//	debug(k) ; 
//	rep(i, 1, n) {debug(c[i]) ; debug(i) ; }
	sort (c+1, c+n+1) ; 
//	rep(i, 1, n) {debug(c[i]) ; debug(i) ; }
//	rep(i, 1, n) {
	//	debug(c[i]) ; 
	//	debug( a[i][1].x - a[i][2].x ) ; 
//	}
	rep(i, 1, k) {
		ans = ans - c[i] ; 
//		debug(c[i]) ;
	}
	cout << ans << '\n' ; 
}
///////////////
int main() {
//	ios::sync_with_stdio(0) ; 
// 	freopen("in.in", "r", stdin) ; 
//	freopen("out.err", "w", stderr) ;  

 	freopen("club.in", "r", stdin) ;
	freopen("club.out", "w", stdout) ;
	int T ; cin >> T ; 
	while (T --) {
		solve() ; 
	}
	
	
	return 0 ; 
}
