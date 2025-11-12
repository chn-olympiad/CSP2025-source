#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int c[13];
struct edge {
	int u,v,w;
} s[3000011],t[13][10011];
int head[10011],idx;
int chosen[111],fa[10011],used;
ll ansn=1e18;
int ffa(int x) {
	return fa[x]==x?x:fa[x]=ffa(fa[x]);
}
void SmallTree(ll ans) {
	for(int i=0; i<=n+k; i++)fa[i]=i;
	int N=n;
	for(int i=1; i<=k; i++)if(chosen[i])N++;
	int xb[13],b=0;
	for(int i=0; i<=k; i++)xb[i]=0;
	t[0][0].w=INT_MAX;
	for(int kkk=1; kkk<N; ) {
		int med=0;
		for(int i=1; i<=k; i++)
			if(chosen[i]&&t[i][xb[i]].w<t[med][xb[med]].w)med=i;
		int u,v,w;
		if(s[b].w<t[med][xb[med]].w)u=s[b].u,v=s[b].v,w=s[b].w,b++;
		else u=t[med][xb[med]].u,v=t[med][xb[med]].v,w=t[med][xb[med]].w,xb[med]++;
		if(ffa(u)==ffa(v))continue;
		ans+=w,fa[ffa(u)]=ffa(v),kkk++;
		if(ans>ansn)return;
	}
	ansn=min(ansn,ans);
}
void dfs(int x,ll ans) {
	if(ans>ansn)return;
	if(x==k+1) {
		SmallTree(ans);
		return;
	}
	chosen[x]=1,dfs(x+1,ans+c[x]);
	if(c[x])chosen[x]=0,dfs(x+1,ans);
}
bool cmp(edge a,edge b) {
	return a.w<b.w;
}
void init() {
	sort(s,s+idx,cmp);
	for(int i=1; i<=k; i++)
		sort(t[i],t[i]+n,cmp);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w; i<=m; i++)
		scanf("%d%d%d",&u,&v,&w),s[idx++]= {u,v,w};
	for(int i=1; i<=k; i++) {
		scanf("%d",&c[i]);
			for(int j=1,w; j<=n; j++)scanf("%d",&w),t[i][j-1]= {n+i,j,w};
	}
	init();
	dfs(1,0);
	printf("%lld\n",ansn);
	return 0;
}
