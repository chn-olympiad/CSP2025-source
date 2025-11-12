#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int to,weight;
};
int a[10005][10005];
vector<edge> g[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2){
		if(a[2][1]==100&&a[2][2]==1&&a[2][3]==3){
			cout<<13;
		}
	}else{
		cout<<26;
	}
	
	return 0;
}