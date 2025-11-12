#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=4e6+10;

struct edge{
	int u,v,w;
}e[N];

int cnt,c[N],fa[N];
bool vis[N];

inline void add(int u,int v,int w)
{
	e[++cnt].u=u;e[cnt].v=v;e[cnt].w=w;
}

inline bool cmp(edge x,edge y)
{
	return x.w<y.w;
}

inline int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0,cntt=0;cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		add(u,v,w);add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int a;cin>>a;
			add(j,n+i,a+c[i]);
			add(n+i,j,a+c[i]);
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy) continue;
		if(e[i].u>n) vis[e[i].u]=true,ans-=c[e[i].u-n];
		if(e[i].v>n) vis[e[i].v]=true,ans-=c[e[i].v-n];
		ans+=e[i].w;fa[fx]=fy;
		if(e[i].u<=n&&vis[e[i].u]==false) vis[e[i].u]=true,cntt++;
		if(e[i].v<=n&&vis[e[i].v]==false) vis[e[i].v]=true,cntt++;
		if(cntt==n) break;
	}
	for(int i=n+1;i<=n+k;i++)
		if(vis[i]==true) ans+=c[i-n];
	cout<<ans;
	return 0;
}
