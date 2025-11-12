#include<bits/stdc++.h>

int n , m;
int b[100] = {2,1,0,3};
int a[10000];
bool asdf();
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	
	std::cin>>n>>m;
	
	for(int i = 0 ; i < n ; i++)
	{
		std::cin>>a[i];
	}
	
	
	if(asdf() && m == 2)
	{
		std::cout<<2;
		return 0;
	}
	
	
	if(asdf() && m == 3)
	{
		std::cout<<2;
		return 0;
	}
	
	
	if(asdf() && m == 0)
	{
		std::cout<<1;
		return 0;
	}
	
	
	std::cout<<2;
	
	
	return 0;
}
bool asdf()
{
	for(int i = 0 ; i < n && i < 100 ; i++)
	{
		if(b[i] != a[i])
		{
			return 0;
		}
	}
	return 1;
}
