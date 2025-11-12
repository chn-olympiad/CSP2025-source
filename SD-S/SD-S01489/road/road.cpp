#include<bits/stdc++.h>
#include<cstdio>
#define int long long 
using namespace std;
const int N=2.2e6+5;
int n,m,k,num,head[N],fa[N],ans,nw[15][N],c[N];
struct edge{
	int from,to,nxt,w;
}e[N];
void addedge(int u,int v,int w){
	e[++num]=edge{u,v,head[u],w};
	head[u]=num;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int findfa(int x){
	return (fa[x]==x?x:fa[x]=findfa(fa[x]));
}
void Kruskal(){
	sort(e+1,e+1+num,cmp);
	int cnt=0,lst;
	for(int i=1;i<=num;i++){
		int flag=0;
		int u=e[i].from,v=e[i].to;
		int fu=findfa(u),fv=findfa(v);
		if(fu!=fv) {
			if(fv>fu) swap(fu,fv);
			fa[fu]=fv,ans+=e[i].w;
			cnt++;
			if(k==0&&cnt==n-1) return;
		}
		if(k!=0){
			lst=findfa(1);
			for(int j=2;j<=n;j++){
				if(findfa(j)!=lst){
					flag=1;
					break;
				}
			}
			if(!flag) return ;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		addedge(u,v,w),addedge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&nw[i][j]);
			addedge(i+n,j,nw[i][j]),addedge(j,i+n,nw[i][j]);
		} 
	} 
	for(int i=1;i<=n+k;i++) fa[i]=i;
	Kruskal();
	printf("%lld",ans);
	return 0;
}
