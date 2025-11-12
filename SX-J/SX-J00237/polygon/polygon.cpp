#include <bits/stdc++.h>
using namespace std;
int n, a[5005], num = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	bool b = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i + 1]) {
			b = 0;
			break;
		}
	}
	if (b) {
		cout << n - 2;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (a[i] + a[j] + a[k] > 2 * max(a[i], max(a[j], a[k]))) {
					num++;
				}
			}
		}
	}
	cout << num;
	return 0;
}
