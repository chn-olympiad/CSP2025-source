#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,tot=0,ans=1e18;
ll x[1010101],s[1010101][15],fa[1010101];
ll u1[1010101],v1[1010101],w1[1010101];
struct edge{
	ll u,v,w;
};
edge e[1010101],ee[1010101];
ll fnd(ll x){
	if(fa[x]==x) return x;
	else return fa[x]=fnd(fa[x]);
}
bool cmp(edge p,edge q){
	return p.w<q.w;
}
int cs[15];
ll f(ll sum){
	for(ll i=1;i<=n+k;i++) fa[i]=i;
	ll ans1=0,cnt1=0;
	for(ll i=1;i<=tot;i++){
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		if(cs[u]==0||cs[v]==0) continue;
		ll fu=fnd(u),fv=fnd(v);
		if(fu!=fv){
			ans1+=w;
			cnt1++;
			fa[fu]=fv;
		}
		if(cnt1==n+sum-1) break;
	}
	return ans1;
}
void dfs(ll now,ll val,ll sum){
	if(now==k+1){
		ans=min(ans,val+f(sum));
		return;
	}
	if(val+x[now]>=ans){
		dfs(now+1,val,sum);
		return;
	}
	cs[now+n]=1;
	dfs(now+1,val+x[now],sum+1);
	cs[now+n]=0;
	dfs(now+1,val,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u1[i],&v1[i],&w1[i]);
		e[++tot].u=u1[i],e[tot].v=v1[i],e[tot].w=w1[i];
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&x[i]);
		for(ll j=1;j<=n;j++) 
			scanf("%lld",&s[j][i]);
	}
	for(ll now=1;now<=k;now++)
		for(ll i=1;i<=n;i++)
			e[++tot].u=n+now,e[tot].v=i,e[tot].w=s[i][now];
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=n;i++) cs[i]=1;
	dfs(1,0,0);
	cout<<ans;
	return 0;
}