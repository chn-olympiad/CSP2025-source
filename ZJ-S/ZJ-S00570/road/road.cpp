#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int INF=1e9;
int main(){
	int n,m,k;cin>>n>>m>>k;
	vector<vector<int>>a(n+1,vector<int>(n+1,INF));
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	
	for(int i=1;i<=k;i++){
		vector<int>c(k+1);
		cin>>c[0];
		for(int j=1;j<=n;j++){
			cin>>c[1];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				a[j][k]=min(a[j][k],c[j]+c[k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[j][k]>a[j][i]+a[i][k]){
					a[j][k]
				}
			}
		}
	}
}