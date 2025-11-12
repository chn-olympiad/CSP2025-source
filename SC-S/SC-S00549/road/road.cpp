#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int N=10005,M=1000005,K=1034;
ll n,m,k,fa[N],g[N][15],t[15],minn[N][15];
struct node{ll u,v,w;}opt[N],e[M];ll dp[K];
ll u[N][K],v[N][K];bool vis[N];
bool cmp(node a,node b){return a.w<b.w;}
int find(int u){return fa[u]==u?fa[u]:fa[u]=find(fa[u]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	up(i,1,n) fa[i]=i;
	up(i,1,m) scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);
	up(i,1,k){
		scanf("%lld",&t[i]);
		up(j,1,n) scanf("%lld",&g[j][i]),minn[j][i]=j;
	}ll res=0,cnt=0;
	up(i,1,m){
		int fau=find(e[i].u),fav=find(e[i].v);
		if(fau==fav) continue;opt[++cnt].u=e[i].u,opt[cnt].v=e[i].v,opt[cnt].w=e[i].w;
		up(j,1,k)
			if(e[i].w>g[minn[fav][j]][j]+g[minn[fau][j]][j]){ 
				u[cnt][j]=minn[fau][j],v[cnt][j]=minn[fav][j];
			}
		fa[fau]=fav;res+=e[i].w;
		up(j,1,k)
			if(g[minn[fav][j]][j]>g[minn[fau][j]][j])
				minn[fav][j]=minn[fau][j];
	}dp[0]=res;
	up(i,1,(1<<k)-1) dp[i]=1e18;
	up(i,0,(1<<k)-2){
		up(j,1,k){
			if(i&(1<<(j-1))) continue;
			res=t[j];
			up(r,1,n) vis[r]=0;
			up(r,1,cnt){
				if(!u[r][j]) continue;
				ll gmin=opt[r].w;
				up(l,1,k) if((i&(1<<(l-1)))&&u[r][l]&&l!=j) gmin=min(gmin,g[u[r][l]][l]+g[v[r][l]][l]);
				if(gmin<=g[u[r][j]][j]+g[v[r][j]][j]) continue;
				res-=gmin;vis[u[r][j]]=vis[v[r][j]]=1;
			}
			up(r,1,n) if(vis[r]) res+=g[r][j];
			dp[i|(1<<(j-1))]=min(dp[i|(1<<(j-1))],dp[i]+res);
		}
	} 
	ll ans=1e18;
	up(i,0,(1<<k)-1) ans=min(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}