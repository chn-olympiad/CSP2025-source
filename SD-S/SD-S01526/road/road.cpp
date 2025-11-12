#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
struct Noderode{
	int u;
	int v;
	int w;
}rode[10011];
struct Nodetown{
	int c;
	int a[10011];
}town[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	/*
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&rode[i].u,&rode[i].v,&rode[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&town[i].c);
		for(int j=1;j<=m;j++){
			scanf("%d",&town[i].a[j]);
		}
	}
	*/
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
