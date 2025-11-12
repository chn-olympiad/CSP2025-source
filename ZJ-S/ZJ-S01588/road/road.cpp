#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=1e3+10;
ll n,m,k;
vector< pair<ll,ll> > g[N];
ll c[N],a[N][N];
ll fa[N];
struct node{
	ll u,v,w;
	bool operator<(const node &_)const{
		return w<_.w;
	}
}b[N];
ll find(ll x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void solve1(){
	for(ll i=1;i<=n;i++)fa[i]=i;
	sort(b+1,b+1+n);
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll u=find(b[i].u),v=find(b[i].v);
		if(u!=v){
			ans+=b[i].w;
			fa[u]=fa[v];
		}
	}
	cout<<ans;
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		b[i]={u,v,w};
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	solve1();
	return 0;
}
