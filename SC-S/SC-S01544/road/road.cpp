#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,fa[1000010],c[15],d[15][1000010];
struct aaa{
	int u,v,w;
}a[4000010];
bool cmp(aaa x,aaa b){
	return x.w<b.w;
}
int find_root(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find_root(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&d[i][j]);
	}
	for(int i=1;i<=m;i++){
		int bx=find_root(a[i].u);
		int by=find_root(a[i].v);
		if(bx!=by){
			ans+=a[i].w;
			fa[bx]=by;
		}
	}
	printf("%lld",ans);
	return 0;
}