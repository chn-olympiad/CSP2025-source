#include<bits/stdc++.h>
using namespace std;
int main( )
{
	freopen( "club1.in", "r", stdin );
	freopen( "club1.ans", "w", stdout );

	int a[10];

	int n;
	int m;

	int bigr[10];
	int midr[10];
	int smlr[10];
	
	int l[3];
	int ans = 0;

	cin >> n;									//n(三组 )
	for( int x = 0; x < n; x++ )
	{
		cin >> m;								//m(四样例 ） 
		for ( int y = 0; y < m; y++ ) 
		{
			for ( int z = 0; z < 3; z++ )
			{
				cin >> l[z];
			}
			bigr[y] = max( max( l[0], l[1] ), l[2] );
			midr[y] = min( max( l[0], l[1] ), l[2] );
			smlr[y] = min( min( l[0], l[1] ), l[2] );
			ans += bigr[y];
			
		}
		cout << ans << endl;
		ans = 0;				
	}
	
	fclose( stdout );
	
	return 0;
}
