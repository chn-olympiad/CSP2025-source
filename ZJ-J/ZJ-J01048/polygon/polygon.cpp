#include<bits/stdc++.h>
using namespace std;
long long n,xx[10000],a[10000],ans,mod=998244353;
void dfs(long long h,long long maxx,long long g,long long id)
{
	if(h>maxx*2&&g>=3)
	{
		ans++;
	}
	if(id>n) return ;
	dfs(h+xx[id],maxx=max(maxx,xx[id]),g+1,id+1);
	dfs(h,maxx,g,id+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>xx[i],a[xx[i]]++;
	if(n<=3)
	{
		if(n==3)
		{
			if(xx[1]+xx[2]+xx[3]>max(xx[1],max(xx[3],xx[2]))) cout<<1;
			else cout<<0;
		}
		else cout<<0;
		return 0;
	}
	if(a[1]==n)
	{
		ans=1;
		long long x=1;
		for(long long i=1;i<=n;i++) x=x*i%mod;
		for(long long i=3;i<n;i++)
		{
			long long sum=x;
			for(int j=i;j>=1;j--)
			{
				sum/=j;
			}
			ans=(ans+sum)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0ll,0ll,0ll,1ll);
	cout<<ans;
	return 0;
}
