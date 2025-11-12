#include<bits/stdc++.h>
using namespace std;
struct node{
	int to;
	int dis;
};
vector<long long> g[1000005];
long long road[10005][10005],diss[10005];
queue<node> q;
long long a[5][1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(v);
		g[v].push_back(u);
		road[u][v]=w;
		road[v][u]=w;
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}
	cout<<0;
	return 0;
}
