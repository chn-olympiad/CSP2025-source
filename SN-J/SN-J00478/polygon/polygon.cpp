#include<bits/stdc++.h>
using namespace std;
int m,a[10000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	
	int sum = 0;
	cin >> m ;	

	
	for(int i = 1 ; i <= m ; i++)
	{
		cin >> a[i];
	}	
	
	int n = max(a[1],max(a[2],a[3]));
	
	if(m < 3 )
	{
		cout << "0" ;
	}

	else if(m == 3)
	{
		if( (a[1] + a[2] + a[3]) > 2*n)
		{
			cout << "1" ;
		}
		else
		{
			cout << "0";
		}
	}
	
	else if(m > 3)
	{
		for(int i = 3 ; i <= m ; i++)
		{
			sum += i;
		}
		cout << sum % 998244353 ;
	}
	
	return 0; 
 } 
