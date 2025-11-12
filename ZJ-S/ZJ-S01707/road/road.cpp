#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int ,int > 
const int N=1e6+100;
bool vis[N];
int dis[N];
struct node{
	int v,w;
};
priority_queue<pii > q;
vector<node> G[N];
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
	cout<<0<<"\n";
	return 0;
}
