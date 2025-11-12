#include <bits/stdc++.h>
using namespace std;
int n, m, a, a1, sum = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int f = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a;
			if (f == 0) {
				a1 = a;
				f = 1;
			} else {
				if (a > a1) {
					sum ++;
				}
			}
		}
	}
	if (sum < n) {
		cout << 1 << sum;
	} else if (sum % n == 0) {
		if ((sum / n) % 2 == 0)
			printf("%d 1", sum / n);
		else
			printf("%d %d", sum / n, n);
	} else {
		if ((sum / n + 1) % 2 == 1)
			printf("%d %d", sum / n + 1, sum % n);
		else
			printf("%d %d", sum / n + 1, n + 1 - sum % n);
	}
	return 0;
}