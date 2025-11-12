#include<bits/stdc++.h>
using namespace std;
int main( )
{
	freopen( "number1.in", "r", stdin );
	freopen( "number1.ans", "w", stdout );
	char a[100];
	cin >> a;
	int s = 0;
	int oi[100];
	for( int i = 0; i < 100; i++ )
	{	
		if( a[i] >= '0' && a[i] <= '9' )
		{
			oi[s] = a[i] - '0';
			s++;
		}
	}
	sort( oi, oi+s );
	for( int i = 0; i < s; i++ ) 
	{
		cout << oi[i];
	}
	fclose( stdout );
	return 0;
}
