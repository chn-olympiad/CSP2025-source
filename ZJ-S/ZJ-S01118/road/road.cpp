#include<bits/stdc++.h>
using namespace std;

#define int long long
const int K=15,N=1e4+50,M=1e6+50,inf=1e18;
struct edge{
	int u,v,w;
}g[N],e[M];
int n,m,k,c[K],w[K][N],f[N];
inline int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
inline int solve(int m,bool op){
	int ans=0,cnt=0;
	for(int i=1;i<=n+k;++i)f[i]=i;
	sort(e+1,e+1+m,[](edge a,edge b){
		return a.w<b.w;
	});
	for(int i=1;i<=m;++i){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		f[u]=v,ans+=e[i].w;
		if(op)g[++cnt]=e[i];
	} return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i)
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=0;i<k;++i){
		scanf("%lld",c+i);
		for(int j=1;j<=n;++j)
			scanf("%lld",&w[i][j]);
	}
	int res=solve(m,1);
	for(int i=0;i<(1<<k);++i){
		bitset<K>vis;
		int now=0,cnt=n-1;
		memcpy(e,g,sizeof g);
		for(int j=0;j<k;++j){
			vis[j]=i&(1<<j);
			if(vis[j]){
				now+=c[j];
				for(int p=1;p<=n;++p)
					e[++cnt]={p,n+j+1,w[j][p]};
			}
		}
		now+=solve(cnt,0);
		res=min(res,now);
	} printf("%lld",res);
	return 0;
}
// 15:01 AC road4.in/ans
// maxtime = road2 2.99s
// Update 17:00 input = 2.86s