#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int a[1000001];
int main()
{
	freopen( "number.in" , "r" , stdin );
	freopen( "number.out" , "w" , stdout );
	cin.tie( 0 );
	cout.tie( 0 );
	ios::sync_with_stdio( false );
	cin >> s;
	int len = s.size( );
	for ( int i = 0 ; i < len ; i ++ )
	{
		if ( s[i] >= '0' && s[i] <= '9' )
		{
			a[++ cnt] = s[i] - '0';
		}
	}
	sort( a + 1 , a + 1 + cnt , greater<int>( ) );
	for ( int i = 1 ; i <= cnt ; i ++ )
	{
		cout << a[i];
	}
	return 0;
}
/***********************
Written by zbm TJ-J00446.
2025/11/1.
***********************/ 
