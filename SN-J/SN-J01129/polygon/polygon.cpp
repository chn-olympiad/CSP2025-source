//SN-J01129 陶泽玉 安康市高新中学 
#include <bits/stdc++.h>
using namespace std;
int n,a[50005],maxn;
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1)
	{
		long long nj=1,mj=1,mnj=1;
		for(int i=1;i<=n;i++)
		{
			nj*=i;
			nj%=998244353;
		}
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				mj*=i;
				mj%=998244353;
			}
			for(int j=1;j<=n-i;j++)
			{
				mnj%=998244353;
			}
			ans+=(nj/mj/mnj)%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n<=3)
	{
		maxn=max(a[1],max(a[2],a[3]));
		int q=a[1]+a[2]+a[3];
		if(q>2*maxn)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	
	return 0;
} 
