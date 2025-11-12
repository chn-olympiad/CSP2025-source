#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
vector< pair<int,ll> > G[10005];
bool vis[10005];ll n,m,k,ans;
bool check(){
	for(int i = 1;i <= n;i++)
		if(vis[i] == false) return false;
	return true;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		ll u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i = 1;i <= k;i++){
		ll c,w[10005];
		cin >> c;
		for(int j = 1;j <= n;j++){
			cin >> w[j];
			for(int x = 1;x < j;x++){
			    G[x].push_back({j,w[x]+c+w[j]});
			    G[j].push_back({x,w[x]+c+w[j]});
			}
		}
	}
	set<int> ybj;
	vis[1] = 1;
	ybj.insert(1);
	while(ybj.size() != n){
		pair<int,ll> shsh = {0,LONG_LONG_MAX};
		for(auto v : ybj){
			for(auto u : G[v]){
				if(u.second < shsh.second && vis[u.first] == false){
					shsh = u;
				}
			}	
		}
		vis[shsh.first] = true;
		ybj.insert(shsh.first);
		ans += shsh.second;
	}
	cout << ans;
	return 0;
} 