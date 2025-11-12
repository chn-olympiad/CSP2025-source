#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	vector<long long> a(n+1,0),pre(n+1,0);
	bool all1=true,a01=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			all1=false;
		}
		if(a[i]>=2)
		{
			a01=false;
		}
		pre[i]=pre[i-1]^a[i];
	}
	if(all1)
	{
		cout<<n;
		return 0;
	}
	if(a01)
	{
		if(k==1)
		{
			long long ans=0;
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
		if(k==0)
		{
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
				}
				if(a[i]==1 && a[i-1]==1)
				{
					ans++;
					a[i]=0;
					a[i-1]=0;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((pre[j]^pre[i-1])==k)
			{
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
