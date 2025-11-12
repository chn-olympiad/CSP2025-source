#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define INF 100'000'000'000'000'000
using namespace std;
int n,m,k;
vector<pii> e[10015];
vector<pii> g[10015];
int ans=INF;
int c[15];
int a[15][10005];
priority_queue<pii> pq;
int tag=0;
int vis[10015],dis[10015];
int make(int sta){
	int res=0;
	for(int i=1;i<=n;i++)
		g[i].clear();
	for(int i=1;i<=k;i++){
		if((sta&(1ll<<i-1))==0) continue;
		res+=c[i];
		for(int j=1;j<=n;j++){
			g[j].push_back({i+n,a[i][j]});
			g[i+n].push_back({j,a[i][j]});
		}
	}
	return res;
}
int prim(int sta){
	int res=0;
	for(int i=1;i<=n+k;i++)
		dis[i]=INF;
	pq.push({0,1});
	dis[1]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]==tag) continue;
		vis[u]=tag;
		res+=dis[u];
		for(auto i:e[u]){
			int v=i.first,w=i.second;
			if(w<dis[v]){
				dis[v]=w;
				if(vis[v]!=tag) pq.push({-dis[v],v});
			}
		}
		for(auto i:g[u]){
			int v=i.first,w=i.second;
			if(w<dis[v]){
				dis[v]=w;
				if(vis[v]!=tag) pq.push({-dis[v],v});
			}
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int sta=0;sta<(1ll<<k);sta++){
		int t=make(sta);
		tag++;
		ans=min(ans,t+prim(sta));
	}
	cout<<ans;
	return 0;
}
