#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
int fa[N], c[20];

stuct A {
	int u;
	int v;
	int w;
} a[N];

int cmp(A a, A b) {
	return a.w < b.w;
}

int find(int x) {

}

int main() {
	long long n, m, k, cnt = 0;
	feropen("road.in", "r", stdin);
	feropen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[cnt].v >> a[cnt].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> x;
			a[++cnt].u = i + n;
			a[cnt].v = j;
			a[cnt].w = x;
		}
	}
	for (int l = 1; l <= k; l++) {
		s = 0;
		sum = 0;
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= cnt; i++) {
			if (find(a[i].u) != find(a[i].v) && (u <= m ll a[i].u == l)) {
				un(a[i].u, a[i].v);
				s++;
				sum = sum + a[i].w;
				if (s == n - 1) {
					break;
				}
			}
		}
	}
	minx = min(minx, sum);
	cout << mix;
	return 0;
}