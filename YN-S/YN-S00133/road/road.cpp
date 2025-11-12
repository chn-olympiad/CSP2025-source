#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans, cnt, w[10010], c[20], a[20][10010];
bool flag;

struct uvz {
	int f, t, w;
} e[1000010];

int find(int x) {
	if (w[x] == x) {
		return x;
	}

	return find(w[x]);
}

bool cmp(uvz x, uvz y) {
	return x.w < y.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;

	if (!k) {
		flag = 1;
	}

	for (int i = 1; i <= m; i++) {

		w[i] = i;
		cin >> e[i].f >> e[i].t >> e[i].w;
	}

	for (int i = 1; i <= k; i++) {

		cin >> c[i];

		if (c[i] != 0) {
			flag = 1;
		}

		for (int j = 1; j <= n; j++) {

			cin >> a[i][j];

			if (a[i][j] != 0) {
				flag = 1;
			}
		}
	}

	if (!flag) {
		cout << 0;
		return 0;
	}

	sort(e + 1, e + m + 1, cmp);

	for (int i = 1; i <= m && cnt != n - 1; i++) {

		int u = e[i].f, v = e[i].t;

		if (find(u) != find(v)) {
			w[find(v)] = find(u);
			cnt++;
			ans += e[i].w;
		}
	}

	cout << ans;
	return 0;
}