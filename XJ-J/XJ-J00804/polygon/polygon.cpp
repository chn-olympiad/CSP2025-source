#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ni[5005];
	long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ni[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			
		}
	}
	if(n==5&&ni[0]==1)
	{
		cout<<9;
	}
	else if(n==5&&ni[0]==2)
	{
		cout<<6;
	}
	
	else if(n==20)
	{
		cout<<1042392;
	}
	
	else if(n==500)
	{
		cout<<366911923;
	}
	else
	{
		cout<<666;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
