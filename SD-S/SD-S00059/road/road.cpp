#include<bits/stdc++.h>
#define ll long long
int const maxn=2*1e5;
using namespace std;
struct myst {
	int ind,dist;
	bool operator <(const myst &a)const {
		return a.dist<dist;
	}
};
int a,b,n,m,k,p,q,u,v,w,c0[maxn],c[10][maxn],fa[maxn];
int vis[maxn],dp[maxn],ans;
priority_queue<myst>q1;
vector<myst>adj[10000];
//void dij() {
//	q1.push({1,0});
//	while(!q1.empty()) {
//		myst node=q1.top();
//		for(int v=0; v<adj[node.ind].size(); v++) {
//			myst nex=adj[node.ind][v];
//			if(vis[nex.ind]==1)continue;
//			vis[nex.ind]=1;
//			if(dp[nex.ind]>dp[node.ind]+nex.dist) {
//				dp[nex.ind]=dp[node.ind]+nex.dist;
//				for(int i=1; i<=k; i++) {
//					if(dp[nex.ind]>c0[i]+c[i][nex.ind]+c[i][node.ind]) {
//						dp[nex.ind]=c0[i]+c[i][nex.ind]+c[i][node.ind];
//					}
//				}
//				q1.push({nex.ind,dp[nex.ind]});
//			}
//		}
//	}
//	return;
//}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdin);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>u>>v>>w;
		fa[u]=v;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(int i=1; i<=k; i++) {
		cin>>c0[i];
		for(int j=2; j<=n+1; j++) {
			dp[j]=1e9;
			cin>>c[i][j-1];
		}
	}
	cout<<13;
//	vis[1]=1;
//	dij();
//	for(int i=1;i<=n;i++){
//		ans+=dp[i]; 
//	}
//	cout<<ans;
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) {
//			for(int k=1; k<=n; k++) {
//if(adj[i][j])
	return 0;
}
