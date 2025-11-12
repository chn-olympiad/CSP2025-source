#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;

struct edge {
	ll u, v, w;
	
	bool operator<(const edge & e) {
		return w < e.w;
	}	
};

int n, m, k;
int fa[N], r[N];
vector<int> ans;

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
	if (r[u] > r[v]) {
		fa[v] = u;
	} else {
		fa[u] = v;
		if (r[u] == r[v]) r[v]++;
	}
}

int krus1(vector<edge> g) {
	
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		r[i] = 1;
	}
	
	ll res = 0, cnt = 0;
	for (int i = 0; i < g.size(); i++) {
		int u = g[i].u, v = g[i].v, w = g[i].w;
		u = find(u), v = find(v);
		if (u != v) {
			res += w;
			cnt ++;
			merge(u, v);
		}
		
		if (cnt == n - 1) break;
	}	
	
	return res;
}

int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	if (k == 0) {
		vector<edge> g;
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edge tmp;
			tmp.u = u, tmp.v = v, tmp.w = w;
			g.push_back(tmp);
		}
		sort(g.begin(), g.end());
		
		int ans = krus1(g);
		cout << ans << endl;
	} else {
		int asdf;
		for (int i = 1; i <= k; k++) cin >> asdf; 
		vector<edge> g;
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edge tmp;
			tmp.u = u, tmp.v = v, tmp.w = w;
			g.push_back(tmp);
		}
		sort(g.begin(), g.end());
		
		int ans = krus1(g);
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
