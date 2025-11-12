#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[20];
struct node{
	int to,w;
};
vector<node>g[1000020];
int main(){
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
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			g[n+i].push_back({j,w});
			g[j].push_back({n+i,w});
		}
	}
	return 0;
}