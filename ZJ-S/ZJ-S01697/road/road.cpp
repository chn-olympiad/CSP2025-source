#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back 
const ll N=1e4+100;
struct EDGE{
	ll u;
	ll v;
	ll w;
};
vector<EDGE> ed;
ll a[15][N*2];
bool st[15];
bool vis[N];	
ll n,m,k;
ll minn;
ll fa[N];
ll d[1010][1010];
bool cmp(EDGE p,EDGE q){
	return p.w<q.w;
}
ll find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool merge(ll x,ll y){
	ll r1=find(x),r2=find(y);
	if(r1!=r2){
		fa[r1]=r2;
		return 1;
	}
	return 0;
}
void dfs(ll now){
	if(now==k+1){
		for(ll i=1;i<=n+k;i++){
			fa[i]=i;
		}
		ll res=0;
		vector<EDGE> real=ed;
		for(ll i=1;i<=k;i++){
			if(st[i]){
				res+=a[i][0];
				for(ll j=1;j<=n;j++){
					real.pb({j,n+i,a[i][j]});
				}
			} 
		}	
		sort(real.begin(),real.end(),cmp);
		for(EDGE it:real){
			if(merge(it.u,it.v)){
				res+=it.w;
				if(res>=minn) return;
			}
		}
		ll kkk=find(1);
		for(ll i=2;i<=n;i++){
			if(find(i)!=kkk) return;
		}
		minn=min(minn,res);
		return;
	}
	st[now]=0;
	dfs(now+1);
	st[now]=1;
	dfs(now+1);
}
void solve(){
	cin>>n>>m>>k;
	ll u,v,w;
	while(m--){
		cin>>u>>v>>w;
		if(v<u) swap(u,v);
		ed.pb({u,v,w});
	}
	for(ll i=1;i<=k;i++){
		for(ll j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	minn=1e18;
	bool SP=1;
	for(ll i=1;i<=k;i++){
		if(a[i][0]!=0) SP=0;
	}
	if(SP){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				d[i][j]=1e18;
			}
		}
		for(EDGE it:ed){
			d[it.u][it.v]=it.w;
		}
		for(ll i=1;i<=n;i++){
			fa[i]=i;
		}
		ll res=0;
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				for(ll t=j+1;t<=n;t++){
					d[i][j]=min(d[i][j],a[i][j]+a[i][t]);
				}
			}
		}	
		ed.clear();
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(d[i][j]!=1e18){
					ed.pb({i,j,d[i][j]});
				}
			}
		}
		sort(ed.begin(),ed.end(),cmp);
		for(EDGE it:ed){
			if(merge(it.u,it.v)){
				res+=it.w;
			}
		}
		cout<<res<<'\n';
	}
	dfs(1);
	cout<<minn<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}
