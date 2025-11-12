#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 1010 ;
int n , m , x , l , r , cnt , p , ans [N] [N] ;
struct node {
	int x , id ;
} a [N] ;
bool cmp (node q , node h) {
	return q.x > h.x ;
}
signed main () {
	freopen ("seat.in" , "r" , stdin) ;
	freopen ("seat.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin.tie (NULL) ; cout.tie (NULL) ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; i ++)
		for (int j = 1 ; j <= m ; j ++) {
			cnt ++ ;
			cin >> x ;
			a [cnt].x = x , a [cnt].id = cnt ;
		}
	sort (a + 1 , a + 1 + cnt , cmp) ;
	l = 1 ; r = 1 ; p = 1 ;
	while (p <= n * m) {
		ans [l] [r] = a [p].x ;
		if (a [p].id == 1) {
			cout << r << " " << l ;
			return 0 ;
		}
		if (r % 2 == 1) {
			p ++ ; l ++ ;
			if (l > n) {
				l = n ; r ++ ;
			}
		}
		else {
			p ++ ; l -- ;
			if (l < 1) {
				l = 1 ; r ++ ;
			}
		}
	}
	return 0 ;
}
/*
miaomiao AC
by 927003
*/
