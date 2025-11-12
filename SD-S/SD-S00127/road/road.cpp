#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1100005;
struct node{
	int u,v;
	ll w;
	friend bool operator <(node _,node __){
		return _.w<__.w;
	}
}e[N];
ll c[15];
int n,m,k,p[15],fa[N];
ll ans=0x3f3f3f3f3f3f3f3f;
int findd(int x){
	if(fa[x]==x)return x;
	return fa[x]=findd(fa[x]);
}
void vnion(int u,int v){
	u=findd(u);v=findd(v);
	if(u==v)return;
	fa[u]=v;
}
void dfs(int po,ll sum,int cho){
	if(po==k+1){
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int cnt=0;
		for(int i=1,u,v;i<=m;i++){
			u=e[i].u;v=e[i].v;
			if(u>n&&!p[u-n])continue;
			if(v>n&&!p[v-n])continue;
			if(findd(u)!=findd(v)){
				vnion(u,v);
				sum+=e[i].w;
				cnt++;
			}
			if(cnt==n+cho-1)break;
		}
		if(cnt==n+cho-1)ans=min(ans,sum);
		return;
	}
	p[po]=0;dfs(po+1,sum,cho);
	p[po]=1;dfs(po+1,sum+c[po],cho+1);
	p[po]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		ll w=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&w);
			e[++m].u=j;e[m].v=i+n;e[m].w=w;
		}
	}
	sort(e+1,e+m+1);
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0;
}

