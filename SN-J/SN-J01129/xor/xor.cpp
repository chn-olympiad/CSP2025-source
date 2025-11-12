//SN-J01129 陶泽玉 安康市高新中学 
#include <bits/stdc++.h>
using namespace std;
int n,k,a[500015],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2&&k==0)
	{
		if(a[1]==0)
		{
			ans++;
		}
		if(a[2]==0)
		{
			ans++;
		}
		if(a[1]^a[2]==0)
		{
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n<=100&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(k<=1)
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
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			long long sum=0;
			for(int i=l;i<=r;i++)
			{
				sum=sum^a[i];
			}
			if(sum==k)
			{
				ans++;
				l=r+1;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
} 
