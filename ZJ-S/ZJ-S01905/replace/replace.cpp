#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 2e5 + 5 ;
int n , T , ans ;
string s , s2 , a [N] , b [N] ;
signed main () {
	freopen ("replace.in" , "r" , stdin) ;
	freopen ("replace.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin.tie (NULL) ; cout.tie (NULL) ;
	cin >> n >> T ;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a [i] >> b [i] ;
	}
	while (T --) {
		cin >> s >> s2 ; ans = 0 ;
		for (int i = 1 ; i <= n ; i ++) {
			int x = s.find (a [i]) ;
			while (x != s.npos) {
				string p = s.substr (0 , x) + b [i] + 
				s.substr (x + a [i].size ()) ; 
				if (p == s2)  ans ++ ;
				x = s.find (a [i] , x + 1) ;
			}
		}
		cout << ans << "\n" ;
	}
	return 0 ;
}
/*
miaomiao
by 927003
*/
