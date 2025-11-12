#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define PII pair<int, int>

const int N = 10050, K = 15;

struct edge{
	int v, w;
};

int n, m, k;
ll ans = 1e18;
int c[K], a[K][N], vis[N], dis[N], v[N], h[N];
vector<edge> e[N];
priority_queue<PII, vector<PII>, greater<PII> > q;

ll Prim(){
	ll p = 0;
	q.push({0, 1});
	for(int i = 1; i <= n + k; i ++){
		dis[i] = 1e9 + 7;
		v[i] = 0;
	}
	dis[1] = 0;
	while(!q.empty()){
		PII t = q.top();
		q.pop();
		if(v[t.second]) continue;
		int u = t.second;
		p += t.first;
		v[u] = 1;
		for(edge j : e[u]){
			if(j.v > n && !vis[j.v - n]) continue;
			if(j.w < dis[j.v]){
				q.push({j.w, j.v});
				dis[j.v] = j.w;
			}
		}
	}
	return p;
}

void dfs(int now, ll sum, int cnt){
	if(now > k){
		ans = min(ans, sum + Prim());
		return;
	}
	dfs(now + 1, sum, cnt);
	vis[now] = 1;
	if(!h[now]) dfs(now + 1, sum + c[now], cnt + 1);
	vis[now] = 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i ++){
		cin >> u >> v >> w;
		e[u].push_back((edge){v, w});
		e[v].push_back((edge){u, w});
	}
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1, w; j <= n; j ++){
			cin >> w;
			e[n + i].push_back((edge){j, w});
			e[j].push_back((edge){n + i, w});
		}
	} 
	ans = Prim();
	for(int i = 1; i <= k; i ++){
		vis[i] = 1;
		if(Prim() == ans) h[i] = 1;
		vis[i] = 0;
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}