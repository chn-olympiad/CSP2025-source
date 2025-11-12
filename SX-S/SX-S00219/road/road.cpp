#include <bits/stdc++.h>
using namespace std;
long long n, m, s, c, k, u, v, w, ans, ss = INT_MAX;

struct node {
	long long b[10005];
} a[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (long long  i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			if (i !=  j) {
				a[i].b[j] = INT_MAX;
				a[j].b[i] = INT_MAX;
			} else
				a[i].b[i] = 0;

		}
	}
	for (long long  i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		a[u].b[v] = w;
		a[v].b[u] = w;
	}
	for (long long i = 1; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= k; j++) {
			cin >> w;
			a[c].b[j] = min(a[c].b[j], w + c);
		}
	}
	for (long long kk = 1; kk <= n; kk++) {
		for (long long i = 1; i <= n; i++) {
			if (i == kk)
				continue;
			for (long long j = 1; j <= n; j++) {
				if (j == kk)
					continue;
				if (a[i].b[j] > a[i].b[kk] + a[kk].b[j])
					a[i].b[j] = a[i].b[kk] + a[kk].b[j];
			}
		}
	}
	for (long long i = 1; i <= n; i++) {
		s = INT_MAX;
		for (long long j = i + 1; j <= n; j++) {
			if (a[j].b[i] < ss and i != j) {
				s = min(s, a[j].b[i]);
			}
		}
		for (long long j = i - 1; j >= 1; j--) {
			if (a[j].b[i] < ss and i != j) {
				s = min(s, a[j].b[i]);
			}
		}
		if (s !=  ss)
			ans += s;
	}
	cout << ans;
	return 0;
}
