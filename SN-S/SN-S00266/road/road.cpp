#include<bits/stdc++.h>
using namespace std;

int main ()
{
	
	long long n , m , k , num = 0 , sum = 0 ;
	cin >> n >> m >> k ;
	int u[11111] , v[11111] , w[1100000000] ;
	int c[100000] , a[900000][9000000000] ;
	for(int i = 1 ; i <= n ; i ++ )
	{
		cin >> u[i] >> v[i] >> w[i] ;
		num += w[i] ;
	}
	    
	for(int i = 1 ; i <= k ; i ++ )
	{
		cin >> c[i] ;
		for(int j = 1 ; j <= n ; j ++)
		    cin >> a[i][j] ;		
	}     
	
	cout << num << endl; 
	
	
	return 0 ;
}
