#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;
const ll B=20;
const ll M=2e6+10;
ll n,m,k,fa[N],c[N];
ll a[B][N];
struct edge{
	ll u;ll v;ll w;
}e[M];
ll kth(ll n,ll k){
	return (n>>(k-1))&1;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void Init(ll n){
	for(ll i=1;i<=n;i++) fa[i]=i;
} 
ll Find(ll x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Union(ll x,ll y){
	x=Find(x),y=Find(y);
	if(x==y) return;
	fa[x]=y;
}
vector<edge>es;
ll kkr(){
	sort(e+1,e+1+m,cmp);
	Init(n);
	ll cnt=0;ll ans=0;
	for(ll i=1;i<=m;i++){
		ll u=e[i].u;ll v=e[i].v;
		ll w=e[i].w;
		if(Find(u)!=Find(v)){
			es.push_back(e[i]);
			Union(u,v);cnt++;ans+=w;
			if(cnt==n-1){
				return ans;
			}
		}
	}
	return ans;
}
ll cal(ll m,ll n){
	sort(e+1,e+1+m,cmp);
	Init(n+k);
	ll cnt=0;ll ans=0;
	for(ll i=1;i<=m;i++){
		ll u=e[i].u;ll v=e[i].v;
		ll w=e[i].w;
		if(Find(u)!=Find(v)){
			Union(u,v);ans+=w;cnt++;
			if(cnt==n-1){
				return ans;
			}
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	ll ans=kkr();
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++) cin>>a[i][j];
	}
	ll S=(1ll<<k);
	for(ll s=1;s<S;s++){
		ll res=0;ll tot=n-1;
		for(ll i=1;i<n;i++){
			e[i]=es[i-1];
		}
		ll num=n;
		for(ll i=1;i<=k;i++){
			if(kth(s,i)){
				res+=c[i];
				num++;
				for(ll j=1;j<=n;j++){
					e[++tot]={i+n,j,a[i][j]};
				}
			}
		}
		ans=min(ans,res+cal(tot,num));
	}
	cout<<ans<<'\n';
	return 0;
}
