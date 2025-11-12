#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n,m,k;
int c[100005],a[15][10005],ans=1e9;
vector<pair<int,int> > p[1000005];
bool vis[10005];
void dfs(int now,int res,int cnt){
//	cout<<now<<' '<<res<<'\n';
	if(cnt==n){
		ans=min(ans,res);
		return ;
	}
	for(auto nxt:p[now]){
		if(vis[nxt.first]) continue;
		vis[nxt.first]=1;
		dfs(nxt.first,res+nxt.second,cnt+1);
		dfs(now,res+nxt.second,cnt+1);
		vis[nxt.first]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		p[u].push_back({v,w});p[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][k];
	}
	vis[1]=1;
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
