#include<bits/stdc++.h>
using namespace std;
#define int long long
const int cd=1e4+5;
struct edge{
	int u,v,w;
	bool friend operator <(edge a,edge b){
		return a.w<b.w;
	}
};
vector<edge> vec[cd];
int n,m,k,dis[cd];
void bfs(){
	priority_queue<edge>q;
	q.push({0,1,(int)1e18});
	for(int i=1;i<=n;i++) dis[i]=1e18;
	while(q.size()){
		auto tmp=q.top();
		int pre=tmp.u;
		int u=tmp.v;
		int w=tmp.w;
		for(auto vv:vec[pre]){
			if(vv.v==u) continue;
			dis[vv.v]=min(w+vv.w,dis[vv.v]);
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			vec[i].push_back({j,a+c});
			vec[j].push_back({i,a+c});
		}
	}
	
	bfs();
	cout<<dis[n]<<"\n";
	return 0;
}
