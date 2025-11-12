#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,ans,k;
struct edge{
	int v,w;
};
vector<edge> g[N];
int b[N];
void bfs(){
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;++i){
			int u,v,w;
			cin>>u>>v>>w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
			ans+=w;
		}
	}
	bfs();
	cout<<ans;
	return 0;
}
