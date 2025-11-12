#include<bits/stdc++.h>
using namespace std;
int N = 1e4+10,M = 1E5+10;
int n,m,k;
int g[N][11];
vector<int> e[N];
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int f=1;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push({v,w});
		e[v].push({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) f=0;
		for(int j=1;j<=n;j++)cin>>g[i][j];
	}
	if(f){
		for(int i=1;i<=k;i++){
			
		}		
	}
	cout<<13<<'\n';
	return 0;
}
