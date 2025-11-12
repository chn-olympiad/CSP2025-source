#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,k,tot;
int mp[N][N];
int mpc[N][N];
int tt,u,v,w;
int head[N*20],to[N*20],ww[N*20],nxt[N*20];
void add(int x,int y,int z){
	to[++tot]=y;
	ww[tot]=z;
	head[x]=nxt[tot];
	nxt[tot]=x;
}
void solve();
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		solve();
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>tt;
		mpc[tt][0]=1;
		for(int j=1;j<=n;j++){
			cin>>w;
			mpc[tt][j]=w;
			mpc[j][tt]=w;
		}
	}
	return 0;
}
void solve(){
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>tt;
		mpc[tt][0]=1;
		for(int j=1;j<=n;j++){
			cin>>w;
			mpc[tt][j]=w;
			mpc[j][tt]=w;
		}
	}
}
/*
dp[i][x][y][z]=max(dp[i-1][x-1][y][z]+a[i].pos[2],max(dp[i-1][x][y-1][z]+a[i].y,dp[i-1][x][y][z-1]+a[i].z)); 

1
2
10 9 8
4 0 0

*/
