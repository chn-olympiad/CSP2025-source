#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e3+5, M = 1e6+5, K = 15;
int n, m, k;
int c[K][N];

struct node {
	int u, v, w;
} a[M + K * N + K];

bool cmp(node x, node y) {
	return x.w < y.w;
}
int fa[N + K + K];

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

int krust() {
	int cnt = 0, sum = 0;
	for (int i = 1; i <= m; i++) {
		int x = find(a[i].u), y = find(a[i].v);
		if (x != y && x <= n && y <= n) {
			cnt++;
			sum += a[i].w;
			fa[x] = y;
			if (cnt == n - 1) {
				break;
			}
		}
	}
	return sum;
}
bool ok[K];

int kru(int te) {
	int cnt = 0, sum = 0;
	for (int i = 1; i <= n + k + k; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m + n + 1; i++) {
		int x = find(a[i].u), y = find(a[i].v);
		if (x != y && (x == te || x == te + k || x <= n) && (y == te || y == te + k || y <= n)) {
			cnt++;
			sum += a[i].w;
			fa[x] = y;
			if (cnt == n + 1) {
				break;
			}
		}
	}
	return sum;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int uu, vv, ww;
		cin >> uu >> vv >> ww;
		a[i] = {uu, vv, ww};
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i][0];
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	sort(a + 1, a + 1 + m, cmp);
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	int res = krust();
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			a[m + j] = {i + n, j, c[i][j]};
		}
		a[n + m + 1] = {i + n, i + n + k, c[i][0]};
		res = min(res, kru(i + n));
	}
	cout << res;
	return 0;
}
