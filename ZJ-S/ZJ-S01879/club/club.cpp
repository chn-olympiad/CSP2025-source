#include<bits/stdc++.h>
#define For( i , a , b ) for( register ll i = ( a ) ; i <= ( b ) ; ++i )
#define Rep( i , a , b ) for( register ll i = ( a ) ; i >= ( b ) ; --i )
#define ll long long 
using namespace std ;
inline ll read() {
	ll s = 0 ; char ch = getchar() ; bool f = 0 ;
	for( ; !isdigit( ch ) ; ch = getchar() ) f ^= !( 45 ^ ch ) ;
	for( ; isdigit( ch ) ; ch = getchar() ) s = ( s << 3 ) + ( s << 1 ) + ( ch ^ 48 ) ;
	if( f ) return -s ;
	return s ;
}
const ll N = 1e5 + 5 ;
ll T , n , a[ N ][ 5 ] , c[ 5 ] , ans ;
ll T1 , T2 ;
priority_queue < ll > q ;
int main() {
	freopen("club.in" , "r" , stdin ) ;
	freopen("club.out" , "w" , stdout ) ;
	T = read() ;
	while( T-- ) {
		ans = 0 ;
		For( i , 1 , 3 ) c[ i ] = 0 ;
		while( !q.empty() ) q.pop() ;
		n = read() ;
		For( i , 1 , n ) {
			For( j , 1 , 3 )
				a[ i ][ j ] = read() ;
			a[ i ][ 0 ] = 1 ;
			For( j , 2 , 3 )
				if( a[ i ][ j ] > a[ i ][ a[ i ][ 0 ] ] )
					a[ i ][ 0 ] = j ;
			c[ a[ i ][ 0 ] ] ++ ;
			ans += a[ i ][ a[ i ][ 0 ] ] ;
		}
		For( j , 1 , 3 ) {
			if( c[ j ] > n / 2 ) {
				For( i , 1 , n ) {
					if( a[ i ][ 0 ] == j ) {
						ll tmp = 0 ;
						For( k , 1 , 3 )
							if( k != j )
								tmp = max( tmp , a[ i ][ k ] ) ;
						q.push( -a[ i ][ a[ i ][ 0 ] ] + tmp ) ;
					}
				}
				while( c[ j ] > n / 2 ) {
					c[ j ] -- ;
					ans += q.top() ;
					q.pop() ;
				}
			}
		}
		printf("%lld\n" , ans ) ;
	}
	return 0 ;
}
