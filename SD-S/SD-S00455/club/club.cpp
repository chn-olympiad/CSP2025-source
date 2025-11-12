#include<bits/stdc++.h>
using namespace std ;  
# define stp ios::sync_with_stdio ( false ) 
# define endl "\n"
const int N = 1e5 + 11 ; 
int t , n , num [ 4 ] , ans ;  
struct node {
	int f ;
	int s ; 
	int p ; 
	int maxid ; 
	int maxx ; 
	int d ; 	
} a [ N ] ;
bool cmp ( node a , node b ) {
	return a . d > b . d ; 
}
int main ( ) {
	freopen ( "club.in" , "r" , stdin ) ;
	freopen ( "club.out" , "w" , stdout ) ;
	stp ; 
	cin >> t ;
	while ( t -- ) {
		cin >> n ; 
		memset ( num , 0 , sizeof num ) ;
		ans = 0 ; 
		for ( int i = 1 ; i <= n ; i ++ ) {
			cin >> a [ i ] . f >> a [ i ] . s >> a [ i ] . p ; 
			a [ i ] . maxx = max ( a [ i ] . f , max ( a [ i ] . s , a [ i ] . p ) ) ;
			if ( a [ i ] . f >= a [ i ] . s && a [ i ] . s >= a [ i ] . p ) {
				num [ 1 ] ++ ; 
				a [ i ] . maxid = 1 ; 
				a [ i ] . d = a [ i ] . f - a [ i ] . s ; 
			}
			else if ( a [ i ] . f >= a [ i ] . p && a [ i ] . p >= a [ i ] . s ) {
				num [ 1 ] ++ ; 
				a [ i ] . maxid = 1 ; 
				a [ i ] . d = a [ i ] . f - a [ i ] . p ; 
			}
			else if ( a [ i ] . s >= a [ i ] . p && a [ i ] . p >= a [ i ] . f ) {
				num [ 2 ] ++ ; 
				a [ i ] . maxid = 2 ; 
				a [ i ] . d = a [ i ] . s - a [ i ] . p ; 
			}
			else if ( a [ i ] . s >= a [ i ] . f && a [ i ] . f >= a [ i ] . p ) {
				num [ 2 ] ++ ; 
				a [ i ] . maxid = 2 ; 
				a [ i ] . d = a [ i ] . s - a [ i ] . f ; 
			}
			else if ( a [ i ] . p >= a [ i ] . s && a [ i ] . s >= a [ i ] . f ) {
				num [ 3 ] ++ ; 
				a [ i ] . maxid = 3 ; 
				a [ i ] . d = a [ i ] . p - a [ i ] . s ; 
			}
			else if ( a [ i ] . p >= a [ i ] . f && a [ i ] . f >= a [ i ] . s ) {
				num [ 3 ] ++ ; 
				a [ i ] . maxid = 3 ; 
				a [ i ] . d = a [ i ] . p - a [ i ] . f ; 
			}
		}
		if ( num [ 1 ] <= n / 2 && num [ 2 ] <= n / 2 && num [ 3 ] <= n / 2 ) {
			for ( int i = 1 ; i <= n ; i ++ ) 
				ans += a [ i ] . maxx ;
			cout << ans << endl ; 
			continue ; 
		}
		int id , cnt = 0 ; 
		if ( num [ 1 ] > n / 2 ) 
			id = 1 ; 
		if ( num [ 2 ] > n / 2 ) 
			id = 2 ; 
		if ( num [ 3 ] > n / 2 ) 
			id = 3 ;
		sort ( a + 1 , a + n + 1 , cmp ) ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( a [ i ] . maxid != id ) 
				ans += a [ i ] . maxx ; 
			else if ( cnt < n / 2 ) {
				cnt ++ ; 
				ans += a [ i ] . maxx ; 
			}
			else 
				ans += a [ i ] . maxx - a [ i ] . d ; 
		}
		cout << ans << endl ; 
	}
	return 0 ; 
}
