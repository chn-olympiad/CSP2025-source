#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll n ,m ,k;
	cin>>n>>m>>k;
	vector<ll> vis(2*(n+k)+1) ,dis(2*(n+k)+1 ,1e18);
	vector<pair<ll ,ll>> g[2*(n+k)+1];
	priority_queue<pair<ll ,ll> ,vector<pair<ll ,ll>> ,greater<pair<ll ,ll>>> q;
	vector<ll> vv(n+1);
	for(ll i = 1;i <= m;i++){
		ll u ,v ,w;
		cin>>u>>v>>w;
		g[u].push_back({v ,w});
		g[v].push_back({u ,w});
	}
	for(ll i = 1;i <= k;i++){
		cin>>vv[i];
		for(ll j = 1;j <= n;j++){
			ll u;
			cin>>u;
			g[n+i].push_back({j ,u+vv[i]});
			g[j].push_back({n+i ,u});
		}
	}
	dis[1] = 0;
	q.push({1 ,0});
	while(!q.empty()){
		ll u = q.top().first;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(auto p : g[u]){
			ll v = p.first;
			ll w = p.second;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u]+w;
				q.push({v ,dis[v]});
			}
		}
	}
	for(ll i = 1;i <= n+k;i++){
		ans += dis[i];
	}
	cout<<ans;
}

signed main(){
	freopen("road.in" ,"r" ,stdin);
	freopen("road.out" ,"w" ,stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}