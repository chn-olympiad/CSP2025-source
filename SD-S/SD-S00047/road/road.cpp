#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int f[n+4][n+4]={},w[n+4],c[k+4][n+4];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=10000000000;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cin>>f[u][v];
		f[u][v]=f[v][u];
	}
	for(int i=1;i<=k;i++){
		int cl;
		cin>>cl;
		for(int j=1;j<=n;j++)cin>>c[cl][j];
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j>=i;j++){
			f[i][j]=min(f[i][j],f[i][j-1]+f[j-1][j]);
		}
	}
	cout<<f[1][n];
	return 0;
}

