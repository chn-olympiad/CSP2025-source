#include <bits/stdc++.h>
using namespace std;
int a[10005][10005], x, y;

struct xiang {
	int a1[10005];
	int c;
} b[13];
int d[10000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		cin >> y;
		cin >> a[x][y];
	}
	for (int i = 1; i <= k; i++) {
		cin >> b[i].c;
		for (int j = 1; j <= n; j++) {
			cin >> b[i].a1[j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != 0) {
				a[j][i] = a[i][j];
			}
			if (a[j][i] != 0) {
				a[i][j] = a[j][i];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			for (int q = 1; q <= k; q++) {
				if (a[i][j] > b[q].c + b[q].a1[i] + b[q].a1[j]) {
					a[i][j] = b[q].c + b[q].a1[i] + b[q].a1[j];
				}
			}
		}
	}
	int o = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			o++;
			d[o] = a[i][j];

		}
	}
	sort(d + 1, d + o + 1);
	int ans = 0, ab = n - 1;
	for (int i = 1; i <= ab; i++) {
		if (d[i] != 0) {
			ans += d[i];
		} else {
			ab++;
		}
	}
	cout << ans << endl;
	return 0;
}
