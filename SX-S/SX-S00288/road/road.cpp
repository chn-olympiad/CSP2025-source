#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

constexpr int N = 1e4 + 5, K = 12, inf = 0x3f3f3f3f;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

int n, m, k, fa[N + K], tot, c[K], a[K][N], t[K];//Ö¸Õë

int find(int u) {
	if (fa[u] == u)
		return u;
	return fa[u] = find(fa[u]);
}
LL ans;

struct node {
	int u, v, w;
	bool operator < (const node &p)const {
		return w > p.w;
	}
} d[K][N];

bool cmp(node x, node y) {
	return x.w < y.w;
}
priority_queue<node> q;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		q.push({u, v, w});
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	while (!q.empty()) {
		node tp = q.top();
		q.pop();
		const int u = tp.u, v = tp.v, w = tp.w;
		if (find(u) == find(v))
			continue;
		ans += tp.w;
		fa[fa[u]] = fa[v];
		d[0][++tot] = {u, v, w};
		if (tot == n - 1)
			break;
	}
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++)
			d[i][j].u = n + i, d[i][j].v = j, d[i][j].w = read();
		sort(d[i] + 1, d[i] + n + 1, cmp);
	}
	for (int i = 1; i < (1 << k); i++) {
		for (int j = 0; j <= k; j++)
			t[j] = 1;
		for (int j = 1; j <= n + k; j++)
			fa[j] = j;
		LL sum = 0;
		int num = 0;
		for (int j = 1; j <= k; j++)
			if ((i >> (j - 1)) & 1)
				sum += c[j], num++;
		for (int j = 1; j < n + num; j++) {
			int mn = inf, id = -1;
			for (int l = 0; l <= k; l++)
				if (!l || (i >> (l - 1)) & 1) {
					if (d[l][t[l]].w < mn) {
						mn = d[l][t[l]].w;
						id = l;
					}
				}
			const int u = d[id][t[id]].u, v = d[id][t[id]].v;
			if (find(u) == find(v)) {
				t[id]++;
				j--;
				continue;
			}
			fa[fa[u]] = fa[v];
			sum += d[id][t[id]].w;
			t[id]++;
		}
		ans = min(ans, sum);
	}
	printf("%lld", ans);
	return 0;
}
