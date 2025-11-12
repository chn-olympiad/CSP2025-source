#include <bits/stdc++.h>

#define int long long

#define ull unsigned long long

#define endl '\n'

using namespace std;

const int N = 1e5 + 5;

struct node

{
	
	int a , b , c;
} a [ N ];

signed main ()
{
	
	ios::sync_with_stdio ( 0 );
	
	cin . tie ( 0 );
	
	cout . tie ( 0 );
	
	freopen ( "club.in" , "r" , stdin );
	
	freopen ( "club.out" , "w" , stdout );

    int t; cin >> t;
    
    while ( t -- )
    
    {
    	
    	int n; cin >> n;
    	
    	int sum = 0 , a1 = 0 , b2 = 0 , c3 = 0;
    	
    	for ( int i = 1 ; i <= n ; ++ i )
    	
    	{
    		
    		cin >> a [ i ] . a >> a [ i ] . b >> a [ i ] . c;
		} 
		
		for ( int i = 1 ; i <= n ; ++ i )
		
		{
			
			for ( int j = 1 ; j <= n ; ++ j )
			
			{
					
					if ( n / 2 > a1 && n / 2 > b2 && n / 2 > c3 )
					
					{
					 
						if ( a [ i ] . a > a [ i ] . b && a [ i ] . a > a [ i ] . c )
						
						{
						 
							sum += a [ i ] . a;
							
							a1 ++;
						}
						
						else if ( a [ i ] . b > a [ i ] . a && a [ i ] . b > a [ i ] . c )
						
						{
							
							sum += a [ i ] . b;
							
							b2 ++;
						}
						
						else if ( a [ i ] . c > a [ i ] . a && a [ i ] . c > a [ i ] . b )
						
						{
							
							sum += a [ i ] . c;
							
							c3 ++;
						}
						
						else
						
						{
							
							sum += a [ i ] . a;
							
							a1 ++;
						}
					}
				
			}
		}
		
		cout << sum << endl;
	}
	return 0;
}