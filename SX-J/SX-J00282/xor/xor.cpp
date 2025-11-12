#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], f[1005][1005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= 255; j++) {
			f[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			for (int j = 0; j <= 255; j++) {
				f[i][j] = f[i - 1][j];
			}
			if (k == 0) {
				f[i][0]++;
			}
			continue;
		}
		for (int j = 0; j <= 255; j++) {
			if (f[i - 1][j] == -1)
				continue;
			if (j == k)
				continue;
			f[i][j ^a[i]] = f[i - 1][j];
			if ((j ^ a[i]) == k)
				f[i][j ^ a[i]]++;
		}
		f[i][0] = max(f[i - 1][k], f[i][k]);
		f[i][0] = max(f[i][0], f[i - 1][0]);
		f[i][0] = max(0, f[i][0]);
	}
	cout << f[n][0];

	return 0;
}