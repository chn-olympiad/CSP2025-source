#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
	int u,v;
	ll w;
}ed[1200006];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
ll eds=0;
edge remed[120000];
edge workon[120000];
ll remeds=0;
ll workeds;
ll n,m,k;
vector<ll> newedge[20];
ll fa[10100];
ll c[25];
ll getfa(ll x){
	if(fa[x]==x) return fa[x];
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void init(){
	for(ll i=1;i<=n+k;i++){
		fa[i]=i;
	}
}
void kruskal_first(){
	init();
	sort(ed+1,ed+m+1,cmp);
	for(ll i=1;i<=m;i++){
		if(getfa(ed[i].u)!=getfa(ed[i].v)){
			remed[remeds]=ed[i];
			remeds++;
			fa[getfa(ed[i].u)]=getfa(ed[i].v);
		}
	}
}
ll kruskal(ll S){
	init();
	ll ans=0;
	for(ll i=0;i<remeds;i++){
		workon[i]=remed[i];
	}
	workeds=remeds;
	for(ll i=0;i<k;i++){
		if(S&(1ll<<i)){
			ans+=c[i+1];
			for(ll j=0;j<newedge[i+1].size();j++){
				workon[workeds]=ed[newedge[i+1][j]];
				workeds++;
			}
		}
	}
	sort(workon,workon+workeds,cmp);
	for(ll i=0;i<workeds;i++){
		if(getfa(workon[i].u)!=getfa(workon[i].v)){
			fa[getfa(workon[i].u)]=getfa(workon[i].v);
			ans+=workon[i].w;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	}
	eds=m;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			eds++;
			ed[eds].u=n+i;
			ed[eds].v=j;
			cin>>ed[eds].w;
			newedge[i].push_back(eds);
		}
	}
	kruskal_first();
	ll ans=10000000000000000;
	for(ll i=0;i<(1ll<<k);i++){
		ans=min(ans,kruskal(i));
	}
	cout<<ans;
	return 0;
}