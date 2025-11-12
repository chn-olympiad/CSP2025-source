#include<bits/stdc++.h>
#define ll long long
const int N=2e6+5;
int n,m,k;
int fa[20005];
struct node{
	int from,to;
	ll len;
}a[N];
bool cmp(node x,node y){
	return x.len<y.len;
}
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k+1;++i) fa[i]=i;
	if(k==0){
		ll ans=0;
		for(int i=1;i<=m;++i){
			int u,v;
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			a[i].from=u,a[i].to=v,a[i].len=w;
		}
		std::sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;++i){
			int x=a[i].from,y=a[i].to;
			ll s=a[i].len;
			int fx=get(x),fy=get(y);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=s;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=m;++i) scanf("%d%d%lld",&a[i].from,&a[i].to,&a[i].len);
	ll ans=0;
	int tot=m,u=n;
	for(int i=1;i<=k;++i){
		int c;
		scanf("%d",&c);
		++u;
		for(int j=1;j<=n;++j){
			ll w;
			scanf("%lld",&w);
			if(w==0){
				++tot;
				a[tot].from=u,a[tot].to=j,a[tot].len=0;
			}
		}
	}
	std::sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;++i){
		int x=get(a[tot].from),y=get(a[tot].to);
		ll w=a[tot].len;
		if(x!=y){
			fa[x]=y;
			ans+=w;
			printf("%lld\n",ans);
		}
	}
	printf("%lld",ans);
	return 0;
}