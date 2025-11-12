#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
vector<pair<int,int>>g[N];

int son[N],f[N],sz[N],tp[N],dep[N];
vector<int>lf;
void dfs1(int fa,int u){
	dep[u]=dep[fa]+1,f[u]=fa,sz[u]=1;
	for(auto t:g[u]){
		int v=t.first;
		if(v==fa)continue;
		dfs1(u,v);
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}
void dfs2(int top,int u){
	tp[u]=top;
	if(son[u])dfs2(top,son[u]);
	for(auto t:g[u]){
		int v=t.first;
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int dis[N][N],vis[N];
void dijk(int hd){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	memset(vis,0,sizeof vis);
	dis[hd][hd]=0;
	q.push({0,hd});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto t:g[u]){
			int v=t.first,w=t.second;
			if(dis[hd][v]>dis[hd][u]+w){
				dis[hd][v]=dis[hd][u]+w;
				q.push({dis[hd][v],v});
			}
		}
	}
}
int lca(int u,int v){
	while(tp[u]!=tp[v]){
		if(dep[tp[u]]<dep[tp[v]])swap(u,v);
		u=f[tp[u]];
	}
	if(dep[u]<dep[v])swap(u,v);
	return v;
}
void solve1(){
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs1(0,1);
	dfs2(1,1);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i)dijk(i);
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			ans=max(ans,dis[i][j]);
	cout<<ans;
}

struct node{
	int v;int w;int op;
};
vector<node>G[N];
int c[N],a[11][N];
int d[N][N],vi[N];
void spfa(int hd){//dijk2
	memset(vis,0,sizeof vis);
	memset(vi,0,sizeof vi);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	d[hd][hd]=0;
	q.push({0,hd});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto t:G[u]){
			int v=t.v,w=t.w,op=t.op;
			if(!op)if(d[hd][v]>d[hd][u]+w){
				d[hd][v]=d[hd][u]+w;
				q.push({d[hd][v],v});
			}
			if(op){
				for(int i=1;i<=k;++i){
					if(d[hd][v]>d[hd][u]+a[i][v]+c[i]){
						d[hd][v]=d[hd][u]+a[i][v]+c[i];
						q.push({d[hd][v],v});
					}
				}
			}
		}
	}
}
void solve2(){
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w,0});
		G[v].push_back({u,w,0});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		c[i]+=c[i-1];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			G[i].push_back({j,0,1});
			G[j].push_back({i,0,1});
		}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;++i){
		spfa(i);
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			ans=max(ans,d[i][j]);
		}
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	if(k==0)solve1();
	else solve2();
}
