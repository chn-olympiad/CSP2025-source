#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 1e5 + 5 , M = 200 + 5 ;
int n ;
struct Club{
	int a , b , c ;
	int cl = 0 ;
	int clt = 0 ;
	bool f = false ;
} me[N] ;
bool cmpfca( Club x , Club y ) {
	return x.a > x.b ;
}
int ans = 0 ;
int dfs( int u , int c1 , int c2 , int c3 , int sum ) {
	if ( u > n ) {
		return sum ;
	}
	if ( c1 > ( n / 2 ) || c2 > ( n / 2 ) || c3 > ( n / 2 ) ) {
		return sum ;
	}
	int t ;
	if ( c1 < ( n / 2 ) ) {
		t = dfs( u + 1 , c1 + 1 , c2 , c3 , sum + me[u].a ) ;
		ans = max( ans , t ) ;
	}
	if ( c2 < ( n / 2 ) ) {
		t = dfs( u + 1 , c1 , c2 + 1 , c3 , sum + me[u].b ) ;
		ans = max( ans , t ) ;		
	}
	if ( c3 < ( n / 2 ) ) {
		t = dfs( u + 1 , c1 , c2 , c3 + 1 , sum + me[u].c ) ;
		ans = max( ans , t ) ;		
	}

	return ans ;
}
signed main( ) {
	ios::sync_with_stdio( false ) , cin.tie( 0 ) , cout.tie( 0 ) ;
	freopen( "club.in" , "r" , stdin ) ;
	freopen( "club.out" , "w" , stdout ) ;
	int T ;
	cin >> T ;
	while ( T-- ) {
		cin >> n ;
		ans = 0 ;
		bool fb = true , fc = true ;
		for ( int i = 1 ; i <= n ; i++ ) {
			cin >> me[i].a >> me[i].b >> me[i].c ;
			me[i].cl = 0 ;
			me[i].f = false ;
			if ( me[i].c != 0 || me[i].b != 0 ) {
				if ( me[i].b != 0 && me[i].c != 0 ) {
					fb = false ;
				}
				fc = false ;
			}
		}
		if ( fc ) {
			sort( me + 1 , me + n + 1 , cmpfca ) ;
			int ans = 0 ;
			for ( int i = 1 ; i <= ( n / 2 ) ; i++ ) {
				ans += me[i].a ;
			}
			cout << ans ;
			continue ;
		}
		dfs( 1 , 0 , 0 , 0 , 0 ) ;
		cout << ans << endl ;
	}
	return 0 ;
}