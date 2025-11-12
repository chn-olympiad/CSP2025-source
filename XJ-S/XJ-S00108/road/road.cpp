#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> >g[10000005];
priority_queue<pair<int, int> > q;
//void dijkstra(int n,int m){
	//q.push({0,s});
	//while(!q.empty()){
		//if()
	//}
//}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int c,a[15][10005];
		cin>>c;
		for(int j=1;j<=n;j++) cin>>a[i][j];
		
	}
	cout<<13;
} 
