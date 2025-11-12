#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define il inline
#define fi first
#define se second
using namespace std;
const ll N=2e4+10,M=2e6+10;
ll n,m,k,ecnt;
struct Edge{ll u,v,w;}e[M];
ll c[20];
bool cmp(Edge x,Edge y){return x.w<y.w;}
ll fa[N],siz[N];
void init_dsu(){for(ll i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;}
ll get(ll x){return (fa[x]==x)?x:(fa[x]=get(fa[x]));}
void merge(ll u,ll v){
	ll fu=get(u),fv=get(v);
	if(fu==fv) return;
	if(siz[fu]<siz[fv]) swap(fu,fv);
	siz[fu]+=siz[fv],siz[fv]=0;
	fa[fv]=fu;
}
ll countbit(ll x,ll &cost){
	ll res=0,tmp=1;
	cost=0;
	while(x){
		if(x&1){
			res++;
			cost+=c[tmp];
		}
		x>>=1;
		tmp++;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w; cin>>u>>v>>w;
		e[i]=(Edge){u,v,w};
	}
	ecnt=m;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			ll w; cin>>w;
			e[++ecnt]=(Edge){j,n+i,w};
		}
	}
	sort(e+1,e+ecnt+1,cmp);
	ll ans=1e18;
	for(ll i=0;i<=(1<<k)-1;i++){
		ll res=0,con=0;
		ll now=n+countbit(i,res);
//		cout<<bitset<3>(i)<<":"<<now<<" "<<res<<"\n";
		init_dsu();
		for(ll j=1;j<=ecnt;j++){
			ll u=e[j].u,v=e[j].v,w=e[j].w;
			if(u>v) swap(u,v);
			if(v>n&&!((i>>(v-n-1))&1)) continue;
//			cout<<u<<" "<<v<<"\n";
			if(get(u)==get(v)) continue;
			merge(u,v);
			con++;
			res+=w;
			if(res>=ans) break;
			if(con==now-1){
				ans=res;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}