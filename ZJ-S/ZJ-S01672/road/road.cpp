#include<bits/stdc++.h>
#define mk(x,y) make_pair(x,y)
using namespace std ;
const int N = 1e6 + 5 , M = 1e4 + 5 , MAX = 2147483647 ;
int n , m , k ;
struct Edge{
	int fo ;
	int to ;
	int w ;
} e[N] ;
int cnte ;
int he[N] ;
struct Town{
	int kt ;
	int co[M] ; 
} ci[ 10 + 5 ] ;
int ru[N] ;
int mp[M][M] ;
void add( int x , int y , int z ) {
	cnte++ ;
	e[cnte].fo = x ;
	e[cnte].to = y ;
	e[cnte].w = z ;
	he[x] = cnte ;
}
bool cmp( Edge x , Edge y ) {
	return ( x.w == y.w ) ? ( x.fo < y.fo ) : ( x.w > y.w ) ;
}
signed main( ) {
	ios::sync_with_stdio( false ) , cin.tie( 0 ) , cout.tie( 0 ) ;
	freopen( "road.in" , "r" , stdin ) ;
	freopen( "road.out" , "w" , stdout ) ;
	cin >> n >> m >> k ;
	int x , y , z ;
	for ( int i = 1 ; i <= m ; i++ ) {
		cin >> x >> y >> z ;
		add( x , y , z ) ;
		ru[x]++ ;
		ru[y]++ ;
	}
	for ( int i = 1 ; i <= k ; i++ ) {
		cin >> ci[i].kt ;
		for ( int j = 1 ; j <= n ; j++ ) {
			cin >> ci[i].co[j] ;
		}
	}
	sort( e + 1 , e + m + 1 , cmp ) ;
	int cnt = 1 ;
	int cntm = 0 ;
	while ( m > n - 1 ) {
		if ( ru[ e[cnt].fo ] > 1 && ru[ e[cnt].to ] > 1 ) {
			ru[ e[cnt].fo ]-- ;
			ru[ e[cnt].to ]-- ;
			if ( cnt <= n ) {
				swap( e[cnt] , e[ m - cntm ] ) ;
				cntm++ ;
			}
			m-- ;
		}
		cnt++ ;
	}
	int ans = 0 ;
	memset( mp , 0x3f3f3f3f , sizeof( mp ) ) ;
	for ( int i = 1 ; i <= m ; i++ ) {
		mp[ e[i].fo ][ e[i].to ] = e[i].w ;
		mp[ e[i].to ][ e[i].fo ] = e[i].w ;
	}
	int root ;
	for ( int i = 1 ; i <= n ; i++ ) {
		if ( ru[i] > 1 ) {
			root = i ;
			break ;
		}
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		mp[i][i] = 0 ;
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		ans = ans + mp[i][root] ;
	}
	for ( int l = 0 ; l < ( 1 << k ) ; l++ ) {
		int sum = 0 ;
		int minn = ans ;
		for ( int j = 1 ; j <= k ; j++ ) {
			if ( ( l >> ( j - 1 ) && j != 1 ) || ( j == 1 && l % 2 == 1 ) ) {
				sum += ci[j].kt ;
				for ( int i = 1 ; i <= n ; i++ ) {
					for ( int p = i ; p <= n ; p++ ) {
						if ( i == p ) {
							continue ;
						}
						if ( ( mp[i][root] + mp[root][p] ) > ( ci[k].co[i] + ci[k].co[p] ) ) {
							minn = minn - mp[i][root] ;
							minn += ci[k].co[i] + ci[k].co[p] ;
						}
						mp[i][p] = min( mp[i][root] + mp[root][p] , ci[k].co[i] + ci[k].co[p] ) ;
						mp[i][root] = ci[k].co[i] + ci[k].co[p] ;
					}
				}
			}
		}
		sum += minn ;
		ans = min( ans , sum ) ;
	}
	cout << ans << endl ;
	return 0 ;
}