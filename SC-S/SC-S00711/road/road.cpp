#include<bits/stdc++.h>
using namespace std;
int n , m , k ;
const int N = 1e4 + 15 ;
int a [ N ] [ N ] ;
bool f [ N ] [ N ] , fa [ N ] ;
int ans = 1e9 + 10 ;
void dfs ( int i , int sum , int l )
{
	if ( l == n - 1 )
	{
		ans = min ( ans , sum ) ;
		return ;
	}
	fa [ i ] = 1 ;
	for ( int j = 1 ; j <= n ; j ++ )
	{
		if ( f [ i ] [ j ] == 1 && fa [ j ] == 0 )
		{
			sum += a [ i ] [ j ] ;
			dfs ( j , sum , l + 1 ) ;
			sum -= a [ i ] [ j ] ;
		}
	}
	fa [ i ] = 0 ;
}
int main ()
{
	freopen ( "road.in" , "r" , stdin ) ;
	freopen ( "road.out" , "w" , stdout ) ;
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	int u , v , w ;
	for ( int i = 1 ; i <= m ; i ++ )
	{
		scanf ( "%d%d%d" , &u , &v , &w ) ;
		a [ u ] [ v ] = w ;
		f [ u ] [ v ] = 1 ;
		a [ v ] [ u ] = w ;
		f [ v ] [ u ] = 1 ;
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		if ( f [ 1 ] [ i ] == 1 )
		{
			memset ( fa , 0 , sizeof ( 0 ) ) ;
			fa [ 1 ] = 1 ;
			dfs ( i , a [ 1 ] [ i ] , 1 ) ;
		}
	}
	printf ( "%d" , ans ) ;
	return 0 ;
}