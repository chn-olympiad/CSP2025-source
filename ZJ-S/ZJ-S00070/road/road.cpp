#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rg register int
const int maxn=10040,maxm=1000060;
ll n,m,k,ans=0;
struct nh{
	ll u,v,w;
};
inline bool cmp(nh x,nh y){
	return x.w<y.w;
}
ll d[maxn][maxn],c[maxn],used[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	memset(used,0,sizeof(used));
	for(rg i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		d[u][v]=w;d[v][u]=w;
 	}
	for(rg i=1;i<=k;i++){
		int op;scanf("%lld",&op);
		for(rg j=1;j<=n;j++)
			scanf("%lld",&c[j]);
		
	}
 	int pos=0;
 	n-=1;
	while(n>1){
		++pos;
		if(used[p[pos].u]&&used[p[pos].v])
			continue;
		n--;
		used[p[pos].u]=1;used[p[pos].v]=1;
		ans+=p[pos].w;
	}
	printf("%d\n",ans);
	return 0;
}