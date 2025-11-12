#include<bits/stdc++.h>
using namespace std ;
const int N = 500 + 5 , MOD = 998244353 ;
int n , m ;
int da[N] ;
int re[N] ;
bool vis[N] ;
int sum[N] ;
int cnt = 0 ;
void dfs( int u , int dep , int ste , int ans ) {
	ste++ ;
	if ( ste > n ) {
		return ;
	}
	vis[u] = true ;
	if ( sum[u] >= re[u] ) {
		ans++ ;
	}
	if ( ans < re[u] && sum[u] < re[u] ) {
		dep++ ;
	}
	if ( dep >= m ) {
		cnt++ ;
		cnt = cnt % MOD ;
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		if ( i != u && !vis[i] ) {
			vis[i] = true ;
			if ( sum[i] >= re[i] ) {
				ans++ ;
			}
			if ( ans < re[i] && sum[i] < re[i] ) {
				dep++ ;
			}
			dfs( i , dep , ste , ans ) ;
			vis[i] = false ;
		}
	}
	return ;
}
signed main( ) {
	ios::sync_with_stdio( false ) , cin.tie( 0 ) , cout.tie( 0 ) ;
	freopen( "employ.in" , "r" , stdin ) ;
	freopen( "employ.out" , "w" , stdout ) ;
	cin >> n >> m ;
	string x ;
	cin >> x ;
	for ( int i = 1 ; i <= n ; i++ ) {
		da[i] = x[ i - 1 ] - '0' ;
	}
	int t = 0 ;
	for ( int i = 1 ; i <= n ; i++ ) {
		if ( da[i] == 0 ) {
			t++ ;
		}
		sum[i] = t ;
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> re[i] ;
	}
	dfs( 1 , 0 , 0 , 0 ) ;
	cout << cnt << endl ;
	return 0 ;
}