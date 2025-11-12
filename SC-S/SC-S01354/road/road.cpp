#include<bits/stdc++.h>
#define int long long
using namespace std;
int fa[200005],n,m,k;
struct edge
{
	int v,nxt,w;
}eg[20000005];
int tot,head[200005];
void addedge(int u,int v,int w)
{
	eg[++tot]={v,head[u],w};
	head[u]=tot;
}
void init()
{
	for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x)
{
	if(x!=fa[x])return fa[x]=find(fa[x]);
	return fa[x];
}
bool Union(int u,int v)
{
	int f1=find(u),f2=find(v);
	if(f1==f2)return true;
	fa[f1]=f2;
	return true;
}
bool cmp(edge s1,edge s2)
{
	return s1.w<s2.w;
}
pair<int,int>e[20000005];

void kruskal()
{
	int ans=0,cnt=0;
	sort(eg+1,eg+tot,cmp);
	for(int i=1;i<=tot;i++)
	{
		if(Union(e[i].first,e[i].second))
		{
			ans+=eg[i].w;
			if(++cnt==n-1)break;
		}
	}
	cout<<ans;
}
int ww[1005][1005],c[200005];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cn=0;
	int flg=0;
	init();
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
		e[++cn]={u,v};
	}
	for(int i=n;i<=n+k-1;i++)
	{
		int flg=0;
		cin>>c[i];
		if(c!=0)flg=1;
		for(int j=1;j<=n;j++)
		{
			cin>>ww[i][j];
			if(ww[i][j]!=0)flg=1;
		}
		if(!flg)
		{
			cout<<0;
			return 0;
		}
	}
	for(int i=n;i<=n+k-1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				addedge(j,k,ww[i][j]+ww[i][k]+c[i]);
				e[++cn]={j,k};
			}
		}
	}
	kruskal();
}