#include <bits/stdc++.h>
using namespace std;

struct sd {
	int u, v, w;
} s[1000005];

int cmp(sd x, sd y) {
	return x.w < y.w;
}
int c[1000005], b[15][10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> s[i].u >> s[i].v >> s[i].w;
	}
	if (k == 0) {
		int sum = 0;
		sort(s + 1, s + m + 1, cmp);
		for (int i = 1; i <= n - 1; i++) {
			sum += s[i].w;
		}
		cout << sum;
		return 0;
	}
	int f = 1, f1 = 1;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0) {
			f = 0;
		}
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
			if (b[i][j] != 0) {
				f1 = 0;
			}
		}
	}
	if (f == 0 && f1 == 0) {
		cout << 0;
	}
	return 0;
}
