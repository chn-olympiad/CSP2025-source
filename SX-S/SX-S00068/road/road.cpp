#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}

struct Edge {
	int u, v, w;
	bool operator < (const Edge &a) const {
		return w < a.w;
	}
} a[1111111];

int n, m, k, fa[11111], cst[15];
long long ans = 1e18;
bitset<11111> used;

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

long long kruskal(int num) {
	int cnt = 0;
	long long sum = 0;
	for (int i = 1; cnt < num - 1; i++) {
		if (!used[a[i].u] || !used[a[i].v])
			continue;
		int fu = find(a[i].u), fv = find(a[i].v);
		if (fu != fv)
			cnt++, fa[fu] = fv, sum += a[i].w;
	}
	return sum;
}

int main() {
	file();
	cin >> n >> m >> k;
	for (int i = 1; i <= 11000; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	bool sa = 1;
	for (int i = 1; i <= k; i++) {
		cin >> cst[i];
		if (cst[i])
			sa = 0;
		bool ze = 0;
		for (int j = 1; j <= n; j++) {
			a[++m].u = n + i; a[m].v = j;
			scanf("%d", &a[m].w);
			if (!a[m].w)
				ze = 1;
		}
		if (!ze)
			sa = 0;
	}
	for (int i = 1; i <= n; i++)
		used[i] = 1;
	sort(a + 1, a + m + 1);
	if (sa) {
		for (int i = 1 + n; i <= k + n; i++)
			used[i] = 1;
		cout << kruskal(n + k);
	} else {
		for (int i = 0; i < (1 << k); i++) {
			for (int j = 1; j <= 11000; j++)
				fa[j] = j;
			int cnt1 = 0;
			long long add = 0;
			for (int j = 1; j <= k; j++)
				used[n + j] = (i >> j - 1) & 1, cnt1 += (i >> j - 1) & 1, add += ((i >> j - 1) & 1) * cst[j];
			ans = min(kruskal(n + cnt1) + add, ans);
		}
		cout << ans, exit(0);
	}
	return 0;
}
