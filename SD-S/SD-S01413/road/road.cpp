#include <bits/stdc++.h>
#define int long long
using namespace std;
int ppct(int xxx,int wei){
	return (xxx>>(wei-1))%2;
}
int dis[1020][1020];bool vis[1020];
struct ayu{
	int v,w;
};vector<ayu>x[1020];
int y[12][1020];
void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	dis[s][s]=0;memset(vis,0,sizeof(vis));
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<x[u].size();i++){
			int v=x[u][i].v,w=x[u][i].w;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push(make_pair(dis[s][v],v));
			}
		}
	}
	return;
}
int dp[1020][2049];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		x[u].push_back((ayu){v,w});
		x[v].push_back((ayu){u,w});
	}
	memset(dis,120,sizeof(dis));
	memset(dp,120,sizeof(dp));
	for(int i=1;i<=n;i++){
		dij(i);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>y[i][j];
		}
	}
	dp[1][0]=dp[1][2048]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<k);j++){
			for(int l=1;l<i;l++){
				dp[i][j]=min(dp[i][j],dp[i-1][j]+dis[l][i]);
				for(int g=0;g<k;g++){
					if((1<<g)|j){
						int z=j^(1<<g);
						dp[i][j]=min(dp[i][j],dp[i-1][z]+y[g+1][0]+y[g+1][l]+y[g+1][i]);
						dp[i][j]=min(dp[i][j],dp[i-1][j]+y[g+1][i]);
					}
				}
			}
		}
	}
	int ans=1e15;
	for(int i=0;i<(1<<k);i++){
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<"\n";
	return 0;
}//-g3 -Wl,--stack=268435456 
