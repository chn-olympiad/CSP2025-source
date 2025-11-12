#include<bits/stdc++.h>
#define int long long
#define N 10004
#define M 1000006
#define K 11
using namespace std;
struct Edge{
	int u,v,w;
	bool operator<(const Edge x)const{
		return w<x.w;
	}
}e[M];
int n,m,k,tot,head[N],ver[M],edge[M],nxt[M],fa[N],c[K],a[K][N];
void add(int u,int v,int w){
	ver[++tot]=v,edge[tot]=w,nxt[tot]=head[u],head[u]=tot;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void solve(){
	int res=0LL,cnt=0LL;
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[x]=y,res+=e[i].w,cnt++;
		if(cnt==n-1) break;
	}
	printf("%lld\n",res);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		e[i].u=u,e[i].v=v,e[i].w=w;
		add(u,v,w),add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",c+i);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	solve();
	return 0;
}
