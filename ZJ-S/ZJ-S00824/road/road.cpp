#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1e4+15,M=1.2e6+5,K=12;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,c[K],a[K][N];
struct Edge{
	int u,v,w;
	inline bool operator<(Edge op)const{return w<op.w;}
};
Edge eg[M],eg2[M];
int fa[N],sz[N];
inline void init(){
	for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
}
inline int fd(int u){return u==fa[u]?u:fa[u]=fd(fa[u]);}
inline void merge(int u,int v){
	if(sz[u]<sz[v])swap(u,v);
	u=fd(u),v=fd(v);
	fa[v]=u,sz[u]+=sz[v],sz[v]=0;
}
signed main()
{
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&eg[i].u,&eg[i].v,&eg[i].w);
	int or_ret=0;
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		or_ret|=c[i];
		for(int j=1;j<=n;j++)scanf("%d",a[i]+j);
	}
	if(!or_ret){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				eg[++m].u=n+i,eg[m].v=j,eg[m].w=a[i][j];
			}
		}
		sort(eg+1,eg+m+1);
		ll ans=0;
		init();
		for(int i=1;i<=m;i++){
			int u=eg[i].u,v=eg[i].v,w=eg[i].w;
			if(fd(u)==fd(v))continue;
			else merge(u,v),ans+=w;
		}printf("%lld",ans);
	}
	else{
		ll fi_ans=INF;
		for(int t=0;t<(1<<k);t++){
			int new_m=m;
			ll ans=0;
			for(int i=1;i<=m;i++)eg2[i]=eg[i];
			for(int i=1;i<=k;i++){
				if((t>>(i-1))&1)continue;// not in choose
				ans+=c[i];
				for(int j=1;j<=n;j++){
					eg2[++new_m].u=n+i,eg2[new_m].v=j,eg2[new_m].w=a[i][j];
				}
			}
			sort(eg2+1,eg2+new_m+1);
			init();
			for(int i=1;i<=new_m;i++){
				int u=eg2[i].u,v=eg2[i].v,w=eg2[i].w;
				if(fd(u)==fd(v))continue;
				else merge(u,v),ans+=w;
			}fi_ans=min(fi_ans,ans);
		}printf("%lld",fi_ans);
	}
	return 0;
}
