#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[10010];
int len[10010][10010];
int main(){
	freopen("road.in", "r",stdin);
	freopen("road.out", "w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		len[u][v]=w;
		len[v][u]=w;
	}
	for(int i=1;i<=n+1;i++){
		scanf("%d",&c[i]);
	}
	return 0;
} 
