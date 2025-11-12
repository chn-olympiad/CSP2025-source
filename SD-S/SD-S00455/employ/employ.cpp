#include<bits/stdc++.h>
using namespace std ; 
# define int long long 
# define zyq ios::sync_with_stdio ( false ) 
const int N = 19 , mod = 998244353 ; 
int n , m , dp [ 1000000 ] [ N ] , ans ; 
int c [ N ] , flag [ N ] ; 
signed main ( ) {
	freopen ( "employ.in" , "r" , stdin ) ;
	freopen ( "employ.out" , "w" , stdout ) ;
	zyq ;  
	cin >> n >> m ; 
	for ( int i = 1 ; i <= n ; i ++ ) {
		char C ;
		cin >> C ; 
		flag [ i ] = C - '0' ;
	}
	for ( int i = 1 ; i <= n ; i ++ ) 
		cin >> c [ i ] ;
	dp [ 0 ] [ 0 ] = 1 ; 
	for ( int i = 0 ; i < ( 1 << n ) - 1 ; i ++ ) {
		int cnt = 0 ; 
		int x = i ; 
		while ( x ) {
			if ( x & 1 ) 
				cnt ++ ; 
			x >>= 1 ; 
		}
		for ( int j = 1 ; j <= n ; j ++ ) {
			if ( ! ( i & ( 1 << ( j - 1 ) ) ) ) {
				for ( int k = 0 ; k < 18 ; k ++ ) {
					if ( ! flag [ cnt + 1 ] || k >= c [ j ] ) {
						dp [ i | ( 1 << ( j - 1 ) ) ] [ k + 1 ] += dp [ i ] [ k ] ;
						dp [ i | ( 1 << ( j - 1 ) ) ] [ k + 1 ] %= mod ; 
					}
					else {
						dp [ i | ( 1 << ( j - 1 ) ) ] [ k ] += dp [ i ] [ k ] ;
						dp [ i | ( 1 << ( j - 1 ) ) ] [ k ] %= mod ; 
					}
				}
			}
		}
	}
	for ( int i = 1 ; i <= n - m ; i ++ ) {
		ans += dp [ ( 1 << n ) - 1 ] [ i ] ;
		ans %= mod ; 
	}
	cout << ans ; 
	return 0 ; 
} 
