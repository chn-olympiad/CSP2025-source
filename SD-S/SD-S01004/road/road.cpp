#include<bits/stdc++.h>
using namespace std;
int n,m,k,qt[10005],ans,c[10005],q[10005][10005],fa[10005];
struct edge
{
	int v,u,w;
	bool b=0;
}e[1000005];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int bfs(int x)
{
	if(fa[x]=x)return x;
	fa[x]=bfs(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	} 
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].v>>e[i].u>>e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>q[i][j];
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(bfs(e[i].u)==bfs(e[i].v))continue;
		else
		{
			ans+=e[i].w;
			fa[e[i].u]=e[i].v;
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
