#include <bits/stdc++.h>
using namespace std;
int n, m, a[100], sum = 1, f[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i > 1) {
			if (a[i] > a[1])
				sum++;
		}
	}
	int nextx = 1, nexty = 1;
	for (int i = 1; i <= n * m; i++) {
		f[nexty][nextx] = i;
		if (nextx % 2 == 1) {
			if (nexty == m) {
				nextx++;
				continue;
			}
			nexty++;
		}
		if (nextx % 2 == 0) {
			if (nexty == 1) {
				nextx++;
				continue;
			}
			nexty--;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (f[i][j] == sum) {
				cout << j << ' ' << i;
			}
		}
	}
	return 0;
}