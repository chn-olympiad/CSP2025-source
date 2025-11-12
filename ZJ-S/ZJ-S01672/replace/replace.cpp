#include<bits/stdc++.h>
using namespace std ;
const int N = 1e4 + 5 ;
int n , m ;
struct STRing{
	string a ;
	string b ;
} st[N] ;
signed main( ) {
	ios::sync_with_stdio( false ) , cin.tie( 0 ) , cout.tie( 0 ) ;
	freopen( "replace.in" , "r" , stdin ) ;
	freopen( "replace.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> st[i].a >> st[i].b ;
	}
	string x , y ;
	while ( m-- ) {
		cin >> x >> y ;
		int cnt = 0 ;
		int len = x.size( ) ;
		int l = 0 , r = len - 1 ;
		for ( int i = 0 ; i < len ; i++ ) {
			for ( int j = 1 ; j <= n ; j++ ) {
				string xt = x ;
				int lt = st[j].a.size( ) ;
				bool f = true ;
				if ( lt + i > len ) {
					continue ;
				}
				for ( int k = i ; k < i + lt ; k++ ) {
					if ( x[k] == st[j].a[ k - i ] ) {
						x[k] = st[j].b[ k - i ] ;
					}
					else {
						f = false ;
					}
				}
				if ( f ) {
					if ( x == y ) {
						cnt++ ;
					}
				}
				x = xt ;
			}
		}
		cout << cnt << endl ;
	}
	return 0 ;
}