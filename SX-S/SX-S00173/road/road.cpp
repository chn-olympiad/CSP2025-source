#include <bits/stdc++.h>
using namespace std;
int n, m, k, s = 0;

int c[20], a[20][10010], d[10010] = {};
long long ans = 0;
struct str {
	int u, v, w;
} r[2000010];
int comp(str aa, str bb) {
	return aa.w < bb.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &r[i].u, &r[i].v, &r[i].w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
		for (int j = 1; j <= n; j++) {
			for (int kk = j + 1; kk <= n; kk++) {
				m++;
				r[m].u = j;
				r[m].v = kk;
				r[m].w = a[i][j] + a[i][kk] + c[i];
			}
		}
	}
	sort(r + 1, r + m + 1, comp);
	s = 2;
	ans += r[s - 1].w;
	d[r[s - 1].u] = 1;
	d[r[s - 1].v] = 1;
	while (s < n) {
		for (int i = 2; i <= m ; i++) {
			if (d[r[i].u] == 0 || d[r[i].v] == 0) {
				if (d[r[i].v] == 0) {
					d[r[i].v] = 1;
					s++;
				}
				if (d[r[i].u] == 0) {
					d[r[i].u] = 1;
					s++;
				}
				ans += r[i].w;
			}
			if (s >= n)
				break;
		}
	}
	printf("%lld", ans);
	return 0;
}//RP++
