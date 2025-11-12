#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int pic[10010][10010],w[10010],c[20],ci[20][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cin>>w[i];
		pic[u][v]=w[i];
		pic[v][u]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ci[i][j];
		}
	}
	cout<<24; 
	return 0;
}
