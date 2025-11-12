#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#include<vector>
#define ll long long
using namespace std;
ll a[10005][10005],ans=1000000005,tot=0;
bool vis[10005];
int n,m,k;
void dfs(int p,int cnt,ll val)
{
	
	if(cnt==n)
	{
		ans=min(ans,val);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<"\n\n55555555555555555555555555\n\n";
		if(!vis[i]&&a[p][i]!=1000000005)
		{
			vis[i]=1;
//			cout<<p<<' '<<i<<' '<<val+a[p][i]<<"\n";
			dfs(i,cnt+1,val+a[p][i]);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		tot=tot+i;
	}
	for(int i=1;i<=10001;i++)
	{
		for(int j=1;j<=10001;j++)
		{
			a[i][j]=1000000005;
		}
	}
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	a[0][1]=0;
	dfs(0,0,0);
	cout<<ans;
	return 0;
 }

