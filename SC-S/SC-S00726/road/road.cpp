#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=1e4+5;
vector<array<int,3>>g[MAX];
bool vis[MAX];
int ans=0;
void dfs(int x){
	vis[x]=true;
	sort(g[x].begin(),g[x].end());
	int len=g[x].size(),i=0;
	while(vis[g[x][i][1]]){
		i++;
		if(i>len-1)return;
	}
	ans+=g[x][i][0];
	dfs(i);
	vis[x]=false;
}
int n,m,k;
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v,false});
		g[v].push_back({w,u,false});
	}
	for(int u=1;u<=k;u++){
		int t,w;
		cin>>t;
		for(int v=1;v<=n;v++){
			cin>>w;
			g[u].push_back({w,v,false});
			g[v].push_back({w,u,false});
		}
		ans+=t;
	}
	dfs(1);
	cout<<ans<<'\n';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}