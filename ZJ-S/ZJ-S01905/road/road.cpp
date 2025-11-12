#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 1e6 + 5 , M = 1e4 + 5 ;
int n , m , k , f [M] , cnt , x , y , z , ans , r [20] [M] , fl [20] ,
mi = 2e9 , p [20] ;
struct node {
	int u , v , w ;
} a [N] , b [N] ;
bool cmp (node q , node h) {
	return q.w < h.w ;
}
int find (int x) {
	return (f [x] == x ? x : f [x] = find (f [x])) ;
}
int check (int cho) {
	int sum = n , tot = 0 , cnt2 = cnt , ans = 0 ;
	for (int i = 1 ; i <= cnt ; i ++)   b [i] = a [i] ;
	for (int i = 1 ; i <= k ; i ++)
		if (fl [i]) {
//			cout << i << " " ;
			sum ++ ;
			for (int j = 1 ; j <= n ; j ++) {
				b [++ cnt2] = (node) {n + i , j , r [i] [j]} ;
			}	
		}
	for (int i = 1 ; i <= n + k ; i ++)  f [i] = i ;
	sort (b + 1 , b + 1 + cnt2 , cmp) ;
	for (int i = 1 ; i <= cnt2 ; i ++) {
		if (tot >= sum - 1)  break ;
		int x = b [i].u , y = b [i].v , z = b [i].w ;
		int fx = find (x) , fy = find (y) ;
		if (fx != fy) {
			f [fx] = fy ; tot ++ ;
			ans += z ;
		} 
	}
//	cout << ans << "\n" ;
	return ans + cho ;
}
void dfs (int t , int s) {
	if (s > mi)  return ;
	if (t > k) {
		mi = min (mi , check (s)) ;
		return ;
	}
	fl [t] = 1 ;
	dfs (t + 1 , s + p [t]) ;
	fl [t] = 0 ;
	dfs (t + 1 , s) ;
}
signed main () {
	freopen ("road.in" , "r" , stdin) ;
	freopen ("road.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin.tie (NULL) ; cout.tie (NULL) ;
	cin >> n >> m >> k ;
	for (int i = 1 ; i <= m ; i ++) {
		cin >> x >> y >> z ;
		a [++ cnt] = (node) {x , y , z} ;
	}
	for (int i = 1 ; i <= k ; i ++) {
		cin >> p [i] ;
		for (int j = 1 ; j <= n ; j ++)
			cin >> r [i] [j] ;
	}
	dfs (1 , 0) ;
	cout << mi ;
	return 0 ;
}
/*
miaomiao 48pts ...
by 927003
*/
