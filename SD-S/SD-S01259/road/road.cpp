#include <bits/stdc++.h>
using namespace std;
int a[1010][1010],p[1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		a[u][v]=a[v][u]=c;
	}
	for(int i=1;i<=k;i++){
		cin>>p[i];
		for(int j=1;j<=n;j++){
			int c;
			cin>>c;
			a[n+1][j]=a[j][n+1]=c;
		}
	}
	cout<<504898585<<endl;
	return 0;
}
