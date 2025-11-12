#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e4+5;
int mapp[N][N];
int u,v,w;
int n,m,k;
bool vis[N];
int a[13][N];

int dfs(int from,int to,int sum){
	bool f=true;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			f=false;
		}
	}
	if(f==true) return sum;
	for(int i=1;i<=n;i++){
		if(vis[i]==true){
			dfs(to,i,sum+mapp[to][i]);
		}
	}
}

signed main(){

	ios::sync_with_stdio(0),cin.tie(0);

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);


	memset(vis,false,sizeof vis);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mapp[u][v]=mapp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		int mn=1e9;
		for(int i=1;i<=n;i++){
			mn=min(mn,dfs(1,i,0));
		}
	}


	return 0;
}
