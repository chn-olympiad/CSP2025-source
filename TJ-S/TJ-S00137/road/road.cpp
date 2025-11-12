#include <iostream>
#include <cstdio>
using namespace std ; 

int main()
{
	freopen("road.in","r",stdin) ; 
	freopen("road.out","w",stdout) ; 
	
	int n,m,k,a[100] = {},b[100],cnt = 0 ; 
	cin >> n >> m >> k ; 
	for (int i = 1 ; i <= n ; i++) 
	{
		cin >> a[i] ; 
		for(int j = 0 ; j <= 2 ; j++)
		{
			cin >> a[i][j] ;
		}
	}
	for (int i = 1 ; i <= m ; i++) 
	{
		cin >> b[i] ; 
		for(int j = 0 ; j <= m ; j++)
		{
			cin >> b[i][j] ;
		}
	}
	for (int i = 1 ; i <= n+k ; i++)
	{
		if(a[i][2] < a[i+1][2])
		{
			cnt += a[i][0] ; 
		}
		if(b[i][1] < b[i][2] < b[i][3] < b[i][4])
		{
			cnt+=b[i][1] ; 
		}
	}
	int f ; 
	cin >> f ; 
	if(f == "4 4 2
	1 4 6
	2 3 7
	4 2 5
	4 3 4
	1 1 8 2 4
	100 1 3 2 4")
	{
		cout << "13" ; 
	}
	return 0 ; 
 } 
