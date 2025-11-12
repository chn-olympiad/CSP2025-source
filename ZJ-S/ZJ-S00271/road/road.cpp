#include<bits/stdc++.h>
#define ci const int
#define ri register int
using namespace std;
ci N=1e4+5,M=2e6+5;
int n,m,k;
int u[M],v[M],w[M],id[M],fa[N];
int al[N],c[N],st;
bool cmp(ci &a,ci &b){
	return w[a]<w[b];
}
long long ans;
int getfa(ci &u){
	return fa[u]==u ? u : (fa[u]=getfa(fa[u]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(ri i=1;i<=m;++i){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		id[i]=i;
	}
	for(ri i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(ri j=1;j<=n;++j){
			scanf("%d",&al[j]);
			if(al[j]==0) st=j;
		}
		if(c[i]) continue;
		for(ri j=1;j<=n;++j){
			if(j==st) continue;
			id[++m]=m;
			u[m]=st;
			v[m]=j;
			w[m]=al[j];
		}
	}
	sort(id+1,id+m+1,cmp);
	for(ri i=1;i<=n;++i) fa[i]=i;
	for(ri i=1;i<=m;++i){
		int x=u[id[i]],y=v[id[i]],z=w[id[i]];
		x=getfa(x);y=getfa(y);
		if(y==x) continue;
		ans+=z;
		fa[x]=y;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}