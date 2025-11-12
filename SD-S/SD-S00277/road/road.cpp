#include <bits/stdc++.h>

#define int long long

const int N = 1e4 + 50;

using namespace std;

int n, m, k;
int p[N];
int ans;
int mp[N];
vector<pair<int, int>> G[N];
struct Village {
	int v[N];
	int builded;
} a[20];
struct Node {
	int u, v, w;
	int operator < (const Node y) const {
		return w > y.w;
	}
};

int fifa(int x) {
	if (p[x] == x) return x;
	return p[x] = fifa(p[x]);
}

void add(int x, int y) {
	x = fifa(x), y = fifa(y);
	if (x != y) {
		p[x] = y;
	}
}

int query(int x, int y) {
	x = fifa(x), y = fifa(y);
	return x == y;
}

void init() {
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}
}

/*
4 5 10
1 2 3
2 3 4
3 4 5
4 1 6
1 3 7
1 3 4 5 6
2 3 4 5 6
3 3 4 5 6
4 3 4 5 6
5 3 4 5 6
6 3 4 5 6
7 3 4 5 6
8 3 4 5 6
9 3 4 5 6
10 3 4 5 6
*/

void ksl() {
	int flag = 0;
	priority_queue<Node> pq;
	for (int i = 1; i <= n + k; i++) {
		for (auto e: G[i]) {
			pq.push({i, e.first, e.second});
		}
	}
	while (!pq.empty() && flag < n) {
		int u = pq.top().u, v = pq.top().v, w = pq.top().w;
		pq.pop();
		if (query(u, v)) {
			continue;
		}
		if (u > n && a[u - n].builded) {
			ans -= a[u - n].v[0];
		}
		if (u > n && !a[u - n].builded) {
			a[u - n].builded = true;
		}
		if (v > n && a[v - n].builded) {
			ans -= a[v - n].v[0];
		}
		if (v > n && !a[v - n].builded) {
			a[v - n].builded = true;
		}
		if (!mp[u] && u <= n) {
			mp[u] = 1;
			flag++;
		}
		if (!mp[v] && v <= n) {
			mp[v] = 1;
			flag++; 
		}
		ans += w;
		add(u, v);
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init();
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i].v[0];
		for (int j = 1; j <= n; j++) {
			cin >> a[i].v[j];
			G[i + n].push_back({j, a[i].v[j] + a[i].v[0]});
		}
		a[i].builded = false;
	}
	ksl();
	cout << ans;
	return 0;
}

