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
const ll N = 1e4 + 115 , M = 1e6 + 115 , K = 15 ;
ll n , m , k , c[ N ] , f[ N ] , elen , ans , z[ N ] , p[ N ] , len ;
struct edge{
	ll w , u , v ;
} t[ M ] , r[ K ][ N ] ;
bool cmp( edge x1 , edge x2 ) {
	return x1.w < x2.w ;
}
ll getf( ll x ) {
	if( x == f[ x ] ) return x ;
	else return f[ x ] = getf( f[ x ] ) ;
}
void primary_match() {
	For( i , 1 , n ) f[ i ] = i ;
	For( i , 1 , m ) {
		ll fu = getf( t[ i ].u ) , fv = getf( t[ i ].v ) ;
		if( fu != fv ) {
			f[ fu ] = fv ; 
			r[ 0 ][ ++elen ] = t[ i ] ;
			ans += t[ i ].w ;
			if( elen == n - 1 ) break ;
		}
	}
}
void solve() {
	For( C , 1 , ( 1 << k ) - 1 ) {
	//	cout << C << endl ;
		ll sum = 0 , cnt = 0 , nod = n ;
		len = 0 ;
		For( i , 1 , k ) {
			if( ( ( C >> ( i - 1 ) ) & 1 ) )
				sum += c[ i ] , z[ ++len ] = i , nod ++ ;
		}
		For( i , 1 , n + k ) f[ i ] = i ;
		For( i , 0 , k ) p[ i ] = 1 ;
	//	cout << nod << " " << len << endl ;
		while( cnt < nod - 1 ) {
			ll px = 0 ;
			edge tmp ;
			tmp.w = -1 ;
			For( i , 0 , len ) {
				if( p[ i ] <= n - ( i == 0 ) && ( tmp.w == -1 || tmp.w > r[ z[ i ] ][ p[ i ] ].w ) )
					tmp = r[ z[ i ] ][ p[ i ] ] , px = i ;
			}
			p[ px ] ++ ;
			ll fu = getf( tmp.u ) , fv = getf( tmp.v ) ;
			if( fu != fv ) ++cnt , sum += tmp.w , f[ fu ] = fv ;
		}
		ans = min( ans , sum ) ;
	}
}
int main() {
	freopen("road.in" , "r" , stdin ) ;
	freopen("road.out" , "w" , stdout ) ;
	n = read() ;
	m = read() ;
	k = read() ;
	For( i , 1 , m ) {
		t[ i ].u = read() ;
		t[ i ].v = read() ;
		t[ i ].w = read() ;
	}
	sort( t + 1 , t + 1 + m , cmp ) ;
	For( i , 1 , k ) {
		c[ i ] = read() ;
		For( j , 1 , n ) {
			r[ i ][ j ].u = i + n ; 
			r[ i ][ j ].v = j ; 
			r[ i ][ j ].w = read() ;
		}
		sort( r[ i ] + 1 , r[ i ] + n , cmp ) ;
	}
	primary_match() ;
	solve() ;
	printf("%lld\n" , ans ) ;
	return 0 ;
}
