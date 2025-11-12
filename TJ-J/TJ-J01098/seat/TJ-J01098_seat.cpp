#include<bits/stdc++.h>
using namespace std;
int main( )
{
	freopen( "seat1.in", "r", stdin );
	freopen( "seat1.ans", "w", stdout );
	int n, m;
	cin >> n >> m;
	int a[100];
	for ( int i = 0; i < n+m; i++ )
		cin >> a[i];
	int r1 = a[0];
	sort( a, a+n+m );
	int r2 = 0;
	for( int i = 0; i < n+m; i++ )
	{
		if( a[i] == r1 )
		{
			r2 = i;
			break;
		}
	}
	int lie, hang;
	lie = r2 / n;
	hang = r2 % m;
	cout << lie << " " << hang;
	fclose( stdout );
	return 0;
}
