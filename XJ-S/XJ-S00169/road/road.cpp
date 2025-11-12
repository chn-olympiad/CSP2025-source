#include <bits/stdc++.h>
using namespace std;
long long vis[ml],dis[ml];
struct node{
	long long to,w;
};
vector<node> G[ml];
long long n,m,k;
void dji(int x){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[x] = 0;
	set< pair<int,int> > st;
	st.insert(make_pair(dis[x],x));
	while(!st.empty()){
		pair<int,int> now = *st.begin();
		st.erase(st.begin());
		int u = now.second;
		if(vis[u] == 1) continue;
		vis[u] = 1;
		for(int i=0;i<G[u].size();i++){
			node it = G[u][i];
			int v = it.to;
			int w = it.w;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				st.insert(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int wk;
		cin >> wk;
		for(int j=1;j<=n;j++){
			int cost;
			cin >> cost;
			G[n+i].push_back({j,cost});
			G[j].push_back({n+i,cost + wk});
		}
	}
	dji(1);
	cout << dis[n]; 
	return 0;
}
