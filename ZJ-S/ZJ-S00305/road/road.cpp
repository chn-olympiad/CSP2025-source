#include <bits/stdc++.h>
using namespace std;
int n,m,k,N,u,v,w,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	N=n+k;
	int d[N+1][N+1];
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		d[u][v]=w;
		d[v][u]=w;
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>w;
		for(int j=1;j<=n;j++){
			d[i][j]=w;
			d[j][i]=w;
		}
	}
	for(int i=1;i<=N;i++)d[i][i]=0;
	for(int K=1;K<=N;K++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	cout<<d[1][n];
	return 0;
}
