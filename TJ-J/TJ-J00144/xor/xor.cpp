#include<bits/stdc++.h>
/*
异或和
使用枚举算法 dp[i][j]存储从A[j]开始、长度为i的区间的异或和 
*/ 
using namespace std ;
int n , k , l , r , ans = 0 ;
int A[500005] ;
int dp[1005][1005] ;
int main() {
	freopen ( "xor.in" , "r" , stdin ) ;
	freopen ( "xor.out" , "w" , stdout ) ;
	cin >> n >> k ;
	l = -1 , r = -1 ;
	for ( int i = 0 ; i < n ; i++ ) {
		cin >> A[i] ;
		dp[1][i] = A[i] ;
	}
	for ( int i = 2 ; i <= n ; i++ ) {
		for ( int j = 0 ; j <= n - i ; j++ ) {
			int num = A[j] ;
			for ( int a = j + 1 ; a <= j + i ; a++ ) {
				num = num ^ A[a] ;
			}
			dp[i][j] = num ;
		}
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 0 ; j <= n - i ; j++ ) {
			if ( dp[i][j] == k && ( j > r || j + i < l ) ) {
				ans++ ;
				l = j , r = j + i ;
			}
		}
	}
	cout << ans << endl ; 
	return 0 ;
}
