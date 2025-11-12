#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int h[5010];
int k;
int u;
int a[5010];
int jp[5010];
int d;

int dfs(int x, int m, int l) {
	for (int i = 1; i <= l; i++) {
		if (m + h[i] <= x && jp[i] == 0) {
			d++;
			jp[i] = 1;
			dfs(x, m + h[i], l);
			jp[i] = 0;
		}
	}
	return d;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	sort(h + 1, h + 1 + n);
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + h[i];
	}
	for (int i = 3; i <= n; i++) {
		if (a[i] > h[i] * 2) {
			k++;
			k %= 998244353;
			if (i > 3) {
				for (int j = i - 3; j >= 1; j--) {
					if (a[i] - j > 2 * h[i]) {
						d = 0;
						u = dfs(a[i] - 2 * n - 1, 0, j);
						k += u;
						k %= 998244353;
						break;
					}
				}
			}

		}
	}
	cout << k;
	return 0;
}