#include <bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 1e6 + 5 ;
int n , f [20] ;
char s [N] ;
string ans ;
signed main () {
	freopen ("number.in" , "r" , stdin) ;
	freopen ("number.out" , "w" , stdout) ;
	ios::sync_with_stdio (false) ;
	cin.tie (NULL) ; cout.tie (NULL) ; 
	cin >> (s + 1) ;
	n = strlen (s + 1) ;
	for (int i = 1 ; i <= n ; i ++) {
		if (s [i] >= '0' && s [i] <= '9') {
			f [s [i] - '0'] ++ ;
		}
	}
	for (int i = 9 ; i >= 0 ; i --) {
		if (i == 0 && ans == "")  return cout << 0 , 0 ;
		for (int j = 1 ; j <= f [i] ; j ++)
			ans += i + '0' ;
	}
	cout << ans ;
	return 0 ;
}
/*
miaomiao AC
by 927003
*/
