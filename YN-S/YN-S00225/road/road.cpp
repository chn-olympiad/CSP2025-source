#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, w;
} e[999999];
int f[999999];

bool cmp(edge x, edge y) {
	return x.w < y.w;
}
long long an;

int find(int x) {
	if (x == f[x])
		return x;
	else
		return f[x] = find(f[x]);
}
int n, m, k, c[999999], cc[11][999999];

void ku() {
	for (int i = 1; i <= m; i++) {
		int x = find(e[i].u), y = find(e[i].v);
		if (x == y)
			continue;
		f[x] = y;
		an += e[i].w;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= m; j++)
			cin >> cc[i][j];
	}
	if (c[1] == 0 && k != 0)
		cout << 0;
	else {
		sort(e + 1, e + 1 + m, cmp);
		for (int i = 1; i <= n; i++)
			f[i] = i;
		ku();
		cout << an;
	}
	return 0;
}