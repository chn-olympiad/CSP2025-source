#include <bits/stdc++.h>

using namespace std ;

#define ll long long

int n , m , k ;

//vector <pair <int , int> > g[10010] ; 

int read () {
	char ch = getchar () ;
	int f = 1 ;
	ll res = 0 ;
	if (ch == '-') {
		f = -1 ;
		ch = getchar () ;
	}
	while (ch <= '9' && ch >= '0') {
		res = res * 10 + ch - '0' ;
		ch = getchar () ;
	}
	return res * f ;
}

int c[20] ;

int a[15][10010] ;

struct node {
	int u ,v , w ;
}g[11000005];
int tot ;

int fa[20010] ;
ll ans = 0 ;
int Find (int x) {
	return ((fa[x] == x) ? x : fa[x] = Find (fa[x])) ;
}

bool cmp (node e , node f) {
	return e.w < f.w ;
}

void kruskal () {
	sort (g + 1 , g + 1 + tot , cmp) ;
	int edg = 0 ;
	bool ok = 0 ;
	for (int i = 1 ; i <= n + k; ++i) fa[i] = i ;
	for (int i = 1 ; i <= tot ; ++i) {
		int xx = Find (g[i].u) , yy = Find (g[i].v) ;
		if (xx == yy) continue ;
		fa[yy] = xx ;
		++edg ;
		ans += g[i].w ;
		if (g[i].u > n || g[i].v > n) ok = 1 ;
		if (edg == n - 1) break ;
	}
}

void kru () {
	sort (g + 1 , g + 1 + tot , cmp) ;
	for (int i = 1 ; i <= n ; ++i) fa[i] = i;
	int edg = 0 ;
	for (int i = 1 ; i <= tot ; ++i) {
		int xx = Find (g[i].u) , yy = Find (g[i].v) ;
		if (n - 1 == edg) break ;
		if (xx == yy) continue ;
		fa[yy] = xx ;
		++edg ;
		ans += g[i].w ;
		if (edg == n - 1) break ;
	}
}

int main (){
   freopen ("road.in" , "r" , stdin) ;
   freopen ("road.out" , "w" , stdout) ;
  
  n = read () , m = read() , k = read() ;
  
  for (int i = 1 ; i <= m ; ++i) {
  	int u , v , w ;
//  	u = read () , v = read() , w = read() ;
 		g[++tot] = (node){read() , read() , read()} ;
	}
	
	int cc = 0 ;
	
	for (int i = 1 ; i <= k ; ++i) {
		c[i] = read() ;
		if (c[i] == 0) ++cc ;
		for (int j = 1 ; j <= n ; ++j) {
			a[i][j] = read() ;
		}
	}
	
	if (k == 0) {
		kru() ;
		printf ("%lld\n" , ans) ;
		return 0 ;
	}
	
	if (cc == k) {
		for (int i = 1 ; i <= k ; ++i) {
			for (int j = 1 ; j <= n ; ++j) {
				g[++tot] = (node){i + n , j , a[i][j]} ;
			}
		}
		kruskal () ;
		printf ("%lld\n" , ans) ;
	}	
  
  return 0 ;
}
