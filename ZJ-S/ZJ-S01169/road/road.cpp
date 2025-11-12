#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,a[N][N],u,v,w,c,dis[N][N];
void prim(int x,int y){
	dis[x][y]=0;
	vis=1;
	
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n+k; i++)
		for(int j=1; j<=n+k; j++)
			dis[i][j]=a[i][j]=1e9+1;
	for(int i=0; i<m; i++) {
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	for(int i=0; i<k; i++) {
		cin>>c;
		for(int j=1; j<=n; j++) {
			cin>>w;
			a[n+k][j]=a[j][n+k]=w;
		}
	}
	prim(1,1);
	return 0;
}
