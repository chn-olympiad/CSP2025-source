#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,fa[N],cnt,c[15];
ll ans=1e18+10,a[15][N];
struct node {
	int u,v;
	ll w;
	bool operator <(const node &a)const {
		return w<a.w;
	}
} edg[M<<1],fpx[M<<1];
int get(int u) {
	return u==fa[u]?u:fa[u]=get(fa[u]);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; ++i) {
		scanf("%d%d%lld",&edg[i].u,&edg[i].v,&edg[i].w);
	}
	sort(edg+1,edg+m+1);
	for(int i=1; i<=n; ++i) {
		fa[i]=i;
	}
	for(int i=1; i<=m; ++i) {
		int u=edg[i].u,v=edg[i].v;
		int fu=get(u),fv=get(v);
		if(fu!=fv) {
			fa[fu]=fv;
			edg[++cnt]=edg[i];
		}
	}
	for(int i=1; i<=k; ++i) {
		scanf("%d",&c[i]);
		for(int j=1; j<=n; ++j)scanf("%lld",&a[i][j]);
	}
	for(int i=0; i<(1<<k); ++i) {
		ll res=0;
		int op=cnt;
		for(int j=1; j<=op; ++j)fpx[j]=edg[j];
		for(int j=1; j<=k; ++j) {
			if(i&(1<<(j-1))) {
				res+=c[j];
				for(int w=1; w<=n; ++w) {
					fpx[++op]=(node) {
						w,n+j,a[j][w]
					};
				}
			}
		}
		for(int j=1; j<=n+k; ++j)fa[j]=j;
		sort(fpx+1,fpx+op+1);
		for(int j=1; j<=op; ++j) {
			int u=fpx[j].u,v=fpx[j].v;
			ll w=fpx[j].w;
			int fu=get(u),fv=get(v);
			if(fu!=fv) {
				fa[fu]=fv;
				res+=w;
			}
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
}
/*听见你说，外站看tes，路边一坨，被咒活抽陀螺，我已习惯，你突然间被零封，外战满败，lpl变小丑，沟槽小奶油，是个人都踩你头，没成绩有脾气，不是肯就是送，哥哥紧紧地将他余生绑在tes，年年换队友，就成了不粘锅，把净化用来解了击飞，结晶也是某些粉丝最纯粹，钞票装满兜，接q又送头，尽了力的69，绝望被人开抽*/
