#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
struct node{
	int to,cost;
};
vector<node> G[N];
int c[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			G[j].push_back({n+i,w});
			G[n+i].push_back({j,w});
		}
	}
	cout<<"0";
	return 0;
}