#include<bits/stdc++.h>
using namespace std;
int n,a[5004],s=0,ans=0,maxx=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
		if(a[i]>maxx)
		{
			maxx=a[i];
		}
	}
	if(s>maxx*2)
	{
		ans=1;
	}
	else
	{
		ans=0;
	}
	cout<<ans%998244353;
	return 0;
} 
