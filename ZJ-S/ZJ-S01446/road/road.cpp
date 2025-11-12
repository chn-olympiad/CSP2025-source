#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],a[100100],fa[100100],vis[15],dis[10010][10010];
struct node
{
	int u,v,id;
	long long w;
}e[10000010];
int find(int x)
{
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
bool cmp(node q,node p)
{
	return q.w<p.w;
}
long long kal()
{
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,id=e[i].id;
		long long w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv)
		{
			fa[fu]=fv;
			cnt++;
			ans+=w;
			if(id) vis[id]++;
		}
		if(cnt==n-1) return ans;
	}
	return -1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].id=0;
		dis[e[i].u][e[i].v]=e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[j];
		for(int j=1;j<=n;j++)
		{
			for(int x=j+1;x<=n;x++)
			{
				if(c[i]+a[j]+a[x]>=dis[j][x]) continue;
				e[++m].u=j;
				e[m].v=x;
				e[m].w=c[i]+a[j]+a[x];
				e[m].id=i;
				dis[j][x]=e[m].w;
			}
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	long long res=kal();
	for(int i=1;i<=k;i++) 
		if(vis[i]>1) res-=c[i]*(vis[i]-1);
	cout<<res;
	return 0;
}