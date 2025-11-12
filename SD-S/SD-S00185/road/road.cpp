#include<bits/stdc++.h>
#define dbg(x) cerr<<#x<<" is : "<<x<<endl
using namespace std;
int n,m,k,a[15],c[15],vis[15],fa[10050],go[10050][10];
long long ans=0;
int w[1000050],e[1000050],r[1000050];
struct edge
{
	int u,v,w;
	friend bool operator <(edge q,edge b)
	{
		return q.w>b.w;
	}
};
priority_queue<edge> q;
int _find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=_find(fa[x]);
}
void dfs(int x)
{
	if(x>k)
	{
		long long an=0;
		for(int i=1;i<=m;i++)
		{
			q.push({w[i],e[i],r[i]});
		}
		for(int i=1;i<=k;i++)
		{
			if(!c[i])continue;
			an+=a[i];
			for(int j=1;j<=n;j++)q.push({i+n,j,go[j][i]});
		}
		while(!q.empty())
		{
			int u=q.top().u,v=q.top().v,p=q.top().w;
			q.pop();
			int fu=_find(u),fv=_find(v);
			if(fu==fv)continue;
			fa[fu]=fv;
			an+=p;
		}
		for(int i=1;i<=n+k;i++)fa[i]=i;
		ans=min(ans,an);
		return;
	}
	c[x]=1;
	dfs(x+1);
	c[x]=0;
	dfs(x+1);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]>>e[i]>>r[i];
		q.push({w[i],e[i],r[i]});
	}
	if(k==0)
	{
		while(!q.empty())
		{
			int u=q.top().u,v=q.top().v,p=q.top().w;
			q.pop();
			int fu=_find(u),fv=_find(v);
			if(fu==fv)continue;
			fa[fu]=fv;
			ans+=p;
		}
		cout<<ans;
		return 0;
	}
	bool isA=1;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)cin>>go[j][i];
		if(a[i])isA=0;
	}
	if(isA)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long dic=1e18;
				for(int z=1;z<=k;z++)
				{
					dic=min(dic,1ll*go[j][z]+go[i][z]);
				}
				q.push({i,j,dic});
			}
		}
		while(!q.empty())
		{
			int u=q.top().u,v=q.top().v,p=q.top().w;
			q.pop();
			int fu=_find(u),fv=_find(v);
			if(fu==fv)continue;
			fa[fu]=fv;
			ans+=p;
		}
		cout<<ans;
		return 0;
	}
	ans=1e18;
	dfs(1);
	cout<<ans;
	return 0;
}

