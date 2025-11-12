#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],ans,cnt=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(a[0]==1)
	{
		ans=1;
		for(int i=0;i<n-2;i++)
		{
			ans=ans*2;
		}
		cout<<ans;
	}else if(n<3)
	{
		cout<<0;
	}else if(n=3)
	{
		if(a[0]>a[1]+a[2]&&a[1]>a[0]+a[2]&&a[2]>a[1]+a[0])
		{
			cout<<1;
		}else
		{
			cout<<0;
		}
	}else
	{
		cout<<0;
	}
	return 0;
}
