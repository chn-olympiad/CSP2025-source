#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,t,fa[2005],mon[15],cnt=0;
long long ans=0x7ffffffffffffff;
bool mp[15];
int find(long long x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct edge{
	int u,v,w;
}realedge[1100005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
long long klu(long long num){
	for(register int i=1;i<=1010;i++) fa[i]=i;
	int add=0,i=0;
	long long ttans=0;
	for(int i=1;i<=k;i++){
		if(mp[i]) ttans+=mon[i]*1ll;
	}
	if(ttans>ans) return 0x7ffffffffffffff;
	while(add!=n+num-1&&i<cnt){
		i++;
		int l=realedge[i].u,r=realedge[i].v,lo=realedge[i].w;
		if((l>n&&mp[l-n]==0)||find(l)==find(r)) continue;
		fa[find(l)]=find(r);
		ttans+=lo*1ll;
		add++;
		if(ttans>ans) return 0x7ffffffffffffff;
	}
	if(add==n+num-1) return ttans;
	return 0x7ffffffffffffff;
}
void dfs(long long step,long long num){
	if(step==k+1){
		long long awa=klu(num);
		if(awa<ans) ans=awa;
		return;
	}
	mp[step]=1;
	dfs(step+1,num+1);
	mp[step]=0;
	dfs(step+1,num);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		realedge[i]={u,v,w};
	}
	cnt=m;
	for(register int i=1;i<=k;i++){
		scanf("%lld",&mon[i]);
		for(register int j=1;j<=n;j++){
			scanf("%lld",&t);
			cnt++;
			realedge[cnt]={n+i,j,t};
		}
	}
	sort(realedge+1,realedge+1+cnt,cmp);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}

