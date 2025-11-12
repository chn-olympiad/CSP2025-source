#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PQ priority_queue
const int N=1e6+5;
int c[15],a[15][1005],ans=1e9+7,vis[N];
int n,m,k;
struct node{
	int v,w;
};
vector<node>G[N];
void dfs(int rt,int fa,int sum,int deep){
	if(vis[rt])return;
	vis[rt]=1;
	if(deep==m){
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<G[rt].size();i++){
		int to=G[rt][i].v,val=G[rt][i].w;
		if(to==fa)continue;
		dfs(to,rt,sum+val,deep+1);
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(i,0,0,1);
	}
	cout<<ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

