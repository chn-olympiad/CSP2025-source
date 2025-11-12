#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
	int u, v, w;
};

bool flag[20];
int n, m, k;
int c[20], a[20][10010], p[10010];
vector<Edge> e;

int root(int x) {
	return (p[x] == x ? p[x] : p[x] = root(p[x]));
}

int kruskal() {
	int ret = 0;
	vector<Edge> e2 = e;
	for (int i = 1; i <= k; ++i) 
		if (flag[i]) 
			for (int j = 1; j <= n; ++j) 
				e2.push_back({n + i, j, a[i][j]});
				
	sort(e2.begin(), e2.end(), [](const Edge& i, const Edge& j) {
		return i.w < j.w; 
	});
	
	for (int i = 1; i <= n + k; ++i) 
		p[i] = i;
	
	for (auto ed : e2) {
		int ru = root(ed.u), rv = root(ed.v);
		if (ru == rv) {
			continue;
		}
		p[ru] = p[rv];
		ret += ed.w; 
	}
	
	return ret;
}

int DFS(int last) {
	int ret = 0;
	if (last == k) {
		ret = kruskal();
		for (int i = 1; i <= k; ++i) 
			if (flag[i])
				ret += c[i];
		return ret;
	}
	flag[last + 1] = 1;
	ret = DFS(last + 1);
	flag[last + 1] = 0;
	ret = min(ret, DFS(last + 1));
	return ret;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	}
	
	cout << DFS(0);
	return 0;
}
