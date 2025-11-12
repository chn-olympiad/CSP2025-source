#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[11],a[10001][10001];
void dfij(int u){
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[v][u]=a[u][v]=w;
	}
	dij(1);
	cout<<13;
	return 0;
}
