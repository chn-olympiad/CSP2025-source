# include <bits/stdc++.h>
# define int long long
using namespace std ;
const int N = 2e5 + 7 ;
string s1 [ N ] , s2 [ N ] ;
int cntleft [ N ] , cntright [ N ] ;
signed main ( )
{
	freopen ( "replace.in" , "r" , stdin ) ;
	freopen ( "replace.out" , "w" , stdout ) ;
	int n , q ;
	cin >> n >> q ;
	for ( int i = 1 ; i <= n ; i = i + 1 )
	{
		cin >> s1 [ i ] >> s2 [ i ] ;
		while ( s1 [ i ] [ 0 ] == s2 [ i ] [ 0 ] && s1 [ i ] . size ( ) > 0 && s2 [ i ] . size ( ) > 0 )
		{
			s1 [ i ] . erase ( 0 , 1 ) ;
			s2 [ i ] . erase ( 0 , 1 ) ;
			cntleft [ i ] = cntleft [ i ] + 1 ; 
		}
		while ( s1 [ i ] [ max ( s1 [ i ] . size ( ) , s2 [ i ] . size ( ) ) - 1 ] == s2 [ i ] [ max ( s1 [ i ] . size ( ) , s2 [ i ] . size ( ) ) - 1 ] && s1 [ i ] . size ( ) > 0 && s2 [ i ] . size ( ) > 0 )
		{
			s1 [ i ] . pop_back ( ) ;
			s2 [ i ] . pop_back ( ) ;
			cntright [ i ] = cntright [ i ] + 1 ;
		}
	}
	while ( q -- )
	{
		string t1 , t2 ;
		cin >> t1 >> t2 ;
		int cl = 0 , cr = 0 ;
		if ( t1 . size ( ) != t2 . size ( ) )
		{
			cout << 0 << "\n" ;
			continue ;
		}
		while ( t1 [ 0 ] == t2 [ 0 ] && t1 . size ( ) > 0 && t2 . size ( ) > 0 )
		{
			t1 . erase ( 0 , 1 ) ;
			t2 . erase ( 0 , 1 ) ;
			cl = cl + 1 ;
		}
		while ( t1 [ max ( t1 . size ( ) , t2 . size ( ) ) - 1 ] == t2 [ max ( t1 . size ( ) , t2 . size ( ) ) - 1 ] && t1 . size ( ) > 0 && t2 . size ( ) > 0 )
		{
			t1 . pop_back ( ) ;
			t2 . pop_back ( ) ;
			cr = cr + 1 ;
		}
		int cnt = 0 ;
		for ( int i = 1 ; i <= n ; i = i + 1 )
		{
			if ( s1 [ i ] . size ( ) < t1 . size ( ) || s2 [ i ] . size ( ) < t2 . size ( ) )
			{
				continue ;
			}
			if ( s1 [ i ] == t1 && s2 [ i ] == t2 && cl >= cntleft [ i ] && cr >= cntright [ i ] )
			{
				cnt = cnt + 1 ;
			}
		}
		cout << cnt << "\n" ;
	}
	return 0 ;
}
