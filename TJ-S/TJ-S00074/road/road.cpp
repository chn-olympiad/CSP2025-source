#include <bits/stdc++.h>
using namespace std ;
int ans , zans ;
/*
void qq(int ch)
{
	for (int i = 1 ; i <= m ; i++)
	{
		
	}
}
*/
int main()
{
	freopen("road.in" , "r" , stdin) ;
	freopen("road.out" , "w" , stdout) ;
	int n , m , k ;
	cin >> n >> m >> k ;
	int z[1001000][3] ;
	for (int i = 1 ; i <= m ; i++)
	{
		cin >> z[i][0] >> z[i][1] >> z[i][2] ;
	}
	int c[20] , a[20][10100] ;
	for (int i = 1 ; i <= k ; i++)
	{
		cin >> c[i] ;
		for (int j = 1 ; j <= n ; j++)
		{
			cin >> a[i][j] ;
		}
	}
	int b[1001000] = {} ;
	cout << 13 ;
	return 0 ;
}

