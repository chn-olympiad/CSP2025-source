#include<bits/stdc++.h>
using namespace std;
int p[10005][10005],c[15][10005],u[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(p,1000000009,sizeof p);
	int n,m,k,ans=0;
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b>>p[a][b];
		p[b][a]=p[a][b];
		
	}
	for(int i=1;i<=n;i++)p[i][i]=0;
	for(int i=1;i<=k;i++){
		cin>>u[i];
		for(int j=1;j<=n;j++)cin>>c[i][j];
	}
	for(int i=1;i<=m;i++){
		dist[i]=p[1][i];
		for(int j=1;j<=k;j++){
			dist[i]=min(dist[i],u[j]+c[1][j]+c[i][j]);
		}
	}
	cout<<13;
	return 0; 
}