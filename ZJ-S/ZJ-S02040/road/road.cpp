#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+10,M=1e6+10,INF=0x3f3f3f3f;
ll n,m,k,fa[N],c[20],mc[20][N],ans=INF,ch[20],cnt=0;
struct Edge{
	ll u,v,w;
}e[M],f[M];
bool cmp(Edge e1,Edge e2){
	return e1.w<e2.w;
}
ll Find(ll l){
	if(fa[l]==l)return fa[l];
	return fa[l]=Find(fa[l]);
}
void Union(ll l,ll r){
	ll x=Find(l),y=Find(r);
	if(x!=y)fa[x]=y;
	return;
}
ll solve(){
	ll res=0,bnt=m,yb=0;
	for(ll i=1;i<=m;i++){
		e[i].u=f[i].u;
		e[i].v=f[i].v;
		e[i].w=f[i].w;
	}
	for(ll i=1;i<=cnt;i++){
		res+=c[ch[i]];
		for(ll j=1;j<=n;j++){
			e[++bnt].u=n+i;
			e[bnt].v=j;
			e[bnt].w=mc[ch[i]][j];
		}
	}
	sort(e+1,e+bnt+1,cmp);
	for(ll i=1;i<=bnt;i++){
		if(yb>=n+cnt-1)break;
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		if(Find(u)==Find(v))continue;
		else{
			yb++;
			Union(u,v);
			res+=w;
		}
	}
	return res;
}
void dfs(ll x){
	if(x>k){
		for(ll i=1;i<=n+10;i++)fa[i]=i;
		ans=min(ans,solve());
		return;
	}
	dfs(x+1);
	ch[++cnt]=x;
	dfs(x+1);
	cnt--;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(ll i=1;i<=n+10;i++)fa[i]=i;
	for(ll i=1;i<=m;i++)scanf("%d %d %d",&f[i].u,&f[i].v,&f[i].w);	
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>mc[i][j];
	}
	if(k==0){
		ll yb=0,res=0;
		sort(f+1,f+m+1,cmp);
		for(ll i=1;i<=m;i++){
			if(yb>=n-1)break;
			ll u=f[i].u,v=f[i].v,w=f[i].w;
			if(Find(u)==Find(v))continue;
			else{
				yb++;
				Union(u,v);
				res+=w;
			}
		}
		cout<<res;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}