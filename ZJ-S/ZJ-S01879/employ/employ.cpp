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
const ll N = 1005 , mod = 998244353 ;
ll n , m , fac[ N ] , ans , t[ N ] , s[ N ] , a[ N ] ;
bool vis[ N ] ;
char sc[ N ] ;
void dfs( ll x ) {
	if( x == n + 1 ) {
		ll tmp = 0 ;
		For( i , 1 , n ) {
			if( a[ t[ i ] ] <= tmp || s[ i ] == 0 )
				tmp ++ ;
		}
		if( n - tmp >= m ) ans ++ ;
	}
	For( i , 1 , n ) {
		if( !vis[ i ] ) {
			vis[ i ] = 1 ;
			t[ x ] = i ;
			dfs( x + 1 ) ;
			vis[ i ] = 0 ;
		}
	}
}
int main() {
	freopen("employ.in" , "r" , stdin ) ;
	freopen("employ.out" , "w" , stdout ) ;
	n = read() ;
	m = read() ;
	scanf("%s" , sc ) ;
	fac[ 0 ] = 1 ;
	For( i , 1 , n ) a[ i ] = read() , s[ i ] = sc[ i - 1 ] - '0' , fac[ i ] = fac[ i - 1 ] * i % mod ;
	if( n <= 12 ) dfs( 1 ) ;
	else ans = fac[ n ] ;
	printf("%lld\n" , ans ) ;
	return 0 ;
}
