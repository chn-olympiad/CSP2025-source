#include<bits/stdc++.h>
using namespace std;
int g[5050],a[5050],cnt,n;
const int mod=998244353;
void dfs(int x)
{
	if(x>=n)
	{
		int sum=0,maxn=0,c=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				c++;
				sum+=g[i];
				maxn=max(maxn,g[i]);
			}
		}
		if(sum>maxn*2&&c>=3)
		{
			cnt++;
			cnt%=mod;
		}
		return;
	}
	a[x]=1;
	dfs(x+1);
	a[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>g[i];
	if(n<=2)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n==3)
	{
		int sum=0,maxn=0;
		for(int i=1;i<=n;i++)
		{
			sum+=g[i];
			maxn=max(maxn,g[i]);
		}
		if(sum>2*maxn)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	dfs(1);
	cout<<cnt<<endl;
	return 0;
}
