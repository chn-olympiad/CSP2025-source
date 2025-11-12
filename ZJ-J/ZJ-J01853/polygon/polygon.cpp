#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 5010 , mod = 998244353 ;
int n , a [N] , u [510] [50010] , b [N] , ans ;
int dfs (int t , int s) {
	int sum = 0 ;
//	cout << t << " " << s << "\n" ;
	if (t > n)  return 0 ;
	if (u [t] [s])  return u [t] [s] ;
	if (s > a [t] && t >= 3) {
		sum ++ ; sum %= mod ;
	}
	sum += dfs (t + 1 , s + a [t]) ;
	sum %= mod ;
	sum += dfs (t + 1 , s) ;
	sum %= mod ;
	return u [t] [s] = sum % mod ;
}
signed main () {
	freopen ("polygon.in" , "r" , stdin) ;
	freopen ("polygon.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin.tie (NULL) ; cout.tie (NULL) ;
	cin >> n ;
	for (int i = 1 ; i <= n ; i ++)  cin >> a [i] ;
	sort (a + 1 , a + 1 + n) ;
	for (int i = 1 ; i <= n ; i ++)  b [i] = b [i - 1] + a [i] ;
	cout << dfs (1 , 0) % mod ;
	return 0 ;
}
/*
miaomiao 68pts ...
by 927003
°¥£¬Ô¤¼Æ298pts£¬×£¸£ÍËÒÛ¿ìÀÖ 
*/
