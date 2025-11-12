#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,res;
const int N=1e4+5,M=(1<<10)+5;
int n,m,k,sum,cnt,c[12],tot[M],fa[N+10],siz[N+10];
struct Node{
	int u,v,w;	
}g[M][N+13],e[N*100],g1[12][N];
inline int findf(int x){
	if(fa[x]==x) return x;
	return fa[x]=findf(fa[x]);
}
inline bool cmp(Node x,Node y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=0;i<k;i++){
		scanf("%d",&c[i]);
		for(int j=1,w;j<=n;j++){
			scanf("%d",&w); g1[i][j]={n+1+i,j,w};
		}
		sort(g1[i]+1,g1[i]+1+n,cmp);
	}
	for(int i=1;i<=n;i++) siz[i]=1,fa[i]=i;
	sort(e+1,e+1+m,cmp); cnt=1;
	for(int i=1;i<=m;i++){
		if(cnt==n) break;
		int fx=findf(e[i].u),fy=findf(e[i].v);
		if(fx==fy) continue;
		ans+=e[i].w; g[0][++tot[0]]=e[i];
		if(siz[fx]>siz[fy]) swap(fx,fy);
		fa[fx]=fy; siz[fy]+=siz[fx]; cnt=siz[fy];
	}
	for(int i=1;i<(1<<k);i++){
		int l=1,r=1,j=0; res=0; cnt=1; sum=n;
		for(int o=1;o<=n+k;o++) fa[o]=o,siz[o]=1;
		for(int o=0;o<k;o++){
			if(i>>o&1) res+=c[o],sum++;
		}
		while((i>>j&1)==0) j++; 
		while(l<=tot[i^(1<<j)]&&r<=n){
			if(g[i^(1<<j)][l].w<g1[j][r].w) e[++tot[i]]=g[i^(1<<j)][l],l++;
			else e[++tot[i]]=g1[j][r],r++;
		}
		while(l<=tot[i^(1<<j)]) e[++tot[i]]=g[i^(1<<j)][l],l++;
		while(r<=n) e[++tot[i]]=g1[j][r],r++;
		int len=tot[i]; tot[i]=0;
		for(int v=1;v<=len;v++){
			if(cnt==sum) break;
			int fx=findf(e[v].u),fy=findf(e[v].v);
			if(fx==fy) continue;
			res+=e[v].w; g[i][++tot[i]]=e[v];
			if(siz[fx]>siz[fy]) swap(fx,fy);
			fa[fx]=fy; siz[fy]+=siz[fx]; cnt=siz[fy];
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans); 
	return 0;
} 
