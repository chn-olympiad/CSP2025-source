#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20000;
int sum=1e17,fa[N],tot=0,tag[2000000],chose[N],n,m,k,c[N];
struct edge{
	int u,v,w;
	bool operator<(const edge&x)const{
		return w<x.w;
	}
}g[2000000];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int kruskal(int ff){
	int cnt=n+ff,ans=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=tot;i++){
		int u=g[i].u,v=g[i].v;
		if(tag[u]||tag[v])continue;
		int x=find(u),y=find(v);
		if(x==y)continue;
		fa[x]=y,cnt--,ans+=g[i].w;
		if(cnt==1)return ans;
	}
}
void dfs(int now){
	if(now==k){
		int res=0,ff=0;
		memset(tag,0,sizeof(tag));
		for(int i=1;i<=k;i++){
			if(chose[i]==0)tag[i+n]=1;
			else res+=c[i],ff++;
		}
		sum=min(sum,kruskal(ff)+res);
		return;
	}
	chose[now+1]=1;
	dfs(now+1);
	chose[now+1]=0;
	dfs(now+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[++tot]={u,v,w};
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i])flag=false;
		for(int j=1,w;j<=n;j++){
			scanf("%lld",&w);
			g[++tot]={n+i,j,w};
		}
	}
	sort(g+1,g+tot+1);
	if(flag){
		printf("%lld",kruskal(k));
		return 0;
	}
	dfs(0);
	printf("%lld",sum);
	return 0;
}
