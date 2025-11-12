#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],ans=0,y=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		 } 
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		y=a[i]|y;
		if(y==k)
		{
			ans++;
			y=0;
		}
	}
	cout<<ans;
	return 0;
 } 
