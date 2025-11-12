#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int n,m,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>c;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j] = min(a[i][k]+a[k][j],a[i][j]);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[1][i];
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
