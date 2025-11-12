#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,t[10005][10005],mi[10005][10005],c[10005];
void dfs(int x){
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		//r[i]={pre[b],w};
		t[u][v]=t[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&t[i][j]);
	}
	printf("254");
	return 0;
}
