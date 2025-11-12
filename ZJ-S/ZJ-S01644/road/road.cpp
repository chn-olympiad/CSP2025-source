#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, ll>
#define fi first
#define se second
using namespace std;
const int maxn = 1e4 + 7;
struct edge{
	int to; ll val;
};
int n, m, k;
ll dis[maxn], vis[maxn], E[maxn];
vector<edge> p[maxn];
vector<int> V;
priority_queue<pii> q;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k; ll sum = 0;
	for(int i = 1, u, v, w; i <= m; ++i){
		cin >> u >> v >> w;
		p[u].push_back({v, w}); p[v].push_back({u, w});
	}
	for(int i = 1, c; i <= k; ++i){
		cin >> c;
		for(int j = 1, x; j <= n; ++j){
			cin >> x;
			if(x == 0) V.push_back(j);
			E[j] = x;
			p[n + i].push_back({j, c + x}); p[j].push_back({n + i, c + x});
		}
		if(c == 0 && V.size()){
			for(int j = 0; j < V.size(); ++j){
				for(int k = 1; k <= n && k != j; ++k){
					p[j].push_back({k, E[k]}); p[k].push_back({j, E[k]});
				}
			}
		}
	}
	for(int i = 1; i <= n + k; ++i){
		dis[i] = LLONG_MAX;
	}
	dis[1] = 0; q.push({1, 0});
	while(!q.empty()){
		pii t = q.top(); q.pop(); vis[t.fi] = 1;
		int u = t.fi;
		for(int i = 0; i < p[u].size(); ++i){
			int v = p[u][i].to; ll w = p[u][i].val;
			if(!vis[v]){
				if(dis[v] == LLONG_MAX){
					dis[v] = dis[u] + w;
					q.push({v, dis[v]});
					sum += w;
				}else if(dis[v] > dis[u] + w){
					sum -= dis[v];
					dis[v] = dis[u] + w;
					sum += dis[v];
					q.push({v, dis[v]});
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}
