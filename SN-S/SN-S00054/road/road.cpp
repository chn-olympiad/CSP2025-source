//刘尚泽坤  SN-S00054  西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1005][1005],f[1005],sum,ans=0x7ffffff,p;
struct c
{
	int num;
	int d[1005];
}t[1005];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			return false;
		}
	}
	return true;
}
void dfs(int x)
{
	f[x]=1;
	if(check())
	{
		ans=min(ans,sum);
	}
	for(int i=1;i<=t[x].num;i++)
	{
		if(f[t[x].d[i]])
		{
			continue;
		}
		sum+=a[x][t[x].d[i]];
		f[t[x].d[i]]=1;
		dfs(t[x].d[i]);
		sum-=a[x][t[x].d[i]];
		f[t[x].d[i]]--;
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
		t[u].d[++t[u].num]=v;
		t[v].d[++t[v].num]=u;
	}
	if(k==0)
	{
		f[1]=1;
		dfs(2);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		for(int j=1;j<=n;j++)
		{
			cin>>p;
			a[n+i][j]=p;
			a[j][n+i]=p;
			t[n+i].d[++t[n+i].num]=j;
			t[j].d[++t[j].num]=n+i;
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
3 3 0
1 2 1
1 3 2
2 3 3
*/
