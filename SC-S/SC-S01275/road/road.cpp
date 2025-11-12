#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
using namespace std;
vector<pair<ll, ll> > edge[10005];
ll n, m, k;
ll dis[10005];
bool vis[10005];
void dijkstra(ll st){
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	queue<pair<ll, ll> > q;
	q.push(make_pair(0, st));
	dis[st] = 0;
	while(!q.empty()){
		ll d = q.front().first;
		ll u = q.front().second;
		q.pop();
		if(vis[d]) continue;
		vis[d] = true;
		for(auto it : edge[u]){
			ll v = it.first;
			ll w = it.second;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				q.push(make_pair(dis[v], v));
			}
		}
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		ll u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(v, w));
		edge[v].push_back(make_pair(u, w));
	}
	for(int i = 1; i <= k; i ++){
		for(int j = 1; j <= n + 1; j ++){
			ll w;
			cin >> w;
			if(j == 1) continue;
			edge[n + i].push_back(make_pair(j - 1, w));
			edge[j - 1].push_back(make_pair(n + i, w));
		}
	}
	dijkstra(1);
	ll sum = 0;
	for(int i = 1; i <= n; i ++){
		sum += dis[i];
	}
	cout << sum;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/