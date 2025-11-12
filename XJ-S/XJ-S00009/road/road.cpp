#include<bits/stdc++.h>
#define N 1000010
using namespace std;

struct Edge
{
	int u,v,w;
}e[N*2];

int fa[N];
int n,m,k;
int cnt=0;

int find(int x)
{
	if(x==fa[x])
		return x;
	else
		return fa[x]=find(fa[x]);
}
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
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
		cin>>e[i].u>>e[i].v>>e[i].w; 
	}
	
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int i=1;i<=n;i++)
		{
			int y;
			cin>>y;
		}
	}
	
	sort(e+1,e+m+1,cmp);
	
	int ans=0;
	
	for(int i=1;i<=m;i++)
	{
		int x1=find(e[i].u);
		int y1=find(e[i].v);
		
		if(x1!=y1)
		{
			ans+=e[i].w;
			fa[x1]=y1;
		}
	}
	
	cout<<ans;
	return 0;
}
