#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i <= b ; i++)
#define reb(i, a, b) for (int i = a; i <= b ; i--)
#define debug(x) cerr << #x << " = " << x << '\n' ;
#define ddd cerr << "Done."

using ll = long long ;

using namespace std ;
int n, m , k ; 
const int N = 2e6; 
struct node {
	int v, w ; 
};
struct edge {
	int u, v, w ;  
}e[N] ;
vector < node > g[N] ;  

int fa[N]; 

int getfa(int x) {
	return (fa[x] == x ? x : fa[x] = getfa(fa[x]) ); 
}
int cmp(edge &a, edge &b) {
	return a.w < b.w ; 
} 
int ans = 0 ; 
void kruscal() {
	
	rep(i, 1, n) fa[i] = i ; 
	sort(e+1, e+m+1, cmp) ; 
	rep(i, 1, m) {
		int u = e[i].u, v = e[i].v, w = e[i].w ; 
		if (getfa(u) != getfa(v)) {
			ans += w ; 
			fa[getfa(u)] = getfa(v) ;
		}
	}
	
}
int c[N], a[10][N] ; 
int main() {
 	freopen("road.in", "r", stdin) ;
	freopen("road.out", "w", stdout) ;
	cin >> n >> m >> k ;
	
	rep(i, 1, m) {
		int u, v, w ; 
		cin >> u >> v >> w ; 
		g[u].push_back({v, w}) ;  
		g[v].push_back({u, w}) ;  
		e[i] = {u, v, w} ; 
	}
	

	kruscal() ;
	
	cout << ans ; 

	return 0 ;
}

