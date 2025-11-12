#include<bits/stdc++.h>
using namespace std;


int main()
{
	 
	int t ;
	long long n , q , sum = 0 ;
	
	cin >> t >> n ;
	q = n / 2 ;
	
	int a[100100] , b[100100] , c[100100] , maxn[100100] ;
	
	
	
	for(int k = 1 ; k <= t ; k ++)
	{
		for(int i = 1 ; i <= n ; i ++ )
	    {
		    cin >> a[i] >> b[i] >> c[i] ;	
		    maxn[i] = max(a[i] , b[i]);
		    maxn[i] = max(maxn[i] , c[i]);
		   
					
	    }
	    
		if(n == 2)
		{
			long long x[10] ;
			x[1] = a[1] + b[2] ;
			x[2] = a[1] + c[2] ;
			x[3] = b[1] + a[2] ;
			x[4] = b[1] + c[2] ;	
	        x[5] = c[1] + b[2] ;
			x[6] = c[1] + a[2] ;
			sum = max(x[1] , x[2]) ;
			sum = max(sum , x[3]) ;
			sum = max(sum , x[4]) ;
			sum = max(sum , x[5]) ;
			sum = max(sum , x[6]) ;
			cout << sum << endl ;
			sum = 0 ;
			continue ;
		}
		
				
		for(int j = 1 ; j <= n ; j ++)
		{
			sum += maxn[j] ;
		}
		
		cout << sum << endl ;
		
	    sum = 0 ;
	}
	return 0;
}
