#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=1e4+5,M=1e6+5,K=15;
constexpr ll inf=1e18;
int n,m,k;
//struct node{int to;ll w;};
struct Edge{int u,v; ll w;} E[M],e[N];
ll c[K];
ll a[K][N];
ll cnt=0;
struct DSU
{
	int fa[N];
	DSU() {for(int i=1;i<=n;i++) fa[i]=i;}
	int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
	void Merge(int x,int y,ll w)
	{
		int fx=find(x),fy=find(y);
		if(fx!=fy)
			fa[fx]=fy,/*e[x].push_back({y,w}),e[y].push_back({x,w}) e[++cnt]={x,y,w}*/cnt+=w;
	}
};
inline void Kruskal()
{
	sort(E+1,E+1+m,[](const Edge &x,const Edge &y){return x.w<y.w;});
	DSU dsu=DSU();
	for(int i=1;i<=m;i++)
		dsu.Merge(E[i].u,E[i].v,E[i].w);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>E[i].u>>E[i].v>>E[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	Kruskal();
	if(k==0)
		cout<<cnt<<'\n';
	return 0;
}
