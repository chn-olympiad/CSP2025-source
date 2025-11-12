#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[15], h[10015], x, f[10015], an;
long long ans = LLONG_MAX;
bitset<15>y;
bitset<2200005>g;
vector<int>d;

struct node {
	int n, u, v, w;
} e[2200005];

bool cmp(int x, int y) {
	return e[x].w > e[y].w;
}

int z(int w) {
	if (f[w] == w)
		return w;
	return f[w] = z(f[w]);
}

void dfs(int s) {
	if (s > k) {
		long long sum = 0, gs = n;
		for (int i = 1; i <= n + k; i++) {
			if (i > n) {
				if (!y[i - n])
					continue;
				else
					sum += c[i - n];
			}
			int x = h[i];
			for (; x; x = e[x].n) {
				if (e[x].v > n)
					if (!y[e[x].v - n])
						continue;
				if (g[x])
					continue;
				d.push_back(x);
				if (x % 2)
					g[x + 1] = true;
				else
					g[x - 1] = true;
				g[x] = true;
			}
			gs++;
		}
		sort(d.begin(), d.end(), cmp);
		int s = 0;
		while (!d.empty()) {
			if (s >= gs - 1)
				break;
			if (z(e[d[d.size() - 1]].u) != z(e[d[d.size() - 1]].v)) {
				s++;
				sum += e[d[d.size() - 1]].w;
				f[z(e[d[d.size() - 1]].u)] = z(e[d[d.size() - 1]].v);
			}
			d.pop_back();
		}
		while (!d.empty())
			d.pop_back();
		int zx = z(1);
		bool d = true;
		for (int i = 2; i <= n; i++) {
			if (z(i) != zx)
				d = false;
		}
		if (d)
			ans = min(ans, sum);
		for (int i = 1; i <= n + k; i++)
			f[i] = i;
		for (int i = 1; i <= (m + k * n) * 2; i++)
			g[i] = false;
		return;
	}
	y[s] = true;
	dfs(s + 1);
	if (c[s] > 0) {
		y[s] = false;
		dfs(s + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[++x] = node{h[u], u, v, w};
		h[u] = x;
		e[++x] = node{h[v], v, u, w};
		h[v] = x;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			e[++x] = node{h[n + i], n + i, j, w};
			h[n + i] = x;
			e[++x] = node{h[j], j, n + i, w};
			h[j] = x;
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}
