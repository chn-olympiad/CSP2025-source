#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 510 , mod = 998244353 ;
int n , m , a [N] , p [N] , ans , f [N] , fl ;
char s [N] ;
bool check () {
	int sum = 0 , tot = 0 ;
	for (int i = 1 ; i <= n ; i ++) {
//		cout << p [i] << " " << tot << "->" ;
		if (a [p [i]] <= tot) {
			tot ++ ; continue ;
		}
		if (s [i] == '0') {
			tot ++ ;
		}
		else {
			sum ++ ;
		}
	}
//	cout << "\n" ;
	return sum >= m ;
}
void dfs (int t) {
	if (t > n) {
		ans += check () ;
		ans %= mod ;
	}
	for (int i = 1 ; i <= n ; i ++) {
		if (f [i] == 0) {
			f [i] = 1 ; p [t] = i ;
			dfs (t + 1) ;
			f [i] = 0 ;
		}
	}
}
signed main () {
	freopen ("employ.in" , "r" , stdin) ;
	freopen ("employ.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin.tie (NULL) ; cout.tie (NULL) ;
	cin >> n >> m >> (s + 1) ; fl = 1 ;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a [i] ;	
	}  
	for (int i = 1 ; i <= n ; i ++)
		if (s [i] == '0') {
			fl = 0 ; 
			break ;
		}
	else {
		dfs (1) ;
		cout << ans ;
	}
	return 0 ;
}

