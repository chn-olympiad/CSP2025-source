#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int n,m,k,e[N][N],u,v,w,a[15][N],c[N],vis[N],dis[N][3],f=1,ans;
void dfs(int x,int dian){
	if(dian==n) return ;
	int r1=2e6,r2,r3;
	for(int i=1;i<=n;i++){
		if(e[x][i]<=1e6&&vis[i]==0){
			if(dis[f][0]>e[x][i]){
				dis[f][0]=e[x][i];
				dis[f][1]=i;
				dis[f][2]=x;
			}
		}
	}
	for(int i=1;i<=f;i++){
		if(dis[i][0]<r1){
			r1=dis[i][0];
			r2=i;
		}
	}
	ans+=r1;
	r3=dis[r2][2];
	vis[dis[r2][1]]=1;
	dis[r2][0]=2e6;
	f++;
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&e[r3][i]<=1e6){
			if(dis[r2][0]>e[r3][i]){
				dis[r2][0]=e[r3][i];
				dis[r2][1]=i;
			}
		}
	}
	dfs(dis[r2][1],dian+1);
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=2e6;
		}
		dis[i][0]=2e6;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u][v]=min(e[u][v],w);
		e[v][u]=min(e[v][u],w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	vis[1]=1;
	dfs(1,1);
	cout<<ans;
	return 0;
}
