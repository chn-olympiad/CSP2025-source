#include <bits/stdc++.h>

#define int long long

#define ull unsigned long long

#define endl '\n'


#define str string

using namespace std;

const int N = 510 , mod = 998244353;

int n , m , a [ N ] , ans;

str s;

bool b [ N ];

int dfs ( int k , int node )

{
	
	if ( node == m )
	
	{
		
		ans ++;
		
		ans %= mod;
		
		return 0;
	}
	
	if ( k == n + 1 )
	
	{
		
		return 0;
	}
	
	for ( int i =  1 ; i <= n ; i ++ )
	
	{
		
		if ( ! b [ i ] )
		
		{
			
			if ( k - node - 1 >= a [ i ] || s [ k - 1 ] == '0' )
			
			{
				
				b [ i ] = 1;
				
				dfs ( k + 1 , node );
				
				b [ i ] = 0;
			}
			
			else
			
			{
				
				b [ i ] = 1;
				
				dfs ( k + 1 , node + 1 );
				
				b [ i ] = 0;
			}
		}
	}
}

signed main ( )

{
	
	ios::sync_with_stdio ( 0 );
	
	cin . tie ( 0 );
	
	cout . tie ( 0 );
	
	freopen ( "employ.in" , "r" , stdin );
	
	freopen ( "employ.out" , "w" , stdout );

    cin >> n >> m;
    
    cin >> s;
    
    for ( int i = 1 ; i <= n ; ++ i ) cin >> a [ i ];
    
    if ( n <= 15 )
    
    {
    	
    	dfs ( 1 , 0 );
    	
    	cout << ans;
	}

    return 0;
}