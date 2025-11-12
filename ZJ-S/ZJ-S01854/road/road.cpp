#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e4+5;
const int maxm=1e6+5;
int n,m,k;ll a[15][maxn],c[maxn];
struct EDGE{int u,v;ll w;}E[maxm<<1],ss[maxm<<1];
inline bool cmp(EDGE u,EDGE v){return u.w<v.w;}
int fa[maxn];
inline void init(int o){
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=n+k;++i) fa[i]=i;
}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool merge(int u,int v){
	u=find(u);v=find(v);
	if(u==v) return 0;
	fa[v]=u;return 1;
}
inline ll Kruskal(int o){
	init(o);ll ans=0;int tot=0;
	for(int i=1;i<=m;++i){
		int u=E[i].u,v=E[i].v;
		if(merge(u,v)){
			ans+=E[i].w;
			++tot;
		}
		if(tot==n+o-1) break;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cerr<<clock()<<' ';
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&E[i].u,&E[i].v,&E[i].w);
	}
	for(int i=1;i<=m;++i) ss[i]=E[i];
	bool A=1;
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		if(c[i]!=0) A=0;
		for(int j=1;j<=n;++j){
			scanf("%lld",&a[i][j]);
		}
	}
	if(A||k==0){
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				E[++m]=(EDGE){i+n,j,a[i][j]};
			}
		}
		printf("%lld\n",Kruskal(k));
		return 0;
	}
	ll res=1e18;
	for(int S=0;S<(1<<k);++S){
		int mm=m,oo=0;ll now=0;
		for(int i=1;i<=m;++i){E[i]=ss[i];}
		for(int i=1;i<=k;++i){
			if(S&(1<<(i-1))){
				for(int j=1;j<=n;++j){
					E[++m]=(EDGE){i+n,j,a[i][j]};
				}
				now+=c[i];++oo;
			}
		}
		res=min(res,now+Kruskal(oo));
		m=mm;
		if(double(clock()*1.0/CLOCKS_PER_SEC)>0.98) break;
	}
	printf("%lld\n",res);
//	cerr<<clock();
	return 0;
}
/*
I will AFO on 2025.11.29.
Goodbye,OI.
SuperCowHorse
*/