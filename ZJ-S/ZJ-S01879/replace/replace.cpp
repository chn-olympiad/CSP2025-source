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
const ll L = 5e6 + 105 , N = 2e5 + 105 ;
ll n , len = 10 , m , la1[ N ] , lc1[ N ] , la2[ N ] , lc2[ N ] , ans[ N ] ;
ll mod[ 15 ] = {0,998244353,998244389,998244391,998244397,998244407,998244431,998244433,998244473,998244487,1000000007};
ll pi[ 15 ] = {0,131,1331,13331,133331,809,811,821,823,827,829} ;
vector < char > as[ N ] , cs[ N ] ;
ll bs1[ N ][ 15 ] , bs2[ N ][ 15 ] ;
vector < char > at[ N ] , ct[ N ] ;
ll bt1[ N ][ 15 ] , bt2[ N ][ 15 ] ;
char s1[ N ] , s2[ N ] ;
void input() {
	n = read() ;
	m = read() ;
	For( ii , 1 , n ) {
		scanf("%s%s" , s1 , s2 ) ;
		ll leni = strlen( s1 ) ;
		For( i , 0 , leni - 1 ) {
			if( s1[ i ] == s2[ i ] )
				as[ ii ].push_back( s1[ i ] ) , ++la1[ ii ] ;
			else break ;
		}
		Rep( i , leni - 1 , 0 ) {
			if( s1[ i ] == s2[ i ] )
				cs[ ii ].push_back( s1[ i ] ) , ++lc1[ ii ] ;
			else break ;
		}
		For( i , la1[ ii ] , leni - lc1[ ii ] - 1 ) {
			For( p , 1 , 10 ) {
				bs1[ ii ][ p ] = ( s1[ i ] - 'a' + 1 + bs1[ ii ][ p ] * pi[ p ] ) % mod[ p ] ;
				bs2[ ii ][ p ] = ( s2[ i ] - 'a' + 1 + bs2[ ii ][ p ] * pi[ p ] ) % mod[ p ] ;
			}
		}
	}
	For( ii , 1 , m ) {
	//	cout << ii << endl ;
		scanf("%s%s" , s1 , s2 ) ;
	//	cout << s1 << " " << s2 << endl ;
		ll leni = strlen( s1 ) ;
		For( i , 0 , leni - 1 ) {
			if( s1[ i ] == s2[ i ] )
				at[ ii ].push_back( s1[ i ] ) , ++la2[ ii ] ;
			else break ;
		}
		Rep( i , leni - 1 , 0 ) {
			if( s1[ i ] == s2[ i ] )
				ct[ ii ].push_back( s1[ i ] ) , ++lc2[ ii ] ;
			else break ;
		}
	//	cout << la2[ ii ] << " " << leni - lc2[ ii ] - 1 << endl ;
	//cout << ii << " &^: " << la2[ ii ] << " " << lc2[ ii ] << " " << leni << endl ;
		For( i , la2[ ii ] , leni - lc2[ ii ] - 1 ) {
			For( p , 1 , 10 ) {
				bt1[ ii ][ p ] = ( s1[ i ] - 'a' + 1 + bt1[ ii ][ p ] * pi[ p ] ) % mod[ p ] ;
				bt2[ ii ][ p ] = ( s2[ i ] - 'a' + 1 + bt2[ ii ][ p ] * pi[ p ] ) % mod[ p ] ;
			}
		}
	}
}
int s[ N ] , t[ N ] ;
bool cmp1( int x , int y ) {
	For( i , 1 , len )
		if( bs1[ x ][ i ] != bs1[ y ][ i ] )
			return bs1[ x ][ i ] < bs1[ y ][ i ] ;
	For( i , 1 , len )
		if( bs2[ x ][ i ] != bs2[ y ][ i ] )
			return bs2[ x ][ i ] < bs2[ y ][ i ] ;
	return x < y ;
} 
bool cmp2( int x , int y ) {
	For( i , 1 , len )
		if( bt1[ x ][ i ] != bt1[ y ][ i ] )
			return bt1[ x ][ i ] < bt1[ y ][ i ] ;
	For( i , 1 , len )
		if( bt2[ x ][ i ] != bt2[ y ][ i ] )
			return bt2[ x ][ i ] < bt2[ y ][ i ] ;
	return x < y ;
} 
bool chks( int x , int y ) {
	x = s[ x ] ; y = s[ y ] ;
	For( i , 1 , len )
		if( bs1[ x ][ i ] != bs1[ y ][ i ] || bs2[ x ][ i ] != bs2[ y ][ i ] )
			return false ;
	return true ;
}
bool chkt( int x , int y ) {
	x = s[ x ] ; y = t[ y ] ;
	For( i , 1 , len )
		if( bs1[ x ][ i ] != bt1[ y ][ i ] || bs2[ x ][ i ] != bt2[ y ][ i ] )
			return false ;
	return true ;
}
bool chkex( int x , int y ) {
	x = t[ x ] ; y = s[ y ] ;
	For( i , 1 , len ) {
		if( bt1[ x ][ i ] < bs1[ y ][ i ] )
			return true ;
		else if( bt1[ x ][ i ] > bs1[ y ][ i ] )
			return false ;
	}
	For( i , 1 , len ) {
		if( bt2[ x ][ i ] < bs2[ y ][ i ] )
			return true ;
		else if( bt2[ x ][ i ] > bs2[ y ][ i ] )
			return false ;
	}
	return false ;
}
void solve() {
	For( i , 1 , n )
		s[ i ] = i ;
	For( i , 1 , m )
		t[ i ] = i ;
	sort( s + 1 , s + 1 + n , cmp1 ) ;
	sort( t + 1 , t + 1 + m , cmp2 ) ;
	int l = 1 , r = 1 , lm = 1 , rm = 1 ;
	while( l <= n && lm <= m ) {
		r = l ;
		while( r < n && chks( l , r + 1 ) ) ++r ;
		while( lm <= m && chkex( lm , l ) ) ++lm ;
		if( lm <= m && chkt( l , lm ) ) {
			rm = lm ;
			while( rm < m && chkt( l , rm + 1 ) ) rm ++ ;
			if( lm > m ) break ;
			For( j , lm , rm ) {
				For( i , l , r ) {
					bool flag = 1 ;
					int d1 = la2[ t[ j ] ] - la1[ s[ i ] ], d2 = lc2[ t[ j ] ] - lc1[ s[ i ] ] ;
					if( d1 < 0 ) continue ;
					if( d2 < 0 ) continue ;
					Rep( k , la1[ s[ i ] ] - 1 , 0 )
						if( as[ s[ i ] ][ k ] != at[ t[ j ] ][ k + d1 ] )
							{ flag = 0 ; break ; }
					Rep( k , lc1[ s[ i ] ] - 1 , 0 )
						if( cs[ s[ i ] ][ k ] != ct[ t[ j ] ][ k + d2 ] )
							{ flag = 0 ; break ; }
					ans[ t[ j ] ] += flag ;
				}
			}
			lm = rm + 1 ;
		}
		l = r + 1 ;
	}
}
int main() {
	freopen("replace.in" , "r" , stdin ) ;
	freopen("replace.out" , "w" , stdout ) ;
	input() ;
	solve() ;
	For( i , 1 , m ) printf("%lld\n" , ans[ i ] ) ;
	return 0 ;
}
