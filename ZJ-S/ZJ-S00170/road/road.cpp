#include<bits/stdc++.h>
#define il inline
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,idx,a[K][N],fa[2*N],sz[2*N],b[M],tot,c[K],cnt[M],p[M];
ll ans=1e18;
struct Edge{
	int u,v,w;
	bool operator<(Edge k){
		return w<k.w;
	}
}e[M],g[M];
il int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
il void merge(int x,int y){
	if(sz[x]<sz[y]){
		fa[x]=y;
		sz[y]+=sz[x];
	}
	else{
		fa[y]=x;
		sz[x]+=sz[y];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j],b[++tot]=a[i][j];
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			merge(u,v);
			g[++idx]=e[i];b[++tot]=e[i].w;
		}
	}
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-(b+1);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++) a[i][j]=lower_bound(b+1,b+tot+1,a[i][j])-b;
	for(int i=1;i<=idx;i++) g[i].w=lower_bound(b+1,b+tot+1,g[i].w)-b;
	for(int i=0;i<(1<<k);i++){
		int t=n,idx2=idx;
		ll sum=0;
		for(int j=1;j<=k;j++)
			if(i&(1<<(j-1))){
				t++;
				sum+=c[j];
				for(int l=1;l<=n;l++) g[++idx2]={t,l,a[j][l]};
			}
		for(int j=1;j<=tot;j++) cnt[j]=0;
		for(int j=1;j<=idx2;j++) cnt[g[j].w]++;
		for(int j=1;j<=tot;j++) cnt[j]+=cnt[j-1];
		for(int j=idx2;j>=1;j--) p[cnt[g[j].w]--]=j;
		for(int j=1;j<=t;j++) fa[j]=j,sz[j]=1;
		for(int j=1;j<=idx2;j++){
			int u=find(g[p[j]].u),v=find(g[p[j]].v);
			if(u!=v){
				merge(u,v);
				sum+=b[g[p[j]].w];
				if(sum>ans) break;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
}
