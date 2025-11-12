#include<bits/stdc++.h>
using namespace std;
int n,m,k,num,fa[20001];
long long ans;
struct pp{
	int u,v,w;
}a[2000001];
bool cmp(pp x,pp y){
	return x.w<y.w;
}
int find(int u){
	if(fa[u]==u) return u;
	fa[u]=find(fa[u]);
	return fa[u];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;i++){
		int x;scanf("%d",&x);
		for(int j=1;j<=n;j++){
			scanf("%d",&x);++m;
			a[m].u=n+i,a[m].v=j,a[m].w=x;
		}
	}
	n+=k;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		if(num==n-1) break;
		int u=a[i].u,v=a[i].v;
		fa[u]=find(fa[u]);fa[v]=find(fa[v]);
		if(fa[u]!=fa[v]){
			num+=1;
			ans+=a[i].w;
			fa[fa[u]]=fa[v];
		}
	}
	printf("%lld",ans);
	return 0;
}
