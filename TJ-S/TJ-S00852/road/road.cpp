#include<bits/stdc++.h>
using namespace std;
int g[10015][10015];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	long long ans=0;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
		ans+=w;
	}
	int ne=n;
	for(int i=1;i<=k;i++){
		
		cin>>w;
		
		for(int j=1;j<=n;j++){
			cin>>w;
			
		}
	}
	cout<<ans;
	return 0;
}


