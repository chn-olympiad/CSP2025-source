#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 5e5 + 5 ;
int n , k , a [N] , l , r , ans , sum , b [N] , tot ;
void dfs (int t , int lt , int rt) {
	int x = (k >> t) % 2 , s = 0 , l = 1 ;
//	cout << t << " " << lt << " " << rt << "\n" ;
	if ((k >> t) == 0)  return ans ++ , void () ; 
	for (int i = lt ; i <= rt ; i ++) {
		int y = (a [i] >> t) % 2 ;
		s ^= y ;
		if (s == x) {
			dfs (t + 1 , l , i) ;
			l = i + 1 ; s = 0 ;
		}
	}
	return ;
}
signed main () {
	freopen ("xor.in" , "r" , stdin) ;
	freopen ("xor.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin.tie (NULL) ; cout.tie (NULL) ;
	cin >> n >> k ;
	for (int i = 1 ; i <= n ; i ++)  cin >> a [i] ;
	dfs (0 , 1 , n) ;
	cout << ans ;
	return 0 ;
}
/*
miaomiao 30pts ...
by 927003
*/
