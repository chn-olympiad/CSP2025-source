#include<bits/stdc++.h>
using namespace std ; 
# define int long long 
# define zyq ios::sync_with_stdio ( false ) 
const int N = 1e4 + 21 , M = 1e6 + 11 ;
int n , m , k , f [ N ] , ans , cnt , c [ 11 ] ; 
struct node {
	int u ; 
	int v ; 
	int w ; 
	int id ;
} a [ 2 * M ] ;
int find ( int x ) {
	if ( f [ x ] == x ) 
		return x ; 
	return f [ x ] = find ( f [ x ] ) ;
}
bool b ; 
bool cmp ( node a , node b ) {
	return a . w < b . w ; 
}
bool flag [ 11 ] ; 
signed main ( ) {
	freopen ( "road.in" , "r" , stdin ) ;
	freopen ( "road.out" , "w" , stdout ) ;
	zyq ;  
	cin >> n >> m >> k ;
	for ( int i = 1 ; i <= m ; i ++ ) {
		cin >> a [ i ] . u >> a [ i ] . v >> a [ i ] . w ;  
		a [ i ] . id = 0 ; 	
	}
	int p = 0 ; 
	for ( int i = 1 ; i <= k ; i ++ ) {
		cin >> c [ i ] ;
		if ( c [ i ] > 0 ) 
			b = 1 ; 
		for ( int j = 1 ; j <= n ; j ++ ) {
			int x ; 
			cin >> x ;
			if ( x > 0 ) 
				b = 1 ; 
			p ++ ;
			a [ p + m ] . u = i + n ; 
			a [ p + m ] . v = j ; 
			a [ p + m ] . w = x ;
			a [ p + m ] . id = i ; 
		}
	}
	sort ( a + 1 , a + m + p + 1 , cmp ) ;
	for ( int i = 1 ; i <= n + k ; i ++ ) 
		f [ i ] = i ;
	if ( ! b ) {
		for ( int i = 1 ; i <= p + m ; i ++ ) {
			if ( cnt == n + k - 1 ) 
				break ; 
			int x = find ( a [ i ] . u ) ;
			int y = find ( a [ i ] . v ) ;  
			if ( x != y ){
				cnt ++ ;
				ans += a [ i ] . w ; 
				f [ x ] = f [ y ] ;
			}
		}
		cout << ans ;
	}
	else {
		ans = 1e18 ; 
		for ( int i = 0 ; i < 1 << k ; i ++ ) {
			int sum = 0 , r = 0 ; 
			cnt = 0 ; 
			memset ( flag , 0 , sizeof flag ) ;
			for ( int j = 1 ; j <= k ; j ++ ) {
				if ( ( i >> ( j - 1 ) ) & 1 ) {
					sum += c [ j ] ;
					flag [ j ] = 1 ; 
					r ++ ; 	
				}
			}
			flag [ 0 ] = 1 ; 
			for ( int j = 1 ; j <= n + k ; j ++ ) 
				f [ j ] = j ; 
			for ( int j = 1 ; j <= p + m ; j ++ ) {
				if ( cnt == n + r - 1 ) 
					break ; 
				int x = find ( a [ j ] . u ) ;
				int y = find ( a [ j ] . v ) ;  
				if ( x != y && flag [ a [ j ] . id ] ){
					cnt ++ ;
					sum += a [ j ] . w ;  
					f [ x ] = f [ y ] ;
				}
			}
			if ( cnt == n + r - 1 )
				ans = min ( ans , sum ) ;
		}
		cout << ans ;
	}
	return 0 ;  
}
//T1写了45分钟，我太菜了，明明是个红题的……
//希望这次能拿省一吧，为了S我付出的太多了  
