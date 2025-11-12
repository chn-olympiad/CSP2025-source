#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn=1e4+5;
const int maxm=1e6+15;
int n,m,k,blm;
long long ans;
int c[12];
vector<pii> g[maxm];

void dfs(int u,int fa){
	blm++;
	if(blm>100000000) return;
	int cm=maxm;
	for(auto edge:g[u]){
		int v=edge.first,w=edge.second;
		if(v==fa) continue;
		dfs(v,u);
		cm=min(cm,w);
	}
	ans+=cm; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
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
			int a;cin>>a;
			g[m+j].push_back({j,a});
			g[j].push_back({m+j,a});
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 