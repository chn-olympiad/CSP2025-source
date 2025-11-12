#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k;

struct hsu {
	int a, b, c;
} edge[1000010];

struct citty {
	int num;
	int cy[10010];
} ct[30];

bool cmp(hsu q, hsu p) {
	return q.c < p.c;
}

int fa[10010];

int fd(int a) {
	if (a == fa[a]) {
		return a;
	}
	return fa[a] = fd(fa[a]);
}

int ans = 0;

void dijkstra() {
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		int af, bf;
		af = fd(edge[i].a);
		bf = fd(edge[i].b);
		if (fa[af] != fa[bf]) {
			cout << edge[i].a << " " << edge[i].b << " " << edge[i].c << endl;
			ans += edge[i].c;
			fa[af] = fa[bf];
		}
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i].a = a;
		edge[i].b = b;
		edge[i].c = c;
	}
	int maxx = INT_MIN;
	for (int i = 1; i <= k; i++) {
		cin >> ct[i].num;
		maxx = max(maxx, ct[i].num);
		for (int j = 1; j <= k; j++) {
			cin >> ct[i].cy[j];
			maxx = max(maxx, ct[i].cy[j]);
		}
	}
	if (maxx == 0) {
		cout << 0;
	}
	if (k == 0) {
		dijkstra();
		cout << ans << endl;
	}
	return 0;
}
/*
6 9 0
1 2 3
2 3 7
1 3 4
1 4 7
3 6 5
2 5 9
4 5 2
4 6 6
3 5 5
*/
/*
4 5 2
1 2 3
1 3 4
3 6 5
3 5 5
*/
