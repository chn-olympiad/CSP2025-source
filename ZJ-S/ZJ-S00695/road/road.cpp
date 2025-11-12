/*#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int u,v,w;
}e[1000005];
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int fa[10005];
int c[10005];
int a[10005];
int ee[10005][10005];
int fid(int a)
{
	if(fa[a]==a)
		return a;
	return fa[a]=fid(fa[a]);
}
void merge(int u,int v)
{
	u=fid(u);
	v=fid(v);
	fa[u]=v;
}
int main()
{
	//freopen("road3.in","r",stdin);
	//freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k,i,j;
	long long ans=0;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u,e[i].v=v,e[i].w=w;
	}
	for(i=1;i<=k;i++)
	{
		int x=0;	
		cin>>c[i];
		for(j=1;j<=n;j++)
		{
			cin>>a[j];
			if(a[j]==0)
				x=j;
		}
		if(x)
		{
			for(j=1;j<=n;j++)
				ee[x][j]=a[j];
		}
	}
	sort(e+1,e+m+1,cmp);
	int cnt=n-1;
	for(i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(fid(u)!=fid(v)
		{
			ans+=min(e[i].w,min(ee[u][v]?ee[u][v]:1000000007,ee[v][u]?ee[v][u]:1000000007));
			merge(u,v);
			if(!(--cnt))
				break;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int u,v,w;
}e[1000005];
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int fa[10005];
int c[10005];
int a[10005];
//int ee[10005][10005];
int fid(int a)
{
	if(fa[a]==a)
		return a;
	return fa[a]=fid(fa[a]);
}
void merge(int u,int v)
{
	u=fid(u);
	v=fid(v);
	fa[u]=v;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k,i,j;
	long long ans=0;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u,e[i].v=v,e[i].w=w;
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(j=1;j<=n;j++)
			cin>>a[j];
	}
	sort(e+1,e+m+1,cmp);
	int cnt=n-1;
	for(i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(fid(u)!=fid(v))//It was fid[u] here,haha.
		{
			ans+=e[i].w;
			merge(u,v);
			if(!(--cnt))
				break;
		}
	}//Kruskal
	cout<<ans<<'\n';
	return 0;
}
//Near to AC,but this might not be so easy,meow.