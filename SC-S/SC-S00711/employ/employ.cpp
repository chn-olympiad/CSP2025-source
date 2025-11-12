#include<bits/stdc++.h>
using namespace std;
int n , m ;
string s ;
const int mod = 998244353 ;
int a [ 510 ] ;
int ans ;
bool f [ 510 ] ;
void dfs ( int i , int k , int m1 , int o )
{
	if ( s [ k ] == '0' || a [ i ] <= o )
		o ++ ;
	else
		m1 ++ ;
	if ( k == n - 1 && m1 >= m )
	{
		ans ++ ;
		ans %= mod ;
		return ;
	}
	f [ i ] = 1 ;
	for ( int j = 1 ; j <= n ; j ++ )
	{
		if ( f [ j ] == 1 )
			continue ;
		dfs ( j , k + 1 , m1 , o ) ;
	}
	f [ i ] = 0 ;
}
int main ()
{
	freopen ( "employ.in" , "r" , stdin ) ;
	freopen ( "employ.out" , "w" , stdout ) ;
	scanf ( "%d%d" , &n , &m ) ;
	cin >> s ;
	for ( int i = 1 ; i <= n ; i ++ )
		scanf ( "%d" , &a [ i ] ) ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		dfs ( i , 0 , 0 , 0 ) ;
	}
	printf ( "%d" , ans ) ;
	return 0 ;
}