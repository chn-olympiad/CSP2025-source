#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+20;
int fa[N], c[20];

struct A {
	int u;
	int v;
	int w;
} a[N];

int cmp(A a, A b) {
	return a.w < b.w;
}

int find(int x) {
	if (fa[x] != x) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void un(int x, int y) {
	x = find(x);
	y = find(y);
	fa[y] = x;
}

int main() {
	long long n, m, k, x, cnt = 0, s, minx = LLONG_MAX, sum, f = 1;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[++cnt].u >> a[cnt].v >> a[cnt].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0) {
			f = 0;
		}
		for (int j = 1; j <= n; j++) {
			cin >> x;
			a[++cnt].u = i + n;
			a[cnt].v = j;
			a[cnt].w = x;
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	if (!f || k == 0) {
		for (int l = 1; l <= k; l++) {
			s = 0;
			sum = 0;
			for (int i = 1; i <= n + k; i++) {
				fa[i] = i;
			}
			for (int i = 1; i <= cnt; i++) {
				if (find(a[i].u) != find(a[i].v) && (a[i].u <= m || a[i].u == l + n)) {
					un(a[i].u, a[i].v);
					s++;
					sum = sum + a[i].w;
					if (s == n) {
						break;
					}
				}
			}
			sum = sum + c[l];
			minx = min(minx, sum);
		}
		s = 0;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= cnt; i++) {
			if (find(a[i].u) != find(a[i].v) && a[i].u <= m) {
				un(a[i].u, a[i].v);
				s++;
				sum = sum + a[i].w;
				if (s == n - 1) {
					break;
				}
			}
		}
		minx = min(minx, sum);
		cout << minx;
	} else {
		sum = 0;
		for (int i = 1; i <= cnt; i++) {
			if (find(a[i].u) != find(a[i].v)) {
				un(a[i].u, a[i].v);
				sum = sum + a[i].w;
				f = 1;
				for (int j = 1; j < n; j++) {
					if (find(j) != find(j + 1)) {
						f = 0;
					}
				}
				if (f) {
					cout << sum;
					return 0;
				}
			}
		}
	}
	return 0;
}
