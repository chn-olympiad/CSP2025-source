#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1E4+50;
int n,m,k;
int c[15],w[15][N];
int val[50],ans=1e18,cnt;
struct node{
	int u,v,w;
	bool operator<(const node &a)const{
		return w<a.w;
	}
}e[1000005],g[100005];
struct DSU {
	int siz[N],fa[N],cnt;
	void init(){
		for(int i=1;i<=n+12;i++)
			fa[i]=i,siz[i]=1;
		cnt=0;
	}
	int find(int x) {
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	
	bool merge(int x,int y) {
		x=find(x),y=find(y);
		if(x==y)return false;
		if(siz[x]>siz[y])swap(x,y);
		fa[x]=y;
		siz[y]+=siz[x];
		cnt++;
		return true;
	}
}dsu;
int dp[2][1030],popc[1030];
void solve(int x,int y,int w,int tot){
	dsu.init() ;
	int i=1,j=1;
	while(dsu.cnt <tot-1){
		if(i>m && j>cnt )break;
		if(j>cnt || i<=m && e[i]<g[j] ){
			if(dsu.merge(e[i].u,e[i].v )){
				w+=e[i].w ;
			}
			++i;
		}
		else {
			if(dsu.merge(g[j].u,g[j].v )){
				w+=g[j].w ;
			}
			++j;
		}
	}
	ans=min(ans,w);
}
signed main() {
	freopen("road.in","r",stdin);
	
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u ,&e[i].v ,&e[i].w );
		if(e[i].u >e[i].v )swap(e[i].u ,e[i].v );
	}
	for(int i=0;i<k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w[i][j]);
		}
	}
	for(int i=1;i<=1024;i++)
		popc[i]=popc[i/2]+(i&1);
	
	sort(e+1,e+m+1);
	for(int st=0;st<(1<<k);st++){
		int W=0;
		cnt=0;
		for(int i=0;i<k;i++){
			if(st&1<<i){
				W+=c[i];
				for(int j=1;j<=n;j++){
					g[++cnt]={i+n+1,j,w[i][j]};	
				}		
			}
		}
		sort(g+1,g+cnt+1);
		solve(0,st,W,popc[st]+n);
	}
	cout<<ans;
	return 0;
}

