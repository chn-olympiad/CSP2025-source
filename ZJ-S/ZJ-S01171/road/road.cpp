#include<bits/stdc++.h>
using namespace std;
vector<int> g[100010];
int a[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++){
		int v,u,h;
		cin>>v>>u>>h;
		g[v].push_back(u);
		g[u].push_back(v);
		g[v][u]=h;
		g[u][v]=h;
		ans+=h;
	}
	cout<<ans;
	return 0;
}
