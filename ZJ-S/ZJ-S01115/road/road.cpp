#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,m,k,ans=1e18;
int dis[N][N];
int c[N];
bool vis[N];
struct node{
	int v,w;
	bool friend operator <(node x,node y){
		return x.w<y.w;
	}
};
vector<node>g[N];
void dfs(int u,int fa,int len,int tot){
	if(u>n)len+=c[u];
	else{
		tot++;
	}
	if(tot==n){
		ans=min(ans,len);
		return;
	}
	if(len>=ans)return;
	for(auto t:g[u]){
		int v=t.v,w=t.w;
		if(v==fa)continue;
		if(v<=n&&vis[v])continue;
		vis[v]=true;
		dfs(v,u,len+w,tot);
		vis[v]=false;
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[n+i];
		for(int j=1;j<=n;j++){
			cin>>dis[i][j];
			g[i+n].push_back({j,dis[i][j]});
			g[j].push_back({i+n,dis[i][j]});
		}
	}
	dfs(1,-1,0,0);
	cout<<ans<<'\n';
	return 0;
}
