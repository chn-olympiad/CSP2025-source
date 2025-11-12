#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int dis[10000][10000],vis[10000][10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(dis,100000000,sizeof(dis));
	if(k==0){
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			cin>>dis[x][y];
			dis[y][x]=dis[x][y];
		}
		
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		cin>>dis[x][y];
		dis[y][x]=dis[x][y];
	}
	for(int i=n+1;i<=n+k;i++){
		int v;
		cin>>v;
		for(int j=1;j<=n;j++){
			cin>>dis[i][j];
			dis[i][j]+=v;
			dis[j][i]=dis[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	cout<<dis[1][n];
	return 0;
}