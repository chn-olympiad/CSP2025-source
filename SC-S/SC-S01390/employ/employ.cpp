#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505 ;
const int MOD = 998244353 ;
int n , m ;
char s[N] ;
int c[N] ;
int cnt1 = 0 ;
bool vis[N] ;
void solve1( int u , int last , int out ) {
	if ( u > last ) {
		if ( last - out >= m ) {
			cnt1 ++ ;
			if ( cnt1 > MOD )	cnt1 -= MOD ;
		}return ;
	}for ( int i = 1 ; i <= last ; i ++ ) {
		if ( vis[i] )	continue ;
		vis[i] = 1 ;
		solve1( u + 1 , last , out + ( s[u] == '1' ? c[i] <= out : 1 ) ) ;
		vis[i] = 0 ;
	}
}
signed main() {
    freopen( "employ.in" , "r" , stdin ) ;
    freopen( "employ.out" , "w" , stdout ) ;
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> n >> m ;
    cin >> s + 1 ;
    int t = 0 ;
    for ( int i = 1 ; i <= n ; i ++ ) {
    	if ( s[i] == '0' )	t ++ ;
	}if ( n - t < m ) {
		cout << 0 ;
		return 0 ;
	}
    for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> c[i] ;
		if ( c[i] == 0 )	t ++ ;
	}if ( n <= 10 ) {
		solve1( 1 , n , 0 ) ;
		cout << cnt1 ;
	}else if ( m == n ) {
		if ( t != 0 ) {
			cout << 0 ;
		}else {
			int ans = 1 ;
			for ( int i = 1 ; i <= n ; i ++ ) {
				ans *= i ;
				ans %= MOD ;
			}cout << ans ;
		}
	}
    return 0 ;
}
