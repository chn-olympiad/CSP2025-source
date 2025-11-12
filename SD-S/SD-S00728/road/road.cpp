#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+20,M=1e6+5,K=15;

int n,m,k;
int a[K][N],c[K];
int u[M],v[M],w[M],chs[M];
struct edge{int u,v,w,col;};
vector<edge> mst,nst;
int fa[N+K];
ll ans=1e18;

int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
void init() {for(int i=1;i<=n+k;i++) fa[i]=i;}
bool cmp(edge a,edge b){return a.w<b.w;}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		mst.push_back({u[i],v[i],w[i],i});
	}
	init();
	sort(mst.begin(),mst.end(),cmp);
	for(auto tmp:mst)
	{
		int u=tmp.u,v=tmp.v,w=tmp.w,id=tmp.col;
		if(find(u)==find(v)) continue;
		nst.push_back({u,v,w,0});
		fa[fa[u]]=fa[v];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j],nst.push_back({i+n,j,a[i][j],i});
	}
	sort(nst.begin(),nst.end(),cmp);
	for(int i=0;i<(1<<k);i++)
	{
		ll now=0;
		init();
		for(int j=1;j<=k;j++)
			if((i>>(j-1))&1) now+=c[j];
		for(auto tmp:nst)
		{
			int u=tmp.u,v=tmp.v,w=tmp.w,id=tmp.col;
			if(find(u)==find(v)) continue;
			if(id!=0&&(!((i>>(id-1))&1))) continue;
			now+=w;
			fa[fa[u]]=fa[v];
		}
		ans=min(ans,now);
	}
	cout<<ans;
	return 0;
}

