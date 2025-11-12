#include <bits/stdc++.h>
#define int long long
int n,m,k;
const int MAXN=3e5+5,MAXM=3e6+5;
int c[20],x[20][MAXN];
struct edges{
	int u,v,w;
}edg[MAXM];
int cmp(edges a1,edges a2){
	return a1.w<a2.w;
}
int fa[MAXM];
int findfa(int x){
	if(x==fa[x])return x;
	return fa[x]=findfa(fa[x]);
}
void join(int x,int y){
	x=findfa(x),y=findfa(y);
	if(x==y)return;
	fa[x]=y;
	return;
}
int totbian=0;
int kruskal(){
	int ans=0;
	for(int i=1;i<=2e6+2000;i++)fa[i]=i;
//	for(int i=1;i<=m;i++){
//		std::cout<<edg[i].w<<'\n';
//	}
	std::sort(edg+1,edg+totbian+1,cmp);
	for(int i=1;i<=totbian;i++){
		int u1=edg[i].u,v1=edg[i].v;
		//std::cout<<edg[i].w<<'\n';
		if(findfa(u1)==findfa(v1))continue;
		ans+=edg[i].w;
		join(u1,v1);
	//	std::cout<<u1<<' '<<v1<<'\n';
//		std::cout<<edg[i].w<<'\n';
	}return ans;
}
int vis[25],ans=1e18;
void check1(){
	totbian=m;
	int myans=0;	
for(int i=1;i<=k;i++){
	edg[++totbian].u=n+i*2-1;
	edg[totbian].v=n+i*2;
	edg[totbian].w=c[i]; 
//	edg[++totbian].u=n+i*2-1;
//	edg[totbian].v=n+2*k+1;
//	edg[totbian].w=0;
//	edg[++totbian].u=n+i*2;
//	edg[totbian].v=1;
//	edg[totbian].w=0;
	for(int j=1;j<=n;j++){
		edg[++totbian].u=j;
		edg[totbian].v=n+i*2-1;
		edg[totbian].w=x[i][j];
	//	std::cout<<x<<'\n';
	}
}

//edg[++totbian].u=n+2*k+1;
//edg[totbian].v=1;
//edg[totbian].w=0;
ans=std::min(ans,kruskal()+myans);
//std::cout<<kruskal()<<'\n';
}
void dfs(int now){
	if(now==k+1){
		check1();return;
	}
	if(c[now])dfs(now+1);
	vis[now]=1;
	dfs(now+1);vis[now]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
std::cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	scanf("%lld%lld%lld",&edg[i].u,&edg[i].v,&edg[i].w);
//	std::cin>>edg[i].u>>edg[i].v>>edg[i].w;
	totbian++;
//	std::cout<<edg[i].w<<'\n';
}
//	for(int i=1;i<=m;i++){
//		std::cout<<edg[i].w<<'\n';
//	}
//std::cout<<kruskal()<<'\n';
int flg=0;
int qwq=kruskal();
if(k==0){
	std::cout<<qwq<<'\n';
	return 0;
}
for(int i=1;i<=k;i++){
	scanf("%lld",&c[i]);
	if(c[i]!=0)flg=1;
	for(int j=1;j<=n;j++){
		scanf("%lld",&x[i][j]);
	}
}
if(flg==0){
	
for(int i=1;i<=k;i++){
	edg[++totbian].u=n+i*2-1;
	edg[totbian].v=n+i*2;
	edg[totbian].w=c[i]; 
//	edg[++totbian].u=n+i*2-1;
//	edg[totbian].v=n+2*k+1;
//	edg[totbian].w=0;
//	edg[++totbian].u=n+i*2;
//	edg[totbian].v=1;
//	edg[totbian].w=0;
	for(int j=1;j<=n;j++){
		edg[++totbian].u=j;
		edg[totbian].v=n+i*2-1;
		edg[totbian].w=x[i][j];
	//	std::cout<<x<<'\n';
	}
}
//edg[++totbian].u=n+2*k+1;
//edg[totbian].v=1;
//edg[totbian].w=0;
std::cout<<kruskal()<<'\n';
}
else{
	dfs(1);
	std::cout<<std::min(qwq,ans)<<'\n';
}
	return 0;
}
//csps rp++!
//scanf 用lld!
//算算空间时间!
//t2

 
 
 
 
 
