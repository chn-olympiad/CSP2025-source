#include <bits/stdc++.h>
using namespace std;
long long n, m, k, u[10004], v[10004], w[10004], c[12], a[12][6], minn = 1000000000000000000, ans;
bool b[10004][10004], cs;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
	for (int j = 1; j <= k; j++) {
		scanf("%lld", &c[j]);
		for (int l = 1; l <= n; l++)
			scanf("%lld", &a[j][l]);
	}
	for (int j = 1; j <= k; j++) {
		if (c[j] == 0) {
			cout << 0;
			return 0;
		}
	}
	for (int i = 1; i < m - n + 2; i++) {
		ans = w[i];
		cs = true;
		for (int j = i + 1; j <= m; j++) {
			b[i][j] = b[j][i] = false;
			if (u[i] == u[j] || u[i] == v[j] || v[i] == u[j] || v[i] == v[j]) {
				ans += w[j];
				if (u[i] == u[j] && v[i] == v[j]) {
					ans = min(w[i], w[j]);
					break;
				}
				if (u[i] == v[j] && v[i] == u[j]) {
					ans = min(w[i], w[j]);
					break;
				}
				if (u[i] != u[j])
					b[u[i]][u[j]] = b[u[j]][u[i]] = true;
				if (v[i] != u[j])
					b[v[i]][u[j]] = b[u[j]][v[i]] = true;
				if (u[i] != v[j])
					b[u[i]][v[j]] = b[v[j]][u[i]] = true;
				if (v[i] != v[j])
					b[v[i]][v[j]] = b[v[j]][v[i]] = true;
			}
		}
		for (int p = 1; p < n; p++) {
			for (int q = p + 1; q <= n; q++) {
				if (b[p][q] = false)
					cs = false;
			}
		}
		if (ans < minn && cs == true)
			minn = ans;
	}
	printf("%lld", minn);
	return 0;
}