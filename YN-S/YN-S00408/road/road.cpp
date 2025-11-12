#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int fa[11111];

struct B {
	int u;
	int v;
	int w;
};
B e[11111];

int find(int x) {
	if (fa[x] == x)
		return x;
	else {
		fa[x] = find(fa[x]);
		return fa[x];
	}
}

bool cmp(B b1, B b2) {
	return b1.w < b2.w;
}

int Kru(int op, int ed) {
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= m + n * k; i++) {
		if (find(fa[e[i].u]) != find(fa[e[i].v])) {
			fa[e[i].u] = fa[e[i].v];
			if (e[i].u <= n)
				cnt++;
			ans += e[i].w;
			cout << e[i].u << ' ' << e[i].v << '\n';
		}
		if (cnt == n - 1)
			break;
	}
	return ans;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e + 1, e + m + 1, cmp);
	int ans1 = Kru(1, n);
	int c[k + 1];
	int cnt = 0;
	bool shuchu = false;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0)
			shuchu = true;
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (a != 0)
				shuchu = true;
			cnt++;
			e[m + cnt].u = i + n;
			e[m + cnt].v = j;
			e[m + cnt].w = a;
		}
	}
	if (shuchu) {
		cout << 0 << '\n';
		return 0;
	} else
		cout << ans1 << '\n';
	return 0;
}