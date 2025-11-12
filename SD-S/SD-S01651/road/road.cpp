#include<bits/stdc++.h>
#define cmin(a,b) a=std::min(a,b)
#define cmax(a,b) a=std::max(a,b)
#define inf
#define mod
#define maxn 20004
#define maxm 2000006
#define maxk 15
#define int long long
inline void read(int &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
	}
}
int n,m,K,c[maxn],to[maxk][maxn];
namespace DSU{
	int fa[maxn];
	void init(){
		for(int i=1;i<=n+K;i++) fa[i]=i;
	}
	int find(int x){
		if(fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
}
using namespace DSU;
struct edge{
	int u,v,w,tp;
	bool operator <(edge oth){
		return w<oth.w;
	}
}edg[maxm],get[maxm];
int vis[maxn],ans,pos; 
void Kruskal1(){
	int tot=m+n*K;
	init(),std::sort(edg+1,edg+tot+1);
	for(int i=1;i<=tot;i++){
		if(edg[i].tp==1){
			get[++pos]=edg[i];
			continue;
		}
		int u=edg[i].u,v=edg[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv) get[++pos]=edg[i],fa[fu]=fv;
	}
}
int Kruskal2(){
	int res=0;init();
	for(int i=1;i<=pos;i++){
		int u=get[i].u,v=get[i].v,w=get[i].w;
		if(get[i].tp==1&&!vis[u-n]) continue;
		int fu=find(u),fv=find(v);
		if(fu!=fv) fa[fu]=fv,res+=w;
	}
	return res;
} 
void dfs(int x,int cost){
	if(x==K+1){
		cmin(ans,cost+Kruskal2());
		return;
	}
	for(int i=0;i<=1;i++){
		vis[x]=i,dfs(x+1,cost+(i==1)*c[x]);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(K);
	for(int i=1,u,v,w;i<=m;i++){
		read(u),read(v),read(w);
		edg[i]={u,v,w};
	}
	for(int i=1;i<=K;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(to[i][j]);
			edg[m+(i-1)*n+j]={i+n,j,to[i][j],1};
		}
	}
	Kruskal1();
//	for(int i=1;i<=pos;i++){
//		printf("%lld - %lld %lld\n",get[i].u,get[i].v,get[i].w);
//	}
	ans=1e18,dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
/*
mlogm+2^k*(n+k*n)*log 
*/

