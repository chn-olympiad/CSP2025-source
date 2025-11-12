#include<bits/stdc++.h>
#define fi first
#define se second 
#define endl "\n"
#define int long long 
using namespace std;
const int maxn=1e4+10;
int n,m,k;
int dis[maxn][maxn];
int xz[12][maxn];
void floyd(){
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			for(int h=1;h<=n+k;h++){
				if(dis[i][h]!=INT_MAX && dis[h][j]!=INT_MAX){
					dis[i][j]=min(dis[i][j],dis[i][h]+dis[h][j]);
				}
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			dis[i][j]=INT_MAX;
			dis[i][i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	for(int i=1;i<=k;i++){
		cin>>xz[i][0];
		for(int j=1;j<=n;j++){
			cin>>xz[i][j];
			dis[n+i][j]=min(dis[n+i][j],xz[i][j]);
			dis[j][n+i]=min(dis[j][n+i],xz[i][j]);
		}
	}
	floyd();
	int sum=dis[1][n];
//	for(int i=1;i<=k;i++){
//		bool f=false;
//		for(int j=1;j<=n;j++){
//			if(dis[n+i][j]!=INT_MAX){
//				f=true;
//			}
//		}
//		if(f==true){
//			cout<<sum<<" ";
//			sum+=xz[i][0];
//		}
//	}
	cout<<sum;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/