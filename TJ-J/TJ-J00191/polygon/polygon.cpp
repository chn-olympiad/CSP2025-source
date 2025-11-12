#include<bits/stdc++.h>

int n , a[500000 + 20] , bl;

int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	
	std::cin>>n;
	for(int i = 0 ; i < n ; i++)
	{
		std::cin>>a[i];
	}
	
	
	for(int i = 0 ; i < n ; i++)
	{
		int j = i + 1;
		int k = j + 1;
		if(a[i] + a[j] > a[k] &&
		   a[i] + a[k] > a[j] &&
		   a[j] + a[k] > a[i] &&
		   a[j] + a[i] > a[k] &&
		   a[j] + a[i] > a[k] &&
		   a[k] + a[i] > a[j] &&
		   a[k] + a[j] > a[i]   )
		{
			bl++;
		}
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		int j = i + 1;
		int k = j + 1;
		int l = k + 1;
		if(a[i] + a[j] + a[k] > a[l] &&
		   a[i] + a[j] + a[l] > a[k] &&
		   
		   a[i] + a[k] + a[j] > a[l] &&
		   a[i] + a[k] + a[l] > a[j] &&
		   
		   a[i] + a[l] + a[j] > a[k] &&
		   a[i] + a[l] + a[k] > a[j] &&
		   
		   
		   
		   a[j] + a[i] + a[k] > a[l] &&
		   a[j] + a[i] + a[l] > a[k] &&
		   
		   a[j] + a[k] + a[i] > a[l] &&
		   a[j] + a[k] + a[i] > a[l] &&
		   
		   a[j] + a[l] + a[i] > a[k] &&
		   a[j] + a[l] + a[k] > a[i] &&
		   
		   
		   
		   a[k] + a[i] + a[j] > a[l] &&
		   a[k] + a[i] + a[l] > a[j] &&
		   
		   a[k] + a[j] + a[i] > a[l] &&
		   a[k] + a[j] + a[l] > a[i] &&
		   
		   a[k] + a[l] + a[i] > a[j] &&
		   a[k] + a[l] + a[j] > a[i] &&
		   
		   
		   
		   a[l] + a[i] + a[j] > a[k] &&
		   a[l] + a[i] + a[k] > a[j] &&
		   
		   a[l] + a[j] + a[i] > a[k] &&
		   a[l] + a[j] + a[k] > a[i] &&
		   
		   a[l] + a[k] + a[i] > a[j] &&
		   a[l] + a[k] + a[j] > a[i]   )
		   {
		   		bl++;
		   }
		
		
		
	}
	std::cout<<bl;
	return 0;
}
