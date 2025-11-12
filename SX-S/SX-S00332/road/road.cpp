#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int f[10005][10005],a[10005][10005],u,v,w;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int kk=1;kk<=n;kk++){
				f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
