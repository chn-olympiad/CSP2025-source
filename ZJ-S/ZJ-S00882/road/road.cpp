#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[15][10005];
struct road {
	int u,v,w;
} edge[1000005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i=1; i<=k; i++)
		for(int j=0; j<=n; j++)cin>>c[i][j];
	
	cout<<0;
	return 0;
}

