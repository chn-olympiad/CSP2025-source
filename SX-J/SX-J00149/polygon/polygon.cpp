#include <bits/stdc++.h>
using namespace std;
int m, a[5005], sum, sum1, sum2, cnt;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= m - 1; i++) {
		sum1 += a[i];
	}
	for (int i = 3; i <= m; i++) {
		sum2 += a[i];
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i++) {
		if (m >= 3 and sum > a[m] * 2) {
			cnt++;
		}
		if (m >= 3 and sum1 > a[m] * 2) {
			cnt++;
		}
		if (m >= 3 and sum2 > a[m] * 2) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
