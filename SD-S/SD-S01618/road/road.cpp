#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int nxt;
	int from;
	int to;
	int w;
	int g=0;
}edge[2500010],EDGE[11000],Edge[11100];
int cnt=0,head[10100],n,m,k,c[15],a[15][10100];
void add(int u,int v,int w)
{
	edge[++cnt].nxt=head[u];
	head[u]=cnt;
	edge[cnt].from=u;
	edge[cnt].to=v;
	edge[cnt].w=w;
	return;
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int fa[11000],ans=1e18;
int find(int a)
{
	return fa[a]==a?a:fa[a]=find(fa[a]);
}
int read()
{
	char ch=getchar();
	while(ch<'0'&&ch>'9')ch=getchar();
	int res=0;
	while((ch>='0')&&(ch<='9'))
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(edge+1,edge+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int x=find(edge[i].from),y=find(edge[i].to);
		if(x!=y)
		{
			fa[x]=y;
			edge[i].g=1;
		}
	}
	int tot=0;
	for(int i=1;i<=cnt;i++)
		if(edge[i].g)
		{
			EDGE[++tot].nxt=edge[i].nxt;
			EDGE[tot].from=edge[i].from;
			EDGE[tot].to=edge[i].to;
			EDGE[tot].w=edge[i].w;
		}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++)
	{
		int num=0,res=0;
		for(int j=1;j<=tot;j++)
			Edge[++num].from=EDGE[num].from,Edge[num].to=EDGE[num].to,Edge[num].w=EDGE[num].w;
		for(int j=0;j<k;j++)
			if((1<<j)&i)
			{
				for(int h=1;h<=n;h++)
					Edge[++num].from=10000+j+1,Edge[num].to=h,Edge[num].w=a[j+1][h];
				fa[j+1+10000]=j+1+10000;
				res+=c[j+1];
			}
		sort(Edge+1,Edge+num+1,cmp);
		for(int j=1;j<=n;j++)fa[j]=j;
		for(int j=1;j<=num;j++)
		{
			int x=find(Edge[j].from),y=find(Edge[j].to);
			if(x!=y)fa[x]=y,res+=Edge[j].w;
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}








