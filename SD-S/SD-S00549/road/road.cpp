#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int M;
int p[100100];
int found(int x)
{
	if(x==p[x])
	{
		return x;
	}
	else
	{
		p[x]=found(p[x]);
		return p[x]; 
	}
}
struct edge
{
	int u; 
	int v;
	int w;
}g[2000010];
bool cmp(edge a,edge b)
{
	return  a.w<b.w;
}
signed main()
{

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=n+k+5;++i)
	{
		p[i]=i;
	}
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[i].u=u;
		g[i].v=v;
		g[i].w=w;
	}
	int ans=0;
	int cnt=0;
	if(k<=0)
	{
		sort(g+1,g+1+m);
		for(int i=1;i<=m;++i)
		{
			int u=g[i].u;
			int v=g[i].v;
			int w=g[i].w;
			u=found(u);
			v=found(v);
			if(u!=v)
			{
				p[u]=v;
				cnt++;
				ans+=w;
			}
			if(cnt==n-1)
			{
				break;
			}
		}
		cout<<ans<<"\n";
	}
	else
	{
		cout<<0<<"\n";
	}
	return 0;
}

