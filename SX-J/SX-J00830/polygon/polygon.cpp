#include <bits/stdc++.h>
using namespace std;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0, maxx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		maxx = max(maxx, a[i]);
	}
	if (n == 3) {
		if (sum > 2 * maxx)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if (n == 4) {
		int mx, cnt, ans = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k <= n; k++) {
					mx = max(a[i], a[j]);
					mx = max(mx, a[k]);
					cnt = a[i] + a[j] + a[k];
					if (cnt > 2 * mx)
						ans++;
				}
			}
		}
		if (sum > 2 * maxx)
			ans++;
		cout << ans;
		return 0;
	}
	if (n == 5) {
		int mx, cnt, ans = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k <= n; k++) {
					mx = max(a[i], a[j]);
					mx = max(mx, a[k]);
					cnt = a[i] + a[j] + a[k];
					if (cnt > 2 * mx)
						ans++;
				}
			}
		}
		for (int i = 1; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					for (int g = k + 1; g <= n; g++) {
						mx = max(a[i], a[j]);
						mx = max(mx, a[k]);
						mx = max(mx, a[g]);
						cnt = a[i] + a[j] + a[k] + a[g];
						if (cnt > 2 * mx)
							ans++;
					}
				}
			}
		}
		if (sum > 2 * maxx)
			ans++;
		cout << ans;
		return 0;
	}
	if (n == 6) {
		int mx, cnt, ans = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k <= n; k++) {
					mx = max(a[i], a[j]);
					mx = max(mx, a[k]);
					cnt = a[i] + a[j] + a[k];
					if (cnt > 2 * mx)
						ans++;
				}
			}
		}
		for (int i = 1; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					for (int g = k + 1; g <= n; g++) {
						mx = max(a[i], a[j]);
						mx = max(mx, a[k]);
						mx = max(mx, a[g]);
						cnt = a[i] + a[j] + a[k] + a[g];
						if (cnt > 2 * mx)
							ans++;
					}
				}
			}
		}
		for (int i = 1; i < n - 3; i++) {
			for (int j = i + 1; j < n - 2; j++) {
				for (int k = j + 1; k < n - 1; k++) {
					for (int g = k + 1; g < n; g++) {
						for (int f = g + 1; f <= n; f++) {
							mx = max(a[i], a[j]);
							mx = max(mx, a[k]);
							mx = max(mx, a[g]);
							mx = max(mx, a[f]);
							cnt = a[i] + a[j] + a[k] + a[g] + a[f];
							if (cnt > 2 * mx)
								ans++;
						}
					}
				}
			}
		}
		if (sum > 2 * maxx)
			ans++;
		cout << ans;
		return 0;
	}
	return 0;
}
