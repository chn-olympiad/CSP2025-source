#include<bits/stdc++.h>
typedef long long ll;
const int N=1e4+50,M=1e6+50;

using namespace std;

int fa[N],sz[N];
int findx(int x){return (x==fa[x]?x:fa[x]=findx(fa[x]));}
void mergex(int u,int v)
{
	u=findx(u),v=findx(v);
	if(sz[u]>sz[v]) fa[v]=u,sz[u]+=sz[v];
	else sz[v]+=sz[u],fa[u]=v;
}

struct edge{int u,v;ll w;}ed[M*2],tmp[M*2];
int tot=0;
vector<edge> buc[1<<15];
void rsort(int num)
{
	int tot=0;
	for(int i=1;i<=num;++i) buc[tmp[i].w%(1<<15)].push_back(tmp[i]);
	for(int i=0;i<(1<<15);++i)
	{
		for(edge j:buc[i]) tmp[++tot]=j;
		buc[i].clear();
	}
	tot=0;
	for(int i=1;i<=num;++i) buc[tmp[i].w/(1<<15)].push_back(tmp[i]);
	for(int i=0;i<(1<<15);++i)
	{
		for(edge j:buc[i]) tmp[++tot]=j;
		buc[i].clear();
	}
}

ll krus(int n,int m)
{
	ll ret=0;
	for(int i=1;i<=m;++i) tmp[i]=ed[i];
	rsort(m);
	for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;++i)
	{
		int u=tmp[i].u,v=tmp[i].v;
		if(findx(u)==findx(v)) continue;
		mergex(u,v);ret+=tmp[i].w;
	}
	return ret;
}

void rd(int &x)
{
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int k,n;ll ans=1e18;
int c[15],a[15][N];
bool vis[1<<11];
void dfs(int st,ll sumc)
{
	int ntot=tot;
	for(int i=0;i<k;++i)
	{
		if((st>>i)&1) continue;
		int st1=st|(1<<i);
		if(vis[st1]) continue;
		vis[st1]=1;sumc+=c[i+1];
		for(int u=1;u<=n;++u)
			ed[++tot]={n+1+i,u,a[i+1][u]};
		ans=min(ans,krus(n+__builtin_popcount(st1),tot)+sumc);
		dfs(st1,sumc);
		sumc-=c[i+1];tot=ntot;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m;cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i)
	{
		rd(u),rd(v),rd(w);
		ed[++tot]={u,v,w};
	}
	bool tag=1;
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];tag&=(c[i]==0);
		for(int j=1;j<=n;++j) rd(a[i][j]);
	}
	if(tag)
	{
		for(int i=1;i<=k;++i)
			for(int j=1;j<=n;++j)
				ed[++tot]={j,n+i,a[i][j]};
		cout<<krus(n+k,tot);
	}
	else
	{
		ans=krus(n,tot);
		dfs(0,0);cout<<ans;
	}
	return 0;
}
