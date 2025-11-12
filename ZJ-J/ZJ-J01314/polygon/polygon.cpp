#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
long long ans=0;
int p[1000001];
int chk(int x,int y)
{
	int k=0;
	if(y<3)
		return 0;
	int m;
	for(int i=1,j=0;i<=n;i++)
	{
		if(p[i])
		{
			k+=a[i];
			j=max(j,a[i]);
			m=j;
		}
	}
	if(2*m>=k)
		return 0;
	return 1;
}
void dfs(int u,int step)
{
	if(step==n+1)
	{
		return;
	}
	if(chk(u,step))
	{
		ans++;
	}
	for(int i=u+1;i<=n;i++)
	{
		if(p[i])
		{
			continue;
		}
		p[i]=1;
		dfs(i,step+1);
		p[i]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans%998244353;
	return 0;
}
