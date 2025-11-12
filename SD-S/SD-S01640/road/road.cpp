#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long x,y,w;
	bool operator < (edge c){
		return w<c.w;
	}
}e[2000010];
long long n,m,k,fa[20010],c[20010],a[20][20010],p[20],ans = 1e18;
inline long long getf(long long x){
	return x==fa[x]?x:fa[x] = getf(fa[x]);
}
inline long long kruskal(long long top){
	long long sum = 0;
	for(int i = 1;i<=n+k;i++) fa[i] = i;
	for(int i = 1;i<=top;i++){
		if(!p[e[i].x]||!p[e[i].y]) continue;
		long long fx = getf(e[i].x),fy = getf(e[i].y);
		if(fx!=fy){
			fa[fx] = fy;
			sum+=e[i].w;
		}
	}
	return sum;
}
inline void dfs(long long top){
	if(top==k){
		long long cnt = kruskal(m),tot = 0;
		for(int i = 1;i<=k;i++) if(p[n+i]) tot+=c[i];
		ans = min(ans,cnt+tot);
		return;
	}
	p[n+top+1] = 1;
	dfs(top+1);
	p[n+top+1] = 0;
	dfs(top+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i = 1;i<=n;i++) p[i] = 1;
	for(int i = 1;i<=m;i++){
		scanf("%lld %lld %lld",&e[i].x,&e[i].y,&e[i].w);
	}
	for(int i = 1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j = 1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			e[++m].x = n+i,e[m].y = j,e[m].w = a[i][j];
		}
	}
	sort(e+1,e+m+1);
	if(k==0){
		printf("%lld\n",kruskal(m));
		return 0;
	}
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
