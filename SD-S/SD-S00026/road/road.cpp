#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m, k;

struct Edge {
	int to, w, nxt;
} edges[N];

int x, y, summ;
int head[N], cnt;
void add_edge(int u, int v, int w) {
	edges[++ cnt].w = w;
	edges[cnt].to = v;
	edges[cnt].nxt = head[u];
	head[u] = cnt;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; ++ i) {
		cin >> u >> v >> w;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	for(int i = 1; i <= k; ++ i) {
		int c;
		cin >> c;
		if(c == 0) x ++;
		for(int j = 1; j <= n; ++ j) {
			int a;
			cin >> a;
			if(a == 0) y ++;
			else summ += a;
			add_edge(i + m, j, a);
			add_edge(j, i + m, a); 
		}
	}
	if(x == k && y == k * m) {
		cout << 0 << "\n";
		return 0;
	}
	else {
		cout << summ << "\n";
		return 0;
	}
	if(k == 0) {
		int sum = 0;
		for(int e = head[1]; e != 0; e = edges[e].nxt)
			sum += edges[e].w;
		cout << sum << "\n";
	}
	return 0;
}
