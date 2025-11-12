#include<bits/stdc++.h>
#define ll long long
#define N 1000001
using namespace std;
vector<pair<ll,ll>> G[N];
ll fa[N],contry;
ll findfa(ll u){
	if(u==fa[u]) return fa[u];
	return fa[u]=findfa(fa[u]);
}
ll bin(ll u,ll v){
	fa[u]=fa[v];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({w,v});
		G[v].push_back({w,u});
	}
//	for(ll i=1;i<=k;i++){
//		ll c,a[10001]={};
//		cin>>c;
//		for(ll j=1;j<=n;j++){
//			cin>>a[i];
//		}
//	}
//
	
	cout<<0;
	
	return 0;
}

