#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e4 + 10,M = 2e6 + 10;
const ll Inf = 1e17;

int n,m,k,a[N][11],c[11];
struct edge{int u,v,w;}e[M];
bool cmp(edge x,edge y){return x.w<y.w;}
vector<edge>use;
int fa[N],siz[N];
int find(int u){return (fa[u]==u?u:fa[u]=find(fa[u]));}
void join(int u,int v)
{
	u=find(u);v=find(v);
	if(u==v) return ;
	if(siz[u]>siz[v]) fa[v]=u,siz[u]+=siz[v];
	else fa[u]=v,siz[v]+=siz[u];
}
void init()
{
	for(int i=1;i<=n+k;i++)
		siz[i]=1,fa[i]=i;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=1,x;j<=n;j++)
		{
			cin>>x;
			e[++m]={n+1+i,j,x};
		}
	}
	sort(e+1,e+m+1,cmp);
	init();
	for(int i=1;i<=m;i++)
	{
		if(e[i].u>n) use.push_back(e[i]);
		else
		{
			int u=find(e[i].u),v=find(e[i].v);
			if(u==v) continue;
			else 
			{
				join(u,v);
				use.push_back(e[i]);
			}
		}
	}
	ll ans=Inf;
	for(int S=0;S<(1<<k);S++)
	{
		init();
		ll sum=0;
		for(int i=0;i<k;i++)
			if((S>>i)&1) sum+=c[i];
 		for(int i=0;i<use.size();i++)
		{
			if(sum>ans) break;
			if(e[i].u>n&&(!((S>>(e[i].u-n-1))&1))) continue;
			int u=find(e[i].u),v=find(e[i].v);
			if(u==v) continue;
			else join(u,v),sum+=e[i].w;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
