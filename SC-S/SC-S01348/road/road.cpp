#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+5,K=13;
int n,m,k;
struct Edge{
	int u,v,w;
};
vector<Edge> edge,save;
int val[K][N];
vector<Edge> add[K];
int fa[N],siz[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void init(){
	for (int i=1;i<=n+k;i++)
		fa[i]=i,siz[i]=1;
}
void merge(int u,int v){
	if (siz[u]<siz[v]) swap(u,v);
	fa[u]=v;
	siz[v]+=siz[u];
}
ll res=0;
bitset<(1<<K)> vis;
void dfs(int lst,int ste,const vector<Edge> &edge){
	if (vis[ste]) return;
	vis[ste]=1;
	ll sum=0;
	for (int i=1;i<=k;i++)
		if ((ste>>(i-1))&1)
			sum+=val[i][0];
	init();
	vector<Edge> now;
	size_t i=0;
	size_t j=0;
	while (i<edge.size() && j<add[lst].size())
		if (edge[i].w<add[lst][j].w)
			now.push_back(edge[i++]);
		else now.push_back(add[lst][j++]);
	while (i<edge.size()) now.push_back(edge[i++]);
	while (j<add[lst].size()) now.push_back(add[lst][j++]);
	vector<Edge> save;
	for (const Edge &e:now){
		int u=find(e.u),v=find(e.v);
		if (u==v) continue;
		merge(u,v);
		sum+=e.w;
		save.push_back(e);
	}
	res=min(res,sum);
	for (int i=1;i<=k;i++)
		if (!((ste>>(i-1))&1))
			dfs(i,ste|(1<<(i-1)),save);
}
signed main(){
#ifndef DEBUG
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#endif
//	freopen("road\\road3.in","r",stdin);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for (int u,v,w;m--;){
		cin>>u>>v>>w;
		edge.push_back({u,v,w});
	}
	for (int i=1;i<=k;i++)
		for (int j=0;j<=n;j++)
			cin>>val[i][j];
	for (int i=1;i<=k;i++)
		for (int j=1;j<=n;j++)
			add[i].push_back({n+i,j,val[i][j]});
	for (int i=1;i<=k;i++){
		sort(add[i].begin(),add[i].end(),[&](const Edge &a,const Edge &b){
			return a.w<b.w;
		});
	}
	init();
	sort(edge.begin(),edge.end(),[&](const Edge &a,const Edge &b){
		return a.w<b.w;
	});
	for (const Edge &e:edge){
		int u=find(e.u),v=find(e.v);
		if (u==v) continue;
		merge(u,v);
		save.push_back(e);
		res+=e.w;
	}
	for (int i=1;i<=k;i++)
		dfs(i,1<<(i-1),save);
	cout<<res<<"\n";
}
/*
补药卡我的常啊

那种事情补药啊
*/