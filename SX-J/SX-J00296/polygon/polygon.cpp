#include <bits/stdc++.h>
using namespace std;
int a[1000054];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = j; k <= n; k++) {
				if (a[i] + a[j] + a[k] > 2 * max(max(a[i], a[j]), max(a[j], a[k])) && i != j && j != k && i != k) {
					ans++;
				}

			}
		}
	}
	cout << ans;
	return 0;
}