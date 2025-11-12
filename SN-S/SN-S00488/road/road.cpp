#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
const int N=1e4+5;

int n;
int m, u[M],v[M],w[M],b[M][M];
int k, c[15],a[15][N];
int ans=0;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(u[i]<v[i]) b[u[i]][v[i]]=w[i];
		else b[v[i]][u[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			b[m+i][j]=a[i][j];
		}
	}
	cout << ans;
	
	return 0;
}
