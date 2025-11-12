#include<bits/stdc++.h>
using namespace std;

int a[5005];
int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool b=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(b==0)
		{
			if(a[i]!=1)
			{
				b=1;
			}
		}
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		cout<<1;
		return 0;
	}
	long long ans=0;
	
	if(b==0)
	{
		cout<<(n-2+1)*(n-2)/2%998%244%353;
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
