#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
struct A{
	int to,cost;
};
vector<A>G[10005];
int n,m,k,c;
priority_queue<P> q;
long long dp[10005][10005];
void dij(){
	q.push_back(1,1);
	dp[1][1]=0;
	for(int i=1;i<=n;i++){
		dp[i][1]=0;
	}
	while(!q.empty()){
		P now=q.top();
		q.pop();
		int siz=(int)G[now].size();
		for(int i=0;i<siz;i++){
			int v=G[now][i];
			if(dp[v][now.second+1]==0)dp[v][now.second+1]=dp[now.first][now.second]+v.cost;
			else{
				if(dp[v][now.second+1]>dp[now.first][now.second]+v.cost){
					dp[v][now.second+1]=dp[now.first][now.second]+v.cost;
					q.push(v,now.second+1);
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	dij();
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[i][n]);
	}
	cout<<ans;
	
	
}
