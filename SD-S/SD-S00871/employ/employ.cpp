# include <bits/stdc++.h>
# define int long long
using namespace std ;
const int N = 510 , mod = 998244353 ;
string s ;
int n , m , c [ N ] ;
bool check ( )
{
	for ( int i = 1 ; i <= n ; i = i + 1 )
	{
		if ( s [ i ] == '0' )
		{
			return false ;
		}
	}
	return true ;
}
signed main ( )
{
	freopen ( "employ.in" , "r" , stdin ) ;
	freopen ( "employ.out" , "w" , stdout ) ;
	cin >> n >> m >> s ;
	for ( int i = 1 ; i <= n ; i = i + 1 )
	{
		cin >> c [ i ] ;
	}
	sort ( c + 1 , c + 1 + n ) ;
	int ans = 1 ;
	for ( int i = 1 ; i <= n ; i = i + 1 )
	{
		ans = ans * i ;
		ans = ans % mod ;
	}
	if ( m == n )
	{
		for ( int i = 1 ; i <= n ; i = i + 1 )
		{
			if ( s [ i ] == '0' || c [ i ] == 0 )
			{
				cout << 0 ;
				return 0 ;
			}
		}
		cout << ans ;
	}
	else if ( m == 1 )
	{
		int cnt = 0 , pos = 0 ;
		for ( int i = 1 ; i <= n ; i = i + 1 )
		{
			if ( c [ i ] == 0 )
			{
				cnt = cnt + 1 ;
			}
		}
		if ( c [ n ] > cnt )
		{
			cout << ans ;
		}
		else
		{
			int temp = cnt - c [ n ] + 1 ;
			int res = 1 ;
			for ( int i = 1 ; i <= temp ; i = i + 1 )
			{
				res = res * i ;
				res = res % mod ;	
			}
			for ( int i = 1 ; i <= n - temp ; i = i + 1 )
			{
				res = res * i ;
				res = res % mod ;
			}
			cout << res ;
		}		
	}
	else if ( check ( ) )
	{
		int cnt = 0 , pos = 0 ;
		for ( int i = 1 ; i <= n ; i = i + 1 )
		{
			if ( c [ i ] == 0 )
			{
				cnt = cnt + 1 ;
			}
		}
		for ( int i = 1 ; i <= n ; i = i + 1 )
		{
			if ( c [ i ] > cnt )
			{
				pos = i ;
			}
		}
		if ( n - pos + 1 >= m )
		{
			cout << ans ;				
		}
	}
	return 0 ;
}
