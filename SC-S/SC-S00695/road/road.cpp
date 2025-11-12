#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN=1e4+11,MAXM=1e6+11;
int n,m,k;
int cost[MAXN];
int dis[MAXN][MAXN],dist[MAXN][MAXN],idx=0;
int fa[MAXN];
int edge=0,ans=0;

struct Edge{
	int u,v,w;
}e[MAXM<<2];

bool cmp(Edge ni,Edge ko){
	return ni.w<ko.w;
}

int finden(int x){
	if(fa[x]==x) return x;
	else return fa[x]=finden(fa[x]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		for(int j=1;j<=n;j++) if(i!=j) dist[i][j]=0x3f3f3f3f;
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		dist[a][b]=dist[b][a]=min(min(dist[a][b],dist[b][a]),c);
	}	
	for(int cs=1;cs<=k;cs++){
		scanf("%lld",&cost[cs]);
		for(int j=1;j<=n;j++) scanf("%lld",&dis[cs][j]);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dis[cs][i]+dis[cs][j]+cost[cs]);
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) e[++idx]=(Edge){i,j,dist[i][j]};
	sort(e+1,e+1+idx,cmp);
	for(int i=1;i<=idx;i++){
		int fu=finden(e[i].u),fv=finden(e[i].v);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=min(e[i].w,dist[fu][fv]); 
			edge++;
			if(edge==n-1){printf("%lld\n",ans);break;}
		}
	}
	return 0;
}