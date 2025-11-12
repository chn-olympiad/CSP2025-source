#include <bits/stdc++.h>
using namespace std;
int num, sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[10005];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum = max(sum, a[i]);
		num += a[i];
	}
	if (n == 3) {
		cout << 0;
	}
	if (n > 3) {
		if (sum > num * 2) {
			cout << 2 * n - 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}