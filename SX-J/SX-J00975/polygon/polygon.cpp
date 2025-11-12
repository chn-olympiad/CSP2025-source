#include <bits/stdc++.h>
using namespace std;

int n, a[5010], m = 3;
int c, b, ans = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			for (int k = 3; k <= n; k++) {
				b = a[i] + a[j] + a[k];
				c = max(a[i], a[j]);
				c = max(c, a[k]);
				if (b > c) {
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}