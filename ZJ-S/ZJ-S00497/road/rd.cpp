#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,cw,w[16],cost[16],a[16][1005],p[1005][1005],g[1005][1005];
bool vis[1005];
int prim(int n){
	memset(vis,0,sizeof(vis));
	int ans=0;
	for(int t=1;t<=n;t++){
		int mi=1e18,bh=0;
		for(int i=1;i<=n;i++)
			if(p[t][i]<mi&&vis[i]==0){
				mi=p[t][i];
				bh=i;
			}
		if(bh) vis[t]=1,ans+=p[t][bh];
	}
	return ans;
}
int check(int S){
	memcpy(p,g,sizeof(p));
	int cw=0,sum=0;
	for(int i=1;i<=k;i++)
		if(S&(1ll<<(i-1))) w[++cw]=i;
	for(int i=1;i<=cw;i++)
		for(int j=1;j<=n;j++)
			p[i+n][j]=p[j][i+n]=min(p[i+n][j],a[w[i]][j]);
	for(int i=1;i<=cw;i++) sum+=cost[w[i]];
	return prim(n+cw)+sum;
}
signed main(){
	freopen("road2.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n>>m>>k;
	memset(g,63,sizeof(g));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
//	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	ans=1e18;
	for(int S=0;S<(1ll<<k);S++){
		ans=min(ans,check(S));
	}
	cout<<ans;
	return 0;
}
/*
O(2^k m log m)
*/