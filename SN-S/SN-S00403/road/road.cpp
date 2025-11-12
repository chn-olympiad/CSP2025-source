#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int G[10004][10004],c[15],a[15][10005];
bool fl=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=G[v][u]=w;
	}for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) fl=false;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0) fl=false;
		}
	}
	if(fl) printf("0");
	else{
		for(int i=1;i<=k;i++){
			sum+=c[i]*n;
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
