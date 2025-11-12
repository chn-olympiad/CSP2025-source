#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,fa[10010],c[15],a[15][10010];
struct node{int u,v,w;}e[1000010];
int f(int x){
	return x==fa[x]?x:f(fa[x]);
}
void kruskal(){
	int cnt=0;
	for(int i=1;i<=m;i++){
		int fu=f(e[i].u),fv=f(e[i].v);
		if(fu!=fv){
			cnt++;
			ans+=e[i].w;
			fa[fu]=fa[fv];
		}
		if(cnt==n-1)return;
	}
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),e[i]={u,v,w};
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+1+m,cmp);
	kruskal();
	printf("%d",ans);
	return 0;
}
