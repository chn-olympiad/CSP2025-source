#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 ;
int t , n ;
long long a [ N ] [ 3 ] ;
int d1 [ 3 ] ;
long long ans = 0 ;
void dfs ( long long sum , int k , int i , int l )
{
	d1 [ i ] ++ ;
	if ( d1 [ 0 ] > l || d1 [ 1 ] > l || d1 [ 2 ] > l )
	{
		d1 [ i ] -- ;
		return ;
	}
	if ( k == n )
	{
		d1 [ i ] -- ;
		ans = max ( ans , sum ) ;
		return ;
	}
	for ( int j = 0 ; j <= 2 ; j ++ )
	{
		sum += a [ k + 1 ] [ j ] ;
		dfs ( sum , k + 1 , j , l ) ;
		sum -= a [ k + 1 ] [ j ] ;
	}
	d1 [ i ] -- ;
}
int main ()
{
	freopen ( "club.in" , "r" , stdin ) ;
	freopen ( "club.out" , "w" , stdout ) ;
	scanf ( "%d" , &t ) ;
	while ( t -- )
	{	
		scanf ( "%d" , &n ) ;
		ans = 0 ;
		memset ( d1 , 0 , sizeof ( 0 ) ) ;
 		for ( int i = 1 ; i <= n ; i ++ )
		{
			scanf ( "%lld%lld%lld" , &a [ i ] [ 0 ] , &a [ i ] [ 1 ] , &a [ i ] [ 2 ] ) ;
		}
		for ( int i = 0 ; i <= 2 ; i ++ )
			dfs ( a [ 1 ] [ i ] , 1 , i , n / 2 ) ;
		printf ( "%lld\n" , ans ) ;
	}
	return 0 ;
}