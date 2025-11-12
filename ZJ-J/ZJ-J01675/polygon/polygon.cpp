#include<bits/stdc++.h>
using namespace std;
long long ans,n,a[1000100];
void dfs(long long s,long long x,long long maxn,long long y)
{
	if(x>n)
	{
		if(maxn*2<s&&y>=3)
		{
			ans+=1;
			ans=ans%998244353;
		}
		return;
	}
	if(maxn*2<s&&y>=3)
	{
		ans+=1;
		ans=ans%998244353;
	}
	for(int i=x;i<=n;i++)
	{
		dfs(s+a[i],i+1,max(maxn,a[i]),y+1);
	}
}
int main( )
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	dfs(0,1,0,0);
	cout<<ans%998244353;
	return 0;
}
//QwQ
//suan niao suan niao
//tui yi la
//zhu da jia dou you guang ming de wei lai
