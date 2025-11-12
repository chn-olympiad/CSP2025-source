# include <bits/stdc++.h>
# define int long long
using namespace std ;
const int N = 1e5 + 7 ;
struct Node
{
	int id , from , to , val ;
	friend bool operator < ( Node x , Node y )
	{
		return x . val > y . val ;
	}
} ;
int a [ N ] [ 10 ] , cnt [ 10 ] ;
bool vis [ N ] ;
priority_queue < Node > q ;
void init ( )
{
	memset ( cnt , 0 , sizeof cnt ) ;
	memset ( vis , 0 , sizeof vis ) ;
	while ( q . empty ( ) == false )
	{
		q . pop ( ) ;
	}
} 
signed main ( )
{
	freopen ( "club.in" , "r" , stdin ) ;
	freopen ( "club.out" , "w" , stdout ) ;
	int T ;
	cin >> T ;
	while ( T -- )
	{
		init ( ) ;
		int n , ans = 0 ;
		cin >> n ;
		for ( int i = 1 ; i <= n ; i = i + 1 )
		{
			int maxn = - 1e9 , flag = 0 ;
			for ( int j = 1 ; j <= 3 ; j = j + 1 )
			{
				cin >> a [ i ] [ j ] ;
				if ( a [ i ] [ j ] > maxn )
				{
					maxn = a [ i ] [ j ] ;
					flag = j ;
				}
			}
			ans = ans + maxn ;
			cnt [ flag ] = cnt [ flag ] + 1 ;
		}
		if ( cnt [ 1 ] > n / 2 )
		{
			for ( int i = 1 ; i <= n ; i = i + 1 )
			{
				if ( a [ i ] [ 1 ] >= a [ i ] [ 2 ] && a [ i ] [ 1 ] >= a [ i ] [ 3 ] )
				{
					q . push ( { i , 1 , 2 , a [ i ] [ 1 ] - a [ i ] [ 2 ] } ) ;
					q . push ( { i , 1 , 3 , a [ i ] [ 1 ] - a [ i ] [ 3 ] } ) ;
				}
			}
			int temp = cnt [ 1 ] - n / 2 ;
			while ( cnt [ 1 ] - n / 2 > 0 )
			{
				if ( vis [ q . top ( ) . id ] == false && cnt [ q . top ( ) . to ] + 1 <= n / 2 )
				{
					cnt [ q . top ( ) . from ] = cnt [ q . top ( ) . from ] - 1 ;
					cnt [ q . top ( ) . to ] = cnt [ q . top ( ) . to ] + 1 ;
					vis [ q . top ( ) . id ] = true ;
					ans = ans - q . top ( ) . val ;
				}
				if ( q . empty ( ) == true )
				{
					break ;
				}
				q . pop ( ) ;
			}
		}
		if ( cnt [ 2 ] > n / 2 )
		{
			for ( int i = 1 ; i <= n ; i = i + 1 )
			{
				if ( a [ i ] [ 2 ] >= a [ i ] [ 1 ] && a [ i ] [ 2 ] >= a [ i ] [ 3 ] )
				{
					q . push ( { i , 2 , 1 , a [ i ] [ 2 ] - a [ i ] [ 1 ] } ) ;
					q . push ( { i , 2 , 3 , a [ i ] [ 2 ] - a [ i ] [ 3 ] } ) ;
				}
			}
			int temp = cnt [ 2 ] - n / 2 ;
			while ( cnt [ 2 ] - n / 2 > 0 )
			{
				if ( vis [ q . top ( ) . id ] == false && cnt [ q . top ( ) . to ] + 1 <= n / 2 )
				{
					cnt [ q . top ( ) . from ] = cnt [ q . top ( ) . from ] - 1 ;
					cnt [ q . top ( ) . to ] = cnt [ q . top ( ) . to ] + 1 ;
					vis [ q . top ( ) . id ] = true ;
					ans = ans - q . top ( ) . val ;
				}
				if ( q . empty ( ) == true )
				{
					break ;
				}
				q . pop ( ) ;
			}	
		}
		if ( cnt [ 3 ] > n / 2 )
		{
			for ( int i = 1 ; i <= n ; i = i + 1 )
			{
				if ( a [ i ] [ 3 ] >= a [ i ] [ 1 ] && a [ i ] [ 3 ] >= a [ i ] [ 2 ] )
				{
					q . push ( { i , 3 , 1 , a [ i ] [ 3 ] - a [ i ] [ 1 ] } ) ;
					q . push ( { i , 3 , 2 , a [ i ] [ 3 ] - a [ i ] [ 2 ] } ) ;
				}
			}
			int temp = cnt [ 3 ] - n / 2 ;
			while ( cnt [ 3 ] - n / 2 > 0 )
			{
				if ( vis [ q . top ( ) . id ] == false && cnt [ q . top ( ) . to ] + 1 <= n / 2 )
				{
					cnt [ q . top ( ) . from ] = cnt [ q . top ( ) . from ] - 1 ;
					cnt [ q . top ( ) . to ] = cnt [ q . top ( ) . to ] + 1 ;
					vis [ q . top ( ) . id ] = true ;
					ans = ans - q . top ( ) . val ;
				}
				if ( q . empty ( ) == true )
				{
					break ;
				}
				q . pop ( ) ;
			}			
		}
		cout << ans << "\n" ;
	}
	return 0 ;
}
