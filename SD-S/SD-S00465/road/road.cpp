#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+15;
const int M=1e6+5+2e5;
struct edge{
	int u,v,w;
}e[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int c[15],fa[N],siz[N];
bool vis[15];
int n,m,k;
ll ans=1e18;
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
ll kruskal(int sum){
	for(int i=1;i<=n+k;++i){
		fa[i]=i;
		siz[i]=1;
	}
	int cnt=0;
	ll tmp=0;
	for(int i=1;i<=m;++i){
		if(find(e[i].v)==find(e[i].u))continue;
		if(e[i].u>n&&(!vis[e[i].u-n]))continue;
		if(e[i].v>n&&(!vis[e[i].v-n]))continue;
		if(siz[fa[e[i].u]]<siz[fa[e[i].v]])swap(e[i].u,e[i].v);
		siz[e[i].u]+=siz[e[i].v];
		fa[fa[e[i].v]]=fa[e[i].u];
		cnt++;
		tmp+=e[i].w;
		if(cnt==sum)return tmp;
	}
	return 1e18;
}
void dfs(int nw,ll sum,int cnt){
	if(nw==k+1){
		ans=min(ans,kruskal(n+cnt-1)+sum);
		return;
	}
	vis[nw]=true;
	dfs(nw+1,sum+c[nw],cnt+1);
	vis[nw]=false;
	dfs(nw+1,sum,cnt);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	ll sum=0;
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		sum+=c[i];
		for(int j=1;j<=n;++j){
			e[++m].u=n+i;
			e[m].v=j;
			scanf("%d",&e[m].w);
		}
	}
	sort(e+1,e+m+1,cmp);
	if(sum==0){
		for(int i=1;i<=k;++i)vis[i]=true;
		ans=min(ans,kruskal(n+k-1));
	}
	else dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
