#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
const ll N=1e4+5,M=1e6+5,K=10+5;
ll n,m,k;
struct Edge{
	ll u,v,w;
}e[M<<1],f[M<<1];
ll tp;
ll a[K][N];
ll fa[N];
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
ll ans=inf;
ll kruskal(){
	ll res=0;
	for(ll i=1;i<=n;i++)fa[i]=i;
	sort(f+1,f+tp+1,[](const Edge &x,const Edge &y){return x.w<y.w;});
	for(ll i=1;i<=m;i++){
		ll u=f[i].u,v=f[i].v,w=f[i].w;
		ll fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		res+=w;
	}
	return res;
}
void dfs(ll x,ll w){
	if(x>k){
		for(ll i=1;i<=tp;i++)f[i]=e[i];
		ans=min(ans,w+kruskal());
		return;
	}
	dfs(x+1,w);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<i;j++)
			e[++tp]=Edge{i,j,a[x][i]+a[x][j]};
	dfs(x+1,w+a[x][0]);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<i;j++)
			tp--;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	tp=m;
	bool flag=true;
	for(ll i=1;i<=k;i++)
		for(ll j=0;j<=n;j++){
			cin>>a[i][j];
//			if(a[i][j])flag=false;
		}
//	if(flag){
//		cout<<"0\n";
//		return 0;
//	}
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
} 
