#include <bits/stdc++.h>
using namespace std;
int n,m,rs,rp,hang,lie;
int a[1000];
int main()
{
	freopen( "seat.in" , "r" , stdin );
	freopen( "seat.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	rp ++;
	cin >> n >> m;
	for ( int i = 1 ; i <= n * m ; i ++ )
	{
		cin >> a[i];
	}
	rs = a[1];
	sort( a + 1 , a + n * m + 1 , greater<int>( ) );
	for ( int i = 1 ; i <= n * m ; i ++ )
	{
		if ( a[i] == rs )
		{
			rp = i;
			break;
		}
	}
	lie = rp / n;
	if ( rp % n )
	{
		lie ++;
	}
	if ( lie & 1 )
	{
		if ( rp % n )
		{
			hang = rp % n;
		}
		else
		{
			hang = n;
		}
	}
	else
	{
		if ( rp % n )
		{
			hang = rp % n + n - 1;
		}
		else
		{
			hang = 1;
		}
	}
	cout << lie << ' ' << hang;
	return 0;
}
/***********************
Written by zbm TJ-J00446.
2025/11/1.
***********************/ 
