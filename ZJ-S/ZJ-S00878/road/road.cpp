#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
typedef struct ed {
	int u,v;
	ll w;
} ed ;
ed E[1000000 + 100000 + 50];
ed F[100000 + 50];
ll ww ;
bool ecmp (ed a,ed b) {
	return a.w < b.w;
}
ll c[11] , a[11][10000 + 500];
bool flag;
ll d[11] ;
int fa[10000 + 500] ;
int ff (int x) {
	if (fa[x] == x) return x ;
	fa[x] = ff (fa[x]) ;
	return fa[x] ;
}
int main () {
	freopen ("road.in" , "r" , stdin) ;
	freopen ("road.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i ++) {
		cin >> E[i].u >> E[i].v >> E[i].w ;
	}
	flag = true ;
	for (int i = 1;i <= k;i ++) {
		cin >> c[i] ; 
		d[i] = n + 1;
		for (int j = 1;j <= n;j ++) {
			cin >> a[i][j] ;
			if (a[i][j] == 0) d[i] = j;
		} 
		if (c[i] != 0) flag = false;
		if (d[i] == n + 1) flag = false;
	}
//	cout << "flag = " << (int) (flag) << "\n" ;
	int ecnt = m ;
	int nn = n;
	if (k != 0 && flag) {
		for (int i = 1;i <= k;i ++) {
			for (int j = 1;j <= n;j ++) {
				ecnt ++ ;
				E[ecnt].u = n + i , E[ecnt].v = j , E[ecnt].w = a[i][j] ;
			}
		}	
		nn += k;
	}
	sort (E + 1,E + ecnt + 1,ecmp) ;
	for (int i = 1;i <= n + k;i ++)
		fa[i] = i;
	ll ans = 0;
	ll utt = 0;
	for (int i = 1;i <= m;i ++) {
		int fx = ff(E[i].u) , fy = ff(E[i].v) ;
		if (fx == fy) continue ;
		ans += E[i].w ; 
		fa[fx] = fy;
		utt ++ ;
		if (utt == nn - 1) break ;
	}
	if (k != 0 && k <= 5 && (!flag)) {
		ll anst = ans;
		for (int i = 1;i <= (1 << k) - 1;i ++ ) {
			ll ansp = 0;
			int fcnt = 0;
			nn = n;
			for (int j = 0;j < k;j ++) {
				if (i & (1 << j)) {
					ansp += c[j + 1] ;
					nn ++ ;
					for (int i1 = 1;i1 <= n;i1 ++ )
						fcnt ++ , F[fcnt].u = n + j + 1,F[fcnt].v = i1,F[fcnt].w = a[j + 1][i1];
				}
			}
			sort (F + 1,F + fcnt + 1,ecmp) ;
			for (int j = 1;j <= n + k;j ++)
				fa[j] = j;
			utt = 0;
			for (int i1 = 1,j1 = 1;i1 <= ecnt || j1 <= fcnt;) {
				ed xx;
				if (i1 > ecnt) xx = F[j1] , j1 ++ ;
				else if (j1 > fcnt) xx = E[i1] , i1 ++ ;
				else {
					if (E[i1].w < E[j1].w) xx = E[i1] , i1 ++ ;
					else xx = F[j1] , j1 ++ ;
				}
				int fx = ff (xx.u) , fy = ff (xx.v) ;
				if (fx == fy) continue ;
				utt ++ ;
				ansp += xx.w ;
				fa[fx] = fy;
				if (utt == nn - 1) break ;
			}
			anst = min (anst , ansp) ;
		}
		ans = anst ;
	}
	cout << ans << "\n" ;
	return 0;
}