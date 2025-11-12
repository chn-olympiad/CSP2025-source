//李政霖 SN-S00344 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std ;
int n ;
struct Node {
	int a , b , c ;
	int tiao ;
	int c1 , c2 , c3 ; 
	bool operator < ( const Node & x ) const {
		return x . tiao < tiao ;
	} 
} ;
int main ( ) {
	freopen ( "club.in" , "r" , stdin ) ;
	freopen ( "club.out" , "w" , stdout ) ;
	cin >> n ;
	while ( n -- ) {
		priority_queue < Node > q1 , q2 , q3 ; 
		int m ;
		long long ans = 0 ;
		cin >> m ;
		for ( int i = 1 ; i <= m ; i ++ ) {
			Node p ;
			cin >> p . a >> p . b >> p . c ;
			int maxn = max ( p . a , ( max ( p . b , p . c ) ) ) ;
			ans += maxn ;
			if ( maxn == p . a ) {
				p . c1 = 1 ;
				if ( p . b >= p . c ) {
					p . c2 = 2 ;
					p . c3 = 3 ;
				}
				else {
					p . c2 = 3 ;
					p . c3 = 2 ;
				}
			}
			else if ( maxn == p . b ) {
				p . c1 = 2 ;
				if ( p . a >= p . c ) {
					p . c2 = 1 ;
					p . c3 = 3 ;
				}
				else {
					p . c2 = 3 ;
					p . c3 = 1 ;
				}
			}
			else {
				p . c1 = 3 ;
				if ( p . a >= p . b ) {
					p . c2 = 1 ;
					p . c3 = 2 ;
				}
				else {
					p . c2 = 2 ;
					p . c3 = 1 ;
				}
			}
			if ( p . c2 == 1 ) {
				p . tiao = maxn - p . a ;
			}
			else if ( p . c2 == 2 ) {
				p . tiao = maxn - p . b ;
			}
			else {
				p . tiao = maxn - p . c ;
			}
			if ( p . c1 == 1 ) {
				q1 . push ( p ) ; 
			} 
			else if ( p . c1 == 2 ) {
				q2 . push ( p ) ;
			}
			else {
				q3 . push ( p ) ;
			}
		}
		if ( q1 . size ( ) > ( m / 2 ) ) {
			while ( q1 . size ( ) > ( m / 2 ) ) {
				Node tmp = q1 . top ( ) ;
				ans -= tmp . tiao ;
				q1 . pop ( ) ;
			}
		}
		
		else if ( q2 . size ( ) > ( m / 2 ) ) {
			while ( q2 . size ( ) > ( m / 2 ) ) {
				Node tmp = q2 . top ( ) ;
				ans -= tmp . tiao ;
				q2 . pop ( ) ;
			}
		}
		else {
			while ( q3 . size ( ) > ( m / 2 ) ) {
				Node tmp = q3 . top ( ) ;
				ans -= tmp . tiao ;
				q3 . pop ( ) ;
			}
		}
		cout << ans << endl ; 
	}
	return 0 ;
}
