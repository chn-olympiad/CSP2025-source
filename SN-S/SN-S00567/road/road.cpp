#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=2e6+5,K=11;
struct no{int u,v,w;} e[M],E[M];
int n,m,k,c[K],a[K][N],f[N+K],p[K];
ll ans=1e18;
int fd(int x){return f[x]==x?x:f[x]=fd(f[x]);}
ll tr(){
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++) E[i]=e[i];
	ll re=0;
	sort(e+1,e+m+1,[&](no x,no y){return x.w<y.w;});
	for(int i=1,u,v;i<=m;i++){
		u=e[i].u,v=e[i].v;
		if(fd(u)==fd(v)) continue;
		re+=e[i].w;
		f[fd(u)]=fd(v);
	}
	for(int i=1;i<=m;i++) e[i]=E[i];
	return re;
}
void dfs(int i,ll su){
	if(i>k){
		ans=min(ans,su+tr());
		return;
	}
	dfs(i+1,su);
	for(int j=1;j<=n;j++) e[++m]={n+i,j,a[i][j]};
	dfs(i+1,su+c[i]);
	m-=n;
}
unsigned long long sd=1;
int rd(int x){
	sd^=sd<<11;
	sd^=sd>>13;
	sd^=sd<<41;
	sd^=sd>>43;
	return sd%x+1;
}
void sol(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	int fl=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]) fl=0;
		int ff=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(!a[i][j]) ff=1;
		}
		if(!ff) fl=0;
		p[i]=i;
	}
	if(fl){
		for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) e[++m]={n+i,j,a[i][j]};
		ans=tr();
	}
	else if(m<=100000){
		dfs(1,0);
	}
	else{
		for(int _=1;_<=10;_++){
			for(int i=1;i<=k;i++) swap(p[i],p[rd(i)]);
			ll pr=tr();
			for(int i=1;i<=k;i++){
				ll nw=c[p[i]];
				for(int j=1;j<=n;j++) e[++m]={n+p[i],j,a[p[i]][j]};
				nw+=tr();
				if(pr<=nw) pr=nw;
				else m-=n;
			}
			ans=min(ans,pr);
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ii();
//	int TT;for(scanf("%d",&TT);TT--;)
	sol();
	return 0;
}
