#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=2e6+5;
int n,m,k,fa[N+20],sum[N+20];
ll tmp[15];
bool vis[N],usd[15];
struct node{
	int u,v;ll w;
	bool t;
}e[M];
bool cmp(node x,node y){return x.w<y.w;}
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
ll f(){
	ll ans=0;
	sort(e+1,e+m+1,cmp);
//	for(int i=1;i<=m;i++)
//		printf("%d %d %lld\n",e[i].u,e[i].v,e[i].w);
	for(int i=1;i<=n;i++)
		fa[i]=i,sum[i]=1;
	for(int i=1;i<=k;i++)
		fa[n+i]=n+i,sum[n+i]=0,usd[i]=0,tmp[i]=0;
	for(int i=1;i<=m;i++){
//		printf("%d %d %lld\n",e[i].u,e[i].v,e[i].w);
		if(e[i].t && !usd[e[i].v-n])continue;
		int fu=find(e[i].u),fv=find(e[i].v);
//		printf("fu=%d,fv=%d\n",fu,fv);
		if(fu!=fv){
			fa[fv]=fu;
			sum[fu]+=sum[fv];
			ans+=e[i].w;
//			printf("add %d->%d %lld\n",e[i].u,e[i].v,e[i].w);
			if(e[i].v>n){
				if(!usd[e[i].v-n]){
					tmp[e[i].v-n]=e[i].w;
					usd[e[i].v-n]=1;
				}else tmp[e[i].v-n]=0;
			}
//			printf("now,sum=%d\n",sum);
			if(sum[fu]>=n)break;
		}
	}//cout<<ans<<endl;
	for(int i=1;i<=k;i++)
		ans-=tmp[i];
//	cout<<ans<<endl;
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	ll ans1=f(),x,c;//cout<<ans1<<endl;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c);
		for(int j=1;j<=n;j++){
			scanf("%lld",&x);
			e[++m].u=j;e[m].v=n+i;e[m].w=x;e[m].t=1;
			e[++m].u=j;e[m].v=n+i;e[m].w=c+x;
		}
	}
	ans1=min(ans1,f());
	printf("%lld\n",ans1);
	return 0;
}
