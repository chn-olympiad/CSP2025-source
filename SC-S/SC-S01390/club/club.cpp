#include<bits/stdc++.h>
using namespace std;
int cnt1 , cnt2 , cnt3 ;
priority_queue< int , vector<int> , greater<int> > p1 , p2 , p3 ;
int ans ;
void solve() {
	int n ;
	cin >> n ;
	cnt1 = cnt2 = cnt3 = 0 ;
	while ( !p1.empty() )	p1.pop() ;
	while ( !p2.empty() )	p2.pop() ;
	while ( !p3.empty() )	p3.pop() ; 
	int a , b , c ;
	ans = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a >> b >> c ;
		if ( a >= b and a >= c ) {
			ans += a ;
			p1.push( a - max( b , c ) ) ;
			cnt1 ++ ;
		}else if ( b >= a and b >= c ) {
			ans += b ;
			p2.push( b - max( a , c ) ) ;
			cnt2 ++ ;
		}else {
			ans += c ;
			p3.push( c - max( a , b ) ) ;
			cnt3 ++ ;
		}
	}while ( cnt1 > n / 2 ) {
		ans -= p1.top() ;
		p1.pop() ;
		cnt1 -- ;
	}while ( cnt2 > n / 2 ) {
		ans -= p2.top() ;
		p2.pop() ;
		cnt2 -- ;
	}while ( cnt3 > n / 2 ) {
		ans -= p3.top() ;
		p3.pop() ;
		cnt3 -- ;
	}cout << ans << "\n" ;
	return ;
}
signed main() {
	freopen( "club.in" , "r" , stdin ) ;
	freopen( "club.out" , "w" , stdout ) ;
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    cout.tie(0) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
    	solve() ;
	}
    return 0 ;
}
