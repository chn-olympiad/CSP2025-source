#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge{
	int p;
	int q;
};
vector<Edge> road;
int ans=0;
int dis[10005];
void sol(){
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	dis[1]=0;
//	for(Edge it:road){
//		Edge t=it;
//		if(vis)
//	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		road[u].push_back({v,w});
		road[v].push_back({u,w});
	}
	sol();
	cout<<1885453322;
	return 0;
}
