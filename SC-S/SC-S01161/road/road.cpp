#include <bits/stdc++.h> 
#define ll long long 
#define pii pair < int, int > 
#define fir first 
#define sec second 

using namespace std; 

const int N = 1e4 + 10 + 5; 

int n, m, k; 
int fa[N]; 
vector < pii > g[N]; 
int a[15][N]; 
bool ing[N]; 
ll ans; 
bool vis[N]; 
int c[15]; 

struct node {
	int v, w; 
};

ll f() {
	int u, v, w; 
	ll ans = 0; 
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i; 
		vis[i] = 0; 
	}
	priority_queue < pii, vector < pii >, greater < pii > > pq; 
	pq.push({0, 1}); 
	while (!pq.empty()) {
		u = pq.top().sec; 
		if (vis[u]) {
			pq.pop(); 
			continue; 
		}
		ans += pq.top().fir; 
		pq.pop(); 
		vis[u] = 1; 
		for (auto p : g[u]) {
			v = p.fir; 
			w = p.sec; 
			if (ing[v] && !vis[v]) 
				pq.push({w, v}); 
		}
	}
	return ans; 
}
void dfs(int x, ll sum) {
	if (x > k) {
		ans = min(ans, sum + f()); 
		return ; 
	}
	dfs(x + 1, sum); 
	ing[x + n] = 1; 
	dfs(x + 1, sum + c[x]); 
	ing[x + n] = 0; 
}

signed main() {
	freopen("road.in", "r", stdin); 
	freopen("road.out", "w", stdout); 
	
	scanf("%d%d%d", &n, &m, &k); 
	int u, v, w; 
	for (int i = 1; i <= n; i++) ing[i] = 1; 
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w); 
		g[u].push_back({v, w}); 
		g[v].push_back({u, w}); 
	}
	
	for (int i = 1; i <= k; i++) {
		scanf("%d", c + i); 
		for (int j = 1; j <= n; j++) {
			scanf("%d", &w); 
			g[i + n].push_back({j, w}); 
			g[j].push_back({i + n, w}); 
		}
	}
	
	ans = 1e18; 
	dfs(1, 0); 
	
	printf("%lld\n", ans); 
	
	return 0; 
}