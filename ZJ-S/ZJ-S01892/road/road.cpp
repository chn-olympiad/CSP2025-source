// Goodbye, Cifera
// Expect: 16pts
// 复杂度：O(k!mklog(m+k))
// 听说新换的评测姬很快，祈祷评测机波动……

#include <bits/stdc++.h>

#define int long long

using namespace std; 

#define pii pair<int, int>
#define x first
#define y second

const int N = 1e6 + 1, K = 11; 
int n, m, k, w[N], fa[N + K];
pair<int, pii> g[N], f[K][N];  
vector<int> a; 

priority_queue<
	pair<int, pii> , 
	vector<pair<int, pii>>, 
	greater<pair<int, pii>> 
> pq; 

inline int findfa(int x) { return ((fa[x] == x) ? x : (fa[x] = findfa(fa[x]))); }
inline void combine(int x, int y) { fa[findfa(x)] = findfa(y); }

inline int dfs(int dep) 
{
	if(dep != k + 1) {
		int ret = dfs(dep + 1); 
		a.push_back(dep); 
		ret = min(ret, dfs(dep + 1)); 
		a.pop_back(); 
		return ret; 
	}

	for(int i = 1; i <= n + k; i ++) fa[i] = i; 
	
	auto tpq = pq; 

	for(int it : a) for(int i = 1; i <= n; i ++) tpq.push(f[it][i]); 

	int ret = 0; 
	for(int it : a) ret += w[it];
	while(not tpq.empty()) {
		pair<int, pii> it = tpq.top(); 
		tpq.pop(); 

		if(findfa(it.y.y) == findfa(it.y.x)) continue;
		combine(it.y.x, it.y.y); 
		ret += it.x; 
	}

	return ret; 
}

signed main()
{
	freopen("road.in", "r", stdin); 
	freopen("road.out", "w", stdout); 

	cin.tie(nullptr) -> sync_with_stdio(false); 

	cin >> n >> m >> k; 
	for(int i = 1; i <= m; i ++) cin >> g[i].y.x >> g[i].y.y >> g[i].x;
	for(int i = 1; i <= m; i ++) pq.push(g[i]); 

	for(int i = 1; i <= k; i ++) {
		cin >> w[i]; 

		for(int j = 1, t; j <= n; j ++) {
			cin >> f[i][j].x; 
			f[i][j].y.x = i + n; 
			f[i][j].y.y = j; 
		}  
	}

	cout << dfs(1) << '\n'; 

	return 0; 
}