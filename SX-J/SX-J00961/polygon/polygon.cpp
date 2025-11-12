#include <bits/stdc++.h>
using namespace std;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int maxn = INT_MIN, sum = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i != j && j != k && i != k) {
					sum += a[i] + a[j] + a[k];
					maxn = max(a[i], a[j]);
					maxn = max(maxn, a[k]);
					if (2 * maxn < sum)
						cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
