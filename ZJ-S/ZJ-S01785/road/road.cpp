#include <bits/stdc++.h>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e6+15;
int n,m,k;
pii x;
vector < pii > g [ N ] ;
int dis[N];
bool vis[N];
void dij(int s){
	priority_queue < pii , vector < pii > , greater < pii > > q;
	memset(dis,INF,sizeof(dis));
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		int u=q.top().first;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
   		for( auto x : g [ u ] ){
			int v=x.first;
			int w=x.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w,c;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
 		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>w;
			g[i+n].push_back({j,w+c});
			g[j].push_back({i+n,w+c});
		}
	}dij(1);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dis[i]);
	}cout<<ans;
	return 0;
}
